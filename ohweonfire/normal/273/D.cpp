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

int n,m,dp[2][153][153][4],sum[153][153][4],ans;
int main()
{
	get2(n,m);
	for(int _=1;_<=n;_++)
	{
		int i=_%2;
		for(int l=1;l<=m;l++)for(int r=1;r<=m;r++)for(int t=0;t<4;t++)
		{
			sum[l][r][t]=sum[l-1][r][t]+sum[l][r-1][t];if(sum[l][r][t]>=mod)sum[l][r][t]-=mod;
			sum[l][r][t]+=dp[i^1][l][r][t];if(sum[l][r][t]>=mod)sum[l][r][t]-=mod;
			sum[l][r][t]-=sum[l-1][r-1][t];if(sum[l][r][t]<0)sum[l][r][t]+=mod;
		}
		for(int l=1;l<=m;l++)for(int r=l;r<=m;r++)for(int t=0;t<4;t++)
		{
			if(t==0)dp[i][l][r][t]=1;
			else dp[i][l][r][t]=0;
			int t1=t>>1,t2=t&1,l1,l2,r1,r2,pt1,pt2;
			for(int pt=0;pt<4;pt++)
			{
				pt1=pt>>1,pt2=pt&1;
				if(t1>=pt1&&t2>=pt2)
				{
					if(t1==0){l1=l;l2=r;}
					else{l1=1;l2=l;}
					if(t1!=pt1)l2--;
					if(t2==0){r1=l;r2=r;}
					else{r1=r;r2=m;}
					if(t2!=pt2)r1++;
					if(l1<=l2&&r1<=r2)
					{
						dp[i][l][r][t]+=sum[l2][r2][pt];if(dp[i][l][r][t]>=mod)dp[i][l][r][t]-=mod;
						dp[i][l][r][t]+=sum[l1-1][r1-1][pt];if(dp[i][l][r][t]>=mod)dp[i][l][r][t]-=mod;
						dp[i][l][r][t]-=sum[l2][r1-1][pt];if(dp[i][l][r][t]<0)dp[i][l][r][t]+=mod;
						dp[i][l][r][t]-=sum[l1-1][r2][pt];if(dp[i][l][r][t]<0)dp[i][l][r][t]+=mod;
					}
				}
			}
			ans+=dp[i][l][r][t];if(ans>=mod)ans-=mod;
		}
	}
	printendl(ans);
	return 0;
}