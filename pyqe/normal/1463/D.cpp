#include <bits/stdc++.h>

using namespace std;

long long n,a[200069];
bitset<400069> vtd;

int main()
{
	long long t,rr,i,j,ii,z[2];
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		for(ii=0;ii<2;ii++)
		{
			for(i=1;i<=n*2;i++)
			{
				vtd[i]=0;
			}
			z[ii]=0;
			for(j=1,i=1;i<=n;i++)
			{
				vtd[a[i]]=1;
				for(;j<=a[i]&&vtd[j];j++);
				if(j<=a[i])
				{
					z[ii]++;
					vtd[j]=1;
				}
			}
			for(i=1;i<=n;i++)
			{
				a[i]=n*2+1-a[i];
			}
			for(i=1;i<n+1-i;i++)
			{
				swap(a[i],a[n+1-i]);
			}
		}
		printf("%lld\n",z[0]-(n-z[1])+1);
	}
}