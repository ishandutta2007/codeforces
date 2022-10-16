#include <bits/stdc++.h>

using namespace std;

long long a[4];

int main()
{
	long long t,rr,i,z;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		for(i=0;i<4;i++)
		{
			scanf(" %c",&ch);
			a[i]=ch-'a';
		}
		sort(a,a+4);
		z=0;
		for(i=0;i<3;i++)
		{
			z+=a[i]!=a[i+1];
		}
		printf("%lld\n",z);
	}
}