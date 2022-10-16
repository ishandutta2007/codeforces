#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,d;

int main()
{
	long long i,k;
	pair<long long,pair<long long,long long>> z={-1,{-1,-1}};
	
	scanf("%lld%lld",&d,&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		z=max(z,{d/k*k,{i,d/k}});
	}
	printf("%lld %lld\n",z.sc.fr,z.sc.sc);
}