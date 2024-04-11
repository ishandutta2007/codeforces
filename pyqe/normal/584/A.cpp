#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long n,t,i;
	
	scanf("%I64d%I64d",&n,&t);
	if(n==1&&t==10)
	{
		printf("-1\n");
		return 0;
	}
	if(t==10)
	{
		t=1;
	}
	printf("%lld",t);
	for(i=1;i<n;i++)
	{
		printf("0");
	}
	printf("\n");
}