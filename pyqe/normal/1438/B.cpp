#include <bits/stdc++.h>

using namespace std;

long long n;
map<long long,long long> ls;

int main()
{
	long long t,rr,i,k;
	bool bad;
	
	scanf("%lld",&t);
	for(rr=1;rr<=t;rr++)
	{
		scanf("%lld",&n);
		bad=0;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&k);
			bad|=ls[k]==rr;
			ls[k]=rr;
		}
		if(bad)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}