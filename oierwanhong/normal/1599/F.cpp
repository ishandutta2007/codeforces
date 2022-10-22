#include<cstdio>
#include<cstdlib>
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
const int MAXN = 400011,mod = 1e9+7,inv2=(mod+1)>>1;
ll Qpow(ll a,ll p)
{
	if(a==2&&p==mod-2)return inv2;
	ll res=1;
	while(p){if(p&1)res=res*a%mod;a=a*a%mod,p>>=1;}
	return res;
}
struct Mint
{
	int x;
	Mint(){x=0;}
	Mint(int x):x((0<=x&&x<mod?x:(x%mod+mod)%mod)) {}
	void operator+= (Mint you){x+=you.x;if(x>=mod)x-=mod;}
	void operator-= (Mint you){x-=you.x;if(x<0)x+=mod;}
	void operator*= (Mint you){x=ll(x)*you.x%mod;}
	void operator/= (Mint you){x=ll(x)*Qpow(you.x,mod-2)%mod;}
	Mint Inv(){return Qpow(x,mod-2);}
};
Mint operator+ (Mint a,Mint b){int t=a.x+b.x;return t>=mod?t-mod:t;}
Mint operator- (Mint a,Mint b){int t=a.x-b.x;return t<0?t+mod:t;}
Mint operator* (Mint a,Mint b){return ll(a.x)*b.x%mod;}
Mint operator/ (Mint a,Mint b){return ll(a.x)*Qpow(b.x,mod-2)%mod;}

Mint s1[MAXN],s2[MAXN],a[MAXN];
Mint coef[MAXN];
int main()
{
	int n=read(),m=read();
	for(int i=1;i<=n;++i)a[i]=read(),s1[i]=s1[i-1]+a[i],s2[i]=s2[i-1]+a[i]*a[i];
	coef[0]=0;
	for(int i=1;i<=n;++i)coef[i]=coef[i-1]+Mint(i)*i;
	while(m--)
	{
		int l=read(),r=read(),d=read();
		int len=r-l+1;
		Mint f1=s1[r]-s1[l-1],f2=s2[r]-s2[l-1];
		Mint fir=(f1*2/len-Mint(len-1)*d)/2;
		Mint exp=fir*fir*len+fir*(len-1)*len*d+coef[len-1]*d*d;
		puts(exp.x==f2.x?"Yes":"No");
	}
	return 0;
}