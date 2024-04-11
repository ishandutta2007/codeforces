#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long t,rr,i,k,l,z;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		l=0;
		for(i=0;i<n;i++)
		{
			scanf(" %c",&ch);
			k=ch-'0';
			z=k+1!=l;
			printf("%lld",z);
			l=k+z;
		}
		printf("\n");
	}
}