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
const int poly_bits=18;
const int poly_max=1<<poly_bits;//poly_max=2^poly_bits

int up_pw2(const int&x){int ret=1;while(ret<x)ret<<=1;return ret;}
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
inline void dft(cpx*a,int n,bool rev=0)
{
	for(int i=0,j=0;i<n;i++)
	{
		if(i<j)swap(a[i],a[j]);
		for(int t=n>>1;(j^=t)<t;t>>=1);
	}
	for(int l=1,d=poly_bits-1;l<n;l<<=1,d--)
	{
		int l2=l<<1;
		static cpx cw[poly_max];
		for(int j=0;j<l;j++)cw[j]=w[rev?poly_max-(j<<d):(j<<d)];
		for(int i=0;i<n;i+=l2)for(int j=0;j<l;j++)
		{
			cpx tmp=a[i|l|j]*cw[j];
			a[i|l|j]=a[i|j]-tmp;
			a[i|j]=a[i|j]+tmp;
		}
	}
	if(rev)for(int i=0;i<n;i++)a[i]=a[i]*(1.0/n);
}

cpx tA[poly_max],tB[poly_max];
double tC[poly_max];
void poly_mult(double*a,int n,double*b,int m,double*c,int k=-1)
{
	if(k==-1)k=n+m-1;if(n>k)n=k;if(m>k)m=k;
	if(n<=50&&m<=50)
	{
		memset(tC,0,sizeof(double)*k);
		for(int i=0;i<n;i++)for(int j=0;j<m&&j<k-i;j++)tC[i+j]+=a[i]*b[j];
		for(int i=0;i<k;i++)c[i]=tC[i];
		return;
	}
	int l=up_pw2(n+m-1);
	for(int i=0;i<l;i++)tA[i]=cpx(i<n?a[i]:0,0);
	for(int i=0;i<l;i++)tB[i]=cpx(i<m?b[i]:0,0);
	dft(tA,l);dft(tB,l);
	for(int i=0;i<l;i++)tA[i]=tA[i]*tB[i];
	dft(tA,l,1);
	for(int i=0;i<k;i++)c[i]=(i<l?tA[i].x:0);
}

struct init_t
{
	init_t()
	{
		for(int i=0;i<=poly_max;i++)w[i]=cpx(cos(2*pi/poly_max*i),sin(2*pi/poly_max*i));
	}
} initializer;

int n,m,t,x,a[111],b[111],c[111],mnv[55];

double p[111][20111],f[55][20111],g[111][20111],sum[111][20111],tmp[20111];

int main()
{
	get2(n,m);get2(t,x);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",a+i,b+i,c+i);
		for(int j=1;j<=t;j++)
		{
			scanf("%lf",p[i]+j);
			p[i][j]/=100000;
			sum[i][j]=p[i][j];
		}
		for(int j=t-1;j>=0;j--)sum[i][j]+=sum[i][j+1];
	}
	
	for(int i=1;i<n;i++)mnv[i]=inf;
	for(int tt=1;tt<=n;tt++)for(int e=1;e<=m;e++)mnv[a[e]]=min(mnv[a[e]],mnv[b[e]]+c[e]);
	
	t++;
	for(int i=1;i<n;i++)for(int j=0;j<t;j++)f[i][j]=1e10;
	for(int i=1;i<n;i++)f[i][0]=mnv[i]+x;
	
	for(int i=0;i<t;i++)
	{
		for(int j=1;j<=m;j++)
		{
			g[j][i]+=c[j]+sum[j][i+1]*(x+mnv[b[j]]);
			f[a[j]][i]=min(f[a[j]][i],g[j][i]);
		}
//		for(int j=1;j<=n;j++)printf("i= %d j= %d t= %.10lf\n",i,j,f[j][i]);
		if(i==t-1)break;
		int len=(i+1)&(-i-1),l=i-len+1,r=i,ll=i+1,rr=min(t-1,i+len),tl=1,tr=min(rr-l,t-1);
//		printf("i= %d l= %d r= %d ll= %d rr= %d\n",i,l,r,ll,rr);
		for(int j=1;j<=m;j++)
		{
//			for(int k1=l;k1<=r;k1++)for(int k2=ll;k2<=rr;k2++)if(k1-k2<t)g[j][k2]+=f[b[j]][k1]*p[j][k2-k1];
			poly_mult(f[b[j]]+l,r-l+1,p[j]+tl,tr-tl+1,tmp);
			for(int k=ll;k<=rr;k++)g[j][k]+=tmp[k-ll+r-l];
		}
	}
	printf("%.10lf\n",f[1][t-1]);
	return 0;
}