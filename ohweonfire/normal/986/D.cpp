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

const double eps=1e-10;
const int poly_bits=21;
const int poly_max=1<<poly_bits;//poly_max=2^poly_bits
const int mod=998244353;//a prime in the form of k*poly_max+1 if NTT
const int root=3;//a primitive root of mod

int power(int x,int y,const int&mod=::mod){int ret=1;do{if(y&1)ret=1ll*ret*x%mod;x=1ll*x*x%mod;}while(y>>=1);return ret;}
int up_pw2(const int&x){int ret=1;while(ret<x)ret<<=1;return ret;}
int inv[poly_max+1],fac[poly_max+1],invf[poly_max+1];

//#define NTT
//#define COMB

#ifdef COMB
	int comb(int x,int y){if(x<y||y<0)return 0;return 1ll*fac[x]*invf[y]%mod*invf[x-y]%mod;}
#endif

#ifdef NTT
	#define type int
	int w[poly_max+1];
#else
	#define type cpx
	inline int dcmp(const double&x){if(fabs(x)<eps)return 0;else if(x<0)return -1;else return 1;}
	struct cpx
	{
		double x,y;
		cpx(double _x=0,double _y=0){x=_x;y=_y;}
		bool operator ==(const cpx&b)const{return dcmp(b.x-x)==0&&dcmp(b.y-y)==0;}
		cpx operator+(const cpx &t){return cpx(x+t.x,y+t.y);}
		cpx operator-(const cpx &t){return cpx(x-t.x,y-t.y);}
		cpx operator*(const cpx &t){return cpx(x*t.x-y*t.y,x*t.y+y*t.x);}
		cpx operator*(const double &t){return cpx(x*t,y*t);}
		cpx conj()const{return cpx(x,-y);}
		cpx inv()const{return cpx(x/(x*x+y*y),-y/(x*x+y*y));}
	};
	cpx w[poly_max+1];
#endif
template<typename tp>int simplify(tp*a,int n){while(n&&a[n-1]==tp(0))n--;return n;}
template<typename tp>void copy(tp*a,tp*b,int n,int m){for(int i=0;i<m;i++)b[i]=(i<n?a[i]:tp(0));}

void prework()
{
#ifdef NTT
	w[0]=1;w[1]=power(root,mod-1>>poly_bits);
	for(int i=2;i<=poly_max;i++)w[i]=1ll*w[i-1]*w[1]%mod;
#else
	for(int i=0;i<=poly_max;i++)w[i]=cpx(cos(2*pi/poly_max*i),sin(2*pi/poly_max*i));
#endif
#ifdef COMB
	fac[0]=inv[0]=invf[0]=1;
	for(int i=1;i<poly_max;i++)
	{
		fac[i]=1ll*i*fac[i-1]%mod;
		inv[i]=power(i,mod-2);
		invf[i]=1ll*i*invf[i-1]%mod;
	}
#endif
}

void poly_dotmul(int*a,int*b,int*c,int n,int m){for(int i=0;i<n||i<m;i++)c[i]=(i<n&&i<m?1ll*a[i]*b[i]%mod:0);}
#ifndef NTT
void poly_dotmul(cpx*a,cpx*b,cpx*c,int n,int m){for(int i=0;i<n||i<m;i++)c[i]=(i<n&&i<m?a[i]*b[i]:cpx(0));}
#endif

void poly_add(int*a,int*b,int*c,int n,int m){for(int i=0;i<n||i<m;i++){c[i]=(i<n?a[i]:0)+(i<m?b[i]:0);if(c[i]>=mod)c[i]-=mod;}}
#ifndef NTT
void poly_add(cpx*a,cpx*b,cpx*c,int n,int m){for(int i=0;i<n||i<m;i++){c[i]=(i<n?a[i]:cpx(0))+(i<m?b[i]:cpx(0));}}
#endif
void poly_sub(int*a,int*b,int*c,int n,int m){for(int i=0;i<n||i<m;i++){c[i]=(i<n?a[i]:0)-(i<m?b[i]:0);if(c[i]<0)c[i]+=mod;}}
#ifndef NTT
void poly_sub(cpx*a,cpx*b,cpx*c,int n,int m){for(int i=0;i<n||i<m;i++){c[i]=(i<n?a[i]:cpx(0))-(i<m?b[i]:cpx(0));}}
#endif

