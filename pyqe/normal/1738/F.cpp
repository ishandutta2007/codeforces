#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,a[1069],dsu[1069];
pair<long long,long long> as[1069];
bitset<1069> vtd;

inline long long qr(long long x)
{
	long long k;
	
	printf("? %lld\n",x);
	fflush(stdout);
	scanf("%lld",&k);
	return k;
}

long long fd(long long x)
{
	if(dsu[x]!=x)
	{
		dsu[x]=fd(dsu[x]);
	}
	return dsu[x];
}

int main()
{
	long long t,rr,i,j,k,l,w;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			as[i]={a[i],i};
			dsu[i]=i;
		}
		sort(as+1,as+n+1,greater<pair<long long,long long>>());
		vtd.reset();
		for(i=1;i<=n;i++)
		{
			w=as[i].fr;
			k=as[i].sc;
			if(vtd[k])
			{
				continue;
			}
			vtd[k]=1;
			for(j=0;j<w-1;j++)
			{
				l=qr(k);
				if(!vtd[l])
				{
					dsu[fd(l)]=fd(k);
					vtd[l]=1;
				}
				else
				{
					dsu[fd(k)]=fd(l);
					break;
				}
			}
		}
		printf("!");
		for(i=1;i<=n;i++)
		{
			printf(" %lld",fd(i));
		}
		printf("\n");
		fflush(stdout);
	}
}