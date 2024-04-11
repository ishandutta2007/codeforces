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

int dp[211][211][1111],n,kk,a[211];
#define add(x,y) (x)=((x)+(y))%mod
int main()
{
	get2(n,kk);
	for(int i=1;i<=n;i++)get1(a[i]);sort(a+1,a+n+1);
	dp[1][0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=i&&j+j<=n;j++)
		{
			for(int k=0;k<=kk;k++)
			{
				if(dp[i][j][k]==0)continue;
				if(i==n)continue;
				//nothing
				if(k+(a[i+1]-a[i])*j<=kk)add(dp[i+1][j][k+(a[i+1]-a[i])*j],1ll*dp[i][j][k]*(j+1));
				//begin
				if(k+(a[i+1]-a[i])*(j+1)<=kk)add(dp[i+1][j+1][k+(a[i+1]-a[i])*(j+1)],dp[i][j][k]);
				//end
				if(j&&k+(a[i+1]-a[i])*(j-1)<=kk)add(dp[i+1][j-1][k+(a[i+1]-a[i])*(j-1)],1ll*dp[i][j][k]*j);
			}
		}
	}
	int ans=0;
	for(int i=0;i<=kk;i++)add(ans,0ll+dp[n][0][i]+dp[n][1][i]);
	printendl(ans);
	return 0;
}