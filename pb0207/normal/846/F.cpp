/*
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

const int N=507;

int n,m,k,r[N][N],q,now[N][N],f[N][N];

bool check(int s)
{
	memset(f,0,sizeof(f));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			now[i][j]=max(r[i][j]-s,0);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(now[i][j]>0)
				f[i][j]=0;
			else
				f[i][j]=min(f[i][j-1],min(f[i-1][j],f[i-1][j-1]))+1;
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(f[i][j]>=k)
				return true;
	return false;
}

int main()
{
	cin>>n>>m>>k>>q;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			r[i][j]=1e9+7;
	for(int i=1;i<=q;i++)
	{
		int x,y,t;
		cin>>x>>y>>t;
		r[x][y]=t;
	}
	int l=-1,r=1e9+1;
	while(r-l>1)
	{
		int mid=(l+r)>>1;
		if(check(mid))
			r=mid;
		else
			l=mid;
	}
	if(!check(r))
		cout<<"-1";
	else
		cout<<r;
}
*/

#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;

typedef long long ll;

const int N=2e6+1e3+7;

ll a[N],fd[N];

ll ans,key[N*2],ret[N],tag[N*2],next[N],tot;

ll lt[N*2],rt[N*2],n;

int vis[N];

void update(int now)
{
	key[now]=key[now*2]+key[now*2+1];
}

void pushdown(int now)
{
	key[now*2+1]+=tag[now]*(rt[now*2+1]-lt[now*2+1]+1);
	key[now*2]+=tag[now]*(rt[now*2]-lt[now*2]+1);
	tag[now*2+1]+=tag[now];
	tag[now*2]+=tag[now];
	tag[now]=0;
}

void build(int now,int l,int r)
{
	lt[now]=l;rt[now]=r;
	if(l==r)
	{
		key[now]=ret[l];
		return;
	}
	int mid=(l+r)>>1;
	build(now*2,l,mid);
	build(now*2+1,mid+1,r);
	update(now);

}

ll query(int now,int l,int r,int L,int R)
{
	pushdown(now);
	if(L<=l&&r<=R)
		return key[now];
	int mid=l+r>>1;
	ll ret=0;
	if(L<=mid)
		ret+=query(now*2,l,mid,L,R);
	if(R>mid)
		ret+=query(now*2+1,mid+1,r,L,R);
	update(now);
	return ret;
}

void modify(int now,int l,int r,int L,int R)
{
	pushdown(now);
	if(L<=l&&r<=R)
	{
		tag[now]-=1;
		key[now]-=(ll)r-l+1;
		return;
	}
	int mid=l+r>>1;
	if(L<=mid)
		modify(now*2,l,mid,L,R);
	if(R>mid)
		modify(now*2+1,mid+1,r,L,R);
	update(now);
}


int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		scanf("%I64d",&a[i]);
	for(int i=n;i>=1;i--)
	{
		if(fd[a[i]])
			next[i]=fd[a[i]];
		fd[a[i]]=i;
	}
	for(int i=1;i<=n;i++)
		if(!next[i])
			next[i]=n+1;
	for(int i=1;i<=n;i++)
	{
		if(!vis[a[i]])
			tot++,vis[a[i]]=1;
		ret[i]=tot;
		ans+=tot;
	}
	tot=ans;
	for(ll i=1;i<n;i++)
	{
		tot--;
		tot-=next[i]-i-1;
		ans+=tot;
	}
	ans=ans-(ll)n;
	ans<<=1;
	ans+=(ll)n;
	double anss=ans;
	double nn=n;
	printf("%lf",anss/(nn*nn));
}