#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

vector<int>e[N];
int c[N],u[N],v[N],h[N],ans[N];
void bfs0(int n)
{
	queue<int>q;
	memset(h,-1,sizeof(h));
	for (int i=1;i<=n;i++) if (c[i]) q.push(i),h[i]=0;
	while (!q.empty())
	{
		int now=q.front(); q.pop();
		for (int to:e[now]) if (h[to]<0) q.push(to),h[to]=h[now]+1;
	}
}
int dis[N];
bool vis[N],is[N];
deque<int>q[N];
void bfs1(int n,int k)
{
	memset(is,0,sizeof(is));
	memset(dis,0x3f,sizeof(dis));
	for (int i=1;i<n;i++) if (h[u[i]]==h[v[i]]&&h[u[i]]==k) is[u[i]]=is[v[i]]=1;
	for (int i=1;i<=n;i++) if (is[i]) q[h[i]].push_back(i),dis[i]=0;
	for (int i=0;i<=n;i++)
	while (!q[i].empty())
	{
		int now=q[i].front(); q[i].pop_front();
		for (int to:e[now])
		if (h[to]>h[now]){
			if (dis[to]>dis[now]-1) q[h[to]].push_front(to),dis[to]=dis[now]-1;
		}
		else if (h[to]==h[now]){
			if (dis[to]>max(dis[now]+1,1)) q[h[to]].push_back(to),dis[to]=max(dis[now]+1,1);
		}
	}
	for (int i=1;i<=n;i++) if (dis[i]<=0) ans[i]=max(ans[i],h[i]*2-k);
}

signed main()
{
	int n=read();
	for (int i=1;i<=n;i++) c[i]=read();
	for (int i=1;i<n;i++)
	{
		u[i]=read(),v[i]=read();
		e[u[i]].push_back(v[i]);
		e[v[i]].push_back(u[i]);
	}
	bfs0(n);
	for (int i=1;i<=n;i++) ans[i]=h[i];
	for (int i=1;i<n;i++) if (h[u[i]]==h[v[i]]) vis[h[u[i]]]=1;
	for (int i=0;i<=n;i++) if (vis[i]) bfs1(n,i);
	for (int i=1;i<=n;i++) print(ans[i]," \n"[i==n]);
	
	return 0;
}