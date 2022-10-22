#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
typedef long long ll;
typedef unsigned un;
typedef unsigned long long ull;
typedef std::pair<int,int> pii;
ll read()
{
	ll x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return f*x;
}
ll min(ll a,ll b){return a<b?a:b;}
ll max(ll a,ll b){return a>b?a:b;}
template<typename T> bool umin(T& a,T t){if(a>t)return a=t,1;return 0;}
template<typename T> bool umax(T& a,T t){if(a<t)return a=t,1;return 0;}
/**********/
int main()
{
	int task=read();
	while(task--)
	{
		int n=read();
		ll maxv=0,sum=0,pw=1;
		for(int i=1;i<=n;++i)
		{
			ll x=read();
			while(x%2==0)x>>=1,pw<<=1;
			umax(maxv,x),sum+=x;
		}
		printf("%lld\n",sum+maxv*(pw-1));
	}
	return 0;
}