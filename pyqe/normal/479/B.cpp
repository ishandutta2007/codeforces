#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,d,zs=0;
multiset<pair<long long,long long>> ms;
multiset<pair<long long,long long>>::iterator it;
pair<long long,long long> sq[1069];

int main()
{
	long long i,k,w1,p1,w2,p2,z;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		ms.insert({k,i});
	}
	for(i=0;i<d;i++)
	{
		it=ms.begin();
		w1=(*it).fr;
		p1=(*it).sc;
		it=ms.end();
		it--;
		w2=(*it).fr;
		p2=(*it).sc;
		if(w1+1<=w2-1)
		{
			ms.erase(ms.begin());
			ms.erase(it);
			ms.insert({w1+1,p1});
			ms.insert({w2-1,p2});
			zs++;
			sq[zs]={p2,p1};
		}
		else
		{
			break;
		}
	}
	it=ms.begin();
	w1=(*it).fr;
	it=ms.end();
	it--;
	w2=(*it).fr;
	printf("%lld %lld\n",w2-w1,zs);
	for(i=1;i<=zs;i++)
	{
		printf("%lld %lld\n",sq[i].fr,sq[i].sc);
	}
}