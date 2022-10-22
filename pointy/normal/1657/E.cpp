// Author: Little09
// Problem: CF1657E Star MST
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1657E
// Memory Limit: 500 MB
// Time Limit: 6000 ms
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
#define endl "\n"
#define lowbit(x) (x&(-x))

const ll inf=1000000000000000000; 
const ll mod=998244353;
//const ll mod=1000000007;

const int N=255;
int n,m; 
ll dp[N][N];

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
ll jc[N+5],inv[N+5];
inline ll C(ll x,ll y)
{
	if (y>x) return 0;
	return jc[x]*inv[y]%mod*inv[x-y]%mod;
}
void init()
{
	jc[0]=1;
	for (int i=1;i<=N;i++) jc[i]=jc[i-1]*i%mod;
	inv[N]=ksm(jc[N],mod-2);
	for (int i=N-1;i>=0;i--) inv[i]=inv[i+1]*(i+1)%mod;
}
int main()
{
	init();
	n=read()-1,m=read();
	for (int j=0;j<=m;j++) dp[0][j]=1;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			for (int k=0;k<=i;k++)
			{
				ll u=1ll*k*(k-1)/2;
				u=ksm(m-j+1,u);
				ll v=1ll*k*(i-k);
				v=ksm(m-j+1,v);
				dp[i][j]=(dp[i][j]+dp[i-k][j-1]*C(n-(i-k),k)%mod*u%mod*v%mod)%mod;
			}
		}
	}
	cout << dp[n][m];
	return 0;
}