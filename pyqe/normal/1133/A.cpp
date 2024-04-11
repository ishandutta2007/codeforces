#include <bits/stdc++.h>

using namespace std;

long long n[2];

int main()
{
	long long ii,k,z;
	char ch;
	
	for(ii=0;ii<2;ii++)
	{
		scanf("%lld",&k);
		n[ii]+=k*60;
		scanf(" %c%lld",&ch,&k);
		n[ii]+=k;
	}
	z=(n[0]+n[1])/2;
	if(z/60<10)
	{
		printf("0");
	}
	printf("%lld:",z/60);
	if(z%60<10)
	{
		printf("0");
	}
	printf("%lld\n",z%60);
}