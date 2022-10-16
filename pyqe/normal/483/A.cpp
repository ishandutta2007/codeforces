#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long k,l;
	
	scanf("%lld%lld",&k,&l);
	k+=k%2;
	if(l<k+2)
	{
		printf("-1\n");
	}
	else
	{
		printf("%lld %lld %lld\n",k,k+1,k+2);
	}
}