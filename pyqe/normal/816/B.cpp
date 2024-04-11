#include <bits/stdc++.h>

using namespace std;

long long n,d,ma=2e5,wg[200069],ps[200069];

int main()
{
	long long t,rr,i,k,l,sm=0;
	
	scanf("%lld%lld%lld",&n,&d,&t);
	for(i=0;i<n;i++)
	{
		scanf("%lld%lld",&k,&l);
		wg[k]++;
		wg[l+1]--;
	}
	for(i=1;i<=ma;i++)
	{
		sm+=wg[i];
		ps[i]=ps[i-1]+(sm>=d);
	}
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&k,&l);
		printf("%lld\n",ps[l]-ps[k-1]);
	}
}