#include <bits/stdc++.h>

using namespace std;

long long n;
map<long long,long long> fq;

int main()
{
	long long t,rr,i,k,mx;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		fq.clear();
		mx=0;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&k);
			fq[k]++;
			mx=max(mx,fq[k]);
		}
		printf("%lld\n",max(n%2,mx-(n-mx)));
	}
}