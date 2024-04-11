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

vector<int> g[100111];
int n,c[100111],f[100111],sz[100111];
int gf(int x){return x==f[x]?x:f[x]=gf(f[x]);}
void un(int x,int y){x=gf(x);y=gf(y);if(x!=y){sz[x]+=sz[y];f[y]=x;} }

void dfs(int x,int f)
{
	for(int i=0;i<(int)g[x].size();i++)
	{
		if(g[x][i]==f)continue;
		dfs(g[x][i],x);
		if(c[x]==c[g[x][i]])un(x,g[x][i]);
	}
}
int main()
{
	get1(n);
	for(int i=1,u,v;i<n;i++)
	{
		get2(u,v);
		g[u].pb(v);
		g[v].pb(u);
	}
	for(int i=1;i<=n;i++)
	{
		get1(c[i]);
		f[i]=i;sz[i]=1;
	}
	dfs(1,0);
	for(int i=1;i<=n;i++)
	{
		int all=sz[gf(i)];
		for(int j=0;j<(int)g[i].size();j++)if(c[g[i][j]]!=c[i])all+=sz[gf(g[i][j])];
		if(all==n)
		{
			puts("YES");
			printendl(i);
			return 0;
		}
	}
	puts("NO");
	return 0;
}