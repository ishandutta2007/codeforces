#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long a,b,c=0;
	
	scanf("%lld%lld",&a,&b);
	while(b!=a)
	{
		if(b%2==1||b<a)
		{
			b++;
		}
		else
		{
			b/=2;
		}
		c++;
	}
	printf("%lld\n",c);
}