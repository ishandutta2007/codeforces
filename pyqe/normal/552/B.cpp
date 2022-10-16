#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long k,ml=1,z=0;
	
	scanf("%lld",&n);
	for(k=n;k;k/=10,ml*=10)
	{
		z+=max(n-(ml-1),0ll);
	}
	printf("%lld\n",z);
}