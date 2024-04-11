#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
typedef long long ll;
typedef unsigned long long ull;
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
const int MAXN = 1011;
ll a[MAXN];
int main()
{
	int n=read();
	for(int i=1;i<=n;++i)a[i]=read();
	ll ans=0;
	for(int i=1;i<=n;i+=2)
	{
		ll sum=0,maxlow=0;
		for(int j=i+1;j<=n;++j)
		{
			if((j-i)&1)
			{
				ans+=max(min(a[i]-max(maxlow,1)+1,a[j]-max(maxlow-sum,1)+1),0);
				sum+=a[j],umax(maxlow,sum);
			}
			else sum-=a[j];
		}
	}
	printf("%lld\n",ans);
	return 0;
}