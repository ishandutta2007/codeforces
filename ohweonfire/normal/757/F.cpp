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

const int maxn=200111;
int n,f[maxn][22],m,s,sz[maxn],dep[maxn];
bool use[maxn];
vector<int> g[maxn],rg[maxn],l[maxn],v,tree[maxn];
LL dist[maxn];

priority_queue<pair<LL,int>,vector<pair<LL,int> >,greater<pair<LL,int> > >q;
void dijkstra()
{
	memset(dist,-1,sizeof(dist));
	dist[s]=0;
	q.push(mp(0,s));
	while(!q.empty())
	{
		int x=q.top().ss;LL d=q.top().ff;
		q.pop();
		if(dist[x]!=d)continue;
		for(int i=0;i<(int)g[x].size();i++)
		{
			if(dist[g[x][i]]==-1||dist[g[x][i]]>d+l[x][i])
			{
				dist[g[x][i]]=d+l[x][i];
				q.push(mp(dist[g[x][i]],g[x][i]));
			}
		}
	}
}
void dfs(int x)
{
	use[x]=1;
	for(int i=0;i<(int)g[x].size();i++)
		if(dist[x]+l[x][i]==dist[g[x][i]])
		{
			if(!use[g[x][i]])dfs(g[x][i]);
//			printf("edge %d %d\n",x,g[x][i]);
			rg[g[x][i]].pb(x);
		}
	v.pb(x);
}
int getlca(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);
	for(int i=0;i<20;i++)if((dep[x]-dep[y]>>i)&1)x=f[x][i];
	if(x==y)return x;
	for(int i=19;i>=0;i--)if(f[x][i]!=f[y][i])
	{
		x=f[x][i];
		y=f[y][i];
	}
	return f[x][0];
}
void dfs2(int x)
{
	sz[x]=1;
	for(int i=0;i<(int)tree[x].size();i++)
	{
		dfs2(tree[x][i]);
		sz[x]+=sz[tree[x][i]];
	}
}
int main()
{
	get3(n,m,s);
	for(int i=1,u,uu,w;i<=m;i++)
	{
		get3(u,uu,w);
		g[u].pb(uu);
		l[u].pb(w);
		g[uu].pb(u);
		l[uu].pb(w);
	}
	dijkstra();
	dfs(s);
	reverse(v.begin(),v.end());
	for(int _=1;_<(int)v.size();_++)
	{
		int x=v[_],lca=rg[x][0];
		for(int i=1;i<(int)rg[x].size();i++)
			lca=getlca(lca,rg[x][i]);
		f[x][0]=lca;
		dep[x]=dep[lca]+1;
		for(int i=1;i<20;i++)f[x][i]=f[f[x][i-1]][i-1];
		tree[lca].pb(x);
	}
	dfs2(s);
	int ans=0;
	for(int i=1;i<(int)v.size();i++)ans=max(ans,sz[v[i]]);
	printendl(ans);
	return 0;
}