#include <bits/stdc++.h>

using namespace std;

const long long mm=19;
long long n,d,p10[mm],a[10],wg[10];

int main()
{
	long long t,rr,i,k,z;
	
	p10[0]=1;
	for(i=1;i<mm;i++)
	{
		p10[i]=p10[i-1]*10;
	}
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		d++;
		for(i=0;i<n;i++)
		{
			scanf("%lld",a+i);
			wg[i]=mm-1;
			if(i)
			{
				wg[i-1]=a[i]-a[i-1];
			}
		}
		z=0;
		for(i=0;i<n;i++)
		{
			k=min(p10[wg[i]]-1,d);
			z+=k*p10[a[i]];
			d-=k;
		}
		printf("%lld\n",z);
	}
}