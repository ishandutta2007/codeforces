#include <bits/stdc++.h>

using namespace std;

long long n,ma=1e6,a[100069],fq[1000069],ps[1000069],vl[24000069],dp[2][100069],dv=1e9+7;

int main()
{
	long long i,j,r,sm,z=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		for(j=1;j*j<=a[i];j++)
		{
			if(a[i]%j==0)
			{
				fq[j]++;
				fq[a[i]/j]+=a[i]/j!=j;
			}
		}
	}
	for(i=1;i<=ma;i++)
	{
		ps[i]=ps[i-1]+fq[i];
		fq[i]=0;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j*j<=a[i];j++)
		{
			if(a[i]%j==0)
			{
				fq[j]++;
				vl[ps[j-1]+fq[j]]=i;
				if(a[i]/j!=j)
				{
					fq[a[i]/j]++;
					vl[ps[a[i]/j-1]+fq[a[i]/j]]=i;
				}
			}
		}
	}
	for(i=1;i<=ma;i++)
	{
		sm=i==1;
		for(r=0,j=1;j<=fq[i];j++)
		{
			for(;r<fq[i-1]&&vl[ps[i-2]+r+1]<vl[ps[i-1]+j];r++,sm=(sm+dp[0][r])%dv);
			dp[1][j]=sm;
			z=(z+sm)%dv;
		}
		for(j=1;j<=fq[i];j++)
		{
			dp[0][j]=dp[1][j];
		}
	}
	printf("%lld\n",z);
}