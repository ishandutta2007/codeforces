#include <bits/stdc++.h>

using namespace std;

long long n,nn[2],a[2][100069];

int main()
{
	long long t,rr,i,ii,k;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(ii=0;ii<2;ii++)
		{
			nn[ii]=0;
		}
		for(i=0;i<n;i++)
		{
			scanf("%lld",&k);
			nn[k%2]++;
			a[k%2][nn[k%2]]=k;
		}
		for(ii=0;ii<2;ii++)
		{
			for(i=1;i<nn[ii];i++)
			{
				if(a[ii][i]>a[ii][i+1])
				{
					break;
				}
			}
			if(i<nn[ii])
			{
				break;
			}
		}
		if(ii>=2)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
}