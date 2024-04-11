#include <bits/stdc++.h>

using namespace std;

const long long inf=1e18;
long long n,nn,nm,a[100069],ca[100069];

int main()
{
	long long t,rr,i,j,k,l,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		nn=0;
		for(;n;n/=10)
		{
			nn++;
			a[nn]=n%10;
		}
		z=inf;
		for(k=1;k<inf;k*=2)
		{
			nm=0;
			for(l=k;l;l/=10)
			{
				nm++;
				ca[nm]=l%10;
			}
			for(j=nn,i=nm;i;i--,j--)
			{
				for(;j&&a[j]!=ca[i];j--);
				if(!j)
				{
					break;
				}
			}
			z=min(z,nn-(nm-i)+i);
		}
		printf("%lld\n",z);
	}
}