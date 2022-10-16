#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m;
pair<long long,long long> a[100069];
bitset<100069> sq;

int main()
{
	long long i,k;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		a[i]={k,i};
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)
	{
		k=a[i].sc;
		sq[k]=i%2;
	}
	for(i=1;i<=n;i++)
	{
		printf("%lld%c",(long long)sq[i]," \n"[i==n]);
	}
}