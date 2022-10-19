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
#define N 200010
using namespace std;
ll n,a[N],mxv[N],mx=0,ans=0,cur;
vector<ll> vt[N];
multiset<ll> mst[N];
void predfs(ll x,ll lst)
{
	ll i;
	mxv[x]=0;
	for(i=0;i<vt[x].size();i++)
	{
		if(vt[x][i]!=lst)
		{
			predfs(vt[x][i],x);
			mst[x].insert(-mxv[vt[x][i]]);
			mxv[x]=max(mxv[x],mxv[vt[x][i]]);
		}
	}
	ans+=max((ll)0,a[x]-mxv[x]);
	mxv[x]=max(mxv[x],a[x]);
	return;
}
void trs(ll x,ll y)
{
	ll i;
	if(!mst[x].empty())
	{
		cur-=max((ll)0,a[x]+(*mst[x].begin()));
	}
	else
	{
		cur-=a[x];
	}
	if(!mst[y].empty())
	{
		cur-=max((ll)0,a[y]+(*mst[y].begin()));
	}
	else
	{
		cur-=a[y];
	}
	mst[x].erase(mst[x].lower_bound(-mxv[y]));
	if(!mst[x].empty())
	{
		cur+=max((ll)0,a[x]+(*mst[x].begin()));
	}
	else
	{
		cur+=a[x];
	}
	if(mst[x].empty())
	{
		mxv[x]=a[x];
	}
	else
	{
		mxv[x]=max(-(*mst[x].begin()),a[x]);
	}
	mst[y].insert(-mxv[x]);
	cur+=max((ll)0,a[y]+(*mst[y].begin()));
	mxv[y]=max(-(*mst[y].begin()),a[y]);
	return;
}
void dfs(ll x,ll lst)
{
	ans=min(ans,cur);
	ll i;
	for(i=0;i<vt[x].size();i++)
	{
		if(vt[x][i]!=lst)
		{
			trs(x,vt[x][i]);
			dfs(vt[x][i],x);
			trs(vt[x][i],x);
		}
	}
	return;
}
int main(){
	ll i,x,y;
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
		mx=max(mx,a[i]);
	}
	for(i=1;i<n;i++)
	{
		scanf("%lld%lld",&x,&y);
		x--,y--;
		vt[x].push_back(y);
		vt[y].push_back(x);
	}
	predfs(0,-1);
	cur=ans;
	dfs(0,-1);
	printf("%lld\n",ans+mx);
	return 0;
}