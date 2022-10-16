#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long t,rr,i,c;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		c=0;
		for(i=0;i<n;i++)
		{
			scanf(" %c",&ch);
			if(ch=='t')
			{
				c++;
			}
			else
			{
				printf("%c",ch);
			}
		}
		for(i=0;i<c;i++)
		{
			printf("t");
		}
		printf("\n");
	}
}