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
#define N 50010
using namespace std;
ll n,k,sz[N],mxsz[N],dist[510];
bool cent[N];
vector<ll> vt[N],path;
void dfs2(ll x,ll lst)
{
	path.push_back(x);
	sz[x]=1;
	mxsz[x]=0;
	ll i;
	for(i=0;i<vt[x].size();i++)
	{
		if(vt[x][i]!=lst&&(!cent[vt[x][i]]))
		{
			dfs2(vt[x][i],x);
			sz[x]+=sz[vt[x][i]];
			mxsz[x]=max(mxsz[x],sz[vt[x][i]]);
		}
	}
	return;
}
ll centroid(ll x)
{
	path.clear();
	dfs2(x,-1);
	ll i;
	for(i=0;i<path.size();i++)
	{
		if(max((ll)path.size()-sz[path[i]],mxsz[path[i]])*2<=path.size())
		{
			return path[i];
		}
	}
	return -1;
}
void gdist(ll x,ll lst,ll d)
{
	if(d>k)
	{
		return;
	}
	dist[d]++;
	ll i;
	for(i=0;i<vt[x].size();i++)
	{
		if(vt[x][i]!=lst&&(!cent[vt[x][i]]))
		{
			gdist(vt[x][i],x,d+1);
		}
	}
	return;
}
ll calc()
{
	ll i,ret=0;
	for(i=0;i+i<=k;i++)
	{
		if(i+i==k)
		{
			ret+=dist[i]*(dist[i]-1)/2;
		}
		else
		{
			ret+=dist[i]*dist[k-i];
		}
	}
	return ret;
}
ll dfs(ll x)
{
	ll nxt=centroid(x),i,j,ret;
	cent[nxt]=true;
	for(i=0;i<=k;i++)
	{
		dist[i]=0;
	}
	gdist(nxt,-1,0);
	ret=calc();
	for(i=0;i<vt[nxt].size();i++)
	{
		if(!cent[vt[nxt][i]])
		{
			ret+=dfs(vt[nxt][i]);
			for(j=0;j<=k;j++)
			{
				dist[j]=0;
			}
			gdist(vt[nxt][i],-1,1);
			ret-=calc();
		}
	}
	cent[nxt]=false;
	return ret;
}
int main(){
	ll i,x,y;
	scanf("%I64d%I64d",&n,&k);
	for(i=1;i<n;i++)
	{
		scanf("%I64d%I64d",&x,&y);
		x--;
		y--;
		vt[x].push_back(y);
		vt[y].push_back(x);
	}
	printf("%I64d\n",dfs(0));
	return 0;
}