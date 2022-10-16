#include <bits/stdc++.h>

using namespace std;

long long n,a[300069];

int main()
{
	long long i;
	char ch;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf(" %c",&ch);
		a[i]=ch-'a';
	}
	for(i=1;i<n;i++)
	{
		if(a[i]>a[i+1])
		{
			printf("YES\n%lld %lld\n",i,i+1);
			return 0;
		}
	}
	printf("NO\n");
}