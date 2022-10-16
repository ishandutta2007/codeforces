#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long i;
	
	scanf("%lld",&n);
	printf("%lld\n",n);
	for(i=1;i<=n;i++)
	{
		printf("1%c"," \n"[i==n]);
	}
}