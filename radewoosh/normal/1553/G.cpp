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
const int nax=2000*1007;

int n, q;

int tab[nax];

vi graf[nax];

int sito[nax];

int oj[nax];

vi lista[nax];

int fin(int v)
{
	if (v!=oj[v])
		oj[v]=fin(oj[v]);
	return oj[v];
}

void uni(int a, int b)
{
	oj[fin(a)]=fin(b);
}

int main()
{
	for (int i=2; i<nax; i++)
		if (!sito[i])
			for (int j=i; j<nax; j+=i)
				sito[j]=i;
	scanf("%d%d", &n, &q);
	for (int i=1; i<=n; i++)
		scanf("%d", &tab[i]);
	for (int i=0; i<nax; i++)
		oj[i]=i;
	for (int i=1; i<=n; i++)
	{
		int x=tab[i];
		while(x>1)
		{
			uni(i, n+sito[x]);
			x/=sito[x];
		}
	}
	set<pii> pary;
	for (int i=1; i<=n; i++)
	{
		vi tu;
		int x=tab[i];
		while(x>1)
		{
			tu.push_back(sito[x]);
			x/=sito[x];
		}
		x=tab[i]+1;
		while(x>1)
		{
			tu.push_back(sito[x]);
			x/=sito[x];
		}
		for (int &j : tu)
			j=fin(n+j);
		sort(tu.begin(), tu.end());
		tu.resize(unique(tu.begin(), tu.end())-tu.begin());
		for (int j : tu)
		{
			for (int l : tu)
			{
				if (j<l)
					pary.insert({j, l});
			}
		}
	}
	while(q--)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		if (fin(a)==fin(b))
		{
			printf("0\n");
			continue;
		}
		a=fin(a);
		b=fin(b);
		if (a>b)
			swap(a, b);
		if (pary.count({a, b}))
		{
			printf("1\n");
		}
		else
		{
			printf("2\n");
		}
	}
	return 0;
}