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

const int magic=20;

int n,k,cnt[1<<20],ans,dp[1<<20];
LL con[44];
int main()
{
	for(int i=0;i<(1<<20);i++)cnt[i]=cnt[i>>1]+(i&1);
	get2(n,k);
	for(int i=0;i<n;i++)
	{
		for(int j=0,x;j<n;j++)
		{
			get1(x);
			if(i!=j&&x==0)con[i]|=1ll<<j;
		}
	}
	if(n<=magic)
	{
		for(int i=0;i<(1<<n);i++)
		{
			int cur=0;
			for(int j=0;j<n;j++)if((i>>j)&1)cur|=con[j];
			if((cur&i)==0)ans=max(ans,cnt[i]);
		}
		printf("%.10lf\n",0.5*k*k/ans*(ans-1));
	}
	else
	{
		for(int i=0;i<(1<<magic);i++)
		{
			LL cur=0;
			for(int j=0;j<magic;j++)if((i>>j)&1)cur|=con[j];
			if((cur&i)==0)
			{
				dp[(1<<n-magic)-1^(cur>>magic)]=max(dp[(1<<n-magic)-1^(cur>>magic)],cnt[i]);
			}
		}
		for(int i=(1<<n-magic)-1;i>=0;i--)
		{
			LL cur=0;
			for(int j=0;j<n-magic;j++)if(((i>>j)&1)==0)dp[i]=max(dp[i],dp[i|(1<<j)]);else cur|=con[j+magic];
			if(((cur>>magic)&i)==0)ans=max(ans,cnt[i]+dp[i]);
		}
		printf("%.10lf\n",0.5*k*k/ans*(ans-1));
	}
	return 0;
}