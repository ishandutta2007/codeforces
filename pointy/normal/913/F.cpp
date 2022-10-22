#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=998244353;
const int N=5005;
ll n,a,b,p;
ll f[N],g[N],w[N][N],P[N],Q[N],dp[N],h[N];
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
// 	freopen("help.in","r",stdin);
// 	freopen("help.out","w",stdout);
	init();
	cin >> n >> a >> b;
	p=a*ksm(b,mod-2)%mod;
	f[1]=1,g[1]=0;
	w[0][0]=1;
	P[0]=1;
	for (int i=1;i<=n;i++) P[i]=P[i-1]*p%mod;
	Q[0]=1;
	for (int i=1;i<=n;i++) Q[i]=Q[i-1]*(1+mod-p)%mod;
	for (int i=1;i<=n;i++)
	{
		w[i][0]=1;
		for (int j=1;j<=i;j++)
		{
			w[i][j]=(w[i-1][j]*P[j]+w[i-1][j-1]*Q[i-j])%mod;
		}
	}
	//cout << w[2][1] << endl;
	for (int i=2;i<=n;i++)
	{
		for (int j=1;j<i;j++)
		{
			g[i]=(g[i]+w[i][j]*f[j]%mod)%mod;
		}
		f[i]=(1+mod-g[i])%mod;
	}
	dp[1]=0;
	for (int i=2;i<=n;i++)
	{
		for (int j=1;j<i;j++)
		{
			dp[i]=(dp[i]+f[j]*w[i][j]%mod*(h[i-j]+dp[j])%mod)%mod;
		}
		dp[i]=(dp[i]+1ll*i*(i-1)/2)%mod;
		dp[i]=dp[i]*ksm(1+mod-f[i],mod-2)%mod;
		h[i]=((dp[i]-1ll*i*(i-1)/2)%mod+mod)%mod;
	}
	cout << dp[n];
	return 0;
}