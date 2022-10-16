#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const long long inf=1e18;
long long n,m;
multiset<pair<long long,long long>> ms[100069];

int main()
{
	long long i,k,l,w,w2,z=0;
	multiset<pair<long long,long long>>::iterator it;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		ms[i].insert({-inf,0});
	}
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld%lld",&k,&l,&w);
		it=prev(ms[k].lower_bound({w,-inf}));
		w2=it->sc+1;
		z=max(z,w2);
		it=prev(ms[l].upper_bound({w,inf}));
		if(it->sc<w2)
		{
			for(it=ms[l].lower_bound({w,-inf});it!=ms[l].end()&&it->sc<=w2;)
			{
				it++;
				ms[l].erase(prev(it));
			}
			ms[l].insert({w,w2});
		}
	}
	printf("%lld\n",z);
}