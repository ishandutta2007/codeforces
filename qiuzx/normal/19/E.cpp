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
#define N 10010
using namespace std;
ll n,m,val[N],par[N],dep[N],vis[N],led[N],odd_num=0,odd_cycle=0;
bool hoc;
vector<ll> ans;
vector<pair<ll,ll> > vt[N];
void dfs(ll x,ll lst,ll d,ll lsted)
{
	led[x]=lsted;
	par[x]=lst;
	vis[x]=1;
	dep[x]=d;
	ll i,j;
	for(i=0;i<vt[x].size();i++)
	{
		if(vt[x][i].F==lst)
		{
			continue;
		}
		if(vis[vt[x][i].F]==1)
		{
			if((dep[x]-dep[vt[x][i].F])%2==0)
			{
				odd_cycle++;
				for(j=x;j!=vt[x][i].F;j=par[j])
				{
					val[led[j]]++;
				}
				val[vt[x][i].S]++;
				hoc=true;
			}
			else
			{
				for(j=x;j!=vt[x][i].F;j=par[j])
				{
					val[led[j]]--;
				}
				val[vt[x][i].S]--;
			}
		}
		else if(vis[vt[x][i].F]==0)
		{
			dfs(vt[x][i].F,x,d+1,vt[x][i].S);
		}
	}
	vis[x]=2;
	return;
}
int main(){
	ll i,x,y;
	scanf("%lld%lld",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&x,&y);
		x--;
		y--;
		vt[x].push_back(make_pair(y,i));
		vt[y].push_back(make_pair(x,i));
	}
	for(i=0;i<n;i++)
	{
		if(!vis[i])
		{
			hoc=false;
			dfs(i,-1,0,-1);
			if(hoc)
			{
				odd_num++;
			}
		}
	}
	if(odd_num==0)
	{
		printf("%lld\n",m);
		for(i=0;i<m;i++)
		{
			printf("%lld ",i+1);
		}
		puts("");
		return 0;
	}
	else if(odd_num>1)
	{
		puts("0");
		return 0;
	}
	ans.clear();
	for(i=0;i<=m;i++)
	{
		if(val[i]==odd_cycle)
		{
			ans.push_back(i);
		}
	}
	printf("%lld\n",(ll)ans.size());
	for(i=0;i<ans.size();i++)
	{
		printf("%lld ",ans[i]+1);
	}
	puts("");
	return 0;
}