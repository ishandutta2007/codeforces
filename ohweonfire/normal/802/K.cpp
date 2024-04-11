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

int n,k;
vector<int> g[100111],l[100111];
int dp[100111][2],pre[100111];//0:back 1:not back
pii p[100111];
void dfs(int x,int f=0)
{
	for(int i=0;i<(int)g[x].size();i++)
		if(g[x][i]!=f)
			dfs(g[x][i],x);
	int cnt=0;
	for(int i=0;i<(int)g[x].size();i++)
		if(g[x][i]!=f)
			p[++cnt]=mp(dp[g[x][i]][0]+l[x][i],g[x][i]);
	sort(p+1,p+cnt+1);reverse(p+1,p+cnt+1);
	if(cnt<k)
	{
		int mx=0;
		for(int i=1;i<=cnt;i++)
		{
			dp[x][0]+=p[i].ff;
			mx=max(mx,dp[p[i].ss][1]-dp[p[i].ss][0]);
		}
		dp[x][1]=dp[x][0]+mx;
	}
	else
	{
		int s1=0,s2=0;
		for(int i=1;i<k;i++)dp[x][0]+=p[i].ff;
		for(int i=1;i<k;i++)s1+=p[i].ff;
		s2=s1+p[k].ff;
		for(int i=1;i<=cnt;i++)
		{
			if(i<=k)
				dp[x][1]=max(dp[x][1],s2+dp[p[i].ss][1]-dp[p[i].ss][0]);
			else dp[x][1]=max(dp[x][1],s1+dp[p[i].ss][1]+p[i].ff-dp[p[i].ss][0]);
		}
	}
//	printf("dp %d %d %d\n",x,dp[x][0],dp[x][1]);
}
int main()
{
	get2(n,k);
	for(int i=1,u,v,c;i<n;i++)
	{
		get3(u,v,c);
		g[u].pb(v);g[v].pb(u);
		l[u].pb(c);l[v].pb(c);
	}
	dfs(0);
	printendl(max(dp[0][1],dp[0][0]));
	return 0;
}