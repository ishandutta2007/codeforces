#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<iostream>
#include<algorithm>
using namespace std;

struct Treap
{
    int val,lz,fix,siz;
    Treap *l,*r;
    Treap(int _val)
    {
        val=_val;
        lz=0;
        fix=rand()<<15|rand();
        siz=1;
        l=r=NULL;
    }
};

typedef pair<Treap*,Treap*> Droot;

inline int get_size(Treap *n)
{
    return n ? n->siz : 0;
}

inline void push_up(Treap *n)
{
    n->siz=1+get_size(n->l)+get_size(n->r);
}

inline void push_down(Treap *n)
{
    if(n->l)
    {
        n->l->val+=n->lz;
        n->l->lz+=n->lz;
    }
    if(n->r)
    {
        n->r->val+=n->lz;
        n->r->lz+=n->lz;
    }
    n->lz=0;
}

Treap* merge(Treap *x,Treap *y)
{
    if(!x)return y;
    if(!y)return x;
    push_down(x);
    push_down(y);
    if(x->fix < y->fix)
    {
        x->r=merge(x->r,y);
        push_up(x);
        return x;
    }
    else
    {
        y->l=merge(x,y->l);
        push_up(y);
        return y;
    }
}

Droot split(Treap *n,int k)
{
    if(!n)return Droot{NULL,NULL};
    push_down(n);
    Droot t;
    if(get_size(n->l)>=k)
    {
        t=split(n->l,k);
        n->l=t.second;
        push_up(n);
        t.second=n;
    }
    else
    {
        t=split(n->r,k-get_size(n->l)-1);
        n->r=t.first;
        push_up(n);
        t.first=n;
    }
    return t;
}

int find_kth(Treap *&n,int k)
{
    Droot x=split(n,k-1);
    Droot y=split(x.second,1);
    Treap *t=y.first;
    n=merge(x.first,merge(y.first,y.second));
    return t->val;
}

int get_kth(Treap *n,int v)
{
    if(!n)return 0;
    push_down(n);
    if(v < n->val)return get_kth(n->l,v);
    return get_kth(n->r,v)+get_size(n->l)+1;
}

void insert(Treap *&n,int v)
{
    int k=get_kth(n,v);
    Droot x=split(n,k);
    n=merge(merge(x.first,new Treap(v)),x.second);
}

void modify(Treap *n,int v)
{
    if(!n)return;
    n->val+=v;
    n->lz+=v;
}

void traverse(Treap *n)
{
    if(!n)return;
    traverse(n->l);
    printf("%d ",n->val);
    traverse(n->r);
}

int main()
{
    srand(time(NULL));
    Treap *root=NULL;
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        if(i==1)root=new Treap(l);
        else
        {
            if(find_kth(root,root->siz)<r)
                root=merge(root,new Treap(r));
            Droot x=split(root,get_kth(root,l-1));
            Droot y=split(x.second,get_kth(x.second,r-1)+1);
            Droot z=split(y.first,y.first->siz-1);
            delete z.second;
            modify(z.first,1);
            z.first=merge(new Treap(l),z.first);
            root=merge(x.first,merge(z.first,y.second));
        }
    }
    return 0*printf("%d",root->siz);
}