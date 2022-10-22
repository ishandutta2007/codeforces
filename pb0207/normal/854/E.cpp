#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N=2e5+1e3+7;

typedef long long ll;

int n,m,tot,root[N];

ll p,ans;

struct node{
    int ls,rs;
	ll sum;
}t[N*30];

void insert(int x,int &y,int l,int r,int v)
{
	y=++tot;
    t[y]=t[x];
    t[y].sum++;
    if(l==r) 
		return;
    int mid=(l+r)>>1;
    if(v<=mid) 
		insert(t[x].ls,t[y].ls,l,mid,v);
    else 
		insert(t[x].rs,t[y].rs,mid+1,r,v);
}

ll query(int l,int r,int x,int y,int L,int R)
{
    if(L>R||l>r||L>r||R<l) 
		return 0;
    if(l>=L&&r<=R) 
		return t[y].sum-t[x].sum;
    int mid=(l+r)>>1;
    return query(l,mid,t[x].ls,t[y].ls,L,R)+query(mid+1,r,t[x].rs,t[y].rs,L,R);
}

ll cal(ll x)
{
	return x*(x-1)/2;
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) 
	{
        int x;
        scanf("%d",&x);
        insert(root[i-1],root[i],1,n,x);
    }
    while(m--) 
	{
        int l,r,u,v;
        scanf("%d%d%d%d",&l,&r,&u,&v);
        ans=(ll)n*(ll)(n-1)/2;
        p=query(1,n,root[0],root[n],1,r-1);
        ans-=cal(p);
        p=query(1,n,root[0],root[n],v+1,n);
        ans-=cal(p);
        p=query(1,n,root[0],root[l-1],1,n);
        ans-=cal(p);
        p=query(1,n,root[u],root[n],1,n);
        ans-=cal(p);
        p=query(1,n,root[0],root[l-1],1,r-1);
        ans+=cal(p);
        p=query(1,n,root[0],root[l-1],v+1,n);
        ans+=cal(p);
        p=query(1,n,root[u],root[n],1,r-1);
        ans+=cal(p);
        p=query(1,n,root[u],root[n],v+1,n);
        ans+=cal(p);
        printf("%I64d\n",ans);
    }
}