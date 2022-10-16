#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,inf=1e18;
pair<long long,long long> a[200069];

int main()
{
	long long i,k,l,mx=-inf,c=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&k,&l);
		a[i]={k+l,k-l};
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)
	{
		k=a[i].sc;
		l=a[i].fr;
		if(k>=mx)
		{
			c++;
			mx=l;
		}
	}
	printf("%lld\n",c);
}