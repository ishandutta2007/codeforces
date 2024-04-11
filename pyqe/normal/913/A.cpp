#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long n,m,z=1;
	
	scanf("%lld%lld",&n,&m);
	while(z<=m&&n>0)
	{
		z*=2;
		n--;
	}
	printf("%lld\n",m%z);
}