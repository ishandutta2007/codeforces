#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long t,rr,i;
	bool bad;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		if(n<=26)
		{
			for(i=0;i<n;i++)
			{
				printf("%c",(char)(i+'a'));
			}
			printf("\n");
		}
		else
		{
			bad=n%2;
			if(bad)
			{
				printf("cc");
				n-=3;
			}
			for(i=1;i<=n;i++)
			{
				printf("%c",(char)('a'+(i==n/2+1)));
			}
			if(bad)
			{
				printf("c");
			}
			printf("\n");
		}
	}
}