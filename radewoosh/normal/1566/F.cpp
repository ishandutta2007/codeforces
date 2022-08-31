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

int n, m;

ll tab[nax];

pll odc[nax];

vector<pll> wek[nax];

ll dppow[nax];
ll dpnie[nax];

void mini(ll &a, ll b)
{
	a=min(a, b);
}

bool mniej(pll a, pll b)
{
	return a.second<b.second;
}

void test()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; i++)
		scanf("%lld", &tab[i]);
	sort(tab+1, tab+1+n);
	for (int i=0; i<=n+1; i++)
		wek[i].clear();
	for (int i=1; i<=m; i++)
	{
		ll a, b;
		scanf("%lld%lld", &a, &b);
		int x=lower_bound(tab+1, tab+1+n, a)-tab;
		if (x<=n && tab[x]<=b)
		{
			i--;
			m--;
		}
		else
		{
			odc[i]={a, b};
			wek[x].push_back({a, b});
		}
	}
	//~ debug() << imie(n) << imie(m);
	//~ for (int i=1; i<=n+1; i++)
	//~ {
		//~ debug() << wek[i];
	//~ }
	for (int i=1; i<=n; i++)
		dppow[i]=dpnie[i]=inf;
	if (wek[1].empty())
	{
		dppow[1]=dpnie[1]=0;
	}
	else
	{
		ll najd=0;
		for (pll i : wek[1])
			najd=max(najd, tab[1]-i.second);
		dppow[1]=najd*2;
		dpnie[1]=najd;
	}
	for (int i=2; i<=n; i++)
	{
		sort(wek[i].begin(), wek[i].end(), mniej);
		ll musz=0;
		for (pll j : wek[i])
		{
			ll tu=tab[i]-j.second;
			mini(dppow[i], dpnie[i-1]+2*musz+2*tu);
			mini(dppow[i], dppow[i-1]+musz+2*tu);
			mini(dpnie[i], dpnie[i-1]+2*musz+tu);
			mini(dpnie[i], dppow[i-1]+musz+tu);
			musz=max(musz, j.first-tab[i-1]);
		}
		mini(dppow[i], dppow[i-1]+musz);
		mini(dppow[i], dpnie[i-1]+2*musz);
		mini(dpnie[i], dppow[i]);
	}
	ll najd=0;
	for (pll i : wek[n+1])
		najd=max(najd, i.first-tab[n]);
	ll wyn=min(dppow[n]+najd, dpnie[n]+2*najd);
	printf("%lld\n", wyn);
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}