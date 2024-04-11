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
const int d=62;
//~ const int d=4;

int n;
ll k;

vector <pair<int,ll> > graf[nax];

ll tab[nax];

void dfs(int v, ll w)
{
	tab[v]=w;
	for (auto i : graf[v])
		dfs(i.first, w^i.second);
}

ll par(const pii &v)
{
	ll x=v.second-v.first+1;
	return x*x;
}

int ciecie(pii v, int kt)
{
	for (int i=v.first; i<=v.second; i++)
		if (tab[i]&(1LL<<kt))
			return i-1;
	return v.second;
}

inline ll mno(const ll &a, const ll &b)
{
	return a*b;
}

vector <pair<pii,pii> > wek, pom;

void cons(pii a, pii b)
{
	//~ debug() << "dali " << a << " " << b;
	if (a.first<=a.second && b.first<=b.second)
		wek.push_back({a, b});
}

int main()
{
	scanf("%d%lld", &n, &k);
	for (int i=2; i<=n; i++)
	{
		int a;
		ll b;
		scanf("%d%lld", &a, &b);
		graf[a].push_back({i, b});
	}
	dfs(1, 0);
	sort(tab+1, tab+1+n);
	//~ debug() << range(tab+1, tab+1+n);
	wek.push_back({{1, n}, {1, n}});
	ll wyn=0;
	for (int h=d-1; h>=0; h--)
	{
		//~ debug();
		ll moz=0;
		for (auto i : wek)
		{
			int x=ciecie(i.first, h);
			int y=ciecie(i.second, h);
			//~ debug() << i << " " << x << " " << y;
			moz+=mno(x-i.first.first+1, y-i.second.first+1)+mno(i.first.second-x, i.second.second-y);
		}
		//~ debug() << h << " " << wek << " " << moz << " " << k;
		if (moz>=k)
		{
			//~ debug() << "nope";
			swap(pom, wek);
			wek.clear();
			for (auto i : pom)
			{
				int x=ciecie(i.first, h);
				int y=ciecie(i.second, h);
				cons({i.first.first, x}, {i.second.first, y});
				cons({x+1, i.first.second}, {y+1, i.second.second});
			}
		}
		else
		{
			k-=moz;
			wyn^=(1LL<<h);
			swap(pom, wek);
			wek.clear();
			for (auto i : pom)
			{
				int x=ciecie(i.first, h);
				int y=ciecie(i.second, h);
				cons({i.first.first, x}, {y+1, i.second.second});
				cons({x+1, i.first.second}, {i.second.first, y});
			}
		}
	}
	printf("%lld\n", wyn);
	
	return 0;
}