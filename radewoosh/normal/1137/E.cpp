//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
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
const ll inf=3e18;

ll n;
int q;

ll gb;
ll gs;
set <pll> setel;

priority_queue <pll> kol;

void czys()
{
	while(!kol.empty())
		kol.pop();
}

ll eva(pll v)
{
	return v.second+gb+v.first*gs;
}

void popuj()
{
	while(!kol.empty())
	{
		auto v=kol.top();
		v.first*=-1;
		if (v.first>gs)
			break;
		kol.pop();
		ll x=v.second;
		
		auto it=setel.lower_bound({x, -inf});
		if (it==setel.end() || (*it).first!=x || it==setel.begin())
			continue;
		
		auto jt=it;
		jt--;
		
		if (eva(*jt)>eva(*it))
			continue;
		
		auto kt=it;
		kt++;
		setel.erase(it);
		
		if (kt!=setel.end())
		{
			ll roz=(*kt).first-(*jt).first;
			ll wary=eva(*jt)-eva(*kt);
			if (wary<=0)
				kol.push({1, (*kt).first});
			else
				kol.push({-(gs+(wary+roz-1)/roz), (*kt).first});
		}
	}
}

void ans()
{
	auto it=setel.end();
	it--;
	printf("%lld %lld\n", (*it).first+1, eva(*it));
}

int main()
{
	scanf("%lld%d", &n, &q);
	setel.insert({0, 0});
	while(q--)
	{
		int typ;
		scanf("%d", &typ);
		if (typ==1)
		{
			ll v;
			scanf("%lld", &v);
			n+=v;
			czys();
			setel.clear();
			setel.insert({0, 0});
			gb=0;
			gs=0;
		}
		if (typ==2)
		{
			ll v;
			scanf("%lld", &v);
			
			auto it=setel.end();
			it--;
			pll x=(*it);
			ll roz=n-x.first;
			ll tam=eva(x);
			ll kied=(tam+roz-1)/roz;
			kol.push({-(kied+gs), n});
			
			ll w=eva({n, 0});
			setel.insert({n, -w});
			n+=v;
		}
		if (typ==3)
		{
			ll b, s;
			scanf("%lld%lld", &b, &s);
			gb+=b;
			gs+=s;
		}
		popuj();
		//~ debug() << n << " " << setel;
		ans();
	}
	return 0;
}