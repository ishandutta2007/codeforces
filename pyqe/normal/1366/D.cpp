#include <bits/stdc++.h>

using namespace std;

int n,ma=1e7,fz[10000069],sq[500069][2];

int main()
{
	int i,j,ii,k,w;
	
	for(i=2;i<=ma;i++)
	{
		if(!fz[i])
		{
			for(j=i;j<=ma;j+=i)
			{
				fz[j]=i;
			}
		}
	}
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&k);
		for(w=k;w%fz[k]==0;w/=fz[k]);
		for(ii=0;ii<2;ii++)
		{
			sq[i][ii]=-1;
		}
		if(w>1)
		{
			sq[i][0]=fz[k];
			sq[i][1]=w;
		}
	}
	for(ii=0;ii<2;ii++)
	{
		for(i=1;i<=n;i++)
		{
			printf("%d%c",sq[i][ii]," \n"[i==n]);
		}
	}
}