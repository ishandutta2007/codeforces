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

int n,m,k,sz,ans;
bool gov[100111],use[100111];
vector<int> g[1111];
void dfs(int x)
{
	use[x]=true;
	sz++;
	for(int i=0;i<(int)g[x].size();i++)
		if(!use[g[x][i]])
			dfs(g[x][i]);
}
int main()
{
	get3(n,m,k);
	for(int i=1,x;i<=k;i++)
	{
		get1(x);
		gov[x]=1;
	}
	for(int i=1;i<=m;i++)
	{
		int u,v;
		get2(u,v);
		g[u].pb(v);
		g[v].pb(u);
	}
	int mx=0;
	for(int i=1;i<=n;i++)if(gov[i])
	{
		sz=0;
		dfs(i);
		mx=max(mx,sz);
		ans+=sz*(sz-1)/2;
	}
	for(int i=1;i<=n;i++)if(!use[i]&&!gov[i])
	{
		ans+=mx;
		mx++;
	}
	printendl(ans-m);
	return 0;
}