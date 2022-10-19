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
ll n,k,ans[N],deg[N],res;
vector<ll> vt[N],ed[N],alldeg;
void dfs(ll x,ll lst,ll lstcol)
{
	ll i,cnt=0;
	if(deg[x]>res)
	{
		for(i=0;i<vt[x].size();i++)
		{
			if(vt[x][i]!=lst)
			{
				ans[ed[x][i]]=1;
				dfs(vt[x][i],x,1);
			}
		}
		return;
	}
	for(i=0;i<vt[x].size();i++)
	{
		if(vt[x][i]!=lst)
		{
			cnt++;
			if(cnt==lstcol)
			{
				cnt++;
			}
			ans[ed[x][i]]=cnt;
			dfs(vt[x][i],x,cnt);
		}
	}
	return;
}
int main(){
	ll i,x,y;
	scanf("%lld%lld",&n,&k);
	for(i=1;i<n;i++)
	{
		scanf("%lld%lld",&x,&y);
		x--;
		y--;
		deg[x]++;
		deg[y]++;
		vt[x].push_back(y);
		ed[x].push_back(i);
		vt[y].push_back(x);
		ed[y].push_back(i);
	}
	for(i=0;i<n;i++)
	{
		alldeg.push_back(deg[i]);
	}
	sort(alldeg.begin(),alldeg.end());
	reverse(alldeg.begin(),alldeg.end());
	res=alldeg[k];
	printf("%lld\n",res);
	dfs(0,-1,-1);
	for(i=1;i<n;i++)
	{
		printf("%lld ",ans[i]);
	}
	puts("");
	return 0;
}