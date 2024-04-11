//  This code is written by Eric Sunli Chen ( OhWeOnFire ).
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <map>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;
template<typename T>
void get_int(T &x)
{
	char t=getchar();
	bool neg=false;
	x=0;
	for(; (t>'9'||t<'0')&&t!='-'; t=getchar());
	if(t=='-')neg=true,t=getchar();
	for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
	if(neg)x=-x;
}
template<typename T>
void print_int(T x)
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

int dp[133][3],n;//1:contest 2:sport 3:no
int main()
{
	get1(n);
	for(int i=0;i<133;i++)for(int j=0;j<3;j++)dp[i][j]=inf;
	dp[0][0]=0;
	for(int i=1,x;i<=n;i++)
	{
		get1(x);
		if(x&1)
			dp[i][1]=min(dp[i-1][0],dp[i-1][2]);
		if(x&2)
			dp[i][2]=min(dp[i-1][0],dp[i-1][1]);
		dp[i][0]=min(min(dp[i-1][0],dp[i-1][1]),dp[i-1][2])+1;
	}
	printf("%d\n",min(dp[n][0],min(dp[n][1],dp[n][2])));
	return 0;
}