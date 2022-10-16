#include <bits/stdc++.h>

using namespace std;

long long n,dv,a[2][2069];

int main()
{
	long long i,j,ii,mn=1e18,df;
	
	scanf("%lld%lld",&n,&dv);
	for(ii=0;ii<2;ii++)
	{
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[ii][i]);
		}
		sort(a[ii],a[ii]+n);
	}
	for(i=0;i<n;i++)
	{
		df=(a[1][i]+dv-a[0][0])%dv;
		for(j=1;j<n;j++)
		{
			if(a[1][(j+i)%n]!=(a[0][j]+df)%dv)
			{
				j=-1;
				break;
			}
		}
		if(j!=-1)
		{
			mn=min(mn,df);
		}
	}
	printf("%lld\n",mn);
}