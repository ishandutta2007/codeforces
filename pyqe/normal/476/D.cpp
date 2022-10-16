#include <bits/stdc++.h>

using namespace std;

long long n,d;

int main()
{
	long long i;
	
	scanf("%lld%lld",&n,&d);
	printf("%lld\n",(n*6-1)*d);
	for(i=1;i<=n;i++)
	{
		printf("%lld %lld %lld %lld\n",(i*6-5)*d,(i*6-4)*d,(i*6-3)*d,(i*6-1)*d);
	}
}