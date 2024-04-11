#include <bits/stdc++.h>

using namespace std;

long long n,d[2],fq[2];

int main()
{
	long long i,j,ii,p=0;
	bool bad=1;
	
	scanf("%lld%lld%lld",&n,d,d+1);
	for(fq[0]=0;fq[0]*d[0]<=n;fq[0]++)
	{
		if((n-fq[0]*d[0])%d[1]==0)
		{
			fq[1]=(n-fq[0]*d[0])/d[1];
			bad=0;
			break;
		}
	}
	if(bad)
	{
		printf("-1\n");
		return 0;
	}
	for(ii=0;ii<2;ii++)
	{
		for(i=0;i<fq[ii];i++)
		{
			for(j=1;j<=d[ii];j++)
			{
				p++;
				printf("%lld%c",p+1-d[ii]*(j==d[ii])," \n"[p==n]);
			}
		}
	}
}