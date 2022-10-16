#include <bits/stdc++.h>

using namespace std;

long long n,a[200069];

int main()
{
	long long i,j;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	sort(a+1,a+n+1);
	for(j=1,i=1;1;i++,j++)
	{
		for(;j<=n&&a[j]<i;j++);
		if(j>n)
		{
			break;
		}
	}
	printf("%lld\n",i-1);
}