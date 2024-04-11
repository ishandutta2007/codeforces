#include <bits/stdc++.h>

using namespace std;

long long n,d,dp[100069];

int main()
{
	long long t,rr,i,k,l,l2,z;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		z=0;
		l=0;
		l2=0;
		for(i=1;i<=n;i++)
		{
			scanf(" %c",&ch);
			k=ch=='*';
			if(k)
			{
				if(!l2)
				{
					z++;
					l2=i;
				}
				else if(i-l2>d)
				{
					z++;
					l2=l;
				}
				l=i;
			}
		}
		z+=l2!=l;
		printf("%lld\n",z);
	}
}