#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
typedef long long ll;
typedef unsigned un;
typedef std::pair<int,int> pii;
ll read(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
int min(int a,int b){return a<b?a:b;}
void umax(int& a,int t){if(a<t)a=t;}
bool umin(ll& a,ll t){if(a>t)return a=t,1;return 0;}
/**********/
constexpr int MAXN = 265011, mod=998244353,inv2=(mod+1)>>1;
ll Qpow(ll a,ll p)
{
	ll res=1;
	while(p){if(p&1)res=res*a%mod;a=a*a%mod,p>>=1;}
	return res;
}
inline int S(int x){return x<mod?x:x-mod;}
ll RT[MAXN],inv_len[MAXN];
int poly_init(int n)
{
	int len=1;
	while(len<=n+n+2)len<<=1;
	for(int i=1;i<len;i<<=1)
	{
		ll R=Qpow(3,(mod-1)/(i<<1));
		RT[i]=1;
		for(int j=1;j<i;++j)RT[i+j]=RT[i+j-1]*R%mod;
		inv_len[i]=Qpow(i,mod-2);
	}
	inv_len[len]=Qpow(len,mod-2);
	return len>>1;
}
int status[MAXN];
void DFT(int* a,int len)
{
	for(int i=0;i<len;++i)
		if(status[i]>i)std::swap(a[i],a[status[i]]);
	for(int cur=1;cur<len;cur<<=1)
		for(int j=0;j<len;j+=cur<<1)
			for(int k=0;k<cur;++k)
			{
				int x=a[j+k],y=a[j+cur+k]*RT[cur+k]%mod;
				a[j+k]=S(x+y),a[j+cur+k]=S(x-y+mod);
			}
}
void poly_inv(int* f,int* g,int n)
{
	//printf("Inv:");
	//for(int i=0;i<n;++i)printf("%d ",g[i]);
	//puts("");
	static int inv_tg[MAXN];
	for(int i=0;i<n;++i)f[i]=0;
	f[0]=Qpow(g[0],mod-2);
	for(int sl=2,len=4;sl<=n;sl<<=1,len<<=1)
	{
		//printf("Inv %d:\n",sl);
		for(int i=0;i<len;++i)
			status[i]=(status[i>>1]>>1)|((i&1)?sl:0);
		for(int i=0;i<sl;++i)inv_tg[i]=g[i];
		//for(int i=0;i<len;++i)printf("%d ",f[i]);puts("");
		//for(int i=0;i<len;++i)printf("%d ",inv_tg[i]);puts("");
		DFT(f,len),DFT(inv_tg,len);
		for(int i=0;i<len;++i)f[i]=(2*f[i]%mod-ll(inv_tg[i])*f[i]%mod*f[i]%mod+mod)%mod;
		std::reverse(f+1,f+len);
		DFT(f,len);
		//for(int i=0;i<len;++i)printf("%d ",int(ll(f[i])*inv_len[len]%mod));puts("");
		for(int i=0;i<sl;++i)f[i]=ll(f[i])*inv_len[len]%mod;//,printf("%d ",f[i]);
		//puts("");
		for(int i=sl;i<len;++i)f[i]=0,inv_tg[i]=0;
	}
	for(int i=0;i<(n<<1);++i)inv_tg[i]=0;
	//printf("res=");
	//for(int i=0;i<n;++i)printf("%d ",f[i]);
	//puts("");
}
void poly_sqrt(int* f,int* g,int n)
{
	//printf("SQRT :");
	//for(int i=0;i<n;++i)printf("%d ",g[i]);
	//puts("");
	static int sq_tf[MAXN],sq_tg[MAXN];
	for(int i=0;i<n;++i)f[i]=0;
	f[0]=1;
	for(int sl=2,len=4;sl<=n;sl<<=1,len<<=1)
	{
		poly_inv(sq_tf,f,sl);
		for(int i=0;i<len;++i)
			status[i]=(status[i>>1]>>1)|((i&1)?sl:0);
		for(int i=0;i<sl;++i)sq_tg[i]=g[i];
		//for(int i=0;i<len;++i)printf("%d ",f[i]);puts("");
		//for(int i=0;i<len;++i)printf("%d ",sq_tg[i]);puts("");
		//for(int i=0;i<len;++i)printf("%d ",sq_tf[i]);puts("");
		DFT(sq_tf,len),DFT(sq_tg,len);
		for(int i=0;i<len;++i)sq_tf[i]=ll(sq_tf[i])*sq_tg[i]%mod;
		std::reverse(sq_tf+1,sq_tf+len);
		DFT(sq_tf,len);
		//printf("res=");
		for(int i=0;i<sl;++i)f[i]=(f[i]+sq_tf[i]*inv_len[len])%mod*inv2%mod;//,printf("%d ",f[i]);puts("");
		for(int i=sl;i<len;++i)f[i]=0,sq_tf[i]=sq_tg[i]=0;
	}
	//puts("Finalres:");
	//for(int i=0;i<n;++i)printf("%d ",f[i]);
	//puts("");
}
void poly_mul(int* f,int* g,int len)
{
	puts("MUL::");
	for(int i=0;i<len;++i)printf("%d ",f[i]);puts("");
	for(int i=0;i<len;++i)printf("%d ",g[i]);puts("");
	static int tg[MAXN];
	len<<=1;
	for(int i=0;i<len;++i)
		status[i]=(status[i>>1]>>1)|((i&1)?len>>1:0);
	for(int i=0;i<len;++i)tg[i]=g[i];
	DFT(f,len),DFT(tg,len);
	for(int i=0;i<len;++i)f[i]=ll(f[i])*tg[i]%mod;
	std::reverse(f+1,f+len+1);
	DFT(f,len);
	for(int i=0;i<len;++i)f[i]=ll(f[i])*inv_len[len]%mod;
}
int f[MAXN],g[MAXN],h[MAXN];
int main()
{
	int n=read(),m=read();
	int len=poly_init(m);
	while(n--)f[read()]=1;
	for(int i=0;i<len;++i)
		if(f[i])f[i]=mod-4;
	f[0]=1;
	poly_sqrt(g,f,len);
	g[0]=(g[0]+1)%mod;
	poly_inv(h,g,len);
	for(int i=1;i<=m;++i)printf("%d\n",(h[i]*2)%mod);
	return 0;
}