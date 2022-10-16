#include <bits/stdc++.h>

using namespace std;

long long n,d,nn=0,a[200069],ps[200069],sk[200069];
double ttl=0,pc[200069],dp[200069],wg[200069];

bool cmp(double x,long long y,double x2,long long y2)
{
	return x/y>=x2/y2;
}

bool chk(long long x,long long y,long long y2)
{
	return cmp(wg[y2]-wg[x],ps[x]-ps[y2],wg[y]-wg[x],ps[x]-ps[y]);
}

double f(long long x,double w)
{
	return w*ps[x]+wg[x];
}

int main()
{
	long long i,j,p;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		ps[i]=ps[i-1]+a[i];
		pc[i]=pc[i-1]+(double)1/a[i];
		ttl+=(double)ps[i]/a[i];
	}
	for(i=2;i<=d;i++)
	{
		nn=1;
		p=1;
		for(j=1;j<=n;j++)
		{
			wg[j]=dp[j]-pc[j]*ps[j];
			for(;p<nn&&f(sk[p+1],pc[j])>=f(sk[p],pc[j]);p++);
			dp[j]=f(sk[p],pc[j]);
			for(;nn>=2&&chk(j,sk[nn],sk[nn-1]);nn--);
			p=min(p,nn);
			nn++;
			sk[nn]=j;
		}
	}
	printf("%.20lf\n",ttl-dp[n]);
}