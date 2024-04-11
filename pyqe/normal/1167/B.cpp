#include <bits/stdc++.h>

using namespace std;

long long ky[6]={4,8,15,16,23,42},a[4][2],fq[6],sq[6];

int main()
{
	long long i,j,k;
	bool bad;
	
	for(i=0;i<4;i++)
	{
		printf("? %lld %lld\n",i+1,i+2);
		fflush(stdout);
		scanf("%lld",&k);
		bad=0;
		for(a[i][0]=0;a[i][0]<6;a[i][0]++)
		{
			for(a[i][1]=a[i][0]+1;a[i][1]<6;a[i][1]++)
			{
				if(ky[a[i][0]]*ky[a[i][1]]==k)
				{
					bad=1;
					break;
				}
			}
			if(bad)
			{
				break;
			}
		}
		fq[a[i][0]]++;
		fq[a[i][1]]++;
	}
	for(i=0;i<6;i++)
	{
		if(!fq[i])
		{
			sq[5]=i;
		}
		else if(fq[i]==1&&(a[0][0]==i||a[0][1]==i))
		{
			sq[0]=i;
		}
	}
	for(i=0;i<4;i++)
	{
		for(j=0;j<2;j++)
		{
			if(a[i][j]!=sq[i])
			{
				break;
			}
		}
		sq[i+1]=a[i][j];
	}
	printf("!");
	for(i=0;i<6;i++)
	{
		printf(" %lld",ky[sq[i]]);
	}
	printf("\n");
	fflush(stdout);
}