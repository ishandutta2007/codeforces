#include <bits/stdc++.h>

using namespace std;

long long n,d,a[200069],ls[200069],sq[200069];

int main()
{
	long long i;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld",ls+i);
		if(ls[i]<max(i,ls[i-1])||(ls[i]>ls[i-1]&&ls[i-1]!=i-1))
		{
			printf("No\n");
			return 0;
		}
	}
	for(i=1;i<=n;i++)
	{
		if(ls[i]>ls[i-1]&&sq[i-1]>=a[i]+d)
		{
			printf("No\n");
			return 0;
		}
		sq[i]=max(a[i+(ls[i]==ls[i+1])]+d,sq[i-1]+1);
	}
	printf("Yes\n");
	for(i=1;i<=n;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==n]);
	}
}