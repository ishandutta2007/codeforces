#include <bits/stdc++.h>

using namespace std;

long long n,m;

int main()
{
	long long i;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		printf("%d",!(i%((n-m)/2+1)));
	}
	printf("\n");
}