// LUOGU_RID: 90812567
// Author: Little09
// Problem: CF1728G Illumination
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1728G
// Memory Limit: 500 MB
// Time Limit: 8000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

const int N=5e5+5,M=18;
#define ll long long
const ll mod=998244353;
int d,n,m;
ll a[N],p[N];
ll dp[M][M],s;
ll g[N],f[N],ans[N];
#define mp make_pair
#define pii pair<ll,ll>
#define fi first
#define se second
pii w[N];
ll ask(ll x)
{
	if (f[x]!=-1) return f[x];
	ll res=s;
	for (ll i=x;i;i=(i-1)&x)
	{
		if (__builtin_popcount(i)%2==1) res=(res-g[i]+mod)%mod;
		else res=(res+g[i])%mod;
	}
	return f[x]=res;
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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> d >> n >> m;
	for (int i=1;i<=n;i++) cin >> a[i];
	for (int i=1;i<=m;i++) cin >> p[i];
	sort(p+1,p+m+1);
	p[0]=-d,p[m+1]=2*d;
	s=ksm(d+1,n);
	for (int i=0;i<=m+1;i++)
	{
		for (int j=i+1;j<=m+1;j++)
		{
			dp[i][j]=1;
			for (int k=1;k<=n;k++)
			{
				if (a[k]<=p[i]||a[k]>=p[j]) continue;
				ll res=min(a[k]-p[i],p[j]-a[k]);
				res=min(res,1ll*d+1);
				dp[i][j]=dp[i][j]*res%mod;
			}
		}
	}
	for (int i=0;i<(1<<m);i++)
	{
		int las=0;
		g[i]=1;
		for (int j=1;j<=m;j++)
		{
			if (i&(1<<(j-1))) 
			{
				g[i]=g[i]*dp[las][j]%mod;
				las=j;
			}
		}
		g[i]=g[i]*dp[las][m+1]%mod;
	}
	memset(f,-1,sizeof(f));
	memset(ans,-1,sizeof(ans));
	int q;
	cin >> q;
	while (q--)
	{
		int x;
		cin >> x;
		if (ans[x]!=-1)
		{
			cout << ans[x] << "\n";
			continue;
		}
		for (int i=1;i<=m;i++) w[i].fi=abs(x-p[i]),w[i].se=i;
		sort(w+1,w+m+1);
		ll res=(1<<m)-1;
		ll sum=0,las=0;
		w[m+1].fi=d+1;
		for (int i=0;i<=m;i++)
		{
			sum=(sum+(w[i+1].fi-1-las+1)*ask(res))%mod;
			if (i<m) res^=(1<<(w[i+1].se-1)),las=w[i+1].fi;
		}
		ans[x]=sum;
		cout << sum << "\n";
	}
	return 0;
}