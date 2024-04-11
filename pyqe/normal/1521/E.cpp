#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,d,sq[1069][1069];
pair<long long,long long> as[100069];

int main()
{
	long long t,rr,i,j,k,w,lh,rh,md,zz,y[3],x[3],e;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&d,&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			as[i]={k,i};
		}
		sort(as+1,as+n+1,greater<pair<long long,long long>>());
		for(lh=1,rh=d;lh<=rh;)
		{
			md=(lh+rh)/2;
			if(md*md-(md/2)*(md/2)>=d&&md*((md+1)/2)>=as[1].fr)
			{
				zz=md;
				rh=md-1;
			}
			else
			{
				lh=md+1;
			}
		}
		for(i=1;i<=zz;i++)
		{
			for(j=1;j<=zz;j++)
			{
				sq[i][j]=0;
			}
		}
		for(i=0;i<3;i++)
		{
			y[i]=1+!i;
			x[i]=1+(i==1);
			if(x[i]>zz)
			{
				y[i]+=2;
			}
		}
		for(i=1;i<=n;i++)
		{
			w=as[i].fr;
			k=as[i].sc;
			e=(y[0]>zz)+(y[1]>zz);
			for(j=0;j<w;j++)
			{
				sq[y[e]][x[e]]=k;
				x[e]+=2;
				if(x[e]>zz)
				{
					y[e]+=2;
					x[e]=1+(e==1);
					if(y[e]>zz)
					{
						e=2;
					}
				}
			}
		}
		printf("%lld\n",zz);
		for(i=1;i<=zz;i++)
		{
			for(j=1;j<=zz;j++)
			{
				printf("%lld%c",sq[i][j]," \n"[j==zz]);
			}
		}
	}
}