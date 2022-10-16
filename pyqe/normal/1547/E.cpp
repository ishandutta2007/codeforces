#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const long long inf=1e18;
long long n,m,sq[300069];
pair<long long,long long> a[300069];

int main()
{
	long long t,rr,i,j,ii,k,l,mn;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		for(i=1;i<=m;i++)
		{
			scanf("%lld",&a[i].fr);
		}
		for(i=1;i<=m;i++)
		{
			scanf("%lld",&a[i].sc);
		}
		for(i=1;i<=n;i++)
		{
			sq[i]=inf;
		}
		for(ii=0;ii<2;ii++)
		{
			sort(a+1,a+m+1);
			mn=inf;
			for(j=1,i=1;i<=n;i++)
			{
				for(;j<=m&&a[j].fr<=i;j++)
				{
					k=a[j].fr;
					l=a[j].sc;
					mn=min(mn,l-k);
					a[j].fr=n+1-k;
				}
				sq[i]=min(sq[i],i+mn);
			}
			for(i=1;i<n+1-i;i++)
			{
				swap(sq[i],sq[n+1-i]);
			}
		}
		for(i=1;i<=n;i++)
		{
			printf("%lld%c",sq[i]," \n"[i==n]);
		}
	}
}