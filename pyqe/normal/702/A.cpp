#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long i,k,l=-1,c=0,b=0;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		if(k>l)
		{
			c++;
		}
		else
		{
			b=max(b,c);
			c=1;
		}
		l=k;
	}
	b=max(b,c);
	printf("%lld\n",b);
}