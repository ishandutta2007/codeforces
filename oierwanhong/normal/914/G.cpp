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
const int MAXN = 17,mod = 1e9+7;
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

void FWT_OR(Mint* a,int n)
{
	for(int cur=1;cur<(1<<n);cur<<=1)
		for(int j=0;j<(1<<n);j+=cur<<1)
			for(int k=0;k<cur;++k)a[j+cur+k]+=a[j+k];
}
void IFWT_OR(Mint* a,int n)
{
	for(int cur=1;cur<(1<<n);cur<<=1)
		for(int j=0;j<(1<<n);j+=cur<<1)
			for(int k=0;k<cur;++k)a[j+cur+k]-=a[j+k];
}
void FWT_AND(Mint* a,int n)
{
	for(int cur=1;cur<(1<<n);cur<<=1)
		for(int j=0;j<(1<<n);j+=cur<<1)
			for(int k=0;k<cur;++k)a[j+k]+=a[j+cur+k];
}
void IFWT_AND(Mint* a,int n)
{
	for(int cur=1;cur<(1<<n);cur<<=1)
		for(int j=0;j<(1<<n);j+=cur<<1)
			for(int k=0;k<cur;++k)a[j+k]-=a[j+cur+k];
}
void FWT_XOR(Mint* a,int n)
{
	for(int cur=1;cur<(1<<n);cur<<=1)
		for(int j=0;j<(1<<n);j+=cur<<1)
			for(int k=0;k<cur;++k)
			{
				Mint x=a[j+k],y=a[j+cur+k];
				a[j+k]=x+y,a[j+cur+k]=x-y;
			}
}
void IFWT_XOR(Mint* a,int n)
{
	FWT_XOR(a,n);
	Mint inv=Qpow(1<<n,mod-2);
	for(int i=0;i<(1<<n);++i)a[i]*=inv;
}
int cnt[1<<MAXN];
void subset_conv(Mint* f,Mint* g,Mint* h,int n)
{
	static Mint tf[MAXN+1][1<<MAXN],tg[MAXN+1][1<<MAXN],res[MAXN+1][1<<MAXN];
	for(int i=0;i<=n;++i)
		for(int s=0;s<(1<<n);++s)tf[i][s]=tg[i][s]=res[i][s]=0;
	for(int s=0;s<(1<<n);++s)tf[cnt[s]][s]=f[s];
	for(int s=0;s<(1<<n);++s)tg[cnt[s]][s]=g[s];
	for(int i=0;i<=n;++i)FWT_OR(tf[i],n),FWT_OR(tg[i],n);
	for(int i=0;i<=n;++i)
		for(int j=0;i+j<=n;++j)
			for(int s=0;s<(1<<n);++s)res[i+j][s]+=tf[i][s]*tg[j][s];
	for(int i=0;i<=n;++i)IFWT_OR(res[i],n);
	for(int s=0;s<(1<<n);++s)h[s]=res[cnt[s]][s];
}
Mint f[1<<MAXN],g[1<<MAXN], f1[1<<MAXN], fib[1<<MAXN];
int main()
{
	int t=read(),n=17;
	while(t--)f[read()]+=1;
	memcpy(g,f,sizeof f);
	fib[0]=0,fib[1]=1;
	for(int i=2;i<(1<<MAXN);++i)fib[i]=fib[i-1]+fib[i-2];
	for(int s=1;s<(1<<MAXN);++s)cnt[s]=cnt[s&(s-1)]+1;
	subset_conv(f,f,f1,n);
	for(int s=0;s<(1<<MAXN);++s)f1[s]*=fib[s];
	FWT_XOR(g,n);
	for(int s=0;s<(1<<MAXN);++s)g[s]*=g[s];
	IFWT_XOR(g,n);
	for(int s=0;s<(1<<MAXN);++s)g[s]*=fib[s],f[s]*=fib[s];
	FWT_AND(f,n),FWT_AND(f1,n),FWT_AND(g,n);
	for(int s=0;s<(1<<MAXN);++s)f[s]*=f1[s]*g[s];
	IFWT_AND(f,n);
	Mint ans=0;
	for(int i=0;i<MAXN;++i)ans+=f[1<<i];
	printf("%d\n",ans.x);
	return 0;
}