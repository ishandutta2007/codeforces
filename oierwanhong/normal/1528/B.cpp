//By OIerwanhong ,7/9
#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<set>
typedef long long ll;
typedef unsigned un;
typedef std::vector<int> P;
typedef std::pair<int,int> pii;
ll read(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
template <typename T> bool umax(T& a,T t){if(t>a)return a=t,1;return 0;}
template <typename T> bool umin(T& a,T t){if(t<a)return a=t,1;return 0;}
int abs(int x){return x>0?x:-x;}
/**********/

const int MAXN = 1000011,mod = 998244353;
int f[MAXN],sig[MAXN];
int d[MAXN];
void sieve(int n)
{
	for(int i=1;i<=n;++i)
		for(int j=i;j<=n;j+=i)++d[j];
}
int main()
{
	int n=read();
	sieve(n);
	f[1]=sig[1]=1;
	for(int i=2;i<=n;++i)
	{
		f[i]=(sig[i-1]+d[i])%mod,sig[i]=(sig[i-1]+f[i])%mod;
	}
	printf("%d\n",f[n]);
	return 0;
}