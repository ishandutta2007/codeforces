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
			c+=ch=='0';
		}
		if(!c)
		{
			printf("DRAW\n");
		}
		else if(c==1||c%2==0)
		{
			printf("BOB\n");
		}
		else
		{
			printf("ALICE\n");
		}
	}
}