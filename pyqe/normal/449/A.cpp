#include <bits/stdc++.h>

using namespace std;

long long n,m,d;

int main()
{
	long long ii,k,z=0;
	
	scanf("%lld%lld%lld",&n,&m,&d);
	for(ii=0;ii<2;ii++)
	{
		k=min(d,n-1);
		z=max(z,(n/(k+1))*(m/(d-k+1)));
		swap(n,m);
	}
	printf("%lld\n",z-!z);
}