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
const int MAXN = 110011,L = 455;
const ll INF = 1.233e18;
ll sum[MAXN];
ll f[L+1][MAXN];
inline ll eval(int x,int p){return sum[p]-sum[p-x];}
int main()
{
	int task=read();
	while(task--)
	{
		int n=read(),k=min(n,L);
		for(int i=1;i<=n;++i)sum[i]=sum[i-1]+read();
		for(int x=1;x<=k;++x)
			for(int i=1;i<=n+L;++i)f[x][i]=-INF;
		for(int i=n;i;--i)
		{
			f[1][i]=max(f[1][i+1],sum[i]-sum[i-1]);
			for(int x=2;x<=k;++x)
			{
				f[x][i]=f[x][i+1];
				if(f[x-1][i+x]>eval(x,i+x-1))umax(f[x][i],eval(x,i+x-1));
			}
		}
		for(int x=k;x;--x)
			if(f[x][1]>=0)
			{
				printf("%d\n",x);
				break;
			}
	}
	return 0;
}