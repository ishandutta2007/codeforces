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
#define N 100010
using namespace std;
ll rint(){
	ll ret=0;
	char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) ret=ret*10+(c-'0'),c=getchar();
	return ret;
}
void rout(ll x){
	if(x<10) putchar(x+48);
	else rout(x/10),putchar((x%10)+48);
	return;
}
ll n,m,wei[N],dist[N],dep[N],f[N][20],sld[24][2][2],mndist[24][24][2][2],dp[24][2][2];
bool vis[N];
vector<pair<ll,pair<ll,ll> > > baded;
vector<pair<ll,ll> > vt[N];
void dfs(ll x,ll lst,ll d,ll d2)
{
	ll i;
	dep[x]=d;
	dist[x]=d2;
	for(i=1;i<18;++i)
	{
		f[x][i]=f[f[x][i-1]][i-1];
	}
	vis[x]=true;
	for(i=0;i<vt[x].size();++i)
	{
		if(vt[x][i].F!=lst)
		{
			if(vis[vt[x][i].F])
			{
				if(dep[vt[x][i].F]<dep[x])
				{
					baded.push_back(make_pair(wei[vt[x][i].S],make_pair(x,vt[x][i].F)));
				}
				continue;
			}
			f[vt[x][i].F][0]=x;
			dfs(vt[x][i].F,x,d+1,d2+wei[vt[x][i].S]);
		}
	}
	return;
}
ll glca(ll x,ll y)
{
	if(dep[x]<dep[y])
	{
		swap(x,y);
	}
	ll i;
	for(i=17;i>=0;--i)
	{
		if(dep[f[x][i]]>=dep[y])
		{
			x=f[x][i];
		}
	}
	if(x==y)
	{
		return x;
	}
	for(i=17;i>=0;--i)
	{
		if(f[x][i]!=f[y][i])
		{
			x=f[x][i];
			y=f[y][i];
		}
	}
	return f[x][0];
}
ll getdist(ll x,ll y)
{
	return dist[x]+dist[y]-2*dist[glca(x,y)];
}
void getdp(ll id)
{
	ll i,j,k;
	memset(dp,63,sizeof(dp));
	priority_queue<pair<ll,pair<ll,pair<ll,ll> > > > pq;
	dp[id][0][0]=dp[id][1][1]=0;
	pq.push(make_pair(0,make_pair(id,make_pair(0,0))));
	pq.push(make_pair(0,make_pair(id,make_pair(1,1))));
	while(!pq.empty())
	{
		ll v=-pq.top().F,x=pq.top().S.F,c1=pq.top().S.S.F,c2=pq.top().S.S.S;
		pq.pop();
		if(v!=dp[x][c1][c2])
		{
			continue;
		}
		if(dp[x][c1][c2^1]>v+baded[x].F)
		{
			dp[x][c1][c2^1]=v+baded[x].F;
			pq.push(make_pair(-dp[x][c1][c2^1],make_pair(x,make_pair(c1,c2^1))));
		}
		for(i=0;i<baded.size();++i)
		{
			ll nv=v+getdist(c2?baded[x].S.S:baded[x].S.F,baded[i].S.F);
			if(dp[i][c1][0]>nv)
			{
				dp[i][c1][0]=nv;
				pq.push(make_pair(-nv,make_pair(i,make_pair(c1,0))));
			}
			nv=v+getdist(c2?baded[x].S.S:baded[x].S.F,baded[i].S.S);
			if(dp[i][c1][1]>nv)
			{
				dp[i][c1][1]=nv;
				pq.push(make_pair(-nv,make_pair(i,make_pair(c1,1))));
			}
		}
	}
	for(i=0;i<baded.size();++i)
	{
		mndist[id][i][0][0]=dp[i][0][0];
		mndist[id][i][0][1]=dp[i][0][1];
		mndist[id][i][1][0]=dp[i][1][0];
		mndist[id][i][1][1]=dp[i][1][1];
	}
	return;
}
int main(){
	ll i,j,x,y;
	n=rint(),m=rint();
	for(i=0;i<m;++i)
	{
		x=rint()-1,y=rint()-1,wei[i]=rint();
		vt[x].push_back(make_pair(y,i));
		vt[y].push_back(make_pair(x,i));
	}
	ll q=rint();
	dfs(0,-1,0,0);
	for(i=0;i<baded.size();++i)
	{
		getdp(i);
	}
	while(q--)
	{
		x=rint()-1,y=rint()-1;
		ll ans=getdist(x,y);
		for(i=0;i<baded.size();++i)
		{
			sld[i][0][0]=getdist(x,baded[i].S.F),sld[i][0][1]=getdist(x,baded[i].S.S);
			sld[i][1][0]=getdist(y,baded[i].S.F),sld[i][1][1]=getdist(y,baded[i].S.S);
		}
		for(i=0;i<baded.size();++i)
		{
			for(j=0;j<baded.size();++j)
			{
				ans=min(ans,sld[i][0][0]+mndist[i][j][0][0]+sld[j][1][0]);
				ans=min(ans,sld[i][0][0]+mndist[i][j][0][1]+sld[j][1][1]);
				ans=min(ans,sld[i][0][1]+mndist[i][j][1][0]+sld[j][1][0]);
				ans=min(ans,sld[i][0][1]+mndist[i][j][1][1]+sld[j][1][1]);
			}
		}
		rout(ans),putchar('\n');
	}
	return 0;
}