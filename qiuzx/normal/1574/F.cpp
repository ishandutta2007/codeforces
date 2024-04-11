//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 300010
using namespace std;
ll n,m,k,app[N],dp[N];
vector<ll> allsz,can_upd,vt[N],bk[N];
ll dfs(ll x)
{
	if(vt[x].size()>1||bk[x].size()>1)
	{
		return -1;
	}
	if(vt[x].size()==0)
	{
		return 1;
	}
	ll ret=dfs(vt[x][0]);
	if(ret==-1)
	{
		return -1;
	}
	return ret+1;
}
int main(){
	ll i,j,sz,x,lst;
	scanf("%lld%lld%lld",&n,&m,&k);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&sz);
		lst=-1;
		for(j=0;j<sz;j++)
		{
			scanf("%lld",&x);
			x--;
			if(lst!=-1)
			{
				vt[lst].push_back(x);
				bk[x].push_back(lst);
			}
			lst=x;
		}
	}
	for(i=0;i<k;i++)
	{
		sort(vt[i].begin(),vt[i].end());
		vt[i].erase(unique(vt[i].begin(),vt[i].end()),vt[i].end());
		sort(bk[i].begin(),bk[i].end());
		bk[i].erase(unique(bk[i].begin(),bk[i].end()),bk[i].end());
	}
	for(i=0;i<k;i++)
	{
		if(bk[i].size()==0)
		{
			sz=dfs(i);
			if(sz!=-1)
			{
				app[sz]++;
			}
		}
	}
	for(i=0;i<=k;i++)
	{
		if(app[i]>0)
		{
			can_upd.push_back(i);
		}
	}
	assert(can_upd.size()<800);
	dp[0]=1;
	for(i=0;i<m;i++)
	{
		for(j=0;j<can_upd.size();j++)
		{
			if(i+can_upd[j]<=m)
			{
				dp[i+can_upd[j]]=(dp[i+can_upd[j]]+dp[i]*app[can_upd[j]])%mod;
			}
		}
	}
	printf("%lld\n",dp[m]);
	return 0;
}