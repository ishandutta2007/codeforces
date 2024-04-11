//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define mod 1000000007
#define F first
#define S second
#define ll long long
#define N 200010
using namespace std;
ll fact[N],inv[N];
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
ll GetC(ll x,ll y)
{
	if(x<y||x<0||y<0)
	{
		return 0;
	}
	return (fact[x]*((inv[y]*inv[x-y])%mod))%mod;
}
ll n,l,r,mn[N],mx[N],ans;
vector<ll> pval,nval,allv;
ll calc(ll x)//choose x and -x
{
	ll mnp=lower_bound(pval.begin(),pval.end(),-x)-pval.begin(),mnn=lower_bound(nval.begin(),nval.end(),x)-nval.begin();
	if(pval[0]>(-x)||nval.back()<x)
	{
		return 0;
	}
	if(mnp==n)
	{
		mnp=n-1;
	}
	if(mnp+1<mnn)
	{
		return 0;
	}
	if(n%2==0)
	{
		return GetC(mnp-mnn+1,n/2-mnn);
	}
	return (GetC(mnp-mnn+1,n/2-mnn)+GetC(mnp-mnn+1,(n+1)/2-mnn))%mod;
}
int main(){
	ll T,i;
	fact[0]=inv[0]=1;
	for(i=1;i<N;i++)
	{
		fact[i]=(fact[i-1]*i)%mod;
		inv[i]=ksm(fact[i],mod-2);
	}
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld%lld%lld",&n,&l,&r);
		pval.clear();
		nval.clear();
		allv.clear();
		for(i=1;i<=n;i++)
		{
			mn[i]=l-i;
			mx[i]=r-i;
			pval.push_back(-mx[i]);//store the data in its opposite form
			nval.push_back(-mn[i]);
			allv.push_back(mx[i]);
			allv.push_back(-mn[i]);
		}
		allv.push_back(0);
		sort(allv.begin(),allv.end());
		allv.erase(unique(allv.begin(),allv.end()),allv.end());
		ans=0;
		for(i=1;i<allv.size();i++)
		{
			//solve when x is in range (allv(i-1),allv(i)]
			ans=(ans+calc(allv[i])*(allv[i]-allv[i-1]))%mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
}