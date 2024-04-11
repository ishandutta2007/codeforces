#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,a[100069],as[100069];
pair<long long,long long> sq[100069];

int main()
{
	long long t,rr,i,k,l=-1e18;
	
	scanf("%lld%lld",&n,&t);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		if(i>1)
		{
			sq[i-1]={l,a[i]};
			as[i-1]=min(l,a[i]);
		}
		l=max(l,a[i]);
	}
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&k);
		if(k<n)
		{
			printf("%lld %lld\n",sq[k].fr,sq[k].sc);
		}
		else
		{
			printf("%lld %lld\n",l,as[(k-1)%(n-1)+1]);
		}
	}
}