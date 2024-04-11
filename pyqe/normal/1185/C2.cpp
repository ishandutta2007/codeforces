#include <bits/stdc++.h>

using namespace std;

long long n,m,fq[169];

int main()
{
	long long i,j,k,c,z=0;
	
	scanf("%lld%lld",&n,&m);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		c=0;
		z=0;
		for(j=0;j<=100;j++)
		{
			if(z+fq[j]*j<m-k)
			{
				c+=fq[j];
				z+=fq[j]*j;
			}
			else
			{
				if(j>0)
				{
					c+=(m-k-z)/j;
				}
				break;
			}
		}
		printf("%lld%c",i-c," \n"[i==n-1]);
		fq[k]++;
	}
}