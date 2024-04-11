#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n;
pair<long long,long long> a[2069];
map<pair<pair<long long,long long>,pair<long long,long long>>,long long> fq;

int main()
{
	long long i,j,y,x,y2,x2,mny,mnx,z=0;
	pair<long long,long long> p,p2;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&y,&x);
		a[i]={y,x};
		for(j=1;j<i;j++)
		{
			y2=a[j].fr;
			x2=a[j].sc;
			mny=min(y,y2);
			mnx=min(x,x2);
			p={y-mny,x-mnx};
			p2={y2-mny,x2-mnx};
			if(p>p2)
			{
				swap(p,p2);
			}
			z+=fq[{p,p2}];
			fq[{p,p2}]++;
		}
	}
	printf("%lld\n",z/2);
}