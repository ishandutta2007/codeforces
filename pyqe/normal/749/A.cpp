#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long a;
	
	scanf("%lld",&a);
	printf("%lld\n",a/2);
	while(a>3)
	{
		a-=2;
		printf("2 ");
	}
	printf("%lld\n",a);
}