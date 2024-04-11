#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long k,a[12],z=0,i;
	
	scanf("%lld",&k);
	for(i=0;i<12;i++)
	{
		scanf("%lld",a+i);
	}
	sort(a,a+12,greater<long long>());
	if(k==0)
	{
		printf("0\n");
		return 0;
	}
	for(i=0;i<12;i++)
	{
		z+=a[i];
		if(z>=k)
		{
			break;
		}
	}
	if(z>=k)
	{
		printf("%lld\n",i+1);
	}
	else
	{
		printf("-1\n");
	}
}