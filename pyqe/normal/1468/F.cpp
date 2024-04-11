#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n;
pair<long long,long long> a[100069];
map<pair<long long,long long>,long long> fq;

int main()
{
	long long t,rr,i,y,x,y2,x2,gd,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		fq.clear();
		for(i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld%lld",&y,&x,&y2,&x2);
			y-=y2;
			x-=x2;
			gd=__gcd(abs(y),abs(x));
			y/=gd;
			x/=gd;
			a[i]={y,x};
			fq[{y,x}]++;
		}
		z=0;
		for(i=1;i<=n;i++)
		{
			z+=fq[{-a[i].fr,-a[i].sc}];
		}
		z/=2;
		printf("%lld\n",z);
	}
}