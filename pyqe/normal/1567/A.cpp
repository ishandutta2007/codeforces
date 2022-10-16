#include <bits/stdc++.h>

using namespace std;

long long n;

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
			if(ch=='U')
			{
				ch='D';
			}
			else if(ch=='D')
			{
				ch='U';
			}
			printf("%c",ch);
		}
		printf("\n");
	}
}