void dft(type*a,int n)
{
	for(int i=0,j=0;i<n;i++){if(i<j)swap(a[i],a[j]);for(int t=n>>1;(j^=t)<t;t>>=1);}
	for(int l=1,d=1;l<n;l<<=1,d++)
	{
		int l2=l<<1;
		for(int i=0;i<n;i+=l2)for(int j=0;j<l;j++)
		{
#ifdef NTT
			int tmp=1ll*a[i|l|j]*w[j<<poly_bits-d]%mod;
			a[i|l|j]=a[i|j]-tmp+mod;if(a[i|l|j]>=mod)a[i|l|j]-=mod;
			a[i|j]+=tmp;if(a[i|j]>=mod)a[i|j]-=mod;
#else
			cpx tmp=a[i|l|j]*w[j<<poly_bits-d];
			a[i|l|j]=a[i|j]-tmp;
			a[i|j]=a[i|j]+tmp;
#endif
		}
	}
}
void idft(type*a,int n)
{
	for(int i=0,j=0;i<n;i++){if(i<j)swap(a[i],a[j]);for(int t=n>>1;(j^=t)<t;t>>=1);}
	for(int l=1,d=1;l<n;l<<=1,d++)
	{
		int l2=l<<1;
		for(int i=0;i<n;i+=l2)for(int j=0;j<l;j++)
		{
#ifdef NTT
			int tmp=1ll*a[i|l|j]*w[poly_max-(j<<poly_bits-d)]%mod;
			a[i|l|j]=a[i|j]-tmp+mod;if(a[i|l|j]>=mod)a[i|l|j]-=mod;
			a[i|j]+=tmp;if(a[i|j]>=mod)a[i|j]-=mod;
#else
			cpx tmp=a[i|l|j]*w[poly_max-(j<<poly_bits-d)];
			a[i|l|j]=a[i|j]-tmp;
			a[i|j]=a[i|j]+tmp;
#endif
		}
	}
#ifdef NTT
	int inv=power(n,mod-2);for(int i=0;i<n;i++)a[i]=1ll*a[i]*inv%mod;
#else
	for(int i=0;i<n;i++)a[i]=a[i]*cpx(1.0/n);
#endif
}

type tA[poly_max],tB[poly_max];
void poly_mult(LL*a,LL*b,LL*c,int n,int m)
{
	int len=up_pw2(n+m-1);
	for(int i=0;i<len;i++)
	{
		tA[i]=cpx(i<n?a[i]:0);
		tB[i]=cpx(i<m?b[i]:0);
	}
	dft(tA,len);dft(tB,len);
	poly_dotmul(tA,tB,tA,len,len);
	idft(tA,len);
	for(int i=0;i<n+m-1;i++)c[i]=(LL)(tA[i].x+0.5);
}

int go(int*a,int n)
{
	for(int i=0;i<n;i++)
	{
		a[i+1]+=a[i]/10;
		a[i]%=10;
	}
	while(n&&a[n])
	{
		a[n+1]+=a[n]/10;
		a[n]%=10;
		n++;
	}
	return n;
}
int go(LL*a,int n)
{
	for(int i=0;i<n;i++)
	{
		a[i+1]+=a[i]/1000;
		a[i]%=1000;
	}
	while(n&&a[n])
	{
		a[n+1]+=a[n]/1000;
		a[n]%=1000;
		n++;
	}
	return n;
}
LL ta[poly_max],tb[poly_max];
int la,lb;
void mult(int t)
{
	ta[0]=1;tb[0]=3;
	la=lb=1;
	while(t)
	{
		if(t&1)
		{
			poly_mult(ta,tb,ta,la,lb);
			la=go(ta,la);
		}
		if(t>1)
		{
			poly_mult(tb,tb,tb,lb,lb);
			lb=go(tb,lb);
		}
		t>>=1;
	}
}

int n,t,a[poly_max],b[poly_max];
char s[poly_max];

void db()
{
	for(int i=0;i<la;i++)ta[i]<<=1;
	la=go(ta,la);
}
int calc()
{
	memset(b,0,sizeof(b));
	for(int i=0;i<la;i++)
	{
		b[i*3]=ta[i]%10;
		b[i*3+1]=ta[i]/10%10;
		b[i*3+2]=ta[i]/100;
	}
	int ret=0;
	while(true)
	{
		bool ok=1;
		for(int i=n;i>=0;i--)if(a[i]!=b[i])
		{
			ok=(a[i]<b[i]);
			break;
		}
		if(ok)return ret;
		ret+=3;
		for(int i=0;i<=n;i++)b[i]*=3;
		go(b,n);
	}
}

int main()
{
	prework();
	scanf("%s",s);
	n=strlen(s);
	if(n==1&&s[0]=='1')
	{
		puts("1");
		return 0;
	}
	
	for(int i=0;i<n;i++)a[n-i-1]=s[i]-'0';
	if(n<=2)t=0;else t=(int)(log(10)/log(3)*(n-2));
	mult(t);
	
	int ans=calc();
	db();ans=min(ans,calc()+2);
	db();ans=min(ans,calc()+4);
	printf("%d\n",ans+t*3);
	
	return 0;
}