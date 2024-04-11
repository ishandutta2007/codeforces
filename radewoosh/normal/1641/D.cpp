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
const int d=17;

int n, m;

vi wek[nax];
ll tab[nax];

int k;
map<int,int> mapa;

ll pod[nax];

int bit[nax];

ll wyn=inf;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve()
{
	for (int i=0; i<(1<<d); i++)
		pod[i]=inf;
	for (int i=1; i<=k; i++)
		bit[i]=rng()%d;
	for (int i=1; i<=n; i++)
	{
		int x=0;
		for (int j : wek[i])
			x|=(1<<bit[j]);
		pod[x]=min(pod[x], tab[i]);
	}
	for (int i=0; i<d; i++)
		for (int j=0; j<(1<<d); j++)
			if (j&(1<<i))
				pod[j]=min(pod[j], pod[j^(1<<i)]);
	for (int i=0; i<(1<<d); i++)
		wyn=min(wyn, pod[i]+pod[((1<<d)-1)^i]);
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=m; j++)
		{
			int x;
			scanf("%d", &x);
			wek[i].push_back(x);
			mapa[x]=0;
		}
		scanf("%lld", &tab[i]);
	}
	for (auto i : mapa)
	{
		k++;
		mapa[i.first]=k;
	}
	for (int i=1; i<=n; i++)
		for (int &j : wek[i])
			j=mapa[j];
	for (int h=0; h<50; h++)
		solve();
	if (wyn==inf)
		wyn=-1;
	printf("%lld\n", wyn);
	return 0;
}