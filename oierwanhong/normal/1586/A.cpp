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
ll a[MAXN];
bool check(ll n)
{
	for(ll i=2;i*i<=n;++i)
		if(n%i==0)return 0;
	return n>1;
}
int main()
{
	int task=read();
	while(task--)
	{
		int n=read();
		ll sum=0;
		for(int i=1;i<=n;++i)a[i]=read(),sum+=a[i];
		if(!check(sum))
		{
			printf("%d\n",n);
			for(int i=1;i<=n;++i)printf("%d ",i);
			puts("");
		}
		else
		{
			printf("%d\n",n-1);
			bool flag=0;
			for(int i=1;i<=n;++i)
				if(!flag&& (a[i]&1))flag=1;
				else printf("%d ",i);
			puts("");
		}
	}
	return 0;
}