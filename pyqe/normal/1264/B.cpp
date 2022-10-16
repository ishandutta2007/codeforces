#include <bits/stdc++.h>

using namespace std;

long long n=0,fqq[4],fq[4],z[100069];

int main()
{
	long long ii,i,k;
	
	for(ii=0;ii<4;ii++)
	{
		scanf("%lld",fqq+ii);
		n+=fqq[ii];
	}
	for(ii=0;ii<4;ii++)
	{
		for(i=0;i<4;i++)
		{
			fq[i]=fqq[i];
		}
		k=ii;
		if(!fq[k])
		{
			continue;
		}
		fq[k]--;
		z[1]=k;
		for(i=2;i<=n;i++)
		{
			if(k-1>=0&&fq[k-1])
			{
				k--;
			}
			else if(k+1<4&&fq[k+1])
			{
				k++;
			}
			else
			{
				break;
			}
			fq[k]--;
			z[i]=k;
		}
		if(i>n)
		{
			printf("YES\n");
			for(i=1;i<=n;i++)
			{
				printf("%lld%c",z[i]," \n"[i==n]);
			}
			return 0;
		}
	}
	printf("NO\n");
}