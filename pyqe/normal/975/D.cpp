#include <bits/stdc++.h>

using namespace std;

long long n,d,d2;
map<long long,long long> fq;
map<pair<long long,long long>,long long> fq2;

int main()
{
	long long i,k,w,w2,z=0;
	
	scanf("%lld%lld%lld",&n,&d,&d2);
	for(i=0;i<n;i++)
	{
		scanf("%lld%lld%lld",&k,&w,&w2);
		w2-=w*d;
		z+=(fq[w2]-fq2[{w2,w}])*2;
		fq[w2]++;
		fq2[{w2,w}]++;
	}
	printf("%lld\n",z);
}