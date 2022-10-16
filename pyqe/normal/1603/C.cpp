#include <bits/stdc++.h>

using namespace std;

const long long dv=998244353;
long long n,a[100069],wg[100069];

int main()
{
	long long t,rr,i,j,k,sm,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		sm=0;
		z=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			wg[i]=1;
			for(j=i-1;j;j--)
			{
				if((a[j]-1)/wg[j]+1<=a[j+1]/wg[j+1])
				{
					break;
				}
				k=(a[j]-1)/(a[j+1]/wg[j+1])+1;
				sm=(sm+(k-wg[j])*j)%dv;
				wg[j]=k;
			}
			z=(z+sm)%dv;
		}
		printf("%lld\n",z);
	}
}