#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long i,k,z=0;
	
	for(i=0;i<5;i++)
	{
		scanf("%lld",&k);
		z+=k;
	}
	if(z%5==0&&z/5>0)
	{
		printf("%lld\n",z/5);
	}
	else
	{
		printf("-1");
	}
}