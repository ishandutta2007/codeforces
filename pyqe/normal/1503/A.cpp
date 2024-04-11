#include <bits/stdc++.h>

using namespace std;

long long n,fq[2];
bitset<200069> a;

int main()
{
	long long t,rr,i,ii,k,c,e,sm;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(ii=0;ii<2;ii++)
		{
			fq[ii]=0;
		}
		for(i=1;i<=n;i++)
		{
			scanf(" %c",&ch);
			a[i]=ch-'0';
			fq[a[i]]++;
		}
		if(fq[0]%2)
		{
			printf("NO\n");
			continue;
		}
		sm=0;
		c=0;
		e=1;
		for(i=1;i<=n;i++)
		{
			if(a[i])
			{
				c++;
				k=c>fq[1]/2;
			}
			else
			{
				k=e;
				e^=1;
			}
			sm+=!k*2-1;
			if(sm<0)
			{
				break;
			}
		}
		if(i<=n)
		{
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		for(ii=0;ii<2;ii++)
		{
			c=0;
			e=ii;
			for(i=1;i<=n;i++)
			{
				if(a[i])
				{
					c++;
					k=c>fq[1]/2;
				}
				else
				{
					k=e;
					e^=1;
				}
				printf("%c","()"[k]);
			}
			printf("\n");
		}
	}
}