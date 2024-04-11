// Author: Little09
// Problem: CF1670F Jee, You See?
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1670F
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
#define endl "\n"
#define lowbit(x) (x&(-x))

const ll inf=1000000000000000000; 
//const ll mod=998244353;
const ll mod=1000000007;

const int N=1005;
int n,m;
ll l,r,z;

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
ll dp[62][2*N];
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

inline ll read()
{
    ll F=1,ANS=0;
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

ll work(ll x,ll y)
{
	mem(dp);
	dp[61][0]=1;
	int u=n*2;
	for (ll i=60;i>=0;i--)
	{
		for (int j=0;j<=u;j++)
		{
			for (int k=(bool)(y&(1ll<<i));k<=n;k+=2)
			{
				bool t=(x&(1ll<<i));
				if (j*2-k+t<0) continue;
				int p=min(j*2-k+t,u+1);
				dp[i][p]=(dp[i][p]+dp[i+1][j]*C(n,k)%mod)%mod;
			}
		}
			for (int k=(bool)(y&(1ll<<i));k<=n;k+=2)
			{
				dp[i][u+1]=(dp[i][u+1]+dp[i+1][u+1]*C(n,k)%mod)%mod;
			}
	}
	ll res=0;
	for (int i=0;i<=u+1;i++) res=(res+dp[0][i])%mod;
	return res;
}

int main()
{
	init();
	n=read(),l=read(),r=read(),z=read();
	ll ans=(work(r,z)-work(l-1,z)+mod)%mod;
	cout << ans;
	return 0;
}