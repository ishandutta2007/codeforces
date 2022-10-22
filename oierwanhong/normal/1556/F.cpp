#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<map>
#include<set>
typedef long long ll;
typedef std::pair<int,int> pii;
int read()
{
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return f*x;
}
ll min(ll a,ll b){return a<b?a:b;}
ll max(ll a,ll b){return a>b?a:b;}
template<typename T> bool umin(T& a,T t){if(a>t)return a=t,1;return 0;}
template<typename T> bool umax(T& a,T t){if(a<t)return a=t,1;return 0;}
int abs(int x){return x>0?x:-x;}
/**********/
const int MAXN = 14,mod = 1e9+7;
int f[1<<MAXN],a[MAXN];
int res[1<<MAXN];
int inv[2000011];
void init()
{
	inv[1]=1;
	for(int i=2;i<=2000000;++i)inv[i]=ll(mod-mod/i)*inv[mod%i]%mod;
}
int main()
{
	init();
	int n=read(),all=(1<<n)-1;
	for(int i=0;i<n;++i)a[i]=read();
	for(int s=1;s<(1<<n);++s)
	{
		f[s]=1;
		for(int t=(s-1)&s;t;t=(t-1)&s)
		{
			int p=f[t];
			for(int i=0;i<n;++i)
				if(t&(1<<i))
					for(int j=0;j<n;++j)
						if((s&(1<<j))&&!(t&(1<<j)))p=ll(p)*a[i]%mod*inv[a[i]+a[j]]%mod;
			f[s]=(f[s]-p)%mod;
		}
	}
	int ans=0;
	for(int s=1;s<(1<<n);++s)
	{
		int cnt=__builtin_popcount(s),p=f[s];
		for(int i=0;i<n;++i)
			if(s&(1<<i))
				for(int j=0;j<n;++j)
					if(!(s&(1<<j)))p=ll(p)*a[i]%mod*inv[a[i]+a[j]]%mod;
		ans=(ans+ll(p)*cnt)%mod;
	}
	printf("%d\n",(ans+mod)%mod);
	return 0;
}