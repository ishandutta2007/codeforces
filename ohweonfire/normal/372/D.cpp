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

set<int> s;
vector<int> g[100111];
int n,k,dep[100111],f[100111][20],dfn[100111],ord[100111],timer;
void dfs(int x,int fa=0)
{
	dfn[x]=++timer;
	ord[timer]=x;
	f[x][0]=fa;
	for(int i=0;i<(int)g[x].size();i++)
		if(g[x][i]!=fa)
		{
			dep[g[x][i]]=dep[x]+1;
			dfs(g[x][i],x);
		}
}
int lca(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);
	for(int i=0;i<20;i++)if((dep[x]-dep[y]>>i)&1)x=f[x][i];
	if(x==y)return x;
	for(int i=19;i>=0;i--)
	{
		if(f[x][i]!=f[y][i])
		{
			x=f[x][i];
			y=f[y][i];
		}
	}
	return f[x][0];
}
int dist(int x,int y){return dep[x]+dep[y]-dep[lca(x,y)]*2;}
int sz;
int calc(int x)
{
	if(s.size()==0)return 1;
	set<int>::iterator it=s.lower_bound(dfn[x]);
	int l=ord[it==s.end()?*s.begin():*it];
	int r=ord[it==s.begin()?*s.rbegin():*(--it)];
	return (dist(l,x)+dist(r,x)-dist(l,r))/2;
}
int main()
{
	get2(n,k);
	for(int i=1,u,v;i<n;i++)
	{
		get2(u,v);
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(1);
	for(int i=1;i<20;i++)for(int j=1;j<=n;j++)f[j][i]=f[f[j][i-1]][i-1];
	int cur=1,ans=0;
	for(int i=1;i<=n;i++)
	{
		while(cur<=n&&sz<=k)
		{
			sz+=calc(cur);
			s.insert(dfn[cur]);
			cur++;
		}
		if(sz<=k)ans=max(ans,cur-i);
		else ans=max(ans,cur-i-1);
		s.erase(dfn[i]);sz-=calc(i);
	}
	printendl(ans);
	return 0;
}