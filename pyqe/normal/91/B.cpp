#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,sq[100069];
pair<long long,long long> a[100069];

int main()
{
	long long i,k,mx=-1e18;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&a[i].fr);
		a[i].sc=i;
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)
	{
		k=a[i].sc;
		mx=max(mx,k);
		sq[k]=mx-k-1;
	}
	for(i=1;i<=n;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==n]);
	}
}