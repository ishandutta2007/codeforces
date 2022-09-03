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
struct BIT
{
	LL bit0[maxn],bit1[maxn];
	int n;
	void clear(int nn)
	{
		mem(bit0,0);
		mem(bit1,0);
		n=nn;
	}
	LL sum(LL *b,int i)
	{
		LL ret=0;
		for(;i;i-=i&-i)ret+=b[i];
		return ret;
	}
	void add(LL *b,int i,int v)
	{
		for(;i<=n;i+=i&-i)b[i]+=v;
	}
	void add(int l,int r,int x)
	{
		add(bit0,l,-x*1ll*(l-1));
		add(bit1,l,x);
		add(bit0,r+1,x*1ll*r);
		add(bit1,r+1,-x);
	}
	LL sum(int i)
	{
		return sum(bit1,i)*i+sum(bit0,i);
	}
	LL query(int i){return sum(i)-sum(i-1);}
};
BIT each,all;
vector<int> g[maxn];
int id[maxn],idk,idl,lid[maxn];
int dep[maxn];
vector<int> line[maxn];
void dfs(int x,int f)
{
	id[x]=++idk;
	line[idl].pb(x);lid[x]=idl;
	for(int i=0;i<int(g[x].size());i++)if(g[x][i]!=f)
	{
		if(x==1){idl++;line[idl].pb(0);line[idl].pb(1);}
		dep[g[x][i]]=dep[x]+1;
		dfs(g[x][i],x);
	}
}
int n,q,op,v,x,d,l,r;
int main()
{
	get2(n,q);
	for(int i=1,x,y;i<n;i++)
	{
		get2(x,y);
		g[x].pb(y);
		g[y].pb(x);
	}
	dep[1]=1;
	dfs(1,0);
	each.clear(n);
	all.clear(n);
	while(q--)
	{
		scanf("%d%d",&op,&v);
		if(op==1)printf("%I64d\n",each.query(id[v])+all.query(dep[v]));
		else
		{
			scanf("%d%d",&x,&d);
			if(v==1)
			{
				all.add(1,d+1,x);
				continue;
			}
			l=max(2,dep[v]-d);r=min(int(line[lid[v]].size())-1,dep[v]+d);
			each.add(id[line[lid[v]][l]],id[line[lid[v]][r]],x);
			if(dep[v]-1<=d)
			{
				int t=min(int(line[lid[v]].size())-1,2+d-dep[v]);
				if(dep[v]-1!=d)each.add(id[line[lid[v]][2]],id[line[lid[v]][t]],-x);
				all.add(1,d-dep[v]+2,x);
			}
		}
	}
	return 0;
}