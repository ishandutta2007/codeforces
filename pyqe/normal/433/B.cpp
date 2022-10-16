#include <bits/stdc++.h>

using namespace std;

long long n,ps[2][100069];

int main()
{
	long long t,rr,i,ii,ky,k,l;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&ps[0][i]);
	}
	for(i=1;i<=n;i++)
	{
		ps[1][i]=ps[0][i];
	}
	sort(ps[1]+1,ps[1]+n+1);
	for(ii=0;ii<2;ii++)
	{
		for(i=1;i<=n;i++)
		{
			ps[ii][i]+=ps[ii][i-1];
		}
	}
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",&ky,&k,&l);
		printf("%lld\n",ps[ky-1][l]-ps[ky-1][k-1]);
	}
}