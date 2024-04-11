#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n;
pair<long long,long long> a[200069];

int main()
{
	long long t,rr,i,y,x,y2,x2,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&a[i].fr);
		}
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&a[i].sc);
		}
		sort(a+1,a+n+1);
		z=0;
		a[0]={1,1};
		for(i=1;i<=n;i++)
		{
			a[i].fr-=a[i].sc-1;
			y=a[i].fr;
			x=a[i].sc;
			y2=a[i-1].fr;
			x2=a[i-1].sc;
			z+=y-y2+x-x2-(y/2-y2/2+(x-x2)*(y/2*2>=(y2+1)/2*2));
		}
		printf("%lld\n",z);
	}
}