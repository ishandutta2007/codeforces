

#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
typedef long long ll;
typedef std::pair<int,int> pii;
ll read()
{
	ll f=1,x=0;int c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return f*x;
}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
ll abs(ll x){return x>0?x:-x;}
template<typename T> inline bool umin(T& a,T t){if(t<a)return a=t,1;return 0;}
template<typename T> inline bool umax(T& a,T t){if(t>a)return a=t,1;return 0;}
/**********/
const int mod = 998244353;
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
	Mint(ll y){x=(0<=y&&y<mod?y:(y%mod+mod)%mod);}
	void operator+= (Mint a){x+=a.x;if(x>=mod)x-=mod;}
	void operator-= (Mint a){x-=a.x;if(x<0)x+=mod;}
	void operator*= (Mint a){x=ll(x)*a.x%mod;}
	Mint operator- (){return x?mod-x:0;}
	Mint operator++ (){return x+1==mod?0:x+1;}
};
Mint operator+ (Mint a,Mint b){int t=a.x+b.x;return t<mod?t:t-mod;}
Mint operator- (Mint a,Mint b){int t=a.x-b.x;return t>=0?t:t+mod;}
Mint operator* (Mint a,Mint b){return ll(a.x)*b.x%mod;}

const int MAXN = 525011;
Mint RT[MAXN];
Mint inv[MAXN],fac[MAXN],Ifac[MAXN];
void poly_init(int n)
{
	int len=1;
	while(len<=n)len<<=1;
	for(int i=1;i<len;i<<=1)
	{
		Mint R=Qpow(3,(mod-1)/(i<<1));
		RT[i]=1;
		for(int j=1;j<i;++j)RT[i+j]=RT[i+j-1]*R;
	}
	inv[1]=1;
	for(int i=2;i<=len;++i)inv[i]=Mint(mod-mod/i)*inv[mod%i];

	fac[0]=1;
	for(int i=1;i<=len;++i)fac[i]=fac[i-1]*i;
	Ifac[0]=1;
	for(int i=1;i<=len;++i)Ifac[i]=Ifac[i-1]*inv[i];
}
int status[MAXN];
void DFT(Mint* a,int len)
{
	for(int i=0;i<len;++i)
		if(status[i]>i)std::swap(a[i],a[status[i]]);
	for(int cur=1;cur<len;cur<<=1)
		for(int j=0;j<len;j+=cur<<1)
			for(int k=0;k<cur;++k)
			{
				Mint x=a[j+k],y=RT[cur+k]*a[j+cur+k];
				a[j+k]=x+y,a[j+cur+k]=x-y;
			}
}
void IDFT(Mint* a,int len)
{
	std::reverse(a+1,a+len);
	DFT(a,len);
	for(int i=0;i<len;++i)a[i]*=inv[len];
}

void Mul(const Mint* const f,const Mint* const g,Mint* res,int n)
{
	static Mint tf[MAXN],tg[MAXN];
	for(int i=0;i<=n;++i)tf[i]=f[i],tg[i]=g[i];
	int len=1;
	while(len<=n)len<<=1;
	for(int i=0;i<len;++i)
		status[i]=(status[i>>1]>>1)|(i&1?len>>1:0);
	DFT(tf,len),DFT(tg,len);
	for(int i=0;i<len;++i)tf[i]=tf[i]*tg[i];
	IDFT(tf,len);
	for(int i=0;i<=n;++i)res[i]=tf[i];
}
Mint f[MAXN],pre[MAXN],res[MAXN],g[MAXN],h[MAXN];
Mint C(int n,int m){return n>=0&&m>=0&&n>=m?fac[n]*Ifac[m]*Ifac[n-m]:0;}
int main()
{
	int n=read(),lim=(n+1)>>1;
	poly_init(n+n);
	for(int u=2;u<=n;++u)f[u]=fac[n-u]*fac[u-2]*C(lim-1,u-1)*(u-1);
	f[1]=fac[n-1];
	Mint dec=0;
	for(int u=n;u;--u)
	{
		res[u]=f[u]-dec;
		dec+=f[u]*inv[u-1];
	}
	for(int u=1;u<=n;++u)printf("%d ",res[u].x);
	puts("");
	return 0;
}