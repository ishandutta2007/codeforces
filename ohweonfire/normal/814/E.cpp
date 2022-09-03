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
int n,a[55],dp[55][55][55][55],ndp[55][55][55][55],c[55][55];

#define add(x,y) (x)=((x)+(y))%mod
int main()
{
	for(int i=0;i<55;i++)
	{
		c[i][0]=1;
		for(int j=1;j<=i&&j<5;j++)
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
	}
	get1(n);
	for(int i=1;i<=n;i++)get1(a[i]);a[1]--;a[2]--;
	if(a[1]==1)dp[0][0][1][0]=1;else if(a[1]==2)dp[0][0][0][1]=1;else dp[0][0][0][0]=1;
	for(int i=1;i<n;i++)
	{
		memset(ndp,0,sizeof(ndp));
		for(int j1=0;j1<55;j1++)for(int j2=0;j2<55;j2++)for(int j3=0;j3<55;j3++)for(int j4=0;j4<55;j4++)
		{
			if(dp[j1][j2][j3][j4]==0)continue;
//			printf("dp %d %d %d %d %d = %d\n",i,j1,j2,j3,j4,dp[j1][j2][j3][j4]);
			for(int t1=0;t1<=j1&&t1<=a[i+1];t1++)for(int t2=0;t2<=j2&&t2<=a[i+1];t2++)for(int t3=0;t3<=j3&&t3<=a[i+1];t3++)for(int t4=0;t4<=j4&&t4<=a[i+1];t4++)
			{
				if(t1+t2+t3+t4>a[i+1])continue;
				if(t1&&t2)continue;
				if(i==1&&(t1||t2||t3||t4))continue;
				if(i>1&&t1+t2+t3+t4==0)continue;
				if(t1+t2>1)continue;
				if(t1==0&&t2==0&&t3+t4>1)continue;
				int coef=1ll*c[j1][t1]*c[j2][t2]*c[j3][t3]*c[j4][t4]*dp[j1][j2][j3][j4]%mod,rem=a[i+1]-t1-t2-t3-t4;
				if(t1==0&&t2==0&&j1==0&&j2==0)add(ndp[j3-t3+t4][j4-t4][rem==1][rem==2],coef);
				else if(t1||t2)add(ndp[j1-t1+t2][j2-t2][j3-t3+t4+(rem==1)][j4-t4+(rem==2)],coef);
			}
		}
		swap(dp,ndp);
	}
	printf("%d\n",dp[0][0][0][0]);
	return 0;
}