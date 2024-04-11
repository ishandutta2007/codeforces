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
    int val[3],lz[2],fix,siz;
    Treap *l,*r;
    Treap(int _num,int _cnt,int _id)
    {
        val[0]=_num,val[1]=_cnt,val[2]=_id;
        lz[0]=lz[1]=0;
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
    if(n->l)for(int i=0;i<2;i++)
    {
        n->l->val[i]+=n->lz[i];
        n->l->lz[i]+=n->lz[i];
    }
    if(n->r)for(int i=0;i<2;i++)
    {
        n->r->val[i]+=n->lz[i];
        n->r->lz[i]+=n->lz[i];
    }
    n->lz[0]=n->lz[1]=0;
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

int get_kth(Treap *n,int v)
{
    if(!n)return 0;
    push_down(n);
    if(v < n->val[0])return get_kth(n->l,v);
    else return get_kth(n->r,v)+get_size(n->l)+1;
}

void insert(Treap *&n,int v,int c,int id)
{
    int k=get_kth(n,v);
    Droot x=split(n,k);
    Treap *t=new Treap(v,c,id);
    n=merge(merge(x.first,t),x.second);
}

void modify(Treap *n,int cut)
{
    if(!n)return;
    n->val[0]-=cut;
    n->lz[0]-=cut;
    n->val[1]+=1;
    n->lz[1]+=1;
}

void clear(Treap *n,Treap *&t,int cut)
{
    if(!n)return;
    push_down(n);
    insert(t,n->val[0]-cut,n->val[1]+1,n->val[2]);
    clear(n->l,t,cut);
    clear(n->r,t,cut);
    delete n;
}

const int MAXN=200005;

int c[MAXN],q[MAXN],id[MAXN],res[MAXN];

void traverse(Treap *n)
{
    if(!n)return;
    push_down(n);
    res[n->val[2]]=n->val[1];
    traverse(n->l);
    traverse(n->r);
    delete n;
}

int main()
{
    srand(time(NULL));
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&c[i],&q[i]),id[i]=i;
    sort(id+1,id+n+1,[](int x,int y)
    {
        return q[x]==q[y] ? c[x]<c[y] : q[x]>q[y];
    });
    Treap *root=NULL;
    int k;
    scanf("%d",&k);
    for(int i=1;i<=k;i++)
    {
        int b;
        scanf("%d",&b);
        insert(root,b,0,i);
    }
    for(int ii=1;ii<=n;ii++)
    {
        int i=id[ii];
        Droot x=split(root,get_kth(root,c[i]-1));//[0,c),[c,2c),[2c,inf)
        Droot y=split(x.second,get_kth(x.second,2*c[i]-1));
        modify(y.second,c[i]);
        clear(y.first,x.first,c[i]);
        root=merge(x.first,y.second);
    }
    traverse(root);
    for(int i=1;i<=k;i++)
        printf("%d ",res[i]);
    return 0;
}