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
const int MAXN = 400011;
int a[MAXN];
int main()
{
	int task=read();
	while(task--)
	{
		int n=read();
		bool ans=0;
		for(int i=1;i<=n;++i)a[i]=read();
		std::sort(a+1,a+n+1);
		//Set all to 0
		bool f0=1;
		for(int i=1;i<=n;++i)
			if(a[i]==1)f0=0;
		//Set all to 1
		bool f1= a[1]>0;
		for(int i=1;i<n;++i)
			if(a[i+1]==a[i]+1)f1=0;
		puts(f0||f1?"YES":"NO");
	}
	return 0;
}