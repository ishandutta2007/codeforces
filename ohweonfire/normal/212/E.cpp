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
		char t;
		bool neg=false;
		x=0;
		for(; (t>'9'||t<'0')&&t!='-'; t=getchar());
		if(t=='-')neg=true,t=getchar();
		for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
		if(neg)x=-x;
	}
	void get_int(LL &x)
	{
		char t;
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

const int maxn=5005;
const int maxlog=20;
const LL mod=1000000007;
vector<int> g[maxn];
int sz[maxn],fa[maxn];
void dfs(int x,int f)
{
	fa[x]=f;
	for(int i=0; i<int(g[x].size()); i++)
		if(g[x][i]!=f)
		{
			dfs(g[x][i],x);
			sz[x]+=sz[g[x][i]];
		}
	sz[x]++;
}
int n,ans;
bool good[maxn],cur[maxn];
int num[maxn];
int main()
{
	get1(n);
	for(int i=1,x,y; i<n; i++)
	{
		get2(x,y);
		g[x].pb(y);
		g[y].pb(x);
	}
	dfs(1,0);
	for(int i=1; i<=n; i++)
	{
		int cnt=0;
		for(int j=0; j<g[i].size(); j++)
			if(g[i][j]!=fa[i])num[cnt++]=sz[g[i][j]];
			else num[cnt++]=n-sz[i];
		if(cnt==0)continue;
		memset(cur,0,sizeof(cur));
		cur[0]=1;
		for(int k=0; k<cnt; k++)
			for(int t=n-1; t>=num[k]; t--)
				cur[t]|=cur[t-num[k]];
		for(int j=1; j<n; j++)
			good[j]|=cur[j];
	}
	for(int i=1; i<n-1; i++)if(good[i])ans++;
	printf("%d\n",ans);
	for(int i=1; i<n-1; i++)if(good[i])printf("%d %d\n",i,n-i-1);
	return 0;
}