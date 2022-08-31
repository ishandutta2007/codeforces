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

int n, q;

int oj[nax];
int xo[nax];

unordered_map <int,int> mapa;

int dajnum(int v)
{
	if (!mapa.count(v))
	{
		n++;
		mapa[v]=n;
		oj[n]=n;
	}
	return mapa[v];
}

int fin(int v)
{
	if (v==oj[v])
		return v;
	int p=fin(oj[v]);
	xo[v]^=xo[oj[v]];
	oj[v]=p;
	return p;
}

void uni(int a, int b, int w)
{
	if (fin(a)==fin(b))
		return;
	w^=xo[a];
	w^=xo[b];
	a=fin(a);
	b=fin(b);
	oj[a]=b;
	xo[a]=w;
}

pii tlu(pii v)
{
	int a=dajnum(v.first);
	int b=dajnum(v.second+1);
	return {a, b};
}

int main()
{
	scanf("%d", &q);
	int zero=dajnum(0);
	int last=0;
	while(q--)
	{
		int typ;
		scanf("%d", &typ);
		if (typ==1)
		{
			int l, r, x;
			scanf("%d%d%d", &l, &r, &x);
			l^=last;
			r^=last;
			x^=last;
			if (l>r)
				swap(l, r);
			//~ debug() << l << " " << r << " " << x;
			pii v=tlu({l, r});
			uni(v.first, v.second, x);
		}
		else
		{
			int l, r;
			scanf("%d%d", &l, &r);
			l^=last;
			r^=last;
			if (l>r)
				swap(l, r);
			pii v=tlu({l, r});
			//~ debug() << l << " " << r;
			int ans=-1;
			if (fin(v.first)==fin(v.second))
				ans=xo[v.first]^xo[v.second];
			last=abs(ans);
			printf("%d\n", ans);
		}
	}
	return 0;
}