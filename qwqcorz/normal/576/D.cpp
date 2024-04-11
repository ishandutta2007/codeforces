#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=155;
const int inf=(1<<30)-1;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

struct matrix
{
	int n,m;
	vector<bitset<N>>a;
	void send(int _n,int _m)
	{
		n=_n,m=_m;
		a.resize(n);
	}
	friend matrix operator *(matrix a,matrix b)
	{
		matrix ret;
		ret.send(a.n,b.m);
		for (int i=0;i<a.n;i++)
		for (int j=0;j<a.m;j++)
		if (a.a[i][j]) ret.a[i]|=b.a[j];
		return ret;
	}
}now,tr;
void power(matrix &ret,matrix a,int b)
{
	while (b)
	{
		if (b&1) ret=ret*a;
		a=a*a;
		b/=2;
	}
}
struct edge
{
	int u,v,w;
	bool operator <(const edge &a)const
	{
		return w<a.w;
	}
}e[N];
vector<int>g[N];
int dis[N];
int bfs(int n)
{
	queue<int>q;
	memset(dis,-1,sizeof(dis));
	for (int i=0;i<n;i++) if (now.a[0][i]) q.push(i),dis[i]=0;
	while (!q.empty())
	{
		int now=q.front(); q.pop();
		for (int to:g[now]) if (dis[to]<0) q.push(to),dis[to]=dis[now]+1;
	}
	return dis[n-1]<0?inf:dis[n-1];
}

signed main()
{
	int n=read(),m=read(),ans=inf;
	for (int i=1;i<=m;i++) e[i].u=read()-1,e[i].v=read()-1,e[i].w=read();
	sort(e+1,e+1+m);
	now.send(1,n);
	now.a[0].set(0);
	tr.send(n,n);
	for (int i=1,lst=0;i<=m;i++)
	{
		power(now,tr,e[i].w-lst);
		tr.a[e[i].u].set(e[i].v);
		g[e[i].u].push_back(e[i].v);
		ans=min(ans,e[i].w+bfs(n));
		lst=e[i].w;
	}
	if (ans<inf) print(ans);
			else puts("Impossible");
	
	return 0;
}