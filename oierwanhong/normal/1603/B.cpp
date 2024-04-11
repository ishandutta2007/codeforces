
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
const int MAXN = 300011;
int main()
{
	int task=read();
	while(task--)
	{
		ll x=read(),y=read();
		if(x>y)printf("%lld\n",x+y);
		else
		{
			ll n=(x+y)>>1;
			if(n%x==y%n){printf("%lld\n",n);continue;}
			ll r=y%x;
			printf("%lld\n",y-(r>>1));
		}
	}
	return 0;
}