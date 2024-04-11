#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
typedef long long ll;
typedef std::pair<int,int> pii;
ll read()
{
	ll x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return f*x;
}
ll min(ll a,ll b){return a<b?a:b;}
ll max(ll a,ll b){return a>b?a:b;}
template<typename T> bool umin(T& a,T t){if(a>t)return a=t,1;return 0;}
template<typename T> bool umax(T& a,T t){if(a<t)return a=t,1;return 0;}
/**********/
const int MAXN = 25, mod = 1e9+7;
int inv[MAXN],Ifac[MAXN];
void init(int n)
{
	inv[1]=1;
	for(int i=2;i<=n;++i)inv[i]=ll(mod-mod/i)*inv[mod%i]%mod;
	Ifac[0]=1;
	for(int i=1;i<=n;++i)Ifac[i]=ll(Ifac[i-1])*inv[i]%mod;
}
ll C(ll n,int m)
{
	n%=mod;
	ll res=1;
	for(int i=n;i>=n-m+1;--i)res=res*i%mod;
	return res*Ifac[m]%mod;
}
ll a[MAXN];
int main()
{
	int n=read();
	init(n);
	ll m=read(),ans=0;
	for(int i=0;i<n;++i)a[i]=read();
	for(int s=0;s<(1<<n);++s)
	{
		ll rest=m,coef=1;
		for(int i=0;i<n;++i)
			if(s&(1<<i))rest-=a[i]+1,coef=-coef;
		if(rest>=0)ans=(ans+coef*C(rest+n-1,n-1))%mod;
	}
	printf("%lld\n",(ans+mod)%mod);
	return 0;
}