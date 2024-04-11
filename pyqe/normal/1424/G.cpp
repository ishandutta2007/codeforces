#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,inf=1e18;
pair<long long,long long> a[200069];

int main()
{
	long long i,k,l,c=0;
	pair<long long,long long> z={-inf,-1};
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&k,&l);
		a[i*2-1]={k,1};
		a[i*2]={l,-1};
	}
	sort(a+1,a+n*2+1);
	for(i=1;i<=n*2;i++)
	{
		k=a[i].fr;
		c+=a[i].sc;
		z=max(z,{c,-k});
	}
	printf("%lld %lld\n",-z.sc,z.fr);
}