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

vector<int> g[5111];
int n,b,dp0[5111][5111],dp1[5111][5111],c[5111],d[5111],sz[5111];
bool cmp(int x,int y){return sz[x]>sz[y];}
void dfs(int x,int f=0)
{
	sz[x]=1;dp0[x][1]=c[x]-d[x];dp1[x][1]=c[x];dp1[x][0]=0;
	for(int i=0;i<(int)g[x].size();i++)
	{
		if(g[x][i]==f)continue;
		dfs(g[x][i],x);
	}
//	sort(g[x].begin(),g[x].end(),cmp);
	for(int i=0;i<(int)g[x].size();i++)
	{
		if(g[x][i]==f)continue;
		int v=g[x][i];
		for(int t1=sz[x];t1>=0;t1--)
			for(int t2=1;t2<=sz[v];t2++)
			{
				dp0[x][t1+t2]=min(dp0[x][t1+t2],dp0[x][t1]+dp0[v][t2]);
				dp1[x][t1+t2]=min(dp1[x][t1+t2],dp1[x][t1]+dp1[v][t2]);
				dp0[x][t1+t2]=min(dp0[x][t1+t2],dp0[x][t1]+dp1[v][t2]);
			}
		sz[x]+=sz[v];
	}
//	printf("x= %d sz= %d\n",x,sz[x]);
//	printf("dp0 ");for(int i=0;i<=n&&dp0[x][i]<=b;i++)printf("%d ",dp0[x][i]);puts("");
//	printf("dp1 ");for(int i=0;i<=n&&dp1[x][i]<=b;i++)printf("%d ",dp1[x][i]);puts("");
}
int main()
{
	get2(n,b);
	for(int i=1,x;i<=n;i++)
	{
		get2(c[i],d[i]);
		if(i>1)
		{
			get1(x);
			g[x].pb(i);
		}
	}
	for(int i=1;i<=n;i++)for(int j=0;j<=n;j++)dp0[i][j]=dp1[i][j]=b+1;
	dfs(1);
	for(int i=n;i>=0;i--)if(dp0[1][i]<=b||dp1[1][i]<=b)
	{
		printendl(i);
		break;
	}
	return 0;
}