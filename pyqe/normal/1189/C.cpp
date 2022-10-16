#include <bits/stdc++.h>

using namespace std;

long long n,ps[100069];

int main()
{
	long long t,rr,i,k,l;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		ps[i]=ps[i-1]+k;
	}
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&k,&l);
		printf("%lld\n",(ps[l]-ps[k-1])/10);
	}
}