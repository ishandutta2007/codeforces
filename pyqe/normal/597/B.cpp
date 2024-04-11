#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n;
pair<long long,long long> a[500069];

int main()
{
	long long i,k,l,mx=0,z=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&k,&l);
		a[i]={l,k};
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)
	{
		l=a[i].fr;
		k=a[i].sc;
		if(k>mx)
		{
			z++;
			mx=l;
		}
	}
	printf("%lld\n",z);
}