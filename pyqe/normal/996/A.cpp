#include <bits/stdc++.h>

using namespace std;

long long a[5]={100,20,10,5,1};

int main()
{
	long long k,z=0,i;
	
	scanf("%lld",&k);
	for(i=0;i<5;i++)
	{
		z+=k/a[i];
		k%=a[i];
	}
	printf("%lld\n",z);
}