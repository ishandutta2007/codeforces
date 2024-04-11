#include <bits/stdc++.h>

using namespace std;

#define fr first
#define sc second

long long n;
pair<long long,long long> a[5069];

int main()
{
	long long i,k,l=-1;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld%lld",&a[i].fr,&a[i].sc);
	}
	sort(a,a+n);
	for(i=0;i<n;i++)
	{
		k=a[i].sc;
		if(l>k)
		{
			k=a[i].fr;
		}
		l=k;
	}
	printf("%lld\n",l);
}