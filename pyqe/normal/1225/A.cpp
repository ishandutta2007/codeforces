#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long a,b;
	
	scanf("%lld%lld",&a,&b);
	if(a==b)
	{
		printf("%lld0 %lld1\n",a,b);
	}
	else if(a+1==b)
	{
		printf("%lld %lld\n",a,b);
	}
	else if(a==9&&b==1)
	{
		printf("9 10\n");
	}
	else
	{
		printf("-1\n");
	}
}