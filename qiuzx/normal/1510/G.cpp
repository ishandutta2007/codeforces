#pragma GCC optimize(2)
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
#define N 110
using namespace std;
ll n,k,par[N],mxcha[N],nxt[N],lft,lft2;
bool pres[N];
vector<ll> ans,vt[N];
void dfs(ll x)
{
	ll i;
	mxcha[x]=0;
	nxt[x]=-1;
	for(i=0;i<vt[x].size();i++)
	{
		dfs(vt[x][i]);
		if(mxcha[x]<mxcha[vt[x][i]]+1)
		{
			mxcha[x]=mxcha[vt[x][i]]+1;
			nxt[x]=vt[x][i];
		}
	}
	return;
}
void dfs2(ll x)
{
	ans.push_back(x);
	ll i;
	for(i=0;i<vt[x].size();i++)
	{
		if(!pres[vt[x][i]])
		{
			if(lft!=0)
			{
				lft--;
				dfs2(vt[x][i]);
				ans.push_back(x);
			}
		}
	}
	if(nxt[x]!=-1&&pres[nxt[x]]&&lft2!=0)
	{
		lft2--;
		dfs2(nxt[x]);
	}
	return;
}
int main(){
	ll i,j,T;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld%lld",&n,&k);
		for(i=0;i<n;i++)
		{
			pres[i]=false;
			vt[i].clear();
		}
		for(i=1;i<n;i++)
		{
			scanf("%lld",&par[i]);
			par[i]--;
			vt[par[i]].push_back(i);
		}
		dfs(0);
		i=0;
		while(i!=-1)
		{
			pres[i]=true;
			i=nxt[i];
		}
		ans.clear();
		printf("%lld\n",2*(k-1)-min(k-1,mxcha[0]));
		lft=k-min(k-1,mxcha[0])-1;
		lft2=min(k,mxcha[0]+1)-1;
		dfs2(0);
		for(i=0;i<ans.size();i++)
		{
			printf("%lld ",ans[i]+1);
		}
		puts("");
	}
	return 0;
}