// Author: Little09
// Problem: CF622F The Sum of the k-th Powers
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF622F
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+7;
ll n,k;
const int N=1e6+50;
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
ll a[N],b[N],c[N];
void init()
{
	jc[0]=1;
	for (int i=1;i<=N;i++) jc[i]=jc[i-1]*i%mod;
	inv[N]=ksm(jc[N],mod-2);
	for (int i=N-1;i>=0;i--) inv[i]=inv[i+1]*(i+1)%mod;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	init();
	cin >> n >> k;
	for (int i=1;i<=k+2;i++) a[i]=n-i;
	b[0]=1,c[k+3]=1;
	for (int i=1;i<=k+2;i++) b[i]=b[i-1]*a[i]%mod;
	for (int i=k+2;i>=1;i--) c[i]=c[i+1]*a[i]%mod;
	ll ans=0,y=0;
	for (int i=1;i<=k+2;i++)
	{
		ll res=b[i-1]*c[i+1]%mod;
		res=res*inv[i-1]%mod*inv[k+2-i]%mod;
		if (k+2-i&1) res*=-1;
		y=(y+ksm(i,k))%mod;
		ans=(ans+res*y)%mod;
	}
	ans=(ans+mod)%mod;
	cout << ans;
	return 0;
}