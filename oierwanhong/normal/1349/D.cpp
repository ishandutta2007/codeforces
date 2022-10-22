#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<random>
#include<chrono>
typedef long long ll;
typedef unsigned un;
typedef __int128 I128;
typedef std::vector<int> P;
typedef std::pair<int,int> pii;
ll read(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
template <typename T> bool umax(T& a,T t){if(t>a)return a=t,1;return 0;}
template <typename T> bool umin(T& a,T t){if(t<a)return a=t,1;return 0;}
/**********/
const int MAXN = 300011,mod = 998244353;
ll inv[MAXN];
void init()
{
	inv[1]=1;
	for(int i=2;i<MAXN;++i)inv[i]=(mod-mod/i)*inv[mod%i]%mod;
}
int f[MAXN],a[MAXN];
int main()
{
	init();
	int n=read(),m=0;
	for(int i=1;i<=n;++i)a[i]=read(),m+=a[i];
	f[0]=f[1]=1;
	for(int i=2;i<=m;++i)
	{
		f[i]=((ll(m)*(n-1)-ll(m-i+1)*(n-2))%mod*f[i-1]-ll(i-1)*(n-1)%mod*f[i-2]-ll(i-1)*(n-1))%mod;
		f[i]=f[i]*inv[m-i+1]%mod;
	}
	int ans=(-f[m]-ll(n-1)*f[0])%mod;
	for(int i=1;i<=n;++i)ans=(ans+f[a[i]])%mod;
	printf("%d\n",(ans+mod)%mod);
	return 0;
}