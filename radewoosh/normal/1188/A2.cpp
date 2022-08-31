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
const int nax=1000*1007;

int n;

vi graf[nax];

vector <vi> chce;

int sto[nax];

vector <vi> wyn;

vi gl;

int szuk(int v, int oj)
{
	if (sto[v]==1)
		gl.push_back(v);
	for (int i : graf[v])
		if (i!=oj)
			szuk(i, v);
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<n; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		sto[a]++;
		sto[b]++;
		graf[a].push_back(b);
		graf[b].push_back(a);
		chce.push_back({a, b, c});
	}
	for (int i=1; i<=n; i++)
	{
		if (sto[i]==2)
		{
			printf("NO\n");
			return 0;
		}
	}
	for (auto i : chce)
	{
		vi raz, dwa;
		int a=i[0];
		int b=i[1];
		int x=i[2];
		if (sto[a]==1)
			raz={a, a};
		else
		{
			gl.clear();
			szuk(a, b);
			raz=vi{gl[0], gl.back()};
		}
		if (sto[b]==1)
			dwa={b, b};
		else
		{
			gl.clear();
			szuk(b, a);
			dwa=vi{gl[0], gl.back()};
		}
		wyn.push_back({raz[0], dwa[0], x/2});
		wyn.push_back({raz[1], dwa[1], x/2});
		if (raz[0]!=raz[1])
			wyn.push_back({raz[0], raz[1], -(x/2)});
		if (dwa[0]!=dwa[1])
			wyn.push_back({dwa[0], dwa[1], -(x/2)});
	}
	
	
	printf("YES\n");
	printf("%d\n", (int)wyn.size());
	for (auto i : wyn)
	{
		for (int j : i)
			printf("%d ", j);
		printf("\n");
	}
	return 0;
}