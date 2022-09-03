//  This code is written by Eric Chen ( OhWeOnFire ).
//  Don't copy my code, because my coding style is easy to recognize.
//  I hope my code will get 'Accepted'!

#include <algorithm>
#include <bitset>
#include <cctype>
#include <cerrno>
#include <clocale>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <limits>
#include <list>
#include <map>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <utility>
#include <vector>
#include <cwchar>
#include <cwctype>

#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<n;i++)
#define fortodo(i,m,n) for(int i=m;i<=n;i++)
#define hash orzYJZ
#define exp orzTZN
#define generate orzTBY
#define next orzMX
#define sqr(x) ((x)*(x))
#define mem(x,y) memset((x),(y),sizeof(x))
#define abs(x) ((x)>0?(x):(-x))
#define get1(a) get_int(a)
#define get2(a,b) get1(a),get1(b)
#define get3(a,b,c) get1(a),get2(b,c)
#define printendl(a) print_int(a),puts("")
#define printspace(a) print_int(a),putchar(' ')

using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
typedef long double LF;
typedef pair<int,int> pii;

const int inf=0x7fffffff;
const LL Linf=(1uLL<<63)-1;
const double EPS=1e-10;

namespace IOSpace
{
	void get_int(int &x)
	{
		char t=getchar();
		bool neg=false;
		x=0;
		for(; (t>'9'||t<'0')&&t!='-'; t=getchar());
		if(t=='-')neg=true,t=getchar();
		for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
		if(neg)x=-x;
	}
	void get_int(LL &x)
	{
		char t=getchar();
		bool neg=false;
		x=0;
		for(; (t>'9'||t<'0')&&t!='-'; t=getchar());
		if(t=='-')neg=true,t=getchar();
		for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
		if(neg)x=-x;
	}
	void print_int(int x)
	{
		if(x<0)putchar('-'),x=-x;
		short a[20]= {},sz=0;
		while(x>0)a[sz++]=x%10,x/=10;
		if(sz==0)putchar('0');
		for(int i=sz-1; i>=0; i--)putchar('0'+a[i]);
	}
	void print_int(LL x)
	{
		if(x<0)putchar('-'),x=-x;
		short a[20]= {},sz=0;
		while(x>0)a[sz++]=x%10,x/=10;
		if(sz==0)putchar('0');
		for(int i=sz-1; i>=0; i--)putchar('0'+a[i]);
	}
}
using namespace IOSpace;

const int maxn=100005;
const int maxlog=20;
const LL mod=1000000007;

vector<int> g[maxn],id[maxn];
int n,fa[20][maxn],dep[maxn];
int ans[maxn],add[maxn],fe[maxn],k;
void dfs(int x)
{
	for(int i=0;i<int(g[x].size());i++)if(g[x][i]!=fa[0][x])
	{
		dep[g[x][i]]=dep[x]+1;
		fa[0][g[x][i]]=x;
		fe[g[x][i]]=id[x][i];
		dfs(g[x][i]);
	}
}
int LCA(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);
	for(int i=19;i>=0;i--)if(((dep[x]-dep[y])>>i)&1)x=fa[i][x];
	if(x==y)return x;
	for(int i=19;i>=0;i--)if(fa[i][x]!=fa[i][y])
	{
		x=fa[i][x];
		y=fa[i][y];
	}
	return fa[0][x];
}
void dfs2(int x)
{
	for(int i=0;i<int(g[x].size());i++)
		if(g[x][i]!=fa[0][x])
		{
			dfs2(g[x][i]);
			ans[fe[g[x][i]]]=add[g[x][i]];
			add[x]+=add[g[x][i]];
		}
}
int main()
{
	get1(n);
	for(int i=1,x,y;i<n;i++)
	{
		get2(x,y);
		g[x].pb(y);
		g[y].pb(x);
		id[x].pb(i);
		id[y].pb(i);
	}
	dfs(1);
	for(int i=1;i<20;i++)
		for(int j=1;j<=n;j++)
			fa[i][j]=fa[i-1][fa[i-1][j]];
	get1(k);
	for(int i=1,x,y;i<=k;i++)
	{
		get2(x,y);
		int lca=LCA(x,y);
		add[x]++;
		add[y]++;
		add[lca]-=2;
	}
	dfs2(1);
	for(int i=1;i<n;i++)printspace(ans[i]);
	return 0;
}