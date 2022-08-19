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
const int nax=100*1007;

int n;

double tab[nax];
double sum[nax];

int oj[nax];

double wyn;

vi graf[nax];

void dfs(int v)
{
	wyn+=tab[v];
	for (int i : graf[v])
	{
		if (oj[v]==i)
			continue;
		wyn-=tab[v]*tab[i];
		sum[v]+=tab[i];
		oj[i]=v;
		dfs(i);
	}
}

void zrob(int v, double m)
{
	wyn+=tab[v]*m;
	wyn-=tab[v]*sum[v]*m;
	wyn-=tab[oj[v]]*tab[v]*m;
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		scanf("%lf", &tab[i]);
		tab[i]=1-tab[i];
	}
	for (int i=1; i<n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a++;
		b++;
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	dfs(1);
	//~ debug() << imie(wyn);
	int q;
	scanf("%d", &q);
	while(q--)
	{
		int v;
		double x;
		scanf("%d%lf", &v, &x);
		v++;
		x=1-x;
		zrob(v, -1);
		sum[oj[v]]-=tab[v];
		tab[v]=x;
		sum[oj[v]]+=tab[v];
		zrob(v, 1);
		printf("%.7lf\n", wyn);
	}
	return 0;
}