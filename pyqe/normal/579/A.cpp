#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long n,c=0;
	
	scanf("%lld",&n);
	while(n>0)
	{
		if(n%2==1)
		{
			n--;
			c++;
		}
		n/=2;
	}
	printf("%lld\n",c);
}