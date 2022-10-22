#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int,int> pii;
ll read(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();return f*x;}
using std::max;
using std::min;
template <typename T> bool umax(T& a,T t){if(t>a)return a=t,1;return 0;}
template <typename T> bool umin(T& a,T t){if(t<a)return a=t,1;return 0;}
/**********/
const int MAXN = 100011;

/*
ll Qpow(ll a,ll p)
{
	ll res=1;
	while(p){if(p&1)res=res*a%mod;a=a*a%mod,p>>=1;}
	return res;
}
*/

ull ss[10];
struct poly
{
	ull a[5];
	poly(){memset(a,0,sizeof a);}
	inline poly operator +(const poly& you)
	{
		poly res;
		for(int i=0;i<5;++i)res.a[i]=a[i]+you.a[i];
		return res;
	}
	inline void operator +=(const poly& you)
	{
		for(int i=0;i<5;++i)a[i]+=you.a[i];
	}
	inline poly operator *(const poly& you)
	{
		poly res;
		for(int i=0;i<5;++i)
			for(int j=0;j<5;++j)ss[i+j]+=a[i]*you.a[j];
		for(int i=0;i<5;++i)res.a[i]=ss[i]+ss[i+5],ss[i]=ss[i+5]=0;
		return res;
	}
	ull val()
	{
		return a[0]-a[4];
	}
};
poly a[MAXN],w[10], m1[10][10],m2[10][10], b[10];
ull f[MAXN];
poly Qpow(poly a,int p)
{
	poly res;
	res.a[0]=1;
	while(p){if(p&1)res=res*a;a=a*a,p>>=1;}
	return res;
}
void DFT(int len)
{
	for(int cur=1;cur<len;cur*=10)
	{
		for(int j=0;j<len;j+=cur*10)
			for(int k=0;k<cur;++k)
			{
				for(int x=0;x<10;++x)b[x]=a[j+x*cur+k];
				for(int x=0;x<10;++x)
				{
					a[j+x*cur+k]=poly();
					for(int p=0;p<10;++p)a[j+x*cur+k]+=m1[x][p]*b[p];
				}
			}
	}
}
void IDFT(int len)
{
	for(int cur=1;cur<len;cur*=10)
		for(int j=0;j<len;j+=cur*10)
			for(int k=0;k<cur;++k)
			{
				for(int x=0;x<10;++x)b[x]=a[j+x*cur+k];
				for(int x=0;x<10;++x)
				{
					a[j+x*cur+k]=poly();
					for(int p=0;p<10;++p)a[j+x*cur+k]+=m2[x][p]*b[p];
				}
			}
	for(int i=0;i<len;++i)f[i]=a[i].val();//l;ohoiehdfiohafsiuophaiupfo
}
const ull mod=1ll<<58;
void exgcd(ll a,ll b,ll& x,ll& y)
{
	if(!b){x=1,y=0;return;}
	else exgcd(b,a%b,y,x),y-=a/b*x;
}
ll Inv(ll a)
{
	ll x,y;
	exgcd(a,mod,x,y);
	return (x%mod+mod)%mod;
}
int main()
{
	int n=read();
	for(int i=1;i<=n;++i)++a[read()].a[0];
	int len=1e5;
	w[0].a[0]=1,w[1].a[3]=-1ull;
	for(int i=2;i<10;++i)w[i]=w[i-1]*w[1];
	for(int i=0;i<10;++i)
		for(int j=0;j<10;++j)
			m1[i][j]=w[i*j%10],m2[i][j]=w[((-i*j)%10+10)%10];
	DFT(len);
	for(int i=0;i<len;++i)a[i]=Qpow(a[i],n);
	IDFT(len);
	ull inv=Inv(5);
	inv=inv*inv*inv*inv*inv;
	for(int i=0;i<n;++i)
	{
		printf("%llu\n",((f[i]*inv)>>5)&(mod-1ull));
	}
	return 0;
}