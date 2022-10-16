#include <bits/stdc++.h>

using namespace std;

long long n,a[100069],as[100069];

int main()
{
	long long t,rr,i,z;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf(" %c",&ch);
			a[i]=ch-'a';
			as[i]=a[i];
		}
		sort(as+1,as+n+1);
		z=0;
		for(i=1;i<=n;i++)
		{
			z+=a[i]!=as[i];
		}
		printf("%lld\n",z);
	}
}