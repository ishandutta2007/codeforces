#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long n,ky[4]={6,8,4,2};
	
	scanf("%lld",&n);
	if(n==0)
	{
		printf("1\n");
		return 0;
	}
	printf("%lld\n",ky[n%4]);
}