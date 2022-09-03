// This amazing code is by Eric Sunli Chen.
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;
template<typename T> void get_int(T &x)
{
	char t=getchar();
	bool neg=false;
	x=0;
	for(; (t>'9'||t<'0')&&t!='-'; t=getchar());
	if(t=='-')neg=true,t=getchar();
	for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
	if(neg)x=-x;
}
template<typename T> void print_int(T x)
{
	if(x<0)putchar('-'),x=-x;
	short a[20]= {},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1; i>=0; i--)putchar('0'+a[i]);
}
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define get1(a) get_int(a)
#define get2(a,b) get1(a),get1(b)
#define get3(a,b,c) get1(a),get2(b,c)
#define printendl(a) print_int(a),puts("")
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

struct max_flow
{
	struct edge
	{
		int to,cap,rev;
		edge(int to,int cap,int rev)
		{
			this->to=to;
			this->cap=cap;
			this->rev=rev;
		}
	};
	vector<edge> g[233];
	void addedge(int from,int to,int cap)
	{
		g[from].pb(edge(to,cap,(int)g[to].size()));
		g[to].pb(edge(from,cap,(int)g[from].size()-1));
	}
	int q[233],front,rear,level[233],iter[233];
	void bfs(int s)
	{
		front=rear=0;
		q[rear++]=s;
		memset(level,-1,sizeof(level));
		level[s]=0;
		while(front!=rear)
		{
			int x=q[front++];
			for(int i=0;i<(int)g[x].size();i++)
			{
				edge &e=g[x][i];
				if(e.cap>0&&level[e.to]==-1)
				{
					q[rear++]=e.to;
					level[e.to]=level[x]+1;
				}
			}
		}
	}
	int dfs(int x,int t,int f)
	{
		if(x==t)return f;
		for(int &i=iter[x];i<(int)g[x].size();i++)
		{
			edge &e=g[x][i];
			if(e.cap>0&&level[e.to]==level[x]+1)
			{
				int d=dfs(e.to,t,min(f,e.cap));
				if(d>0)
				{
					e.cap-=d;
					g[e.to][e.rev].cap+=d;
					return d;
				}
			}
		}
		return 0;
	}
	int maxflow(int s,int t)
	{
		int f,flow=0;
		for(;;)
		{
			bfs(s);
			if(level[t]==-1)return flow;
			memset(iter,0,sizeof(iter));
			while(f=dfs(s,t,inf))flow+=f;
		}
	}
}m1,m2;

int n,m,ans;
vector<pair<int,pii> > e;

void solve(vector<int> &v)
{
	if((int)v.size()<2)return;
	m2=m1;int s=v[0],t=v[1],flow=m2.maxflow(s,t);
//	printf("Edge %d %d %d\n",s,t,flow);
	e.pb(mp(flow,mp(s,t)));ans+=flow;
	vector<int>a,b;
	for(int i=0;i<(int)v.size();i++)if(m2.level[v[i]]!=-1)a.pb(v[i]);else b.pb(v[i]);
	solve(a);solve(b);
}
int f[233];int gf(int x){return x==f[x]?x:f[x]=gf(f[x]);}
void solve2(vector<int> &v,vector<pair<int,pii> >&e)
{
	if(v.size()==1)
	{
		printf("%d ",v[0]);
		return;
	}
	int id=min_element(e.begin(),e.end())-e.begin();
	for(int i=0;i<(int)v.size();i++)f[v[i]]=v[i];
	int tx=e[id].ss.ff,ty=e[id].ss.ss;
	for(int i=0;i<(int)e.size();i++)
	{
		if(i==id)continue;
		f[gf(e[i].ss.ff)]=gf(e[i].ss.ss);
	}
	vector<int>a,b;
	vector<pair<int,pii> >ea,eb;
	for(int i=0;i<(int)v.size();i++)
	{
		if(gf(v[i])==gf(tx))a.pb(v[i]);
		else b.pb(v[i]);
	}
	for(int i=0;i<(int)e.size();i++)
	{
		if(i==id)continue;
		if(gf(e[i].ss.ff)==gf(tx))ea.pb(e[i]);
		else eb.pb(e[i]);
	}
	solve2(a,ea);solve2(b,eb);
}
int main()
{
	get2(n,m);
	for(int i=1,u,v,c;i<=m;i++)
	{
		get3(u,v,c);
		m1.addedge(u,v,c);
	}
	vector<int> v;
	for(int i=1;i<=n;i++)v.pb(i);
	solve(v);
	printf("%d\n",ans);
	solve2(v,e);
	return 0;
}