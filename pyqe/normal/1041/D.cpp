#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,d,inf=1e18;
pair<long long,long long> a[200069];

int main()
{
	long long i,j,k,l,rb,mx=-inf;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&a[i].fr,&a[i].sc);
	}
	rb=a[1].fr+d;
	for(j=1,i=1;i<=n;i++)
	{
		for(;j<=n&&a[j].fr<rb;j++)
		{
			k=a[j].fr;
			l=a[j].sc;
			rb+=l-k;
		}
		k=a[i].fr;
		l=a[i].sc;
		mx=max(mx,rb-k);
		rb+=a[i+1].fr-l;
	}
	printf("%lld\n",mx);
}