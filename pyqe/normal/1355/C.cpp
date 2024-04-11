#include <bits/stdc++.h>

using namespace std;

long long a[4],df[4];

long long tri(long long x)
{
	return x*(x+1)/2;
}

int main()
{
	long long i,k,w,z=0;
	
	for(i=0;i<4;i++)
	{
		scanf("%lld",a+i);
		if(i)
		{
			df[i]=a[i]-a[i-1]+1;
		}
	}
	for(i=a[2];i<=a[3];i++)
	{
		k=i-a[2]+1;
		w=a[1]+1-k;
		if(w>=0)
		{
			z+=tri(w);
		}
		if(w>=df[1])
		{
			z-=tri(w-df[1]);
		}
		if(w>=df[2])
		{
			z-=tri(w-df[2]);
		}
		if(w>=df[1]+df[2])
		{
			z+=tri(w-df[1]-df[2]);
		}
	}
	printf("%lld\n",z);
}