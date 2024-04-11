#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long t,rr,i,k,z;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		z=0;
		for(i=1;i<=n;i++)
		{
			scanf(" %c",&ch);
			k=ch-'0';
			z+=k+(!!k&&i<n);
		}
		printf("%lld\n",z);
	}
}