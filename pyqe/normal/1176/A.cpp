#include <bits/stdc++.h>

using namespace std;

long long n,a[3]={2,3,5};

int main()
{
	long long t,rr,i,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(z=0;n>1;)
		{
			for(i=0;i<3;i++)
			{
				if(n%a[i]==0)
				{
					n=n/a[i]*(a[i]-1);
					z++;
					i=-1;
					break;
				}
			}
			if(i!=-1)
			{
				z=-1;
				break;
			}
		}
		printf("%lld\n",z);
	}
}