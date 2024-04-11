#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long k,l,z=0;
	
	scanf("%lld%lld",&k,&l);
	for(;l;)
	{
		z+=k/l;
		k%=l;
		swap(k,l);
	}
	printf("%lld\n",z);
}