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

vector<int> g[200111],v;
int n,m,k;
bool use[200111];
void dfs(int x)
{
	use[x]=1;
	v.pb(x);
	for(int i=0;i<(int)g[x].size();i++)
	{
		if(!use[g[x][i]])
		{
			dfs(g[x][i]);
			v.pb(x);
		}
	}
}
int main()
{
	get3(n,m,k);
	for(int i=1,u,v;i<=m;i++)
	{
		get2(u,v);
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(1);
	int mxt=(2*n+k-1)/k,cur=0,tot=v.size();
	for(int i=1;i<=k;i++)
	{
		int d=min(mxt,tot-cur);
		if(d==0)
		{
			printf("1 1\n");
			continue;
		}
		printf("%d ",d);
		for(int j=0;j<d;j++)printf("%d ",v[cur+j]);puts("");
		cur+=d;
	}
	return 0;
}