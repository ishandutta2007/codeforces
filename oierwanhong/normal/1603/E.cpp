#pragma GCC optimize("Ofast")
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
typedef unsigned un;
typedef std::pair<int,int> pii;
typedef long long ll;
int read(){int x=0;bool f=0;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=1;c=getchar();}while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();return f?-x:x;}
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
template<typename T> inline bool umin(T& a,T b){if(b<a)return a=b,1;return 0;}
template<typename T> inline bool umax(T& a,T b){if(b>a)return a=b,1;return 0;}
/**********/
const int MAXN = 205;
int mod;
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

Mint f[MAXN][MAXN][22];
Mint fac[MAXN],Ifac[MAXN];
void init(int n)
{
	fac[0]=1;
	for(int i=1;i<=n;++i)fac[i]=fac[i-1]*i;
	Ifac[n]=Mint(1)/fac[n];
	for(int i=n-1;i>=0;--i)Ifac[i]=Ifac[i+1]*(i+1);
}
int main()
{
	int n=read(),SP = 20;
	mod=read();
	init(n+1);
	Mint ans=1;
	for(int A=max(2,n-20);A<=n+1;++A)
	{
		for(int i=0;i<=n+1;++i)
			for(int j=0;j<=n+1;++j)
				for(int k=0;k<=21;++k)f[i][j][k]=0;
		for(int l=1;l<=A;++l)f[l][0][n+1-A]=Ifac[l];
		for(int i=1;i<=n;++i)
			for(int s=0;s<=A;++s)
				for(int j=A;j<n+1;++j)
				{
					if(f[i][s][n+1-j].x==0)continue;
					int upL=min((A-s)/(j+1-A),n-i);
					for(int l=1;l<=upL;++l)
					{
						Mint c=f[i][s][n+1-j]*Ifac[l];
						int upV=min(n+1,(A-s)/l+A);
						for(int v=max(j+1,i+l+1);v<=upV;++v)
							f[i+l][s+l*(v-A)][n+1-v]+=c;
					}
				}
		for(int s=0;s<=A;++s)ans+=f[n][s][0]*fac[n];
	}
	printf("%d\n",ans.x);
	return 0;
}