#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long n,z=0,d,i,k,a[2]={0,0};
	
	scanf("%lld",&n);
	long long b[n];
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		z+=k;
		b[i]=z;
	}
	if(z%3!=0)
	{
		printf("0\n");
	}
	else
	{
		d=z/3;
		for(i=0;i<n;i++)
		{
			if(z==0)
			{
				if(b[i]==0)
				{
					a[0]++;
				}
			}
			else
			{
				if(b[i]==d)
				{
					a[0]++;
				}
				else if(b[i]==d*2)
				{
					a[1]+=a[0];
				}
			}
		}
		if(z==0)
		{
			a[1]=(a[0]-1)*(a[0]-2)/2;
		}
		printf("%lld\n",a[1]);
	}
}