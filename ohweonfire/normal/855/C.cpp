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

const int mod=1e9+7;

int power(int x,int y)
{
	int ret=1;
	while(y)
	{
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod;
		y>>=1;
	}
	return ret;
}
vector<int> g[100111];
int n,m,k,X,dp[100111][12][3],tmp[12][3],rev;
void dfs(int x,int f=0)
{
	dp[x][0][0]=dp[x][1][2]=1;
	for(int i=0;i<(int)g[x].size();i++)
		if(g[x][i]!=f)
		{
			dfs(g[x][i],x);
			memset(tmp,0,sizeof(tmp));
			for(int j=0;j<=X;j++)for(int k=0;j+k<=X;k++)for(int tp=0;tp<3;tp++)for(int tp2=0;tp2<3;tp2++)
			{
				if(tp==2&&tp2==2)continue;
				int nxt=tp;if(tp2==2)nxt=1;
				if(tp==2&&tp2==0)tmp[j+k][nxt]=(tmp[j+k][nxt]+1ll*dp[x][j][tp]*dp[g[x][i]][k][tp2]%mod*rev)%mod;
				else tmp[j+k][nxt]=(tmp[j+k][nxt]+1ll*dp[x][j][tp]*dp[g[x][i]][k][tp2])%mod;
			}
			memcpy(dp[x],tmp,sizeof(tmp));
		}
	for(int i=0;i<=X;i++)
	{
		dp[x][i][0]=1ll*dp[x][i][0]*(m-1)%mod;
		dp[x][i][1]=1ll*dp[x][i][1]*(k-1)%mod;
	}
}
int main()
{
	get2(n,m);
	for(int i=1;i<n;i++)
	{
		int u,v;get2(u,v);
		g[u].pb(v);
		g[v].pb(u);
	}
	get2(k,X);rev=1ll*(k-1)*power(m-1,mod-2)%mod;
	dfs(1);
	int ans=0;
	for(int i=0;i<=X;i++)for(int j=0;j<3;j++)ans=(ans+dp[1][i][j])%mod;
	printendl(ans);
	return 0;
}