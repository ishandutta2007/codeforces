#include <bits/stdc++.h>

using namespace std;

long long n;
map<long long,long long> ls;

int main()
{
	long long i,k,sm=0,mx=1,z=0;
	
	scanf("%lld",&n);
	ls[sm]=2;
	for(i=3;i<=n+2;i++)
	{
		scanf("%lld",&k);
		sm+=k;
		if(ls[sm]>=mx)
		{
			z++;
			mx=i-1;
		}
		ls[sm]=i;
	}
	printf("%lld\n",z);
}