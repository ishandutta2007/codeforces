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
const int MAXN = 5011, mod = 1e9+7;
int S[MAXN][MAXN];
ll Qpow(ll a,ll p)
{
	ll res=1;
	while(p){if(p&1)res=res*a%mod;a=a*a%mod,p>>=1;}
	return res;
}
void init(int n)
{
	S[0][0]=1;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=i;++j)
			S[i][j]=(S[i-1][j-1]+ll(S[i-1][j])*j)%mod;
}
int main()
{
	int n=read(),k=read();
	init(k);
	int ans=0,mul=1;
	for(int j=0;j<=k&&j<=n;++j)
		ans=(ans+ll(mul)*S[k][j]%mod*Qpow(2,n-j)%mod)%mod,mul=ll(mul)*(n-j)%mod;
	printf("%d\n",(ans+mod)%mod);
	return 0;
}