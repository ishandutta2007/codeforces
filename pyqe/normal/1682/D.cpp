#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,ttl,zs;
bitset<200069> a;
pair<long long,long long> sq[200069];

int main()
{
	long long t,rr,i,e,p,l,ft;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		ttl=0;
		for(i=0;i<n;i++)
		{
			scanf(" %c",&ch);
			a[i]=ch-'0';
			ttl+=a[i];
			if(a[i])
			{
				e=i;
			}
		}
		if(ttl%2||!ttl)
		{
			printf("NO\n");
			continue;
		}
		zs=0;
		ft=-1;
		for(i=0;i<=n;i++)
		{
			p=(i+e)%n;
			if(i==n||a[p])
			{
				if(ft!=-1)
				{
					zs++;
					sq[zs]={ft,l};
				}
				else if(i)
				{
					ft=l;
				}
			}
			else
			{
				zs++;
				sq[zs]={l,p};
			}
			l=p;
		}
		printf("YES\n");
		for(i=1;i<=zs;i++)
		{
			printf("%lld %lld\n",sq[i].fr+1,sq[i].sc+1);
		}
	}
}