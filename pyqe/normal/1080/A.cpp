#include <bits/stdc++.h>

using namespace std;

long long n,d,a[3]={2,5,8};

int main()
{
	long long i,z=0;
	
	scanf("%lld%lld",&n,&d);
	for(i=0;i<3;i++)
	{
		z+=(a[i]*n-1)/d+1;
	}
	printf("%lld\n",z);
}