#include <bits/stdc++.h>

using namespace std;

long long n,a[100069],fw[100069];

int main()
{
	long long i,k,p,z,b=0;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		z=0;
		for(p=k-1;p>0;p-=p&-p)
		{
			z=max(z,fw[p]);
		}
		a[k]=max(a[k],z+1);
		for(p=k;p<=100000;p+=p&-p)
		{
			fw[p]=max(fw[p],z+1);
		}
		b=max(b,a[k]);
	}
	printf("%lld\n",b);
}