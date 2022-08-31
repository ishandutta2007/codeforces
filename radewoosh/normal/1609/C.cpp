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

int n, k;

int tab[nax];

int sito[nax];

ll wyn;

void test()
{
	scanf("%d%d", &n, &k);
	for (int i=1; i<=n; i++)
	{
		scanf("%d", &tab[i]);
	}
	wyn=0;
	for (int i=1; i<=k; i++)
	{
		int raz=0;
		int dwa=0;
		int tak=0;
		for (int j=i; j<=n; j+=k)
		{
			if (tab[j]==1)
			{
				raz++;
				dwa++;
			}
			else
			{
				raz++;
				dwa++;
				if (sito[tab[j]])
				{
					dwa=raz;
					raz=0;
					tak=0;
				}
				else
				{
					dwa=raz;
					raz=0;
					tak=1;
				}
			}
			if (tak)
				wyn+=max(dwa-1, 0)-max(raz-1, 0);
			//~ debug() << j << " " << imie(raz) << imie(dwa) << imie(tak);
		}
		//~ debug() << i << " " << imie(wyn);
	}
	printf("%lld\n", wyn);
}

int main()
{
	for (int i=2; i<nax; i++)
		if (!sito[i])
			for (int j=2*i; j<nax; j+=i)
				sito[j]=1;
	sito[1]=1;
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}