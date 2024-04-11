#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long n,k;
	
	scanf("%lld%lld",&n,&k);
	for(k=k;k>0;k--)
	{
		if(n%10==0)
		{
			n/=10;
		}
		else
		{
			n--;
		}
	}
	printf("%lld\n",n);
}