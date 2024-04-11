#include <bits/stdc++.h>

using namespace std;

long long n,c=0,b=0;

int main()
{
	long long i,k,l=0;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		if(k>l+l)
		{
			b=max(b,c);
			c=1;
		}
		else
		{
			c++;
		}
		l=k;
	}
	b=max(b,c);
	printf("%lld\n",b);
}