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
const int nax=400*1007;

int n;

int tab[nax];

ll fen1[nax];
ll fen2[nax];

void pisz1(int v)
{
	v++;
	for (int i=v; i; i-=(i&(-i)))
		fen1[i]++;
}

ll czyt1(int v)
{
	v++;
	ll ret=0;
	for (int i=v; i<nax; i+=(i&(-i)))
		ret+=fen1[i];
	return ret;
}

void pisz2(int v, ll w)
{
	v++;
	for (int i=v; i<nax; i+=(i&(-i)))
		fen2[i]+=w;
}

ll czyt2(int v)
{
	v++;
	ll ret=0;
	for (int i=v; i; i-=(i&(-i)))
		ret+=fen2[i];
	return ret;
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		scanf("%d", &tab[i]);
	ll swsz=0;
	ll wyn=0;
	for (int i=1; i<=n; i++)
	{
		ll przezniego=swsz;
		for (int j=tab[i]; j<nax; j+=tab[i])
			przezniego-=czyt1(j)*tab[i];
		pisz1(tab[i]);
		//~ debug() << czyt2(tab[i]);
		ll niego=tab[i]*(ll)(i-1)-czyt2(tab[i]);
		for (int j=tab[i]; j<nax; j+=tab[i])
			pisz2(j, tab[i]);
		
		swsz+=tab[i];
		
		//~ debug() << i << " " << przezniego << " " << niego;
		wyn+=przezniego+niego;
		printf("%lld ", wyn);
	}
	printf("\n");
	return 0;
}