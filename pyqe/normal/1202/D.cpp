#include <bits/stdc++.h>

using namespace std;

long long n,f[400069];

int main()
{
	long long t,rr,i,k,rm,nn;
	
	f[1]=0;
	for(i=2;1;i++)
	{
		f[i]=f[i-1]+i-1;
		if(f[i]>1000000000)
		{
			nn=i;
			break;
		}
	}
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		k=upper_bound(f,f+nn,n)-f-1;
		rm=n-f[k];
		printf("133");
		for(i=0;i<rm;i++)
		{
			printf("7");
		}
		for(i=0;i<k-2;i++)
		{
			printf("3");
		}
		printf("7\n");
	}
}