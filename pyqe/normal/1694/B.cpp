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
		z=0;
		for(i=1;i<=n;i++)
		{
			scanf(" %c",&ch);
			k=ch-'0';
			z++;
			if(i>1&&k!=l)
			{
				z+=i-1;
			}
			l=k;
		}
		printf("%lld\n",z);
	}
}