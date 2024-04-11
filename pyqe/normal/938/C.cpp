#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long t,rr,i,ii,k,l,w,w2,z,z2;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		z=-1;
		if(!n)
		{
			z=1;
			z2=1;
		}
		for(ii=0,i=1;ii!=-1&&i*i<=n;i++)
		{
			if(n%i==0&&i%2==n/i%2)
			{
				k=i;
				l=n/i;
				for(ii=0;ii<2;ii++)
				{
					w=k-l+1;
					if(w>0)
					{
						w2=k+l-1;
						w/=2;
						w2=(w2+1)/2;
						if(w&&w2/w&&w2/(w2/w)==w)
						{
							z=w2/w;
							z2=w2;
							ii=-1;
							break;
						}
					}
					swap(k,l);
				}
			}
		}
		if(z!=-1)
		{
			printf("%lld ",z2);
		}
		printf("%lld\n",z);
	}
}