#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
typedef unsigned un;
typedef long long ll;
typedef std::pair<int,int> pii;
ll read(){ll x=0;bool f=0;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=1;c=getchar();}while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();return f?-x:x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
template<typename T> inline bool umin(T& a,T b){if(b<a)return a=b,1;return 0;}
template<typename T> inline bool umax(T& a,T b){if(b>a)return a=b,1;return 0;}
/**********/
const int MAXN = 2000011;
int fac[MAXN];
int main()
{
	int n=read(),mod=read();
	fac[0]=1;
	for(int i=1;i<=n;++i)fac[i]=ll(fac[i-1])*i%mod;
	int ans=0;
	for(int i=n;i;--i)
	{
		ans=(ans+ll(n-i+1)*(n-i+1)%mod*fac[i]%mod*fac[n-i])%mod;
		//fprintf(stderr,"Add %lld*%d\n",ll(n-i+1)*(n-i+1),fac);
	}
	printf("%d\n",ans);
	return 0;
}