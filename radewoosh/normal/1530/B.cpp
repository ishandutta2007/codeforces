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
const int nax=27;

int n, m;

int tab[nax][nax];

int odl(pii a, pii b)
{
	return max(abs(a.first-b.first), abs(a.second-b.second));
}

void test()
{
	scanf("%d%d", &n, &m);
	vector<pii> wsz;
	for (int i=2; i<=m; i++)
		wsz.push_back({1, i});
	for (int i=2; i<=n; i++)
		wsz.push_back({i, m});
	for (int i=m-1; i; i--)
		wsz.push_back({n, i});
	for (int i=n-1; i; i--)
		wsz.push_back({i, 1});
	vector<pii> wyn;
	int r=wsz.size()+7;
	while(r--)
	{
		wsz.push_back(wsz[0]);
		wsz.erase(wsz.begin());
		vector<pii> ter;
		for (pii i : wsz)
		{
			int ok=1;
			for (pii j : ter)
			{
				if (odl(i, j)<=1)
				{
					ok=0;
					continue;
				}
			}
			if (ok)
				ter.push_back(i);
		}
		if ((int)ter.size()>(int)wyn.size())
			wyn=ter;
	}
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
			tab[i][j]=0;
	for (pii i : wyn)
		tab[i.first][i.second]=1;
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=m; j++)
			printf("%d", tab[i][j]);
		printf("\n");
	}
	printf("\n");
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}