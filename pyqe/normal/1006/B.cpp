#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,d,pst[2069];
pair<long long,long long> a[2069];

int main()
{
	long long i,z=0,l=0;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&a[i].fr);
		a[i].sc=i;
	}
	sort(a+1,a+n+1,greater<pair<long long,long long>>());
	for(i=1;i<=d;i++)
	{
		pst[i]=a[i].sc;
		z+=a[i].fr;
	}
	sort(pst+1,pst+d+1);
	printf("%lld\n",z);
	for(i=1;i<d;i++)
	{
		printf("%lld ",pst[i]-l);
		l=pst[i];
	}
	printf("%lld\n",n-l);
}