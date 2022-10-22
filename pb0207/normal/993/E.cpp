#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<complex>
#include<cmath>
using namespace std;

typedef complex<double> cb;

const int N=2e5+1e3+7;

const double pi=acos(-1);

int n,x,a[N],sum[N];

struct POLY{

	int n,m,rev[N*4+1];

	cb A[N*4+1],B[N*4+1];

	void init(int x)
	{
		for(n=1,m=0;n<=x;n<<=1,m++);
		for(int i=0;i<n;i++)
			rev[i]=rev[i>>1]>>1|(i&1)<<(m-1);
	}

	void FFT(complex<double>*a,int f)
	{
		for(int i=0;i<n;i++)
			if(i>rev[i])
				swap(a[i],a[rev[i]]);
		for(int i=1;i<n;i<<=1)
		{
			cb wn(cos(pi/i),f*sin(pi/i));
			for(int j=0;j<n;j+=i<<1)
			{
				cb w(1,0);
				for(int k=0;k<i;k++,w*=wn)
				{
					cb x=a[j+k],y=a[j+k+i]*w;
					a[j+k]=x+y;
					a[j+k+i]=x-y;
				}
			}
		}
		if(f==-1)
		{
			for(int i=0;i<n;i++)
				a[i]/=n;
		}
	}
}p;

long long ans[N];

int main()
{
	scanf("%d%d",&n,&x);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+(a[i]<x);
	for(int i=0;i<=n;i++)
		p.A[sum[i]].real()++,p.B[n-sum[i]].real()++;
	p.init(n*2);
	p.FFT(p.A,1);p.FFT(p.B,1);
	for(int i=0;i<p.n;i++)
		p.A[i]*=p.B[i];
	p.FFT(p.A,-1);
	for(int i=n;i<=n*2;i++)
		ans[i-n]=(long long)(p.A[i].real()+0.5);
	ans[0]=(ans[0]-n)>>1;
	for(int i=0;i<=n;i++)
		printf("%lld ",ans[i]);
}