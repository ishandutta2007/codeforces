// By: Little09
// Problem: CF126D Fibonacci Sums
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF126D
// Memory Limit: 250 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
const int N=205;
int m=2;
ll f[N],a[N],cnt;
ll dp[N][2];
inline ll read()
{
	char C=getchar();
	ll F=1,ANS=0;
	while (C<'0'||C>'9')
	{
		if (C=='-') F=-1;
		C=getchar();
	}
	while (C>='0'&&C<='9')
	{
		ANS=ANS*10+C-'0';
		C=getchar();
	}
	return F*ANS;
} 
void work()
{
	n=read();
	f[1]=1,f[2]=2,m=2,cnt=0;
	while (1)
	{
		if (f[m]+f[m-1]>n) break;
		m++;
		f[m]=f[m-1]+f[m-2];
	}
	for (int i=m;i>=1;i--)
	{
		if (n>=f[i])
		{
			n-=f[i];
			a[++cnt]=i;
		}
	}
	sort(a+1,a+cnt+1);
	dp[1][1]=1,dp[1][0]=(a[1]-1)/2;
	for (int i=2;i<=cnt;i++)
	{
		dp[i][1]=dp[i-1][0]+dp[i-1][1];
		dp[i][0]=dp[i-1][0]*((a[i]-a[i-1])/2)+dp[i-1][1]*((a[i]-a[i-1]-1)/2);
	}
	ll ans=dp[cnt][0]+dp[cnt][1];
	printf("%lld\n",ans);
}
int main()
{
	int T=read();
	while (T--) work();
}