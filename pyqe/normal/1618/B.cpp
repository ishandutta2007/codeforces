#include <bits/stdc++.h>

using namespace std;

long long n,sq[100069],zs;

int main()
{
	long long t,rr,i,ii,k;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		zs=0;
		for(i=0;i<n-2;i++)
		{
			for(ii=0;ii<2;ii++)
			{
				scanf(" %c",&ch);
				k=ch-'a';
				if(!zs||k!=sq[zs]||ii)
				{
					zs++;
					sq[zs]=k;
				}
			}
		}
		if(zs<n)
		{
			zs++;
			sq[zs]=sq[zs-1];
		}
		for(i=1;i<=zs;i++)
		{
			printf("%c",(char)(sq[i]+'a'));
		}
		printf("\n");
	}
}