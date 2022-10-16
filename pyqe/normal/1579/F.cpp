#include <bits/stdc++.h>

using namespace std;

long long n,d,vi[1000069];
bitset<1000069> a;

int main()
{
	long long t,rr,i,k,c,c2,p,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&k);
			a[i]=k;
			vi[i]=0;
		}
		z=0;
		for(i=0;i<n;i++)
		{
			if(!vi[i])
			{
				c=0;
				c2=0;
				for(p=i;vi[p]<2;p=(p+d)%n)
				{
					vi[p]++;
					c=(c+1)*a[p];
					c2++;
					z=max(z,c);
				}
				if(z==c2)
				{
					break;
				}
			}
		}
		if(i<n)
		{
			z=-1;
		}
		printf("%lld\n",z);
	}
}