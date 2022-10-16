#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long t,rr,i,ii,k,l[2],c[2][2],z;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(ii=0;ii<2;ii++)
		{
			l[ii]=0;
		}
		z=n+1;
		for(i=1;i<=n;i++)
		{
			scanf(" %c",&ch);
			k=ch-'a';
			if(!k)
			{
				for(ii=0;ii<2;ii++)
				{
					if(l[ii]&&max(c[ii][0],c[ii][1])<2+ii)
					{
						z=min(z,i-l[ii]+1);
					}
				}
				l[1]=l[0];
				l[0]=i;
				for(ii=0;ii<2;ii++)
				{
					c[1][ii]=c[0][ii];
					c[0][ii]=0;
				}
			}
			else
			{
				for(ii=0;ii<2;ii++)
				{
					c[ii][k-1]++;
				}
			}
		}
		if(z==n+1)
		{
			z=-1;
		}
		printf("%lld\n",z);
	}
}