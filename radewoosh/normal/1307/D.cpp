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

int n, m, k;

vi spec;
vi graf[nax];

vi war[nax];

int odl[nax];

queue <int> kol;

vector <pii> faj;

void ans(int v)
{
	printf("%d\n", v);
	exit(0);
}

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i=1; i<=k; i++)
	{
		int x;
		scanf("%d", &x);
		spec.push_back(x);
	}
	for (int i=1; i<=m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	for (int h : {1, n})
	{
		for (int i=1; i<=n; i++)
			odl[i]=-1;
		odl[h]=0;
		kol.push(h);
		while(!kol.empty())
		{
			int v=kol.front();
			kol.pop();
			for (int i : graf[v])
			{
				if (odl[i]==-1)
				{
					odl[i]=odl[v]+1;
					kol.push(i);
				}
			}
		}
		for (int i=1; i<=n; i++)
			war[i].push_back(odl[i]);
	}
	for (int i : spec)
		faj.push_back({war[i][0], war[i][1]});
	debug() << imie(faj);
	sort(faj.begin(), faj.end());
	for (int i=1; i<k; i++)
		if (min(faj[i].first, faj[i-1].first)+min(faj[i].second, faj[i-1].second)+1>=war[n][0])
			ans(war[n][0]);
	int wyn=0;
	for (int i=1; i<k; i++)
		wyn=max(wyn, min(faj[i].first, faj[i-1].first)+min(faj[i].second, faj[i-1].second)+1);
	wyn=min(wyn, war[n][0]);
	ans(wyn);
	return 0;
}