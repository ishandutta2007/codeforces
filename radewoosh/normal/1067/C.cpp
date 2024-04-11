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

int n;
vector <pii> ruch;

pii rusz(pii a, pii b)
{
	return {a.first+b.first, a.second+b.second};
}

int powiedz(vector <pii> wek)
{
	set <pii> setel;
	queue <pii> kol;
	for (pii i : wek)
	{
		setel.insert(i);
		for (pii j : ruch)
			kol.push(rusz(i, j));
	}
	while(!kol.empty())
	{
		pii v=kol.front();
		kol.pop();
		if (setel.count(v))
			continue;
		int li=0;
		for (pii i : ruch)
			li+=setel.count(rusz(v, i));
		if (li>=4)
		{
			setel.insert(v);
			for (pii i : ruch)
				kol.push(rusz(v, i));
		}
	}
	return setel.size();
}

int main()
{
	scanf("%d", &n);
	for (int i=-2; i<=2; i++)
		for (int j=-2; j<=2; j++)
			if (i*i+j*j==5)
				ruch.push_back({i, j});
	vector < pair <int,pii> > wek;
	sort(wek.begin(), wek.end());
	for (int i=0; i<=10000; i++)
		for (int j=0; j<=10000 && (i<3 || j<3); j++)
			if ((i&1)==(j&1))
				wek.push_back({i+j, {i, j}});
	sort(wek.begin(), wek.end());
	vector <pii> chce;
	for (int i=0; i<n; i++)
		chce.push_back(wek[i].second);
	//~ debug() << imie(powiedz(chce)) << " na " << n*n/10;
	//~ int x=powiedz(chce);
	//~ debug() << imie(x-(n*n/10));
	//~ assert(x>=(n*n/10));
	for (pii i : chce)
		printf("%d %d\n", i.first, i.second);
	return 0;
}