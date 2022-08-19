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

pll tab[nax];

char wcz[nax];

pll operator - (pll a, pll b)
{
	return {a.first-b.first, a.second-b.second};
}

ll ilowek(int s, int a, int b)
{
	pll x=tab[a]-tab[s];
	pll y=tab[b]-tab[s];
	return x.first*y.second-x.second*y.first;
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		scanf("%lld%lld", &tab[i].first, &tab[i].second);
	scanf("%s", wcz+1);
	int s=1;
	for (int i=2; i<=n; i++)
		if (tab[i]<tab[s])
			s=i;
	vi jesz;
	printf("%d ", s);
	for (int i=1; i<=n; i++)
		if (i!=s)
			jesz.push_back(i);
	for (int i=1; i<=n-2; i++)
	{
		int v=jesz[0];
		if (wcz[i]=='L')
		{
			for (int j : jesz)
				if (ilowek(s, v, j)<0)
					v=j;
		}
		else
		{
			for (int j : jesz)
				if (ilowek(s, v, j)>0)
					v=j;
		}
		printf("%d ", v);
		for (int &j : jesz)
		{
			if (j==v)
			{
				swap(j, jesz.back());
				jesz.pop_back();
				break;
			}
		}
		s=v;
	}
	printf("%d", jesz[0]);
	printf("\n");
	return 0;
}