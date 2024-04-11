#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
typedef unsigned un;
typedef std::pair<int,int> pii;
typedef long long ll;
ll read(){ll x=0;bool f=0;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=1;c=getchar();}while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();return f?-x:x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
template<typename T> inline bool umin(T& a,T b){if(b<a)return a=b,1;return 0;}
template<typename T> inline bool umax(T& a,T b){if(b>a)return a=b,1;return 0;}
/**********/
const int MAXN = 1011,mod = 998244353;
ll Qpow(ll a,ll p)
{
	ll res=1;
	while(p){if(p&1)res=res*a%mod;a=a*a%mod,p>>=1;}
	return res;
}
struct Mint
{
	int x;
	Mint(){x=0;}
	Mint(ll y){if(0<=y&&y<mod)x=y;else x=(y%mod+mod)%mod;}
	void operator +=(const Mint& you){x+=you.x;if(x>=mod)x-=mod;}
	void operator -=(const Mint& you){x-=you.x;if(x<0)x+=mod;}
	void operator *=(const Mint& you){x=ll(x)*you.x%mod;}
	void operator /=(const Mint& you){x=ll(x)*Qpow(you.x,mod-2)%mod;}
};
Mint operator +(const Mint& a,const Mint& b){int t=a.x+b.x;return t>=mod?t-mod:t;}
Mint operator -(const Mint& a,const Mint& b){int t=a.x-b.x;return t<0?t+mod:t;}
Mint operator *(const Mint& a,const Mint& b){return ll(a.x)*b.x%mod;}
Mint operator /(const Mint& a,const Mint& b){return ll(a.x)*Qpow(b.x,mod-2)%mod;}

Mint fac[MAXN],Ifac[MAXN];
Mint C(int n,int m){return fac[n]*Ifac[m]*Ifac[n-m];}
Mint f[MAXN][MAXN],g[MAXN][MAXN];
Mint h[MAXN][MAXN];
void init(int n)
{
	fac[0]=1;
	for(int i=1;i<=n;++i)fac[i]=fac[i-1]*i;
	Ifac[n]=Qpow(fac[n].x,mod-2);
	for(int i=n-1;i>=0;--i)Ifac[i]=Ifac[i+1]*(i+1);
}
int main()
{
	init(1000);
	int n=read(),m=read();
	for(int i=1;i<=n;++i)
	{
		Mint mul=1;
		for(int j=0;j<=m;++j)
		{
			h[i][j]=mul*Ifac[j],mul*=i;
		}
	}
	for(int j=1;j<=m;++j)f[1][j]=j;
	for(int i=2;i<=n;++i)
	{
		for(int len=1;len<i;++len)
			for(int j=i-1;j<=m;++j)
			{
				f[i][j]+=f[i-len][j-(i-1)]*h[i-1][len];
			}
		for(int j=i-1;j<=m;++j)f[i][j]+=f[i][j-(i-1)];
	}
			//f[i][j]+=f[i][j-1],g[i][j]+=g[i][j-1];
			//printf("F[%d,%d]=(%d,%d) [%d,%d]\n",i,j,f[i][j].x,g[i][j].x,(f[i][j]*fac[i]).x,(g[i][j]*fac[i]).x);
	Mint ans=Qpow(m,n)-f[n][m]*fac[n];
	printf("%d\n",ans.x);
	return 0;
}