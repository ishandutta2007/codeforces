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

void nope()
{
	printf("-1\n");
	exit(0);
}

int n, m;
int g, r;

int tab[nax];

bitset<1007> juz[10007];

ll podl(ll v)
{
	return v/g;
}

ll suf(ll v)
{
	return podl(v+g-1);
}

vi gdz[nax*10];

int main()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=m; i++)
		scanf("%d", &tab[i]);
	scanf("%d%d", &g, &r);
	sort(tab+1, tab+1+m);
	gdz[0].push_back(1);
	for (ll d=0; d<nax*10; d++)
	{
		for (int v : gdz[d])
		{
			//~ debug() << d << " " << v;
			int c=d%g;
			//~ debug() << "A";
			if (juz[v][c])
				continue;
			//~ debug() << "B";
			juz[v][c]=1;
			//~ debug() << "C";
			if (v==m)
			{
				printf("%lld\n", d+podl(d-1)*r);
				return 0;
			}
			if (v!=1)
			{
				//~ debug() << "a1";
				ll byloby=(d+tab[v]-tab[v-1]);
				//~ debug() << "b1";
				if (byloby<nax*10 && !juz[v-1][byloby%g] && podl(d)>=suf(byloby)-1)
				{
					gdz[byloby].push_back(v-1);
				}
				//~ debug() << "c1";
			}
			if (v!=m)
			{
				//~ debug() << "a2";
				ll byloby=(d+tab[v+1]-tab[v]);
				//~ debug() << "b2";
				if (byloby<nax*10 && !juz[v+1][byloby%g] && podl(d)>=suf(byloby)-1)
				{
					gdz[byloby].push_back(v+1);
				}
				//~ debug() << "c2";
			}
		}
	}
	nope();
	return 0;
}