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

int n;

char wcz[nax];

int tab[nax];

ll wyn;

vector<pll> wek;//dlu, war

ll ter, sum;

void pop1()
{
	sum-=wek.back().second;
	wek.back().first--;
	if (!wek.back().first)
		wek.pop_back();
}

void solve()
{
	for (int i=1; i<=n; i++)
	{
		if (tab[i]==1)
		{
			ter++;
			wyn-=(ter*(ter-1))/2;
		}
		else
		{
			for (int j=1; j<=ter; j++)
				pop1();
			for (int j=ter; j; j--)
			{
				sum+=j;
				wek.push_back({1, j});
			}
			ter=0;
		}
		ll kum=1;
		while(!wek.empty() && wek.back().second<=ter)
		{
			sum-=wek.back().first*wek.back().second;
			kum+=wek.back().first;
			wek.pop_back();
		}
		wek.push_back({kum, ter});
		sum+=wek.back().first*wek.back().second;
		wyn+=sum;
		//~ debug() << i << " " << wek << " " << sum;
	}
}

int main()
{
	scanf("%d", &n);
	scanf("%s", wcz+1);
	for (int i=1; i<=n; i++)
		tab[i]=(wcz[i]-'0');
	solve();
	printf("%lld\n", wyn);
	return 0;
}