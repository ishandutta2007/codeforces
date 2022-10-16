#include <bits/stdc++.h>

using namespace std;

long long n,ls[2];

int main()
{
	long long i,k;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		ls[k]=i;
	}
	printf("%lld\n",min(ls[0],ls[1]));
}