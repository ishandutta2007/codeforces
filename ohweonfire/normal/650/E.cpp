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

int f[500111];int gf(int x){return x==f[x]?x:f[x]=gf(f[x]);}

vector<int>g[500111],id[500111];
vector<pii>e[500111];
void unite(int x,int y)
{
	x=gf(x);y=gf(y);
	if(x==y)return;
	if(e[x].size()>e[y].size())swap(x,y);
	f[x]=y;
	while(e[x].size())
	{
		e[y].pb(e[x].back());
		e[x].pop_back();
	}
}

vector<pair<pii,pii> >cmd;
map<pii,int> edges;
int n,x[500111],y[500111],tx[500111],ty[500111];
bool ux[500111],uy[500111];

void dfs(int x,int f=0)
{
	for(int i=0;i<(int)g[x].size();i++)
	{
		if(g[x][i]==f)continue;
		dfs(g[x][i],x);
		if(ux[id[x][i]])
		{
			unite(x,g[x][i]);
			continue;
		}
		pii now;
		int cur=gf(g[x][i]);
		if(e[cur].size()==0)exit(0);
		do
		{
			now=e[cur].back();
			e[cur].pop_back();
		}while(uy[now.ss]);
		uy[now.ss]=1;
		cmd.pb({{x,g[x][i]},{tx[now.ss],ty[now.ss]}});
		unite(g[x][i],now.ff);
	}
}
int main()
{
	get1(n);
	for(int i=1;i<n;i++)
	{
		get2(x[i],y[i]);if(x[i]>y[i])swap(x[i],y[i]);
		edges[mp(x[i],y[i])]=i;
	}
	for(int i=1;i<n;i++)
	{
		get2(tx[i],ty[i]);if(tx[i]>ty[i])swap(tx[i],ty[i]);
		if(edges.find(mp(tx[i],ty[i]))!=edges.end())
			ux[edges[mp(tx[i],ty[i])]]=uy[i]=1;
	}
	for(int i=1;i<n;i++)
	{
		g[x[i]].pb(y[i]);g[y[i]].pb(x[i]);
		id[x[i]].pb(i);id[y[i]].pb(i);
		if(!uy[i])
		{
			e[tx[i]].pb(mp(ty[i],i));
			e[ty[i]].pb(mp(tx[i],i));
		}
	}
	for(int i=1;i<=n;i++)f[i]=i;
	dfs(1);
	printf("%d\n",(int)cmd.size());
	for(int i=0;i<(int)cmd.size();i++)printf("%d %d %d %d\n",cmd[i].ff.ff,cmd[i].ff.ss,cmd[i].ss.ff,cmd[i].ss.ss);
	return 0;
}