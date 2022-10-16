#include <bits/stdc++.h>

using namespace std;

long long n,nn[2],a[2][100069];

int main()
{
	long long t,rr,i,ii,y,x,e;
	double z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(ii=0;ii<2;ii++)
		{
			nn[ii]=0;
		}
		for(i=1;i<=n*2;i++)
		{
			scanf("%lld%lld",&y,&x);
			e=0;
			if(!y)
			{
				e=1;
				swap(y,x);
			}
			nn[e]++;
			a[e][nn[e]]=abs(y);
		}
		for(ii=0;ii<2;ii++)
		{
			sort(a[ii]+1,a[ii]+n+1);
		}
		z=0;
		for(i=1;i<=n;i++)
		{
			z+=sqrt(a[0][i]*a[0][i]+a[1][i]*a[1][i]);
		}
		printf("%.20lf\n",z);
	}
}