#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,as[2][200069],inf=1e18;
pair<long long,long long> a[200069];

int main()
{
	long long t,rr,i,ii,k,l,w,w2,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld%lld",&k,&l);
			a[i]={k,l};
			as[0][i]=k;
			as[1][i]=l;
		}
		for(ii=0;ii<2;ii++)
		{
			sort(as[ii]+1,as[ii]+n+1);
		}
		z=inf;
		for(i=1;i<=n;i++)
		{
			k=a[i].fr;
			l=a[i].sc;
			w=lower_bound(as[1]+1,as[1]+n+1,k)-as[1]-1;
			w2=n+1-(upper_bound(as[0]+1,as[0]+n+1,l)-as[0]);
			z=min(z,w+w2);
		}
		printf("%lld\n",z);
	}
}