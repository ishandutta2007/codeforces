#include <bits/stdc++.h>

using namespace std;

long long n,m,fq[100069];

int main()
{
	long long t,rr,i,k,l,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		for(i=0;i<m;i++)
		{
			fq[i]=0;
		}
		for(i=0;i<n;i++)
		{
			scanf("%lld",&k);
			fq[k%m]++;
		}
		z=0;
		for(i=0;i*2<=m;i++)
		{
			k=fq[i];
			l=fq[(m-i)%m];
			if(k<l)
			{
				swap(k,l);
			}
			z+=max(k-l-1,0ll)+!!k;
		}
		printf("%lld\n",z);
	}
}