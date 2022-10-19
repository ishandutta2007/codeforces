//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define mod 1000000007
#define F first
#define S second
#define ll long long
#define N 100010
#define M 1510
using namespace std;
ll fact[N],inv[N],inv_fac[N];
ll ksm(ll x,ll y)
{
	ll ret=1;
	while(y>0)
	{
		if(y&1)
		{
			ret=(ret*x)%mod;
		}
		x=(x*x)%mod;
		y>>=1;
	}
	return ret;
}
ll C(ll x,ll y){return (x<y||x<0||y<0)?0:(fact[x]*((inv_fac[y]*inv_fac[x-y])%mod))%mod;}
ll n,m,a,b,k,P,p[M],f[M][M],sumf[M],sumff[M],sump[M];
int main(){
	ll i,j;
	fact[0]=inv_fac[0]=inv[1]=inv_fac[1]=fact[1]=1;
	for(i=2;i<N;i++)
	{
		fact[i]=(fact[i-1]*i)%mod;
		inv[i]=(inv[mod%i]*(mod-mod/i))%mod;
		inv_fac[i]=(inv_fac[i-1]*inv[i])%mod;
	}
	cin>>n>>m>>a>>b>>k;
	P=(a*ksm(b,mod-2))%mod;
	for(i=0;i<=m&&i<=k;i++)
	{
		p[i]=(ksm(P,i)*ksm((mod+1-P)%mod,k-i))%mod;
		p[i]=(p[i]*C(k,i))%mod;
	}
	for(i=0;i<=m;i++)
	{
		sump[i+1]=(sump[i]+p[i])%mod;
	}
	f[0][1]=1;
	for(j=1;j<=m;j++)
	{
		sumf[j]=1;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			sumff[j]=(sumff[j-1]+((sumf[m]+mod-sumf[j])%mod)*p[m-j])%mod;
		}
		for(j=1;j<=m;j++)
		{
			ll coef=sump[m-j+1];
			f[i][j]=(coef*sumf[m])%mod;
			f[i][j]=(f[i][j]+mod-((sumff[m]+mod-sumff[j-1])%mod))%mod;
			f[i][j]=(f[i][j]+mod-(((sumf[m]+mod-sumf[m-j+1])%mod)*coef)%mod)%mod;
			f[i][j]=(f[i][j]*p[j-1])%mod;
		}
		for(j=1;j<=m;j++)
		{
			sumf[j]=(sumf[j-1]+f[i][j])%mod;
		}
	}
	cout<<sumf[m]<<endl;
	return 0;
}