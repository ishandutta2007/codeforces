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
const LL Linf=1ll<<62;
const double pi=acos(-1.0);

int n,r,f[55],s[55];
double p[55],dp[55][5555];
bool check(double x)
{
	for(int i=0;i<55;i++)for(int j=0;j<5555;j++)dp[i][j]=1e100;
	for(int i=0;i<=r;i++)dp[n+1][i]=0.0;
	dp[1][0]=x;
	for(int i=n+1;i>=1;i--)
	{
		for(int j=0;j<=r+100;j++)
			dp[i][j]=min(dp[i][j],min((dp[i+1][j+f[i]]+f[i])*p[i]+(dp[i+1][j+s[i]]+s[i])*(1-p[i]),dp[1][0]));
	}
//	printf("%.10lf %.10lf %d\n",x,dp[1][0],dp[1][0]<x);
	if(dp[1][0]<x)return true;
	return false;
}
int main()
{
	get2(n,r);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%lf",f+i,s+i,p+i);
		p[i]/=100;
	}
	double l=0,r=1e20,mid;
	for(int i=1;i<=300;i++)
	{
		mid=(l+r)*0.5;
		if(check(mid))r=mid;
		else l=mid;
	}
	printf("%.10lf\n",l);
	return 0;
}