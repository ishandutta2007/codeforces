#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
#define N 100010
using namespace std;
ll n,v[N],c[N],l[N],r,mx=0;
map<ll,ll> dp,path,acp;
vector<ll> ans,vt[3*N];
void getdp(ll x)
{
	ll i,ss;
	dp.clear();
	path.clear();
	acp.clear();
	for(i=0;i<vt[x].size();i++)
	{
		dp[l[vt[x][i]]]=dp[l[vt[x][i]]+c[vt[x][i]]]=-LINF;
		path[l[vt[x][i]]]=path[l[vt[x][i]]+c[vt[x][i]]]=-1;
		acp[vt[x][i]]=-1;
	}
	dp[0]=0;
	for(ss=0;ss<vt[x].size();ss++)
	{
		i=vt[x][ss];
		if(l[i]==0)//the first truck
		{
			if(v[i]>dp[l[i]+c[i]]||path[l[i]+c[i]]==-1)
			{
				dp[l[i]+c[i]]=v[i];
				path[l[i]+c[i]]=i;
				acp[i]=-1;
			}
		}
		else//not the first truck
		{
			if(path[l[i]]==-1)//no truck before
			{
				continue;
			}
			if(dp[l[i]]+v[i]>dp[l[i]+c[i]]||path[l[i]+c[i]]==-1)
			{
				dp[l[i]+c[i]]=dp[l[i]]+v[i];
				path[l[i]+c[i]]=i;
				acp[i]=path[l[i]];
			}
		}
	}
	i=path[x];
	if(dp[x]>mx)
	{
		mx=dp[x];
		ans.clear();
		while(i!=-1)
		{
			ans.push_back(i);
			i=acp[i];
		}
	}
	return;
}
int main(){
	ll i,j,mx=0;
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld%lld%lld%lld",&v[i],&c[i],&l[i],&r);
		vt[c[i]+l[i]+r].push_back(i);
	}
	for(i=0;i<=300000;i++)
	{
		if(vt[i].empty())
		{
			continue;
		}
		getdp(i);
	}
	sort(ans.begin(),ans.end());
	printf("%lld\n",(ll)ans.size());
	for(i=0;i<ans.size();i++)
	{
		printf("%lld ",ans[i]+1);
	}
	puts("");
	return 0;
}