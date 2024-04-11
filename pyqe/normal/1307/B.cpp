#include <bits/stdc++.h>

using namespace std;

long long n,d;
map<long long,bool> vtd;

int main()
{
	long long t,rr,i,k,mx,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		mx=-1e18;
		vtd.clear();
		for(i=0;i<n;i++)
		{
			scanf("%lld",&k);
			mx=max(mx,k);
			vtd[k]=1;
		}
		z=(d-1)/mx+1;
		z+=(z==1&&!vtd[d]);
		printf("%lld\n",z);
	}
}