#include <bits/stdc++.h>

using namespace std;
int broj;
struct treapNode{
    int key;
    double priority;
    treapNode *left,*right;
    int sizee;
};
treapNode* newNode(int key)
{
    treapNode* temp=new treapNode;
    temp->key=key;
    temp->priority=(double)rand()/RAND_MAX;
    temp->left=temp->right=NULL;
    temp->sizee=1;
    return temp;
}
treapNode* rightRotate(treapNode *y)
{
    //printf("RightRotate\n");
    treapNode *x=y->left,*B=x->right;
    int x_size;
    int b_size;
    if(x==NULL)
    {
        x_size=0;
    }
    else
    {
        x_size=x->sizee;
    }
    if(B==NULL)
    {
        b_size=0;
    }
    else
    {
        b_size=B->sizee;
    }
    x->right=y;
    x->sizee=y->sizee;
    y->sizee=y->sizee-x_size+b_size;
    y->left=B;
    return x;
}
treapNode* leftRotate(treapNode *x)
{
    //printf("LeftRotate\n");
    treapNode *y=x->right,*B=y->left;
    int y_size;
    int b_size;
    if(y==NULL)
    {
        y_size=0;
    }
    else
    {
        y_size=y->sizee;
    }
    if(B==NULL)
    {
        b_size=0;
    }
    else
    {
        b_size=B->sizee;
    }
    y->left=x;
    x->right=B;
    y->sizee=x->sizee;
    x->sizee=x->sizee-y_size+b_size;
    return y;
}
treapNode* insertuj(treapNode* root,int key)  //1- random 0-split
{
    if(root==NULL)
    {
        return newNode(key);
    }

    if(key < root->key)
    {
        (root->sizee)++;
        root->left = insertuj(root->left, key);
        if(root->left->priority<root->priority)
            root=rightRotate(root);
    }
    else
    {
        (root->sizee)++;
        root->right = insertuj(root->right, key);
        if(root->right->priority<root->priority)
            root=leftRotate(root);
    }
    return root;
}
treapNode* trazi(treapNode* root,int key)
{
    if(root->key==key)
    {
        if(root->right==NULL)
        {
        }
        else
        {
            broj+=root->right->sizee;
        }
    }
    if(root==NULL||root->key==key)
        return root;
    if(root->key<key)
    {
        return trazi(root->right,key);
    }
    if(root->right==NULL)
    {
        broj+=1;
    }
    else
    {
        broj+=root->right->sizee+1;
    }
    return trazi(root->left,key);
}
void prvi()
{
    int n;
    scanf("%i",&n);
    long long koliko=0;
    treapNode* root=NULL;
    treapNode* test=NULL;
    for(int i=0;i<n;i++)
    {
        int ccc;
        broj=0;
        scanf("%i",&ccc);
        root=insertuj(root,ccc);
        test=trazi(root,ccc);
        koliko+=(long long)broj;
    }
    //printf("%i\n",koliko);
    if((3*n)%2==koliko%2)
    {
        printf("Petr\n");
    }
    else
    {
        printf("Um_nik\n");
    }
}
void drugi()
{
    int n;
    scanf("%i",&n);
    int niz[n+1];
    int visited[n+1]={};
    for(int i=1;i<=n;i++)
    {
        int a;
        scanf("%i",&a);
        niz[i]=a;
    }
    int br=0;
    for(int i=1;i<=n;i++)
    {
        int tr=i;
        if(visited[tr]==0)
        {
            br++;
        }
        while(visited[tr]==0)
        {
            visited[tr]=1;
            tr=niz[tr];
        }
    }
    //printf("%i\n",br);
    if((3*n)%2==(n-br)%2)
    {
        printf("Petr\n");
    }
    else
    {
        printf("Um_nik\n");
    }
}
int main()
{
    drugi();
    return 0;
}