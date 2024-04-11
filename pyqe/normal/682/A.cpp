#include <bits/stdc++.h>

using namespace std;

long long n,m;

int main()
{
	long long i,z=0;
	
	scanf("%lld%lld",&n,&m);
	for(i=0;i<5;i++)
	{
		z+=((n+5-i)/5-!i)*((m+5-(5-i)%5)/5-!i);
	}
	printf("%lld\n",z);
}