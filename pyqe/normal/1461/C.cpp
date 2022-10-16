#include <bits/stdc++.h>

using namespace std;

long long n,m,a[100069],as[100069];

int main()
{
	long long t,rr,i,k,mn;
	double w,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			as[i]=a[i];
		}
		sort(as+1,as+n+1);
		for(mn=n;mn&&a[mn]==as[mn];mn--);
		z=!!mn;
		for(i=0;i<m;i++)
		{
			scanf("%lld%lf",&k,&w);
			if(k>=mn)
			{
				z*=(double)1-w;
			}
		}
		printf("%.20lf\n",(double)1-z);
	}
}