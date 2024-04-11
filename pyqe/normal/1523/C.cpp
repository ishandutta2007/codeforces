#include <bits/stdc++.h>

using namespace std;

long long n,nn,sk[1069];

int main()
{
	long long t,rr,i,j,k;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		nn=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			nn++;
			sk[nn]=0;
			for(;sk[nn]!=k-1;nn--);
			sk[nn]++;
			for(j=1;j<=nn;j++)
			{
				printf("%lld%c",sk[j],".\n"[j==nn]);
			}
		}
	}
}