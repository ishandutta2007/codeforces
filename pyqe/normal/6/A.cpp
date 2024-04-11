#include <bits/stdc++.h>

using namespace std;

long long a[4];

int main()
{
	long long i;
	bool bad=0,bad2=0;
	
	for(i=0;i<4;i++)
	{
		scanf("%lld",a+i);
	}
	sort(a,a+4);
	for(i=2;i<4;i++)
	{
		bad|=a[i]<a[i-1]+a[i-2];
		bad2|=a[i]==a[i-1]+a[i-2];
	}
	if(bad)
	{
		printf("TRIANGLE\n");
	}
	else if(bad2)
	{
		printf("SEGMENT\n");
	}
	else
	{
		printf("IMPOSSIBLE\n");
	}
}