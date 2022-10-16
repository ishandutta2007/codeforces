#include <bits/stdc++.h>

using namespace std;

long long n,fq[30];

int main()
{
	long long t,rr,i,j,k,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=0;i<30;i++)
		{
			fq[i]=0;
		}
		for(i=0;i<n;i++)
		{
			scanf("%lld",&k);
			for(j=0;k;k/=2,j++)
			{
				fq[j]+=k%2;
			}
		}
		z=0;
		for(i=29;i+1;i--)
		{
			if(fq[i]%2)
			{
				if(fq[i]%4==1||n%2==0)
				{
					z=1;
				}
				else
				{
					z=-1;
				}
				break;
			}
		}
		if(z==1)
		{
			printf("WIN\n");
		}
		else if(!z)
		{
			printf("DRAW\n");
		}
		else
		{
			printf("LOSE\n");
		}
	}
}