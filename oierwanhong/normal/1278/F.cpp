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
const int MAXN = 5011,mod = 998244353;
ll Qpow(ll a,ll p)
{
	ll res=1;
	while(p){if(p&1)res=res*a%mod;a=a*a%mod,p>>=1;}
	return res;
}
int S[MAXN][MAXN];
ll fac[MAXN],Ifac[MAXN];
void init(int n)
{
	fac[0]=1;
	for(int i=1;i<=n;++i)fac[i]=fac[i-1]*i%mod;
	Ifac[n]=Qpow(fac[n],mod-2);
	for(int i=n-1;i>=0;--i)Ifac[i]=Ifac[i+1]*(i+1)%mod;
	S[0][0]=1;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=i;++j)
			S[i][j]=(S[i-1][j-1]+ll(j)*S[i-1][j])%mod;
}
ll C(int n,int m)
{
	ll mul=1;
	for(int i=n;i>n-m;--i)mul=mul*i%mod;
	return mul*Ifac[m]%mod;
}
ll DecPower(int n,int m)
{
	if(n<m)return 0;
	ll res=1;
	for(int i=n;i>n-m;--i)res=res*i%mod;
	return res;
}
int main()
{
	int n=read(),m=read(),k=read();
	ll p=Qpow(m,mod-2);
	init(k);
	/*
	res[0]=1,a[0]=1,a[1]=p;
	while(n)
	{
		if(n&1)
		{
			for(int x=0;x<=k;++x)
				for(int y=0;y<=k-x;++y)tp[x+y]=(tp[x+y]+ll(res[x])*a[y])%mod;
			for(int x=0;x<=k;++x)res[x]=tp[x],tp[x]=0;
		}
		for(int x=0;x<=k;++x)
			for(int y=0;y<=k-x;++y)tp[x+y]=(tp[x+y]+ll(a[x])*a[y])%mod;
		for(int x=0;x<=k;++x)a[x]=tp[x],tp[x]=0;
		n>>=1;
	}
	*/
	int ans=0;
	for(int j=0;j<=k;++j)ans=(ans+ll(S[k][j])*DecPower(n,j)%mod*Qpow(p,j))%mod;
	printf("%d\n",ans);
	return 0;
}