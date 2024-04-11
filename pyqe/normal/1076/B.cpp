#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long i,k;
	
	scanf("%lld",&n);
	for(i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			k=i;
			break;
		}
	}
	if(i*i>n)
	{
		k=n;
	}
	n-=k;
	printf("%lld\n",n/2+1);
}