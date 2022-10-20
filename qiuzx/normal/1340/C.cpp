#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 1000007
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
#define N 10010
#define M 1010
using namespace std;
ll dist[N],n,m,d[N],g,r,ans=LINF;
bool vis[N][M];
vector<ll> hv;
void dfs(ll x,ll lft)
{
	if(vis[x][lft])
	{
		return;
	}
	vis[x][lft]=true;
	if(lft==0)
	{
		hv.push_back(x);
		return;
	}
	ll i;
	if(x+1<m)
	{
		if(lft-(d[x+1]-d[x])>=0)
		{
			if(!vis[x+1][lft-(d[x+1]-d[x])])
			{
				dfs(x+1,lft-(d[x+1]-d[x]));
			}
		}
	}
	if(x-1>=0)
	{
		if(lft-(d[x]-d[x-1])>=0)
		{
			if(!vis[x-1][lft-(d[x]-d[x-1])])
			{
				dfs(x-1,lft-(d[x]-d[x-1]));
			}
		}
	}
	return;
}
int main(){
	ll i,x;
	scanf("%lld%lld",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%lld",&d[i]);
	}
	scanf("%lld%lld",&g,&r);
	sort(d,d+m);
	memset(dist,127,sizeof(dist));
	queue<ll> q;
	dist[0]=0;
	q.push(0);
	vis[0][0]=true;
	while(!q.empty())
	{
		x=q.front();
		q.pop();
		hv.clear();
		dfs(x,g);
		for(i=0;i<hv.size();i++)
		{
			dist[hv[i]]=dist[x]+1;
			q.push(hv[i]);
		}
	}
	for(i=0;i<m;i++)
	{
		if(n-d[i]<=g)
		{
			if(dist[i]<LINF)
			{
				ans=min(ans,n-d[i]+dist[i]*(g+r));
			}
		}
	}
	if(ans<LINF)
	{
		printf("%lld\n",ans);
	}
	else
	{
		puts("-1");
	}
	return 0;
}