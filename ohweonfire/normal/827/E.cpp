// This amazing code is by Eric Sunli Chen.
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;
template<typename T> void get_int(T &x)
{
	char t=getchar();
	bool neg=false;
	x=0;
	for(; (t>'9'||t<'0')&&t!='-'; t=getchar());
	if(t=='-')neg=true,t=getchar();
	for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
	if(neg)x=-x;
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
#define get2(a,b) get1(a),get1(b)
#define get3(a,b,c) get1(a),get2(b,c)
#define printendl(a) print_int(a),puts("")
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

struct FFTsolver
{
	struct cpx
	{
		double x,y;
		cpx(double _x=0,double _y=0){x=_x;y=_y;}
		cpx operator+(const cpx &t){return cpx(x+t.x,y+t.y);}
		cpx operator-(const cpx &t){return cpx(x-t.x,y-t.y);}
		cpx operator*(const cpx &t){return cpx(x*t.x-y*t.y,x*t.y+y*t.x);}
		cpx operator*(const double &t){return cpx(x*t,y*t);}
	};
	cpx w[1100111];
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
	cpx a[1100111],b[1100111],c[1100111];
	void mult(int _a[],int _b[],int _c[],int n,int m)
	{
		int l;
		for(l=1;l<n+m;l<<=1);
		for(int i=0;i<=l;i++)w[i]=cpx(cos(2.0/l*i*pi),sin(2.0/l*i*pi));
		for(int i=0;i<l;i++)a[i]=cpx(i<=n?_a[i]:0,0);
		for(int i=0;i<l;i++)b[i]=cpx(i<=m?_b[i]:0,0);
		for(int i=0;i<l;i++)_c[i]=0;
		fft(a,l,1);fft(b,l,1);
		for(int i=0;i<l;i++)c[i]=a[i]*b[i];
		fft(c,l,-1);
		for(int i=0;i<l;i++)_c[i]=(int)(c[i].x+0.5);
	}
}m1;

char s[500111];
bool have[500111],ok[500111];
int n,a[500111],b[500111],c[1000111];
void solve()
{
	scanf("%d%s",&n,s);
	
	for(int i=0;i<n;i++)if(s[i]=='V')a[i]=1;else if(s[i]=='K')b[n-1-i]=1;
	m1.mult(a,b,c,n,n);
	for(int i=0;i<n+n;i++)if(c[i])have[abs(i-n+1)]=1;
	for(int i=0;i<n;i++)a[i]=b[i]=0;
	
	for(int i=0;i<n;i++)if(s[i]=='V')a[n-i-1]=1;else if(s[i]=='K')b[i]=1;
	m1.mult(a,b,c,n,n);
	for(int i=0;i<n+n;i++)if(c[i])have[abs(i-n+1)]=1;
	for(int i=0;i<n;i++)a[i]=b[i]=0;
	
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		ok[i]=1;
		for(int j=i;j<=n;j+=i)
			ok[i]&=have[j]^1;
		if(ok[i])ans++;
	}
	for(int i=1;i<=n;i++)have[i]=0;
	
	printendl(ans);
	for(int i=1;i<=n;i++)if(ok[i])printf("%d ",i);
	puts("");
}

int main()
{
	int tc;get1(tc);
	while(tc--)solve();
	return 0;
}