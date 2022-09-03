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
template<typename T> bool get_int(T &x)
{
	char t=getchar();
	bool neg=false;
	x=0;
	for(; (t>'9'||t<'0')&&t!='-'&&t!=EOF; t=getchar());
	if(t=='-')neg=true,t=getchar();if(t==EOF)return false;
	for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
	if(neg)x=-x;return true;
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
#define get2(a,b) (get1(a)&&get1(b))
#define get3(a,b,c) (get1(a)&&get2(b,c))
#define printendl(a) print_int(a),puts("")
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

vector<int>g[233];
int n,k,d[233],dp[233][233],dis[233][233],ans[233];
void dfs(int x,int f=0)
{
	for(int i=1;i<=n;i++)dp[x][i]=d[dis[x][i]];
	for(auto v:g[x])if(v!=f)
	{
		dfs(v,x);
		for(int i=1;i<=n;i++)
		{
			int mn=inf;
			for(int j=1;j<=n;j++)if(dis[x][i]<=dis[x][j]&&dis[v][j]<=dis[v][i])mn=min(mn,dp[v][j]);
			dp[x][i]+=mn;
		}
	}
}
void rdfs(int x,int i,int f=0)
{
	if(x==i)ans[x]=x;
	for(auto v:g[x])if(v!=f)
	{
		pii mn=mp(inf,0);
		for(int j=1;j<=n;j++)if(dis[x][i]<=dis[x][j]&&dis[v][j]<=dis[v][i])mn=min(mn,mp(dp[v][j],j));
		rdfs(v,mn.ss,x);
	}
}
int main()
{
	get2(n,k);
	d[0]=k;for(int i=1;i<n;i++)get1(d[i]);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dis[i][j]=(i!=j)*inf;
	for(int i=1,u,v;i<n;i++)
	{
		get2(u,v);
		g[u].pb(v);
		g[v].pb(u);
		dis[u][v]=dis[v][u]=1;
	}
	for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
		dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	dfs(1);
	int t=min_element(dp[1]+1,dp[1]+n+1)-dp[1];
	rdfs(1,t);
	printf("%d\n",dp[1][t]);
	for(int i=1;i<=n;i++)
	{
		if(!ans[i])
		{
			for(int j=1;j<=n;j++)if(ans[j]==j&&(!ans[i]||dis[ans[i]][i]>dis[j][i]))
				ans[i]=j;
		}
		printf("%d ",ans[i]);
	}
	return 0;
}