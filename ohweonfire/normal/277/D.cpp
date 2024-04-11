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

const double eps=1e-10;
struct problem
{
	int tsmall,tlarge,ssmall,slarge,tfail;
	double fail;
	bool operator <(const problem &b)const
	{
		return tlarge*fail*(1-b.fail)<b.tlarge*b.fail*(1-fail);
	}
	void in(){scanf("%d%d%d%d%lf",&ssmall,&slarge,&tsmall,&tlarge,&fail);tfail=(int)(1000000*fail+0.5);}
}p[1111];
int n,t;
pair<LL,double>dp[1111][1611];
int main()
{
	get2(n,t);
	for(int i=1;i<=n;i++)p[i].in();
	sort(p+1,p+n+1);
	for(int i=1;i<=n+1;i++)for(int j=0;j<=t;j++)
	{
		//not solve
		dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
		dp[i][j+1]=max(dp[i][j+1],dp[i][j]);
		double pen=-dp[i][j].ss;LL sc=dp[i][j].ff;
		if(i==n+1)continue;
		//solve small
		if(j+p[i].tsmall<=t)dp[i+1][j+p[i].tsmall]=
			max(dp[i+1][j+p[i].tsmall],mp(sc+p[i].ssmall*1000000ll,-(pen+p[i].tsmall)));
		//solve small+large
		if(j+p[i].tsmall+p[i].tlarge<=t)dp[i+1][j+p[i].tsmall+p[i].tlarge]=
			max(dp[i+1][j+p[i].tsmall+p[i].tlarge],mp(sc+p[i].ssmall*1000000ll+(1000000ll-p[i].tfail)*p[i].slarge,
			-(pen+p[i].tsmall)*p[i].fail-(j+p[i].tsmall+p[i].tlarge)*(1-p[i].fail)));
	}
	printf("%.10lf %.10lf\n",dp[n+1][t].ff*1.0/1000000,-dp[n+1][t].ss);
	return 0;
}