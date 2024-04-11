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

int n, m;

vi graf[nax];
vi farg[nax];
ll tab[nax];
ll snor[nax];

ll wyn;

int tak[nax];

ll los[nax];

unordered_map <ll,ll> mapa;

void test()
{
	wyn=0;
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; i++)
		scanf("%lld", &tab[i]);
	for (int i=1; i<=n; i++)
	{
		graf[i].clear();
		farg[i].clear();
	}
	for (int i=1; i<=m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graf[a].push_back(b);
		farg[b].push_back(a);
	}
	for (int i=1; i<=n; i++)
	{
		ll x=0;
		for (int j : graf[i])
			x+=tab[j];
		wyn=__gcd(wyn, x);
		snor[i]=x;
	}
	for (int i=1; i<=n; i++)
	{
		los[i]=0;
		for (int j=0; j<60; j++)
			los[i]=los[i]*2+(rand()&1);
	}
	mapa.clear();
	for (int i=1; i<=n; i++)
	{
		ll x=0;
		for (int j : farg[i])
			x^=los[j];
		mapa[x]+=tab[i];
	}
	for (auto i : mapa)
		if (i.first)
			wyn=__gcd(wyn, i.second);
	//~ for (int h=0; h<50; h++)
	//~ {
		//~ for (int i=1; i<=n; i++)
			//~ tak[i]=0;
		//~ for (int i=1; i<=n; i++)
		//~ {
			//~ if (rand()&1)
				//~ continue;
			//~ for (int j : graf[i])
				//~ tak[j]=1;
		//~ }
		//~ ll x=0;
		//~ for (int i=1; i<=n; i++)
			//~ x+=tab[i]*tak[i];
		//~ wyn=__gcd(wyn, x);
	//~ }
	
	printf("%lld\n", wyn);
}

int main()
{
	srand(time(0));
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}