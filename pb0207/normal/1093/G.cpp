#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;

const int N=2e5+1e3+7,K=6;

int n,k,q,all;

ll a[N][K];

int cnt;

struct T{
	int l,r,ls,rs;
	ll val[1<<K];
}t[N*2+1];

void update(int x)
{
	for(int S=0;S<=all;S++)
		t[x].val[S]=max(t[t[x].ls].val[S],t[t[x].rs].val[S]);
}

int build(int l,int r)
{
	int x=++cnt;
	t[x].l=l,t[x].r=r;
	if(l==r)
	{
		for(int S=0;S<=all;S++)
			for(int j=1;j<=k;j++)
				if(S&(1<<(j-1)))
					t[x].val[S]-=a[l][j];
				else
					t[x].val[S]+=a[l][j];
		return x;
	} 
	int mid=(l+r)>>1;
	t[x].ls=build(l,mid);
	t[x].rs=build(mid+1,r);
	update(x);
	return x;
}

void change(int x,int p,ll *v)
{
	if(t[x].l==t[x].r)
	{
		for(int S=0;S<=all;S++)
		{
			t[x].val[S]=0;
			for(int j=1;j<=k;j++)
				if(S&(1<<(j-1)))
					t[x].val[S]-=v[j];
				else
					t[x].val[S]+=v[j];
		}
		return;
	}
	int mid=(t[x].l+t[x].r)>>1;
	if(p<=mid)
		change(t[x].ls,p,v);
	else
		change(t[x].rs,p,v);
	update(x); 
}

ll mx[1<<K],v[K];

void query(int x,int l,int r)
{
	if(l<=t[x].l&&t[x].r<=r)
	{
		for(int S=0;S<=all;S++)
			mx[S]=max(mx[S],t[x].val[S]);
		return;
	}
	int mid=(t[x].l+t[x].r)>>1;
	if(l<=mid)
		query(t[x].ls,l,r);
	if(r>mid)
		query(t[x].rs,l,r);
}

int main()
{
	scanf("%d%d",&n,&k);
	all=(1<<k)-1; 
	for(int i=1;i<=n;i++)
		for(int j=1;j<=k;j++)
			scanf("%lld",&a[i][j]);
	build(1,n);
	scanf("%d",&q);
	while(q--)
	{
		int op;
		scanf("%d",&op);
		if(op==1)
		{
			int x;
			scanf("%d",&x);
			for(int i=1;i<=k;i++)
				scanf("%lld",&v[i]);
			change(1,x,v);
		}
		else
		{
			int l,r;
			scanf("%d%d",&l,&r);
			for(int S=0;S<=all;S++)
				mx[S]=-1e12;
			query(1,l,r);
			ll ans=-1e12;
			for(int S=0;S<=all;S++)
				ans=max(ans,mx[S]+mx[all^S]);
			printf("%d\n",ans);
		}
	}
}