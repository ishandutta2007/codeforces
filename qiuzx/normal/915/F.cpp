//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 1000010
using namespace std;
ll rint(){
	ll ret=0;
	char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) ret=ret*10+(c-'0'),c=getchar();
	return ret;
}
ll n,a[N],fa[N],ord[N],sz[N],ans=0;
vector<ll> vt[N];
bool vis[N];
bool cmp1(ll x,ll y)
{
	return (a[x]<a[y]);
}
bool cmp2(ll x,ll y)
{
	return (a[x]>a[y]);
}
ll getf(ll x)
{
	return (x==fa[x])?x:fa[x]=getf(fa[x]);
}
void merg(ll x,ll y)
{
	x=getf(x);
	y=getf(y);
	sz[x]+=sz[y];
	sz[y]=0;
	fa[y]=x;
	return;
}
int main(){
	ll i,j,x,y;
	n=rint();
	for(i=0;i<n;i++)
	{
		ord[i]=i;
		a[i]=rint();
	}
	for(i=1;i<n;i++)
	{
		x=rint()-1,y=rint()-1;
		vt[x].push_back(y);
		vt[y].push_back(x);
	}
	memset(vis,false,sizeof(vis));
	sort(ord,ord+n,cmp1);
	for(i=0;i<n;i++)
	{
		sz[i]=1;
		fa[i]=i;
	}
	for(i=0;i<n;i++)
	{
		x=ord[i];
		vis[x]=true;
		ans+=a[x];
		ll sum=0,sum2=0;
		for(j=0;j<vt[x].size();j++)
		{
			if(vis[vt[x][j]])
			{
				sum+=sz[getf(vt[x][j])];
				sum2+=sz[getf(vt[x][j])]*sz[getf(vt[x][j])];
			}
		}
		ans+=sum*a[x];
		ans+=((sum*sum-sum2)/2)*a[x];
		for(j=0;j<vt[x].size();j++)
		{
			if(vis[vt[x][j]])
			{
				merg(x,vt[x][j]);
			}
		}
	}
	memset(vis,false,sizeof(vis));
	sort(ord,ord+n,cmp2);
	for(i=0;i<n;i++)
	{
		sz[i]=1;
		fa[i]=i;
	}
	for(i=0;i<n;i++)
	{
		x=ord[i];
		vis[x]=true;
		ans-=a[x];
		ll sum=0,sum2=0;
		for(j=0;j<vt[x].size();j++)
		{
			if(vis[vt[x][j]])
			{
				sum+=sz[getf(vt[x][j])];
				sum2+=sz[getf(vt[x][j])]*sz[getf(vt[x][j])];
			}
		}
		ans-=sum*a[x];
		ans-=((sum*sum-sum2)/2)*a[x];
		for(j=0;j<vt[x].size();j++)
		{
			if(vis[vt[x][j]])
			{
				merg(x,vt[x][j]);
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}