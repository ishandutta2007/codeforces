#include <bits/stdc++.h>

using namespace std;

long long n,a[100069],pst[100069],sq[100069],zs=0;

int main()
{
	long long t,rr,i,j,mn;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			pst[a[i]]=i;
		}
		zs=0;
		mn=n+1;
		for(i=n;i;i--)
		{
			if(pst[i]<mn)
			{
				for(j=pst[i];j<mn;j++)
				{
					zs++;
					sq[zs]=a[j];
				}
				mn=pst[i];
			}
		}
		for(i=1;i<=zs;i++)
		{
			printf("%lld%c",sq[i]," \n"[i==zs]);
		}
	}
}