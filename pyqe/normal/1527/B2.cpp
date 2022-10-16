#include <bits/stdc++.h>

using namespace std;

long long n;
bitset<100069> a;

int main()
{
	long long t,rr,i,c;
	bool bad;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		c=0;
		for(i=1;i<=n;i++)
		{
			scanf(" %c",&ch);
			a[i]=ch-'0';
			c+=!a[i];
		}
		for(i=1;i<n+1-i;i++)
		{
			if(a[i]!=a[n+1-i])
			{
				break;
			}
		}
		bad=i<n+1-i;
		if(!c||(c==2&&n%2&&!a[(n+1)/2]))
		{
			printf("DRAW\n");
		}
		else if(!bad&&(c==1||c%2==0))
		{
			printf("BOB\n");
		}
		else
		{
			printf("ALICE\n");
		}
	}
}