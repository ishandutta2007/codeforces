#include <bits/stdc++.h>

using namespace std;

long long n,d,inf=1e18;
map<long long,long long> fq;

int main()
{
	long long t,rr,i,k,mx;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		fq.clear();
		mx=0;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&k);
			k=(d-k%d)%d;
			if(k)
			{
				mx=max(mx,d*fq[k]+k+1);
				fq[k]++;
			}
		}
		printf("%lld\n",mx);
	}
}