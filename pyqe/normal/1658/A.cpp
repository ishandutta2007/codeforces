#include <bits/stdc++.h>

using namespace std;

const long long inf=1e18;
long long n;

int main()
{
	long long t,rr,i,l,z;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		z=0;
		l=-inf;
		for(i=1;i<=n;i++)
		{
			scanf(" %c",&ch);
			if(ch=='0')
			{
				z+=max(3-(i-l),0ll);
				l=i;
			}
		}
		printf("%lld\n",z);
	}
}