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

LL dp[14][63][14];
void prework()
{
	for(int i=2;i<=10;i++)
	{
		dp[i][0][0]=1;
		for(int j=1;j<=60;j++)
			for(int k=0;k<=i;k++)
				dp[i][j][k]=dp[i][j-1][k+1]*(i-k)+(k==0?0:dp[i][j-1][k-1]*k);
	}
}
int dig[111],cnt;
int cur[11];
LL calc(int b,LL x)
{
	cnt=0;
	while(x)
	{
		dig[cnt++]=x%b;
		x/=b;
	}
	reverse(dig,dig+cnt);
	LL ret=0;
	for(int i=1;i<cnt-1;i++)
		ret+=dp[b][i][1]*(b-1);
	int sum=0;
	memset(cur,0,sizeof(cur));
	for(int i=0;i<cnt;i++)
	{
		for(int j=(i==0?1:0);j<dig[i];j++)
		{
			if(cur[j]==0)ret+=dp[b][cnt-i-1][sum+1];
			else ret+=dp[b][cnt-i-1][sum-1];
		}
		if(cur[dig[i]]==0)sum++;
		else sum--;
		cur[dig[i]]^=1;
	}
	return ret;
}
void solve()
{
	int b;LL l,r;get3(b,l,r);
	printendl(calc(b,r+1)-calc(b,l));
}
int main()
{
	prework();
	int q;get1(q);
	while(q--)solve();
	return 0;
}