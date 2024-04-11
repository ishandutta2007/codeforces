#include <bits/stdc++.h>

using namespace std;

long long n,a[100069];

int main()
{
	long long t,rr,i,c,z;
	bool bad,bad2;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		c=0;
		bad=0;
		bad2=0;
		z=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			if(i>1&&i<n)
			{
				z+=(a[i]+1)/2;
				c+=a[i]%2;
				bad|=a[i]>=2;
				bad2|=a[i]>=2&&a[i]%2==0;
			}
		}
		if(!c||(c>=2&&bad)||bad2)
		{
			printf("%lld\n",z);
		}
		else
		{
			printf("-1\n");
		}
	}
}