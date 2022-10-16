#include <bits/stdc++.h>

using namespace std;

long long n,fq[2069];

int main()
{
	long long t,rr,i,j,k,c,mx;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		c=0;
		for(i=0;i<n;i++)
		{
			fq[i]=0;
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				scanf(" %c",&ch);
				k=ch-'0';
				c+=k;
				fq[(i+n-j)%n]+=k;
			}
		}
		mx=0;
		for(i=0;i<n;i++)
		{
			mx=max(mx,fq[i]);
		}
		printf("%lld\n",c-mx+n-mx);
	}
}