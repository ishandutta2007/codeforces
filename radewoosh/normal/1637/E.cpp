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
pll zle[nax];
ll warzle[nax];

map<ll,int> mapa;
map<int,vll> tyle;

ll wyn;

set<pll> pary;

set<pll> bylo;

void test()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; i++)
		scanf("%lld", &tab[i]);
	mapa.clear();
	tyle.clear();
	pary.clear();
	for (int i=1; i<=n; i++)
		mapa[tab[i]]++;
	for (auto i : mapa)
		tyle[i.second].push_back(i.first);
	for (int i=1; i<=m; i++)
	{
		ll a, b;
		scanf("%lld%lld", &a, &b);
		pary.insert({a, b});
		pary.insert({b, a});
		zle[i]={a, b};
		warzle[i]=(mapa[a]+mapa[b])*(a+b);
	}
	wyn=0;
	for (auto &i : tyle)
		sort(i.second.begin(), i.second.end());
	//~ debug() << pary;
	for (auto i : tyle)
	{
		for (auto j : tyle)
		{
			bylo.clear();
			ll mno=(i.first+j.first);
			vll &raz=i.second;
			vll &dwa=j.second;
			queue<pii> kol;
			kol.push({(int)raz.size()-1, (int)dwa.size()-1});
			while(!kol.empty())
			{
				int a=kol.front().first;
				int b=kol.front().second;
				kol.pop();
				if (a<0 || b<0)
					continue;
				if (bylo.count({a, b}))
					continue;
				bylo.insert({a, b});
				if (raz[a]==dwa[b] || pary.count({raz[a], dwa[b]}))
				{
					kol.push({a-1, b});
					kol.push({a, b-1});
					continue;
				}
				//~ if ((raz[a]+dwa[b])*mno==16)
					//~ debug() << raz << " " << dwa << " " << a << " " << b;
				wyn=max(wyn, (raz[a]+dwa[b])*mno);
			}
			
			if (i.first==j.first)
				break;
		}
	}
	
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