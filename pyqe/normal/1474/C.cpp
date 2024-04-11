#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,aa[2069],a[2069],pst[1000069],fq[1000069],zs;
pair<long long,long long> sq[1069];
bitset<2069> vtd;

int main()
{
	long long t,rr,i,j,l,p;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		n*=2;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",aa+i);
		}
		sort(aa+1,aa+n+1,greater<long long>());
		for(i=2;i<=n;i++)
		{
			zs=1;
			sq[zs]={aa[1],aa[i]};
			p=0;
			for(j=2;j<=n;j++)
			{
				if(j!=i)
				{
					p++;
					a[p]=aa[j];
					if(!pst[a[p]])
					{
						pst[a[p]]=p;
					}
					vtd[p]=0;
				}
			}
			l=aa[1];
			for(j=1;j<=n-2;j++)
			{
				if(vtd[j])
				{
					continue;
				}
				fq[a[j]]++;
				p=pst[l-a[j]]+fq[l-a[j]];
				if(p>n-2||a[p]!=l-a[j]||!pst[l-a[j]])
				{
					break;
				}
				zs++;
				sq[zs]={a[j],l-a[j]};
				vtd[p]=1;
				fq[l-a[j]]++;
				l=a[j];
			}
			for(j=1;j<=n-1;j++)
			{
				pst[a[j]]=0;
				fq[a[j]]=0;
			}
			if(zs==n/2)
			{
				break;
			}
		}
		if(zs<n/2)
		{
			printf("NO\n");
			continue;
		}
		printf("YES\n%lld\n",sq[1].fr+sq[1].sc);
		for(i=1;i<=zs;i++)
		{
			printf("%lld %lld\n",sq[i].fr,sq[i].sc);
		}
	}
}