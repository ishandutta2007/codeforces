#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long n,i,p=0,b,k,z=0;
	
	scanf("%lld",&n);
	long long a[n],d[n];
	for(i=0;i<n;i++)
	{
		scanf("%lld%lld",a+i,d+i);
	}
	b=d[0];
	for(i=0;i<n;i++)
	{
		if(i==p)
		{
			while(b!=-1&&d[p]>=b)
			{
				p++;
			}
			k=b;
			b=d[p];
		}
		z+=a[i]*k;
	}
	printf("%lld\n",z);
}