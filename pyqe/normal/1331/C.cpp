#include <bits/stdc++.h>

using namespace std;

long long n,ky[6]={4,1,3,2,0,5};

int main()
{
	long long i,z=0;
	
	scanf("%lld",&n);
	for(i=0;i<6;i++)
	{
		z+=(n>>ky[i]&1)<<i;
	}
	printf("%lld\n",z);
}