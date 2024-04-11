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
const int nax=2200*1007;
const int n1=(1<<20);

int n, m;

int ta[nax];
int tb[nax];

int narz[nax];
int pod[nax];

int daj(int v)
{
	return narz[v]+pod[v];
}

void upd(int v)
{
	pod[v]=max(daj(v*2), daj(v*2+1));
}

void pisz(int v, int a, int b, int graa, int grab, int w)
{
	if (a>=graa && b<=grab)
	{
		narz[v]+=w;
		return;
	}
	if (a>grab || b<graa)
	{
		return;
	}
	pisz((v<<1), a, (a+b)>>1, graa, grab, w);
	pisz((v<<1)^1, (a+b+2)>>1, b, graa, grab, w);
	upd(v);
}

int szuk(int v, int a, int b, int wie)
{
	if (a==b)
		return a;
	wie-=narz[v];
	if (daj(v*2+1)>wie)
		return szuk((v<<1)^1, (a+b+2)>>1, b, wie);
	return szuk((v<<1), a, (a+b)>>1, wie);
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; i++)
	{
		scanf("%d", &ta[i]);
		pisz(1, 1, n1, 1, ta[i], 1);
	}
	for (int i=1; i<=m; i++)
	{
		scanf("%d", &tb[i]);
		pisz(1, 1, n1, 1, tb[i], -1);
	}
	int q;
	scanf("%d", &q);
	while(q--)
	{
		int typ, a, b;
		scanf("%d%d%d", &typ, &a, &b);
		if (typ==1)
		{
			pisz(1, 1, n1, 1, ta[a], -1);
			ta[a]=b;
			pisz(1, 1, n1, 1, ta[a], 1);
		}
		else
		{
			pisz(1, 1, n1, 1, tb[a], 1);
			tb[a]=b;
			pisz(1, 1, n1, 1, tb[a], -1);
		}
		if (daj(1)<=0)
			printf("-1\n");
		else
			printf("%d\n", szuk(1, 1, n1, 0));
	}
	return 0;
}