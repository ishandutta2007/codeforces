#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
typedef long long ll;
typedef std::pair<int,int> pii;
typedef unsigned un;
ll read()
{
	ll x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return f*x;
}
ll min(ll a,ll b){return a<b?a:b;}
ll max(ll a,ll b){return a>b?a:b;}
ll abs(ll x){return x>0?x:-x;}
template<typename T> bool umin(T& a,T t){if(a>t)return a=t,1;return 0;}
template<typename T> bool umax(T& a,T t){if(a<t)return a=t,1;return 0;}
/**********/
const int MAXN = 500011;
ll a[MAXN];
int main()
{
	int n=read();
	ll sum=0;
	for(int i=1;i<=n;++i)a[i]=read(),sum+=a[i];
	std::sort(a+1,a+n+1);
	int m=read();
	while(m--)
	{
		ll x=read(),y=read();
		int p=std::lower_bound(a+1,a+n+1,x)-a;
		ll res=5e18;
		if(p<=n)umin(res,max(y-(sum-a[p]),0ll));
		if(p>1)umin(res,x-a[p-1]+max(y-(sum-a[p-1]),0ll));
		printf("%lld\n",res);
	}
	return 0;
}