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
#define N 200010
using namespace std;
ll n,ans;
vector<ll> vt[N];
ll dfs(ll x,ll lst)
{
	ll i,val=0;
	for(i=0;i<vt[x].size();i++)
	{
		if(vt[x][i]==lst)
		{
			continue;
		}
		val+=dfs(vt[x][i],x);
	}
	if(val==0)
	{
		return 1;
	}
	ans+=val-1;
	return 0;
}
int main(){
	ll T,i,x,y;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld",&n);
		for(i=0;i<n;i++)
		{
			vt[i].clear();
		}
		for(i=1;i<n;i++)
		{
			scanf("%lld%lld",&x,&y);
			x--;
			y--;
			vt[x].push_back(y);
			vt[y].push_back(x);
		}
		ans=0;
		dfs(0,-1);
		printf("%lld\n",ans+1);
	}
	return 0;
}