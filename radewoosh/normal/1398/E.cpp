//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
//~ #pragma GCC target ("avx2")
//~ #pragma GCC optimize("Ofast")
//~ #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//~ #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace __gnu_pbds;
using namespace std;
 
template <typename T>
using ordered_set =
	tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
	*this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
 
#define shandom_ruffle random_shuffle
 
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
const int nax=1000*1007;
const ll inf=1e18;

int q;

ll suma[2];
set<ll> setel[2];

ordered_set<ll> wsz;

ll najfaj;

ll pier(set<ll> &s)
{
	return (*s.begin());
}

ll ost(set<ll> &s)
{
	auto it=s.end();
	it--;
	return (*it);
}

int main()
{
	scanf("%d", &q);
	auto it=wsz.end();
	while(q--)
	{
		int t;
		ll x;
		scanf("%d%lld", &t, &x);
		if (x>0)
		{
			setel[t].insert(x);
			suma[t]+=x;
			wsz.insert(x);
			if (it!=wsz.end() && x>(*it))
				najfaj+=x;
		}
		else
		{
			setel[t].erase(-x);
			suma[t]-=-x;
			if (it!=wsz.end() && -x>(*it))
				najfaj-=-x;
			else if (it!=wsz.end() && -x==(*it))
			{
				najfaj-=-x;
				it++;
			}
			wsz.erase(-x);
		}
		int chce=setel[1].size();
		while(1)
		{
			int czy=0;
			int r=wsz.size();
			int p;
			if (it==wsz.end())
				p=0;
			else
				p=(int)wsz.size()-(int)wsz.order_of_key(*it);
			if (p<chce)
			{
				it--;
				najfaj+=(*it);
				czy=1;
			}
			if (it==wsz.end())
				p=0;
			else
				p=(int)wsz.size()-(int)wsz.order_of_key(*it);
			if (p>chce)
			{
				najfaj-=(*it);
				it++;
				czy=1;
			}
			if (!czy)
				break;
		}
		if (wsz.empty())
		{
			debug() << "a";
			printf("0\n");
		}
		else
		{
			if (najfaj!=suma[1] || !suma[1])
			{
				debug() << "b";
				printf("%lld\n", suma[0]+suma[1]+najfaj);
			}
			else
			{
				if (!suma[0])
				{
					debug() << "c";
					printf("%lld\n", suma[1]*2-pier(setel[1]));
				}
				else
				{
					debug() << "d";
					printf("%lld\n", suma[0]+suma[1]+najfaj-pier(setel[1])+ost(setel[0]));
				}
			}
		}
	}
	return 0;
}