#include <bits/stdc++.h>

using namespace std;

long long n,d,dv;
map<long long,long long> fq;

int main()
{
	long long i,k,tg,z=0;
	
	scanf("%lld%lld%lld",&n,&dv,&d);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		tg=(k*k%dv*k+dv-d)%dv*k%dv;
		z+=fq[tg];
		fq[tg]++;
	}
	printf("%lld\n",z);
}