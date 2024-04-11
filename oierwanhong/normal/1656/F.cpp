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
const int MAXN = 200011;
ll a[MAXN],sum[MAXN];
int main()
{
	int task=read();
	while(task--)
	{
		int n=read();
		for(int i=1;i<=n;++i)a[i]=read();
		std::sort(a+1,a+n+1);
		for(int i=1;i<=n;++i)sum[i]=sum[i-1]+a[i];
		ll maxv=-8e18;
		int pos=0;
		//i=0
		ll K=0,B=0;
		for(int i=2;i<=n;++i)K+=a[1]+a[i],B+=ll(a[1])*a[i];
		if(K>0){puts("INF");continue;}
		maxv=K*-a[1]+B,pos=-a[1];
		//i=n
		K=0,B=0;
		for(int i=1;i<n;++i)K+=a[i]+a[n],B+=ll(a[i])*a[n];
		if(K<0){puts("INF");continue;}
		if(umax(maxv,K*-a[n]+B))pos=-a[n];
		for(int p=1;p<n;++p)
			//[1,p]...[p+1,n]
		{
			B=a[1]*(sum[n]-sum[p])+(sum[p]-sum[1])*a[n];
			K=(sum[n]-sum[p])+(n-p)*a[1]+(sum[p]-sum[1])+(p-1)*a[n];
			if(umax(maxv,K*-a[p]+B))pos=-a[p];
			if(umax(maxv,K*-a[p+1]+B))pos=-a[p+1];
		}
		printf("%lld\n",maxv);
	}
	return 0;
}