// By: Little09
// Problem: CF1265E Beautiful Mirrors
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1265E
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(x) memset(x,0,sizeof(x))
#define printYes puts("Yes")
#define printYES puts("YES")
#define printNo puts("No")
#define printNO puts("NO")

const ll inf=1000000000000000000; 
const ll mod=998244353;

const int N=500005;
int n,m; 
ll a[N],inv,dp[N][2];

inline int read()
{
    int F=1,ANS=0;
	char C=getchar();
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
inline char readchar()
{
	char C=getchar();
    while (C<33||C>126) C=getchar();
    return C;
}
inline int raed(){return read();}

ll ksm(ll x,ll y)
{
	ll res=1;
	while (y)
	{
		if (y&1) res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}

int main()
{
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	inv=ksm(100,mod-2);
	dp[n+1][0]=0,dp[n+1][1]=0;
	for (int i=n;i>=1;i--)
	{
		dp[i][0]=dp[i+1][0]*inv%mod*a[i]%mod;
		dp[i][1]=dp[i+1][1]*inv%mod*a[i]%mod;
		dp[i][1]=(dp[i][1]+inv%mod*(100-a[i]))%mod;
		dp[i][0]=(dp[i][0]+1)%mod;
	}
	ll ans=dp[1][0]*ksm(mod+1-dp[1][1],mod-2)%mod;
	cout << ans;
	return 0;
}