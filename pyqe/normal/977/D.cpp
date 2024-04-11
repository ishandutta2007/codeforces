#include <bits/stdc++.h>

using namespace std;

long long n,a[100069],wg[2][100069],sq[100069],inf=1e18;

int main()
{
	long long i,ii,k,mn=inf;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		k=a[i];
		for(ii=0;ii<2;ii++)
		{
			for(;k%(ii+2)==0;k/=ii+2,wg[ii][i]++);
		}
		mn=min(mn,wg[0][i]-wg[1][i]);
	}
	for(i=1;i<=n;i++)
	{
		sq[wg[0][i]-wg[1][i]-mn+1]=a[i];
	}
	for(i=1;i<=n;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==n]);
	}
}