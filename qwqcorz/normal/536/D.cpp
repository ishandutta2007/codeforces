#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e3+5;
const int M=1e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

struct edge{int to,val;};
vector<edge>e[N];
int a[N],cnt=0;
ll b[N*2];
struct node
{
	int pos;
	ll val;
	bool operator <(const node &a)const
	{
		return val>a.val;
	}
};
bool vis[N];
ll dis1[N],dis2[N];
void dijkstra(int S,ll *dis)
{
	memset(vis,0,sizeof(vis));
	memset(dis,0x3f,sizeof(ll)*N);
	priority_queue<node>q;
	q.push((node){S,dis[S]=0});
	while (!q.empty())
	{
		int now=q.top().pos; q.pop();
		if (vis[now]) continue;
		vis[now]=1;
		for (edge i:e[now])
		{
			int to=i.to,val=i.val;
			if (dis[to]>dis[now]+val)
			{
				dis[to]=dis[now]+val;
				q.push((node){to,dis[to]});
			}
		}
	}
}
int siz[N*2][N*2];
ll sum[N*2][N*2],f[N*2][N*2],g[N*2][N*2];
int csiz(int x1,int x2,int y1,int y2)
{
	return siz[x2][y2]-siz[x1-1][y2]-siz[x2][y1-1]+siz[x1-1][y1-1];
}
ll csum(int x1,int x2,int y1,int y2)
{
	return sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1];
}

signed main()
{
	int n=read(),m=read(),s=read(),t=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read(),w=read();
		e[u].push_back((edge){v,w});
		e[v].push_back((edge){u,w});
	}
	dijkstra(s,dis1);
	dijkstra(t,dis2);
	for (int i=1;i<=n;i++) b[++cnt]=dis1[i];
	for (int i=1;i<=n;i++) b[++cnt]=dis2[i];
	sort(b+1,b+1+cnt);
	cnt=unique(b+1,b+1+cnt)-b-1;
	for (int i=1;i<=n;i++)
		dis1[i]=lower_bound(b+1,b+1+cnt,dis1[i])-b,
		dis2[i]=lower_bound(b+1,b+1+cnt,dis2[i])-b;
//	for (int i=1;i<=n;i++) print(dis1[i]," \n"[i==n]);
//	for (int i=1;i<=n;i++) print(dis2[i]," \n"[i==n]);
	for (int i=1;i<=n;i++)
		siz[dis1[i]][dis2[i]]++,
		sum[dis1[i]][dis2[i]]+=a[i];
	for (int i=1;i<=cnt;i++)
	for (int j=1;j<=cnt;j++)
		siz[i][j]+=siz[i][j-1],
		sum[i][j]+=sum[i][j-1];
	for (int i=1;i<=cnt;i++)
	for (int j=1;j<=cnt;j++)
		siz[i][j]+=siz[i-1][j],
		sum[i][j]+=sum[i-1][j];
	for (int i=cnt;i>=1;i--)
	for (int j=cnt;j>=1;j--)
	{
		if (csiz(i,i,j,cnt)) f[i][j]=max(f[i+1][j],g[i+1][j])+csum(i,i,j,cnt);
						else f[i][j]=f[i+1][j];
		if (csiz(i,cnt,j,j)) g[i][j]=min(f[i][j+1],g[i][j+1])-csum(i,cnt,j,j);
						else g[i][j]=g[i][j+1];
	}
//	for (int i=1;i<=cnt;i++)
//	for (int j=1;j<=cnt;j++)
//	print(f[i][j]," \n"[j==cnt]);
//	for (int i=1;i<=cnt;i++)
//	for (int j=1;j<=cnt;j++)
//	print(g[i][j]," \n"[j==cnt]);
	puts(f[1][1]>0?"Break a heart":(f[1][1]<0?"Cry":"Flowers"));
	
	return 0;
}