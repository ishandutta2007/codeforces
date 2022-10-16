#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const long long dv=998244353,inf=1e18;
long long n,d,nn,a[200069],pr[200069],uba[200069];
bitset<200069> vtd,vtd2;
pair<long long,long long> as[200069];

int main()
{
	long long t,rr,i,k,l,p,z;
	bool bad;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			pr[i]=-1;
			vtd[i]=0;
			vtd2[i]=0;
		}
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			if(k!=-1)
			{
				pr[k]=a[i];
				vtd[a[i]]=1;
			}
		}
		bad=0;
		nn=0;
		for(i=1;i<=n;i++)
		{
			if(!vtd[i])
			{
				for(p=i;1;p=pr[p])
				{
					vtd2[p]=1;
					if(pr[p]==-1)
					{
						break;
					}
					bad|=pr[p]>p+d;
				}
				nn++;
				as[nn]={i,p};
			}
		}
		for(i=1;i<=n;i++)
		{
			if(!vtd2[i])
			{
				for(p=i;!vtd2[p];p=pr[p])
				{
					vtd2[p]=1;
					bad|=pr[p]>p+d;
				}
			}
		}
		if(bad)
		{
			printf("0\n");
			continue;
		}
		sort(as+1,as+nn+1);
		for(i=1;i<=n;i++)
		{
			l=as[i].sc;
			p=upper_bound(as+1,as+nn+1,mp(l+d,inf))-as-1;
			uba[i]=p;
		}
		sort(uba+1,uba+nn+1);
		z=1;
		for(i=1;i<=nn;i++)
		{
			z=z*max(uba[i]-(i-1),0ll)%dv;
		}
		printf("%lld\n",z);
	}
}