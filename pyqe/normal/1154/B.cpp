#include <bits/stdc++.h>

using namespace std;

long long n,nn=0,a[100069];
bitset<100069> vtd;

int main()
{
	long long i,k;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		if(!vtd[k])
		{
			nn++;
			a[nn]=k;
			vtd[k]=1;
		}
	}
	sort(a+1,a+nn+1);
	if(nn>3)
	{
		printf("-1\n");
	}
	else if(nn==3)
	{
		if(a[2]-a[1]!=a[3]-a[2])
		{
			printf("-1\n");
		}
		else
		{
			printf("%lld\n",a[2]-a[1]);
		}
	}
	else if(nn==2)
	{
		printf("%lld\n",(a[2]-a[1])/(1+!((a[2]-a[1])%2)));
	}
	else if(nn==1)
	{
		printf("0\n");
	}
}