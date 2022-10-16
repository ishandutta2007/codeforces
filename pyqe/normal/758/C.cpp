#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,d,nn,inf=1e18;
pair<long long,long long> a[5];

int main()
{
	long long i,ii,y,x,k,z,mx=-inf,mn=inf;
	
	scanf("%lld%lld%lld%lld%lld",&n,&m,&d,&y,&x);
	nn=max(n-1,1ll);
	a[0]={1,1};
	a[1]={min(2ll,n),1};
	a[2]={nn,1};
	a[3]={n,m};
	a[4]={y,x};
	for(i=0;i<5;i++)
	{
		y=a[i].fr;
		x=a[i].sc;
		k=(d+m-x)/m;
		z=0;
		for(ii=0;ii<2;ii++)
		{
			if(y<=nn)
			{
				z+=(k+nn*2-y-nn*ii)/nn/2;
			}
			y=n+1-y;
		}
		mx=max(mx,z);
		mn=min(mn,z);
	}
	printf("%lld %lld %lld\n",mx,mn,z);
}