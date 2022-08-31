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

int n, m, k;

pair <ll,pii> kra[nax];

int ile[nax];
int oj[nax];

int fin(int v)
{
	if (v!=oj[v])
		oj[v]=fin(oj[v]);
	return oj[v];
}

int kto[nax];

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i=1; i<=k; i++)
	{
		scanf("%d", &kto[i]);
		ile[kto[i]]++;
	}
	for (int i=1; i<=m; i++)
	{
		ll a;
		int b, c;
		scanf("%d%d%lld", &c, &b, &a);
		kra[i]={a, {b, c}};
	}
	sort(kra+1, kra+1+m);
	for (int i=1; i<=n; i++)
		oj[i]=i;
	for (int i=1; i<=m; i++)
	{
		int a=kra[i].second.first;
		int b=kra[i].second.second;
		a=fin(a);
		b=fin(b);
		if (a==b)
			continue;
		if (ile[a]+ile[b]==k)
		{
			for (int j=1; j<=k; j++)
				printf("%lld ", kra[i].first);
			printf("\n");
			break;
		}
		ile[b]+=ile[a];
		oj[fin(a)]=fin(b);
	}
	return 0;
}