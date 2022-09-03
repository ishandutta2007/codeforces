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

struct cpx
{
	double x,y;
	cpx(double _x=0,double _y=0){x=_x;y=_y;}
	cpx operator+(const cpx &t){return cpx(x+t.x,y+t.y);}
	cpx operator-(const cpx &t){return cpx(x-t.x,y-t.y);}
	cpx operator*(const cpx &t){return cpx(x*t.x-y*t.y,x*t.y+y*t.x);}
	cpx operator*(const double &t){return cpx(x*t,y*t);}
};
struct FFTsolver
{
	cpx w[600111];
	void fft(cpx a[],int n,int f)
	{
		for(int i=0,j=0;i<n;i++)
		{
			if(i<j)swap(a[i],a[j]);
			for(int t=n>>1;(j^=t)<t;t>>=1);
		}
		for(int l=1;l<n;l<<=1)
		{
			int l2=l<<1;
			for(int i=0;i<n;i+=l2)
			{
				for(int j=0;j<l;j++)
				{
					cpx tmp=a[i+l+j]*(f==1?w[n/l2*j]:w[n-n/l2*j]);
					a[i+l+j]=a[i+j]-tmp;
					a[i+j]=a[i+j]+tmp;
				}
			}
		}
		if(f==-1)
			for(int i=0;i<n;i++)a[i]=a[i]*(1.0/n);
	}
	cpx a[600111],b[600111],c[600111];
	void mult(LL _a[],LL _b[],LL _c[],int n,int m)
	{
		int l;
		for(l=1;l<n+m;l<<=1);
		for(int i=0;i<=l;i++)w[i]=cpx(cos(2.0/l*i*pi),sin(2.0/l*i*pi));
		for(int i=0;i<l;i++)a[i]=cpx(i>=n?0:_a[i],0);
		for(int i=0;i<l;i++)b[i]=cpx(i>=m?0:_b[i],0);
		for(int i=0;i<l;i++)_c[i]=0;
		fft(a,l,1);fft(b,l,1);
		for(int i=0;i<l;i++)c[i]=a[i]*b[i];
		fft(c,l,-1);
		for(int i=0;i<l;i++)_c[i]=(LL)(c[i].x+0.5);
	}
}solver;
int n,x,pre[200111];
LL ans[600111],sum[200111],rsum[200111];
int main()
{
	get2(n,x);
	
	sum[0]++;
	rsum[n]++;
	for(int i=1,v;i<=n;i++)
	{
		get1(v);
		pre[i]=pre[i-1]+(v<x);
		sum[pre[i]]++;
		rsum[n-pre[i]]++;
	}
	solver.mult(sum,rsum,ans,n+1,n+1);
	LL ans1=0;
	for(int i=0,nxt=0;i<=n;i=nxt)
	{
		for(;nxt<=n&&pre[i]==pre[nxt];nxt++);
		ans1+=1ll*(nxt-i)*(nxt-i-1)/2;
	}
	printf("%I64d ",ans1);
	for(int i=n+1;i<=n+n;i++)printf("%I64d ",ans[i]);
	return 0;
}