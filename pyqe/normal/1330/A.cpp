#include <bits/stdc++.h>

using namespace std;

long long n,d,ls[100069];

int main()
{
	long long t,rr,i,k,mx;
	
	scanf("%lld",&t);
	for(rr=1;rr<=t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&k);
			ls[k]=rr;
		}
		for(mx=1,i=0;i<d;i++)
		{
			for(;ls[mx]==rr;mx++);
			ls[mx]=rr;
		}
		for(;ls[mx]==rr;mx++);
		printf("%lld\n",mx-1);
	}
}