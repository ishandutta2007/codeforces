#include <bits/stdc++.h>

using namespace std;

long long n,m;

int main()
{
	long long z;
	
	scanf("%lld%lld",&n,&m);
	if(n>m)
	{
		swap(n,m);
	}
	z=min(m-n,n);
	z+=(n-z)*2/3;
	printf("%lld\n",z);
}