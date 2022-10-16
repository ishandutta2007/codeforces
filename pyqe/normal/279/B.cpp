#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long n,t,i,p=-1,q=0,b=0,z=0;
	
	scanf("%lld%lld",&n,&t);
	long long a[n];
	for(i=0;i<n;i++)
	{
		scanf("%lld",a+i);
	}
	while(p<n)
	{
		p++;
		z+=a[p];
		if(z>t)
		{
			b=max(b,p-q);
			while(z>t)
			{
				z-=a[q];
				q++;
			}
		}
	}
	printf("%lld\n",b);
}