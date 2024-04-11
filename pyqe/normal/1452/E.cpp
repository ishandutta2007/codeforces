#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second;

long long n,m,d,wg[4069];
pair<long long,long long> a[2069];

int main()
{
	long long i,j,k,l,w,sm,z=0;
	
	scanf("%lld%lld%lld",&n,&m,&d);
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld",&k,&l);
		a[i]={k,l};
	}
	for(i=d;i<=n;i++)
	{
		sm=0;
		for(j=1;j<=m;j++)
		{
			k=a[j].fr;
			l=a[j].sc;
			w=max(min(i,l)-max(i-d+1,k)+1,0ll);
			sm+=w;
			if(k-1+w<=min(k+d-1,l))
			{
				wg[k-1+w]++;
				wg[k+d-1]--;
				wg[l]--;
				wg[l+d-w]++;
			}
		}
		w=wg[0];
		wg[0]=0;
		for(j=1;j<=n;j++)
		{
			sm+=w;
			w+=wg[j];
			wg[j]=0;
			z=max(z,sm);
		}
	}
	printf("%lld\n",z);
}