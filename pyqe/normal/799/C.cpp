#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,d[2],nn[2],nm,inf=1e18;
pair<long long,long long> a[2][100069],as[100069];

int main()
{
	long long i,ii,k,l,e,p,sm=0,z=0;
	char ch;
	
	scanf("%lld%lld%lld",&n,d,d+1);
	for(i=0;i<n;i++)
	{
		scanf("%lld%lld %c",&k,&l,&ch);
		e=ch-'C';
		nn[e]++;
		a[e][nn[e]]={l,k};
	}
	for(ii=0;ii<2;ii++)
	{
		sort(a[ii]+1,a[ii]+nn[ii]+1);
		a[ii][0].sc=-inf;
		nm=0;
		p=0;
		for(i=1;i<=nn[ii];i++)
		{
			if(a[ii][i].sc>=a[ii][p].sc)
			{
				nm++;
				as[nm]={a[ii][i].fr,i};
				p=i;
			}
		}
		for(i=1;i<=nn[ii];i++)
		{
			p=as[upper_bound(as+1,as+nm+1,mp(d[ii]-a[ii][i].fr,inf))-as-1].sc;
			if(p!=i)
			{
				z=max(z,a[ii][i].sc+a[ii][p].sc);
			}
		}
		p=as[upper_bound(as+1,as+nm+1,mp(d[ii],inf))-as-1].sc;
		sm+=a[ii][p].sc;
	}
	z=max(z,sm);
	printf("%lld\n",z);
}