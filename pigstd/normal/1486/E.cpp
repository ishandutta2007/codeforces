#include<bits/stdc++.h>
//#define int long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define WT int TT=read();while(TT--) 
#define NO puts("NO");
#define YES puts("YES");
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int inf=1e18;
const int M=5e5+10;
const int N=1e5+10;
int n,cnt,m,t[N][55],u[M],v[M],w[M];
struct Graph
{
	vector<pair<int,int> >e[M];int n,dis[M],vis[M];
	void add(int u,int v,int w){e[u].pb(mp(v,w));}
	struct node
	{
		int id,w;
		bool operator < (const node &b)const{return b.w<w;}
	};
	priority_queue<node> q;
	void dij(int s)
	{
		for (int i=1;i<=n;i++)dis[i]=inf;
		node a;a.id=s,a.w=0,dis[s]=0;q.push(a);
		while(!q.empty())
		{
			node k=q.top();q.pop();int u=k.id;
			if (vis[u])continue;
			vis[u]=1;
			for (int i=0;i<e[u].size();i++)
			{
				int to=e[u][i].x,ww=e[u][i].y;
				if (dis[to]>dis[u]+ww)
				{
					dis[to]=dis[u]+ww;
					if (!vis[to])
					{
						node p;p.id=to,p.w=dis[to];
						q.push(p);
					}
				}
			}
		}
	}
}G;

signed main()
{
	cnt=n=read(),m=read();
	for (int i=1;i<=m;i++)
	{
		u[i]=read(),v[i]=read(),w[i]=read();
		if (!t[u[i]][w[i]])t[u[i]][w[i]]=++cnt;
		if (!t[v[i]][w[i]])t[v[i]][w[i]]=++cnt;
		G.add(u[i],t[v[i]][w[i]],0),G.add(v[i],t[u[i]][w[i]],0);
	}
	for (int i=1;i<=m;i++)
		for (int j=1;j<=50;j++)
		{
			if (t[u[i]][j])
				G.add(t[u[i]][j],v[i],(j+w[i])*(j+w[i]));
			if (t[v[i]][j])
				G.add(t[v[i]][j],u[i],(j+w[i])*(j+w[i]));
		}G.n=cnt;
	G.dij(1);
	for (int i=1;i<=n;i++)
		if (G.dis[i]==inf)cout<<"-1 ";
		else cout<<G.dis[i]<<' ';
	return 0;
}