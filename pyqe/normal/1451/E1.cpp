#include <bits/stdc++.h>

using namespace std;

long long n,ka[5]={1,1,1,1,2},la[5]={2,3,2,3,3},a[5],cr[4],sq[100069];
bitset<5> ky;

int main()
{
	long long i,j,mk,k;
	
	for(i=2;i<5;i++)
	{
		ky[i]=1;
	}
	scanf("%lld",&n);
	for(i=0;i<5;i++)
	{
		if(!ky[i])
		{
			printf("X");
		}
		printf("OR %lld %lld\n",ka[i],la[i]);
		fflush(stdout);
		scanf("%lld",a+i);
	}
	for(i=0;1ll<<i<n;i++)
	{
		for(mk=0;mk<8;mk++)
		{
			for(j=1;j<=3;j++)
			{
				cr[j]=mk>>j-1&1;
			}
			for(j=0;j<5;j++)
			{
				if((!ky[j]&&(cr[ka[j]]^cr[la[j]])!=(a[j]>>i&1))||(ky[j]&&(cr[ka[j]]||cr[la[j]])!=(a[j]>>i&1)))
				{
					j=-1;
					break;
				}
			}
			if(j!=-1)
			{
				break;
			}
		}
		for(j=1;j<=3;j++)
		{
			sq[j]|=cr[j]<<i;
		}
	}
	for(i=4;i<=n;i++)
	{
		printf("XOR %lld %lld\n",i-1,i);
		fflush(stdout);
		scanf("%lld",&k);
		sq[i]=k^sq[i-1];
	}
	printf("!");
	for(i=1;i<=n;i++)
	{
		printf(" %lld",sq[i]);
	}
	printf("\n");
	fflush(stdout);
}