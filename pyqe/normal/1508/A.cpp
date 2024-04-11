#include <bits/stdc++.h>

using namespace std;

long long n,fq[3][2];
bitset<200069> a[3];

int main()
{
	long long t,rr,i,j,ii,jj,e,p[2],pp[2];
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=0;i<3;i++)
		{
			for(ii=0;ii<2;ii++)
			{
				fq[i][ii]=0;
			}
			for(j=1;j<=n*2;j++)
			{
				scanf(" %c",&ch);
				a[i][j]=ch-'0';
				fq[i][a[i][j]]++;
			}
		}
		for(ii=0;ii<2;ii++)
		{
			for(jj=0;jj<2;jj++)
			{
				p[jj]=-1;
			}
			for(i=0;i<3;i++)
			{
				if(fq[i][ii]>=n)
				{
					p[0]=i;
					swap(p[0],p[1]);
				}
			}
			if(p[0]+1)
			{
				break;
			}
		}
		e=ii;
		for(ii=0;ii<2;ii++)
		{
			pp[ii]=0;
		}
		for(i=1;i<=n+1;i++)
		{
			for(ii=0;ii<2;ii++)
			{
				for(pp[ii]++;pp[ii]<=n*2&&(a[p[ii]][pp[ii]]!=e||i==n+1);pp[ii]++)
				{
					printf("%lld",(long long)a[p[ii]][pp[ii]]);
				}
			}
			if(i<=n)
			{
				printf("%lld",e);
			}
		}
		printf("\n");
	}
}