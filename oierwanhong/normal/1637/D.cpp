#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
typedef long long ll;
typedef unsigned un;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
ll read()
{
	ll f=1,x=0;int c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return f*x;
}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
ll abs(ll x){return x>0?x:-x;}
template<typename T> inline bool umin(T& a,T t){if(t<a)return a=t,1;return 0;}
template<typename T> inline bool umax(T& a,T t){if(t>a)return a=t,1;return 0;}
/**********/
const int MAXN = 10011;
const ll LINF = 1.233e18;
int a[MAXN],b[MAXN];
ll f[111][MAXN];
int main()
{
	int task=read();
	while(task--)
	{
		int n=read();
		ll others=0;
		for(int i=1;i<=n;++i)a[i]=read(),others+=ll(n-1)*a[i]*a[i];
		for(int i=1;i<=n;++i)b[i]=read(),others+=ll(n-1)*b[i]*b[i];
		for(int i=0;i<=n;++i)
			for(int j=0;j<=n*100;++j)f[i][j]=LINF;
		f[0][0]=0;
		int sum=0;
		for(int i=1;i<=n;++i)
		{
			for(int j=0;j<=i*100;++j)
			{
				if(j>=a[i])
					umin(f[i][j],f[i-1][j-a[i]]+(j-a[i])*a[i]+(sum-(j-a[i]))*b[i]);
				if(j>=b[i])
					umin(f[i][j],f[i-1][j-b[i]]+(j-b[i])*b[i]+(sum-(j-b[i]))*a[i]);
			}
			sum+=a[i]+b[i];
		}
		ll ans=LINF;
		for(int j=0;j<=n*100;++j)umin(ans,f[n][j]);
		printf("%lld\n",ans*2+others);
	}
	return 0;
}