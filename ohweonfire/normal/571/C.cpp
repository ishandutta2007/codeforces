/*
	Name: The Greatest Code of All Time
	Copyright: HaoBa IT Junior Two
	Author: OhWeOnFire
	Date: Today and Forever
	Description: This code is amazing, as you can see, right?
*/

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
#define printendl(a) print_int(a),putchar('\n')
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

const int maxn=500005;
const int maxlog=20;
const LL mod=1000000007;
int neg[maxn][2],nonneg[maxn][2],ans[maxn];
int n,m;
bool sat[maxn];
queue<int> q;
vector<int> clause[maxn],g[maxn];
vector<pii> id[maxn];
void go(int x)
{
	if(x==0||sat[x])return;
	for(int i=0;i<int(clause[x].size());i++)
		if(clause[x][i]>0&&ans[clause[x][i]]==-1)
		{
			q.push(clause[x][i]);
			ans[clause[x][i]]=0;
		}
		else if(clause[x][i]<0&&ans[-clause[x][i]]==-1)
		{
			q.push(-clause[x][i]);
			ans[-clause[x][i]]=1;
		}
	sat[x]=true;
}
void bfs()
{
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		if(ans[x]==0)
		{
			go(neg[x][0]);
			go(neg[x][1]);
		}
		else
		{
			go(nonneg[x][0]);
			go(nonneg[x][1]);
		}
	}
}
bool use[maxn],found;
vector<int> cycle;
int stv[maxn],ste[maxn],top;
void dfs(int x,int f)
{
	use[x]=true;
	stv[top++]=x;
	for(int i=0;i<int(g[x].size());i++)
		if(!use[g[x][i]])
		{
			ste[top-1]=i;
			dfs(g[x][i],id[x][i].ff);
		}
		else if(id[x][i].ff!=f&&!found)
		{
			ans[id[x][i].ff]=id[x][i].ss;
			cycle.pb(x);
			top--;
			do
			{
				top--;
				ans[id[stv[top]][ste[top]].ff]=id[stv[top]][ste[top]].ss;
				cycle.pb(stv[top]);
			}while(stv[top]!=g[x][i]);
			found=true;
		}
	top--;
}
int dist[maxn];
void bfs2()
{
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(int i=0;i<int(g[x].size());i++)
		{
			if(dist[g[x][i]]==-1)
			{
				q.push(g[x][i]);
				dist[g[x][i]]=dist[x]+1;
				ans[id[x][i].ff]=id[x][i].ss;
			}
		}
	}
}
bool incycle[maxn];
int main()
{
#ifdef LOCAL

#else

#endif
	memset(ans,-1,sizeof(ans));
	memset(dist,-1,sizeof(dist));
	get2(m,n);
	for(int i=1,x,y;i<=m;i++)
	{
		get1(x);
		while(x--)
		{
			get1(y);
			clause[i].pb(y);
			if(y<0)
			{
				if(neg[-y][0]==0)neg[-y][0]=i;
				else
				{
					neg[-y][1]=i;
					ans[-y]=0;
					q.push(-y);
				}
			}
			else
			{
				if(nonneg[y][0]==0)nonneg[y][0]=i;
				else
				{
					nonneg[y][1]=i;
					ans[y]=1;
					q.push(y);
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
		if(neg[i][0]==0&&nonneg[i][1]==0)
		{
			q.push(i);
			ans[i]=1;
		}
		else if(neg[i][1]==0&&nonneg[i][0]==0)
		{
			q.push(i);
			ans[i]=0;
		}
	bfs();
	while(!q.empty())q.pop();
	for(int i=1;i<=n;i++)if(ans[i]==-1)
	{
		g[nonneg[i][0]].pb(neg[i][0]);
		id[nonneg[i][0]].pb(mp(i,0));
		g[neg[i][0]].pb(nonneg[i][0]);
		id[neg[i][0]].pb(mp(i,1));
	}
	memset(use,0,sizeof(use));
	for(int i=1;i<=m;i++)if(!sat[i]&&!use[i])
	{
		found=0;top=0;
		cycle.clear();
		dfs(i,0);
		if(!found||cycle.size()==1)
		{
			puts("NO");
			return 0;
		}
		for(int j=0;j<int(cycle.size());j++)
		{
			incycle[cycle[j]]=true;
			dist[cycle[j]]=0;
			q.push(cycle[j]);
		}
	}
	bfs2();
	puts("YES");
	for(int i=1;i<=n;i++)if(ans[i]==-1)ans[i]=1;
	for(int i=1;i<=n;i++)putchar(ans[i]+'0');
	return 0;
}
/*
11 11
1 4
3 2 3 -4
3 1 -2 5
2 -7 -8
1 -3
3 8 -10 11
1 -6
2 7 -9
2 10 -11
2 6 9
2 -1 -5
*/