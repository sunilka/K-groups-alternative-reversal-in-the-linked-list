#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

struct newnode
{
    int data;
    struct newnode *next;
};

struct newnode *hhead = NULL;
struct newnode *llast = NULL;


struct node *head = NULL;
struct node *last = NULL;


void print()
{
    cout<<"\n printing the linked list here "<<endl;
    struct node *temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

void pprint()
{
    cout<<"\n printing the new linked list here "<<endl;
    struct newnode *temp = hhead;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

void insert_into_ll(int temp)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = temp;
    newnode->next = NULL;

    if(head == NULL){
        head = newnode;
        last = newnode;
    }
    else{
        last->next = newnode;
        last = newnode;
    }
}

void cal(int k)
{
    struct node *temp = head;
    stack<struct node*> s;

    while(temp!=NULL){

        while(temp!=NULL && s.size()<k){
            s.push(temp);
            temp = temp->next;
        }

        while(!s.empty()){
            int ndata = s.top()->data;
            struct newnode *nnewnode = (struct newnode*)malloc(sizeof(struct newnode));
            nnewnode->data = ndata;

            if(hhead == NULL){
                hhead = nnewnode;
                llast = nnewnode;
            }

            else{
                llast->next = nnewnode;
                llast = nnewnode;
            }
            s.pop();
        }

        int p  = k;
        while(temp!=NULL && p){
            int ndata = temp->data;
            struct newnode *nnewnode = (struct newnode*)malloc(sizeof(struct newnode));
            nnewnode->data = ndata;

            if(hhead == NULL){
                hhead = nnewnode;
                llast = nnewnode;
            }

            else{
                llast->next = nnewnode;
                llast = nnewnode;
            }
            temp = temp->next;
            p--;
        }
    }

    pprint();

}



void solve()
{
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        insert_into_ll(temp);
    }

    print();
    cal(k);
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
