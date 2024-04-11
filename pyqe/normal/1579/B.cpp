#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,a[100069],zs;
pair<long long,long long> as[100069];
pair<pair<long long,long long>,long long> sq[100069];

int main()
{
	long long t,rr,i,j,k;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			as[i]={k,i};
		}
		sort(as+1,as+n+1);
		for(i=1;i<=n;i++)
		{
			k=as[i].sc;
			a[k]=i;
		}
		zs=0;
		for(i=1;i<=n;i++)
		{
			for(j=i;a[j]!=i;j++);
			if(j>i)
			{
				zs++;
				sq[zs]={{i,j},j-i};
				for(;j>i;j--)
				{
					a[j]=a[j-1];
				}
				a[i]=i;
			}
		}
		printf("%lld\n",zs);
		for(i=1;i<=zs;i++)
		{
			printf("%lld %lld %lld\n",sq[i].fr.fr,sq[i].fr.sc,sq[i].sc);
		}
	}
}