#include <bits/stdc++.h>

using namespace std;

long long n;
bitset<100069> a;

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
			a[i]=ch-'a';
		}
		for(i=1;i<n;i++)
		{
			if(a[i]!=a[i+1])
			{
				break;
			}
		}
		if(i<n)
		{
			printf("%lld %lld\n",i,i+1);
		}
		else
		{
			printf("-1 -1\n");
		}
	}
}