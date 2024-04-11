#include <bits/stdc++.h>

using namespace std;

long long n,d,a[100069];

int main()
{
	long long t,rr,i;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		for(i=1;i<=n;i++)
		{
			scanf(" %c",&ch);
			a[i]=ch-'a';
		}
		for(i=1;i<=d;i++)
		{
			if(a[i]!=a[n+1-i])
			{
				break;
			}
		}
		if(i>d&&d*2<n)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}