#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,inf=1e18;
multiset<pair<long long,long long>> ms;
multiset<pair<long long,long long>>::iterator it,et;
double pi=acos(-1);

int main()
{
	long long i,k,l,w,ww,z=-inf;
	
	scanf("%lld",&n);
	ms.insert({0,0});
	for(i=0;i<n;i++)
	{
		scanf("%lld%lld",&k,&l);
		w=k*k*l;
		it=ms.lower_bound({w,0});
		it--;
		ww=w+(*it).sc;
		for(it++;it!=ms.end()&&(*it).sc<=ww;)
		{
			et=it;
			it++;
			ms.erase(et);
		}
		ms.insert({w,ww});
		z=max(z,ww);
	}
	printf("%.9lf\n",pi*z);
}