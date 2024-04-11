#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long i,c=0,l=0,l2=0;
	
	scanf("%lld",&n);
	for(i=2;i*i<=n;i++)
	{
		for(;n%i==0;n/=i)
		{
			c++;
			l2=l;
			l=i;
		}
	}
	if(n>1)
	{
		c++;
		l2=l;
		l=n;
	}
	if(c==2)
	{
		printf("2\n");
	}
	else
	{
		printf("1\n%lld\n",l*l2);
	}
}