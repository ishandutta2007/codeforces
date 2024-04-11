#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,d=10,nn[2],pc[1069],a[30],inf=1e18;
pair<long long,long long> as[2][1ll<<20];

int main()
{
	long long t,rr,i,j,ii,k,w,p,sz,lb,mk,sm,c,z;
	
	srand(time(NULL));
	scanf("%lld%lld%lld",&n,&m,&t);
	pc[0]=1;
	for(i=1;i<=n;i++)
	{
		pc[i]=rand()%(1ll<<15)<<45|rand()%(1ll<<15)<<30|rand()%(1ll<<15)<<15|rand()%(1ll<<15);
	}
	for(i=0;i<m;i++)
	{
		scanf("%lld",&sz);
		for(j=0;j<sz;j++)
		{
			scanf("%lld",&k);
			a[i]^=pc[k];
		}
	}
	for(ii=0;ii<2;ii++)
	{
		if(!ii)
		{
			sz=min(m,d);
		}
		else
		{
			sz=max(m-d,0ll);
		}
		lb=d*ii;
		nn[ii]=1ll<<sz;
		for(mk=0;mk<nn[ii];mk++)
		{
			sm=0;
			c=0;
			for(i=0;i<sz;i++)
			{
				if(mk>>i&1)
				{
					sm^=a[i+lb];
					c++;
				}
			}
			as[ii][mk]={sm,c};
		}
	}
	sort(as[1],as[1]+nn[1]);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&sz);
		sm=0;
		for(i=0;i<sz;i++)
		{
			scanf("%lld",&k);
			sm^=pc[k];
		}
		z=inf;
		for(i=0;i<nn[0];i++)
		{
			k=as[0][i].fr;
			w=as[0][i].sc;
			p=lower_bound(as[1],as[1]+nn[1],mp(k^sm,0ll))-as[1];
			if(as[1][p].fr==(k^sm))
			{
				z=min(z,w+as[1][p].sc);
			}
		}
		if(z==inf)
		{
			z=-1;
		}
		printf("%lld\n",z);
	}
}