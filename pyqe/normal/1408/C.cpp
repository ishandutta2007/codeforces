#include <bits/stdc++.h>

using namespace std;

long long n,d,a[100069];

int main()
{
	long long t,rr,i,ii,u,k,p[2],c,e;
	double w[2],sm[2],z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		a[n+1]=d;
		p[0]=0;
		p[1]=n+1;
		for(ii=0;ii<2;ii++)
		{
			sm[ii]=0;
		}
		for(;p[0]+1<p[1];)
		{
			for(ii=0;ii<2;ii++)
			{
				u=!ii*2-1;
				c=p[ii]*u+(n+1)*ii+1;
				w[ii]=sm[ii]+(double)abs(a[p[ii]+u]-a[p[ii]])/c;
			}
			e=w[1]<w[0];
			u=!e*2-1;
			p[e]+=u;
			sm[e]=w[e];
		}
		k=a[p[1]]-a[p[0]];
		p[1]=n+1-p[1];
		if(sm[1]<sm[0])
		{
			swap(p[0],p[1]);
			swap(sm[0],sm[1]);
		}
		z=sm[1]+((double)k-(sm[1]-sm[0])*(p[0]+1))/(p[0]+p[1]+2);
		printf("%.20lf\n",z);
	}
}