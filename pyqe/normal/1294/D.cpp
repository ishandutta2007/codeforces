#include <bits/stdc++.h>

using namespace std;

long long m,fq[400069];

int main()
{
	long long t,rr,i,k,p=0;
	
	scanf("%lld%lld",&t,&m);
	for(rr=1;rr<=t;rr++)
	{
		scanf("%lld",&k);
		fq[k%m]++;
		for(;fq[p%m]>=p/m+1;p++);
		printf("%lld\n",p);
	}
}