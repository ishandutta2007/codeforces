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
/**********/
int main()
{
	int task=read();
	while(task--)
	{
		ll n=read();
		if(n%2050)
		{
			puts("-1");continue;
		}
		n/=2050;
		ll ans=0;
		while(n)ans+=n%10,n/=10;
		printf("%lld\n",ans);
	}
	return 0;
}