#include <bits/stdc++.h>

using namespace std;

long long n,a[100069];

int main()
{
	long long t,rr,i;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf(" %c",&ch);
			a[i]=ch-'0';
		}
		if(n==1||n==2&&a[1]!=a[2])
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}