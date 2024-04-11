#include <bits/stdc++.h>

using namespace std;

long long n;
map<long long,long long> ls;

int main()
{
	long long i,k,sm=0,mx=0,z=0;
	
	scanf("%lld",&n);
	ls[0]=1;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		sm+=k;
		mx=max(mx,ls[sm]);
		z+=i-mx;
		ls[sm]=i+1;
	}
	printf("%lld\n",z);
}