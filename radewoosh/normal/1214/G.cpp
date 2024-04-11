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
using bn=bitset<nax>;

int dajzap(bn &bicik)
{
	return bicik._Find_first();
}

int n, m, q;

bn tab[nax];
bn pref[nax];

set <pii> paryok;

set <pii> setel;

int spokosom(int a, int b)
{
	if ((int)tab[a].count()>(int)tab[b].count())
		swap(a, b);
	if ((tab[a]&tab[b])==tab[a])
		return 0;
	return 1;
}

void usun(int v)
{
	int x=tab[v].count();
	auto it=setel.find({x, v});
	int a=-1;
	int b=-1;
	if (it!=setel.begin())
	{
		it--;
		a=(*it).second;
		paryok.erase({a, v});
		paryok.erase({v, a});
		it++;
	}
	it++;
	if (it!=setel.end())
	{
		b=(*it).second;
		paryok.erase({v, b});
		paryok.erase({b, v});
	}
	setel.erase(setel.find({x, v}));
	if (a!=-1 && b!=-1 && spokosom(a, b))
	{
		paryok.insert({a, b});
		paryok.insert({b, a});
	}
}

void wstaw(int v)
{
	int x=tab[v].count();
	setel.insert({x, v});
	auto it=setel.find({x, v});
	
	int a=-1;
	int b=-1;
	if (it!=setel.begin())
	{
		it--;
		a=(*it).second;
		if (spokosom(v, a))
		{
			paryok.insert({a, v});
			paryok.insert({v, a});
		}
		it++;
	}
	it++;
	if (it!=setel.end())
	{
		b=(*it).second;
		if (spokosom(v, b))
		{
			paryok.insert({v, b});
			paryok.insert({b, v});
		}
	}
	if (a!=-1 && b!=-1)
	{
		paryok.erase({a, b});
		paryok.erase({b, a});
	}
}

bn raz, dwa, prz;

void query()
{
	int v, l, r;
	scanf("%d%d%d", &v, &l, &r);
	usun(v);
	tab[v]^=(pref[r]^pref[l-1]);
	wstaw(v);
	//~ debug() << paryok << " " << setel;
	if (paryok.empty())
	{
		printf("-1\n");
		return;
	}
	auto it=paryok.begin();
	int x=(*it).first;
	int y=(*it).second;
	prz=(tab[x]&tab[y]);
	raz=tab[x]^prz;
	dwa=tab[y]^prz;
	int ox=dajzap(raz);
	int oy=dajzap(dwa);
	if (x>y)
		swap(x, y);
	if (ox>oy)
		swap(ox, oy);
	assert((tab[x][ox]==tab[y][oy]) && (tab[x][oy]==tab[y][ox]) && (tab[x][ox]!=tab[x][oy]));
	printf("%d %d %d %d\n", x, ox, y, oy);
	//~ printf("0\n");
}

int main()
{
	scanf("%d%d%d", &n, &m, &q);
	//~ n=max(n, m);
	//~ m=max(n, m);
	for (int i=0; i<=m; i++)
		for (int j=1; j<=i; j++)
			pref[i][j]=1;
	for (int i=1; i<=n; i++)
		setel.insert({0, i});
	while(q--)
		query();
	return 0;
}