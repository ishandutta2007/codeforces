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
const int nax=2007;

int n, m;

char wcz[nax][nax];

vector <pii> poz[nax];

vector <pair<pii,pii> > odp;

pii zbliz(pii a, pii b)
{
	if (a.first<b.first)
		a.first++;
	if (a.first>b.first)
		a.first--;
	if (a.second<b.second)
		a.second++;
	if (a.second>b.second)
		a.second--;
	return a;
}

void nope()
{
	printf("NO\n");
}

void test()
{
	scanf("%d%d", &n, &m);
	for (int i='a'; i<='z'; i++)
		poz[i].clear();
	odp.clear();
	char naj='a'-1;
	for (int i=1; i<=n; i++)
	{
		scanf("%s", wcz[i]+1);
		for (int j=1; j<=m; j++)
		{
			if (wcz[i][j]!='.')
			{
				poz[wcz[i][j]].push_back({i, j});
				naj=max(naj, wcz[i][j]);
			}
		}
	}
	for (char i=naj; i>='a'; i--)
	{
		auto wez=poz[i];
		sort(wez.begin(), wez.end());
		if (wez.empty())
		{
			odp.push_back({{poz[naj][0]}, {poz[naj][0]}});
			continue;
		}
		pii x=wez[0];
		pii y=wez.back();
		if (x.first!=y.first && x.second!=y.second)
		{
			nope();
			return;
		}
		int licz=0;
		while(1)
		{
			if (wcz[x.first][x.second]!=i && wcz[x.first][x.second]!='?')
			{
				nope();
				return;
			}
			licz+=(wcz[x.first][x.second]==i);
			wcz[x.first][x.second]='?';
			if (x==y)
				break;
			x=zbliz(x, y);
		}
		if (licz!=(int)wez.size())
		{
			nope();
			return;
		}
		odp.push_back({poz[i][0], y});
	}
	
	printf("YES\n");
	reverse(odp.begin(), odp.end());
	printf("%d\n", (int)odp.size());
	for (auto i : odp)
		printf("%d %d %d %d\n", i.first.first, i.first.second, i.second.first, i.second.second);
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}