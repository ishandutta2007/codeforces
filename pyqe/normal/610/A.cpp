#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long n;
	
	scanf("%lld",&n);
	if(n%2==0)
	{
		printf("%lld\n",(n-1)/4);
	}
	else
	{
		printf("0\n");
	}
}