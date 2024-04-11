#include <bits/stdc++.h>

using namespace std;

long long n[2],z=0,dv=1e9+7;

int main()
{
	long long i,ii,k,l,l2;
	
	scanf("%lld%lld",n,n+1);
	for(ii=0;ii<2;ii++)
	{
		k=0;
		l=2;
		l2=0;
		for(i=0;i<n[ii];i++)
		{
			k=(l+l2)%dv;
			l2=l;
			l=k;
		}
		z=(z+k)%dv;
	}
	z=(z+dv-2)%dv;
	printf("%lld\n",z);
}