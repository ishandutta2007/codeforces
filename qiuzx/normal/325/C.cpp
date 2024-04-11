//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#include <bits/stdc++.h>
#define INF 314000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 200010
using namespace std;
ll rint(){
	ll ret=0,uu=1;
	char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-') uu=-1,c=getchar();
	while(isdigit(c)) ret=ret*10+(c-'0'),c=getchar();
	return ret*uu;
}
void rout(ll x){
	if(x<0) putchar('-'),rout(-x);
	else if(x<10) putchar(x+48);
	else rout(x/10),putchar((x%10)+48);
	return;
}
ll n,m,deg[N],orideg[N],dist[N],dep[N];
bool canend[N],cancyc[N],vis[N];
vector<pair<ll,ll> > vt[N],bk[N];
vector<ll> rbk[N];
void bfs0()
{
	ll i,j,x,y;
	queue<ll> q;
	memset(canend,false,sizeof(canend));
	canend[m+n]=true;
	vis[m+n]=true;
	q.push(m+n);
	while(!q.empty())
	{
		x=q.front();
		q.pop();
		for(i=0;i<bk[x].size();i++)
		{
			y=bk[x][i].F;
			deg[y]--;
			if(y<n)
			{
				canend[y]=true;
			}
			else if(deg[y]==0)
			{
				canend[y]=true;
			}
			if((deg[y]==0||y<n)&&canend[y]&&(!vis[y]))
			{
				vis[y]=true;
				q.push(y);
			}
		}
	}
	return;
}
void dijkstra()
{
	ll i,j,x,y;
	for(i=0;i<n;i++)
	{
		dist[i]=INF+1;
	}
	priority_queue<pair<ll,ll> > pq;
	for(i=n;i<=n+m;i++)
	{
		deg[i]=0;
		for(j=0;j<vt[i].size();j++)
		{
			if(canend[vt[i][j].F])
			{
				deg[i]++;
			}
		}
		dist[i]=0;
	}
	pq.push(make_pair(0,n+m));
	while(!pq.empty())
	{
		y=-pq.top().F,x=pq.top().S;
		pq.pop();
		if(dist[x]!=y)
		{
			continue;
		}
		for(i=0;i<bk[x].size();i++)
		{
			if(!canend[bk[x][i].F])
			{
				continue;
			}
			if(bk[x][i].F>=n)
			{
				dist[bk[x][i].F]+=y+bk[x][i].S;
				dist[bk[x][i].F]=min(dist[bk[x][i].F],(ll)INF);
				deg[bk[x][i].F]--;
				if(deg[bk[x][i].F]==0)
				{
					pq.push(make_pair(-dist[bk[x][i].F],bk[x][i].F));
				}
			}
			else
			{
				if(dist[bk[x][i].F]>min((ll)INF,y+bk[x][i].S))
				{
					dist[bk[x][i].F]=min((ll)INF,y+bk[x][i].S);
					pq.push(make_pair(-dist[bk[x][i].F],bk[x][i].F));
				}
			}
		}
	}
	return;
}
ll dfs(ll x)
{
	if(dep[x]<=INF)
	{
		return dep[x];
	}
	vis[x]=true;
	dep[x]=0;
	ll i,j,v;
	for(i=0;i<vt[x].size();i++)
	{
		v=vt[x][i].S;
		if(!canend[vt[x][i].F])
		{
			continue;
		}
		for(j=0;j<vt[vt[x][i].F].size();j++)
		{
			if(!canend[vt[vt[x][i].F][j].F])
			{
				v=0;
				break;
			}
			if(vis[vt[vt[x][i].F][j].F])
			{
				cancyc[x]=true;
				break;
			}
			v+=dfs(vt[vt[x][i].F][j].F);
			if(cancyc[vt[vt[x][i].F][j].F])
			{
				cancyc[x]=true;
				break;
			}
		}
		dep[x]=max(dep[x],v);
	}
	vis[x]=false;
	return dep[x]=min(dep[x],(ll)INF);
}
int main(){
	ll i,j,l,x,y;
	m=rint(),n=rint();
	for(i=0;i<m;i++)
	{
		x=rint()-1,l=rint();
		ll v=0;
		for(j=0;j<l;j++)
		{
			y=rint();
			if(y==-1)
			{
				v++;
			}
			else
			{
				deg[i+n]++;
				vt[i+n].push_back(make_pair(y-1,0));
				bk[y-1].push_back(make_pair(i+n,0));
			}
		}
		deg[x]++;
		vt[x].push_back(make_pair(i+n,v));
		bk[i+n].push_back(make_pair(x,v));
		if(vt[i+n].size()==0)
		{
			deg[i+n]++;
			vt[i+n].push_back(make_pair(m+n,0));
			bk[m+n].push_back(make_pair(i+n,0));
		}
	}
	for(i=0;i<=n+m;i++)
	{
		orideg[i]=deg[i];
	}
	bfs0();
	dijkstra();
	for(i=0;i<=n+m;i++)
	{
		dep[i]=INF+1;
	}
	memset(vis,false,sizeof(vis));
	for(i=0;i<n;i++)
	{
		dfs(i);
	}
	for(i=0;i<n;i++)
	{
		if(!canend[i])
		{
			puts("-1 -1");
		}
		else
		{
			rout(dist[i]),putchar(' ');
			rout(cancyc[i]?-2:dep[i]),putchar('\n');
		}
	}
	return 0;
}