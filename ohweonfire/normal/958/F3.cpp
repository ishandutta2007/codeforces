//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define bged(v) (v).begin(),(v).end()
#define foreach(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
typedef long long ll;
const int Imx=2147483647;
const ll Lbig=2e18;
const int mod=1009;
//My i/o stream
struct fastio
{
	char s[100000];
	int it,len;
	fastio(){it=len=0;}
	inline char get()
	{
		if(it<len)return s[it++];it=0;
		len=fread(s,1,100000,stdin);
		if(len==0)return EOF;else return s[it++];
	}
	bool notend()
	{
		char c=get();
		while(c==' '||c=='\n')c=get();
		if(it>0)it--;
		return c!=EOF;
	}
}_buff;
#define geti(x) x=getnum()
#define getii(x,y) geti(x),geti(y)
#define getiii(x,y,z) getii(x,y),geti(z)
#define puti(x) putnum(x),putchar(' ')
#define putii(x,y) puti(x),puti(y)
#define putiii(x,y,z) putii(x,y),puti(z)
#define putsi(x) putnum(x),putchar('\n')
#define putsii(x,y) puti(x),putsi(y)
#define putsiii(x,y,z) putii(x,y),putsi(z)
inline ll getnum()
{
	ll r=0;bool ng=0;char c;c=_buff.get();
	while(c!='-'&&(c<'0'||c>'9'))c=_buff.get();
	if(c=='-')ng=1,c=_buff.get();
	while(c>='0'&&c<='9')r=r*10+c-'0',c=_buff.get();
	return ng?-r:r;
}
template<class T> inline void putnum(T x)
{
	if(x<0)putchar('-'),x=-x;
	register short a[20]={},sz=0;
	while(x)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1;i>=0;i--)putchar('0'+a[i]);
}
inline char getreal(){char c=_buff.get();while(c<=32)c=_buff.get();return c;}
ll qpow(ll x,ll k){return k==0?1:1ll*qpow(1ll*x*x%mod,k>>1)*(k&1?x:1)%mod;}

