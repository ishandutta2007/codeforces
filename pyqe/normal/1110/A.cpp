#include <bits/stdc++.h>

using namespace std;

long long n,d;

int main()
{
	long long i,k,z=0;
	
	scanf("%lld%lld",&d,&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		z^=k%2&&(d%2||i==n);
	}
	if(!z)
	{
		printf("even\n");
	}
	else
	{
		printf("odd\n");
	}
}