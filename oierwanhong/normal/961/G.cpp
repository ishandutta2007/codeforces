#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<random>
#include<chrono>
typedef long long ll;
typedef unsigned un;
typedef std::vector<int> P;
typedef std::pair<int,int> pii;
ll read(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
template <typename T> bool umax(T& a,T t){if(t>a)return a=t,1;return 0;}
template <typename T> bool umin(T& a,T t){if(t<a)return a=t,1;return 0;}
/**********/
const int MAXN = 200011,mod = 1e9+7;
ll Qpow(ll a,ll p)
{
	ll res=1;
	while(p){if(p&1)res=res*a%mod;a=a*a%mod,p>>=1;}
	return res;
}
ll fac[MAXN],Ifac[MAXN];
ll C(int n,int m){return n>=0&&m>=0&&n>=m?fac[n]*Ifac[m]%mod*Ifac[n-m]%mod:0;}
void init(int n)
{
	fac[0]=Ifac[0]=Ifac[1]=1;
	for(int i=1;i<=n;++i)fac[i]=fac[i-1]*i%mod;
	for(int i=2;i<=n;++i)Ifac[i]=(mod-mod/i)*Ifac[mod%i]%mod;
	for(int i=2;i<=n;++i)Ifac[i]=Ifac[i-1]*Ifac[i]%mod;
}
ll S(int n,int m)
{
	if(n==0&&m==0)return 1;
	int ans=0;
	for(int i=0;i<=m;++i)
		if(i&1)ans=(ans-C(m,i)*Qpow(m-i,n))%mod;
		else ans=(ans+C(m,i)*Qpow(m-i,n))%mod;
	return ans*Ifac[m]%mod;
}
int main()
{
	int n=read(),k=read();
	init(n);
	ll sum=0;
	for(int i=1;i<=n;++i)sum=(sum+read())%mod;
	ll x=(S(n,k)+ll(n-1)*S(n-1,k))%mod;
	printf("%lld\n",(sum*x%mod+mod)%mod);
	return 0;
}