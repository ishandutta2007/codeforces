#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n;
pair<pair<long long,long long>,long long> a[100069];
multiset<pair<long long,long long>> ms;

int main()
{
	long long i,k,l,w,z=0;
	multiset<pair<long long,long long>>::iterator it;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld%lld",&k,&l,&w);
		a[i]={{l,k},w};
	}
	sort(a+1,a+n+1,greater<pair<pair<long long,long long>,long long>>());
	ms.insert({0,0});
	for(i=1;i<=n;i++)
	{
		l=a[i].fr.fr;
		k=a[i].fr.sc;
		w=a[i].sc;
		it=prev(ms.lower_bound({l,0}));
		w+=it->sc;
		z=max(z,w);
		for(it=ms.lower_bound({k,0});it!=ms.end()&&it->sc<=w;it++,ms.erase(prev(it)));
		ms.insert({k,w});
	}
	printf("%lld\n",z);
}