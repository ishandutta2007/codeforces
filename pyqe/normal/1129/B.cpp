#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long i,k;
	
	scanf("%lld",&n);
	k=3998-n%1999;
	printf("2000\n");
	for(i=0;i<1998;i++)
	{
		printf("0 ");
	}
	printf("%lld %lld\n",-k,k+(n+k)/1999);
}