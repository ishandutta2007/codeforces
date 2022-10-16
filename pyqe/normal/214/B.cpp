#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,fq[10],mo[3];

int main()
{
	long long i,j,ii,k,sm,e;
	pair<long long,long long> mxe={-1e18,-1};
	bool bad=1;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		fq[k]++;
		mo[k%3]++;
	}
	if(!fq[0])
	{
		printf("-1\n");
		return 0;
	}
	for(i=0;i<3;i++)
	{
		if(i<=min(mo[1],mo[2]))
		{
			sm=0;
			for(ii=1;ii<=2;ii++)
			{
				sm+=(mo[ii]-i)/3*3+i;
			}
			mxe=max(mxe,{sm,i});
		}
	}
	e=mxe.sc;
	for(ii=1;ii<=2;ii++)
	{
		mo[ii]=(mo[ii]-e)/3*3+e;
	}
	for(i=9;i+1;i--)
	{
		for(j=0;j<fq[i]&&mo[i%3]&&(i||!j||!bad);j++)
		{
			printf("%lld",i);
			mo[i%3]--;
			if(i)
			{
				bad=0;
			}
		}
	}
	printf("\n");
}