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
const int MAXN = 200011;
int a[MAXN];
int loc[MAXN];
int main()
{
	int task=read();
	while(task--)
	{
		int n=read();
		for(int i=1;i<=n;++i)a[i]=read();
		if(n&1)
		{
			for(int i=1;i<n-2;i+=2)printf("%d %d ",-a[i+1],a[i]);
			if(a[n-1]+a[n-2]!=0)
			{
				printf("%d %d %d\n",-a[n],-a[n],a[n-1]+a[n-2]);
			}
			else if(a[n-2]+a[n]!=0)
			{
				printf("%d %d %d\n",-a[n-1],a[n-2]+a[n],-a[n-1]);
			}
			else
			{
				printf("%d %d %d\n",a[n-1]+a[n],-a[n-2],-a[n-2]);
			}
		}
		else
		{
			for(int i=1;i<=n;i+=2)printf("%d %d ",-a[i+1],a[i]);
			puts("");
		}
	}
	return 0;
}