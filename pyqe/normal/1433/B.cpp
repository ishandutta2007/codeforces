#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long t,rr,i,k,c,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		c=-1;
		z=0;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&k);
			if(!k)
			{
				c+=c!=-1;
			}
			else
			{
				z+=max(c,0ll);
				c=0;
			}
		}
		printf("%lld\n",z);
	}
}