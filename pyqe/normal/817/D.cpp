#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,dsu[1000069],cc[1000069];
pair<long long,long long> as[1000069];

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
	long long i,ii,u,uu,k,w,z=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		as[i]={k,i};
	}
	sort(as+1,as+n+1);
	for(ii=0;ii<2;ii++)
	{
		u=!ii*2-1;
		for(i=1;i<=n;i++)
		{
			dsu[i]=i;
			cc[i]=0;
		}
		for(i=1ll+(n-1)*ii;i&&i<=n;i+=u)
		{
			w=as[i].fr;
			k=as[i].sc;
			cc[k]=1;
			z+=w*(cc[fd(k-1)]+1)*(cc[fd(k+1)]+1)*u;
			for(uu=-1;uu<=1;uu+=2)
			{
				if(cc[fd(k+uu)])
				{
					cc[k]+=cc[fd(k+uu)];
					dsu[fd(k+uu)]=k;
				}
			}
		}
	}
	printf("%lld\n",z);
}