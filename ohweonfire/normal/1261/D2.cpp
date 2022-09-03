// This amazing code is by Eric Sunli Chen.
#include<bits/stdc++.h>
using namespace std;
template<typename T> bool get_int(T &x)
{
	char t=getchar();
	bool neg=false;
	x=0;
	for(; (t>'9'||t<'0')&&t!='-'&&t!=EOF; t=getchar());
	if(t=='-')neg=true,t=getchar();if(t==EOF)return false;
	for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
	if(neg)x=-x;return true;
}
template<typename T> void print_int(T x)
{
	if(x<0)putchar('-'),x=-x;
	short a[20]= {},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1; i>=0; i--)putchar('0'+a[i]);
}
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define get1(a) get_int(a)
#define get2(a,b) (get1(a)&&get1(b))
#define get3(a,b,c) (get1(a)&&get2(b,c))
#define printendl(a) print_int(a),puts("")
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

const double eps=1e-8;
const int poly_bits=20;
const int poly_max=1<<poly_bits;//poly_max=2^poly_bits
const int mod=998244353;//a prime in the form of k*poly_max+1 if NTT
const int root=3;//a primitive root of mod
#define COMB
int qpow(int x,int y,const int&mod=::mod){int ret=1;do{if(y&1)ret=(LL)ret*x%mod;x=(LL)x*x%mod;}while(y>>=1);return ret;}
inline int up_pw2(const int&x){int ret=1;while(ret<x)ret<<=1;return ret;}
int inv[poly_max+1],fac[poly_max+1],invf[poly_max+1],w[poly_max+1];

#ifdef COMB
	int comb(int x,int y){if(x<y||y<0)return 0;return (LL)fac[x]*invf[y]%mod*invf[x-y]%mod;}
#endif

int simplify(int*a,int n){while(n&&a[n-1]==0)n--;return n;}
inline void copy(int*a,int*b,int n,int m)
{
	if(n>=m)memcpy(b,a,sizeof(int)*m);
	else
	{
		memcpy(b,a,sizeof(int)*n);
		memset(b+n,0,sizeof(int)*(m-n));
	}
}

void prework()
{
	w[0]=1;w[1]=qpow(root,mod-1>>poly_bits);
	for(int i=2;i<=poly_max;i++)w[i]=(LL)w[i-1]*w[1]%mod;
#ifdef COMB
	fac[0]=inv[0]=invf[0]=1;
	for(int i=1;i<=poly_max;i++)
	{
		fac[i]=(LL)i*fac[i-1]%mod;
		inv[i]=qpow(i,mod-2);
		invf[i]=(LL)inv[i]*invf[i-1]%mod;
	}
#endif
}
void poly_dotmul(int*a,int*b,int*c,int n,int m){for(int i=0;i<n||i<m;i++)c[i]=(i<n&&i<m?(LL)a[i]*b[i]%mod:0);}
void poly_add(int*a,int*b,int*c,int n,int m){for(int i=0;i<n||i<m;i++){c[i]=(i<n?a[i]:0)+(i<m?b[i]:0);if(c[i]>=mod)c[i]-=mod;}}
void poly_sub(int*a,int*b,int*c,int n,int m){for(int i=0;i<n||i<m;i++){c[i]=(i<n?a[i]:0)-(i<m?b[i]:0);if(c[i]<0)c[i]+=mod;}}

inline void dft(int*a,int n,bool rev=0)
{
	for(int i=0,j=0;i<n;i++)
	{
		if(i<j)swap(a[i],a[j]);
		for(int t=n>>1;(j^=t)<t;t>>=1);
	}
	static int cw[poly_max];static uLL ca[poly_max];uLL md2=(LL)mod*mod;
	for(int i=0;i<n;i++)ca[i]=a[i];
	for(int l=1,d=poly_bits-1;l<n;l<<=1,d--)
	{
		int l2=l<<1;
		for(int j=0;j<l;j++)cw[j]=w[rev?poly_max-(j<<d):(j<<d)];
		for(int i=0;i<n;i+=l2)for(int j=0;j<l;j++)
		{
			uLL tmp=LL(ca[i|l|j]%mod)*cw[j];
			ca[i|l|j]=ca[i|j]-tmp+md2;
			ca[i|j]+=tmp;
		}
		if(l==(1<<16))for(int i=0;i<n;i++)ca[i]%=mod;
	}
	for(int i=0;i<n;i++)a[i]=ca[i]%mod;
	if(rev)
	{
		LL inv=qpow(n,mod-2);
		for(int i=0;i<n;i++)a[i]=a[i]*inv%mod;
	}
}

inline void poly_mult(int*a,int*b,int*c,int n,int m,int k=-1)
{
	static int tA[poly_max],tB[poly_max];
	if(k==-1)k=n+m-1;if(n>k)n=k;if(m>k)m=k;
	if(n<=50&&m<=50)
	{
		for(int i=0;i<k;i++)tA[i]=0;
		for(int i=0;i<n;i++)for(int j=0;j<m;j++)tA[i+j]=(tA[i+j]+(LL)a[i]*b[j])%mod;
		for(int i=0;i<k;i++)c[i]=tA[i];
		return;
	}
	int len=up_pw2(n+m-1);
	for(int i=0;i<len;i++)
	{
		tA[i]=i<n?a[i]:0;
		tB[i]=i<m?b[i]:0;
	}
	dft(tA,len);dft(tB,len);
	poly_dotmul(tA,tB,tA,len,len);
	dft(tA,len,1);
	for(int i=0;i<k;i++)c[i]=tA[i];
}

int n,k,h[poly_max];
int val[poly_max];

int main()
{
	prework();
	get2(n,k);
	if(k==1)
	{
		puts("0");
		return 0;
	}
	int cnt=0,ans=0;cnt=n;
	cnt=0;for(int i=1;i<=n;i++)get1(h[i]);h[n+1]=h[1];for(int i=1;i<=n;i++)if(h[i]!=h[i+1])cnt++;
	
	
	val[0]=1;val[1]=k-2;val[2]=1;
	int l=up_pw2(2*cnt+1);
	dft(val,l);
	for(int i=0;i<l;i++)val[i]=qpow(val[i],cnt);
	dft(val,l,1);
	for(int i=cnt+1;i<=2*cnt;i++)
	{
		ans+=val[i];
		if(ans>=mod)ans-=mod;
	}
//	printf("cnt= %d ans= %d\n",cnt,ans);
	ans=(LL)ans*qpow(k,n-cnt)%mod;
	printendl(ans);
	
	return 0;
}