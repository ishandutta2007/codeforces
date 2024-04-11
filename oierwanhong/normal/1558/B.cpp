#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
typedef long long ll;
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
/**********/
const int MAXN = 4000011;
int f[MAXN],sum[MAXN];
int main()
{
	int n=read(),m=read();
	f[n]=1,sum[n]=1;
	for(int i=n-1;i;--i)
	{
		f[i]=sum[i+1];
		for(int p=2;i*p<=n;++p)f[i]=(ll(f[i])+sum[i*p]-((i+1)*p<=n?sum[(i+1)*p]:0))%m;
		sum[i]=(sum[i+1]+f[i])%m;
	}
	printf("%d\n",(f[1]+m)%m);
	return 0;
}