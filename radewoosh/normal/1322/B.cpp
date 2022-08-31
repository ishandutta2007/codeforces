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

int n;
ll tab[nax];

ll wyn;

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		scanf("%lld", &tab[i]);
	}
	for (int h=25; h>=0; h--)
	{
		for (int j=1; j<=n; j++)
			tab[j]%=(1<<(h+1));
		ll x=(1<<h);
		debug() << imie(x);
		sort(tab+1, tab+1+n);
		int w=0;
		ll ile=0;
		for (int i=1; i<=n; i++)
		{
			if (!(tab[i]&x))
			{
				while(w && tab[i]+tab[w]>=x)
					w--;
				//~ debug() << i << " " << w;
				ile+=(i-1)-w;
			}
			else
			{
				
			}
			w++;
		}
		w=0;
		int ost=0;
		debug() << imie(h) << imie(ile);
		debug() << range(tab+1, tab+1+n);
		for (int i=1; i<=n; i++)
		{
			if (!(tab[i]&x))
			{
			}
			else
			{
				while(w>0 && tab[i]+tab[w]>=2*x)
					w--;
				while(ost+1<i && tab[i]+tab[i-ost-1]>=3*x)
					ost++;
				while(ost>0 && (ost+w>=i || tab[i]+tab[i-ost]<3*x))
					ost--;
				//~ debug() << i << " " << w << " " << ost;
				//~ ile+=(i-1)-w-ost;
				ile+=w+ost;
			}
			//~ ost++;
			w++;
		}
		if (ile&1)
			wyn+=x;
	}
	printf("%lld\n", wyn);
	return 0;
}