//-----FFT head-----
const double pi=acos(-1);
struct point
{
	double x,y;
	point(double _x=0,double _y=0){x=_x;y=_y;}
	point operator+(const point &t)const{return point(x+t.x,y+t.y);}
	point operator-(const point &t)const{return point(x-t.x,y-t.y);}
	point operator*(const point &t)const{return point(x*t.x-y*t.y,x*t.y+y*t.x);}
	point conj()const{return point(x,-y);}
};
const int FFTmx=400111;
const int FFTbitn=18;
const int FFTpmx=1<<FFTbitn;
const int FFTbit=15;//max_value<=2^(2*FFTbit)
int FFTsz,pbitrev[FFTmx],bitrev[FFTmx];
point _prew[FFTmx],_w[FFTmx];
void FFTprecalc()
{
	for(int i=0;i<=FFTpmx;i++)_prew[i]=point(cos(2.0/FFTpmx*i*pi),sin(2.0/FFTpmx*i*pi));
	for(int i=0,j=0;i<=FFTpmx;i++)
	{
		pbitrev[i]=j;
		for(int t=FFTpmx>>1;(j^=t)<t;t>>=1);
	}
}
void FFTinit(int n)
{
	FFTsz=1;
	while(FFTsz<n)FFTsz<<=1;
	int tmp=__builtin_ctz(FFTpmx/FFTsz);
	for(int i=0;i<FFTsz;i++)bitrev[i]=pbitrev[i]>>tmp;
}
void FFT(point a[],int coef)
{
	for(int i=0,j=0;i<FFTsz;i++)if(i<bitrev[i])swap(a[i],a[bitrev[i]]);
	for(int l=1,k=1;l<FFTsz;l<<=1,k++)
	{
		if(coef==1)for(int i=0;i<l;i++)_w[i]=_prew[(FFTpmx>>k)*i];
		else for(int i=0;i<l;i++)_w[i]=_prew[FFTpmx-(FFTpmx>>k)*i];
		for(int i=0;i<FFTsz;i+=l+l)
		{
			for(int j=0;j<l;j++)
			{
				point tmp=a[i+l+j]*_w[j];
				a[i+l+j]=a[i+j]-tmp;
				a[i+j]=a[i+j]+tmp;
			}
		}
	}
	if(coef==-1)
	{
		for(int i=0;i<FFTsz;i++)a[i]=a[i]*(1.0/FFTsz);
	}
}
void polymul(int a[],int asz,int b[],int bsz,int c[],int csz=-1)
{
	static point _tl[FFTmx],_tr[FFTmx],_ta[FFTmx],_tb[FFTmx];
	if(csz==-1)csz=asz+bsz;
	for(int i=0;i<asz;i++)a[i]=a[i]<0?a[i]+mod:a[i];
	for(int i=0;i<bsz;i++)b[i]=b[i]<0?b[i]+mod:b[i];
	FFTinit(asz+bsz);
	int msk=(1<<FFTbit)-1;
	for(int i=0;i<FFTsz;i++)
	{
		_ta[i]=i<asz?point(a[i]&msk,a[i]>>FFTbit):0;
		_tb[i]=i<bsz?point(b[i]&msk,b[i]>>FFTbit):0;
	}
	FFT(_ta,1);_ta[FFTsz]=_ta[0];
	FFT(_tb,1);_tb[FFTsz]=_tb[0];
	for(int i=0;i<FFTsz;i++)
	{
		point a0=(_ta[i]+_ta[FFTsz-i].conj())*point(+0.5,0),a1=(_ta[i]-_ta[FFTsz-i].conj())*point(0,-0.5);
		point b0=(_tb[i]+_tb[FFTsz-i].conj())*point(+0.5,0),b1=(_tb[i]-_tb[FFTsz-i].conj())*point(0,-0.5);
		_tl[i]=a0*b0+a0*b1*point(0,1);
		_tr[i]=a1*b0+a1*b1*point(0,1);
	}
	FFT(_tl,-1);
	FFT(_tr,-1);
	for(int i=0;i<FFTsz;i++)
	{
		c[i]=(ll(_tl[i].x+0.5)+
		    ((ll(_tr[i].y+0.5)%mod)<<FFTbit+FFTbit)+
	       (((ll(_tl[i].y+0.5)+ll(_tr[i].x+0.5))%mod)<<FFTbit))%mod;
	}
}

void mul(vector<int> &a,int an,vector<int> &b,int bn)
{
	static int vma[FFTmx],vmb[FFTmx];
	for(int i=0;i<=an;i++)vma[i]=a[i];
	for(int i=0;i<=bn;i++)vmb[i]=b[i];
	polymul(vma,an+1,vmb,bn+1,vma);
	a.clear();
	for(int i=0;i<=an+bn;i++)a.PB(vma[i]);
}
int n,m,k;
int a[FFTmx];
int id[FFTmx];
vector<int> v[200111];

int main()
{
	getiii(n,m,k);
	FFTprecalc();
	set<pair<int,int> > st;
	for(int i=1;i<=n;i++)
	{
		int x;
		geti(x);
		a[x]++;
	}
	for(int i=1;i<=m;i++)
	{
		if(a[i]>0)
		{
			st.insert(MP(a[i],i));
			id[i]=i;
			for(int j=0;j<=a[i];j++)v[i].PB(1);
		}
	}
	while(st.size()>1)
	{
		int x=st.begin()->SS;
		st.erase(st.begin());
		int y=st.begin()->SS;
		st.erase(st.begin());
//		cerr<<x<<","<<y<<endl;
		id[y]=id[x];
		mul(v[x],a[x],v[y],a[y]);
		a[x]+=a[y];
		st.insert(MP(a[x],x));
	}
	int last=st.begin()->SS;
	cout<<(v[id[last]][k]%mod+mod)%mod;
	return 0;
}