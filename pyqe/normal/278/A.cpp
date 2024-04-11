#include <bits/stdc++.h>

using namespace std;

long long n,ps[100069];

int main()
{
	long long i,k,l;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		ps[i]=ps[i-1]+k;
	}
	scanf("%lld%lld",&k,&l);
	if(k>l)
	{
		swap(k,l);
	}
	printf("%lld\n",min(ps[l-1]-ps[k-1],ps[n]-ps[l-1]+ps[k-1]));
}