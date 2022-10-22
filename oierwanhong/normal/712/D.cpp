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
const int MAXN = 440011,T = 220005, mod = 1e9+7;
struct Mint
{
	int x;
	Mint(){x=0;}
	Mint(int x):x(x) {}
	void operator+= (Mint you){x+=you.x;if(x>=mod)x-=mod;}
	void operator-= (Mint you){x-=you.x;if(x<0)x+=mod;}
	void operator*= (Mint you){x=ll(x)*you.x%mod;}
};
Mint operator+ (Mint a,Mint b){int t=a.x+b.x;return t>=mod?t-mod:t;}
Mint operator- (Mint a,Mint b){int t=a.x-b.x;return t<0?t+mod:t;}
Mint operator* (Mint a,Mint b){return ll(a.x)*b.x%mod;}

Mint f[MAXN],sum[MAXN];
int main()
{
	int a=read(),b=read(),k=read(),t=read();
	f[a-b+T]=1;
	sum[0]=f[0];
	for(int i=1;i<MAXN;++i)sum[i]=(sum[i-1]+f[i]);
	for(int i=1;i<=t;++i)
	{
		for(int j=1;j<MAXN;++j)
		{
			f[j]=sum[j];
			if(j>2*k)f[j]=(f[j]-sum[j-2*k-1]);
		}
		sum[0]=f[0];
		for(int j=1;j<MAXN;++j)sum[j]=(sum[j-1]+f[j]);
	}
	sum[MAXN-1]=f[MAXN-1];
	for(int i=MAXN-2;i;--i)sum[i]=(sum[i+1]+f[i]);
	for(int i=1;i<=t;++i)
	{
		for(int j=1;j<MAXN;++j)
		{
			f[j]=sum[j];
			if(j+2*k+1<MAXN)f[j]=(f[j]-sum[j+2*k+1]);
		}
		sum[MAXN-1]=f[MAXN-1];
		for(int j=MAXN-2;j;--j)sum[j]=(sum[j+1]+f[j]);
	}
	printf("%d\n",sum[T+1].x);
	return 0;
}