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
    tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

int tab[nax];

int drz[nax];

pii zap[nax];

vi jakie[nax];

int wyn[nax];

void dod(int v, int w)
{
	v++;
	for (int i=v; i; i-=(i&(-i)))
		drz[i]+=w;
}

void dod(int a, int b, int w)
{
	dod(b, w);
	dod(a-1, -w);
}

int licz(int v)
{
	v++;
	int ret=0;
	for (int i=v; i<nax; i+=(i&(-i)))
		ret+=drz[i];
	return ret;
}

int main()
{
	scanf("%d%d", &n, &q);
	for (int i=1; i<=n; i++)
	{
		scanf("%d", &tab[i]);
	}
	for (int i=1; i<=q; i++)
	{
		scanf("%d%d", &zap[i].first, &zap[i].second);
		jakie[n-zap[i].second].push_back(i);
	}
	for (int i=1; i<=n; i++)
	{
		if (tab[i]<=i)
		{
			int bsa=-1;
			int bsb=i-1;
			while(bsa<bsb)
			{
				int bss=(bsa+bsb+2)>>1;
				if (i-licz(bss)<=tab[i])
					bsa=bss;
				else
					bsb=bss-1;
			}
			//~ debug() << i << " " << bsa << " " << licz(bsa) << " " << tab[i];
			if (bsa!=-1)
			{
				dod(0, bsa, 1);
			}
		}
		//~ for (int j=0; j<=i; j++)
			//~ debug() << i << " " << j << " " << licz(j);
		for (int j : jakie[i])
			wyn[j]=licz(zap[j].first);
	}
	for (int i=1; i<=q; i++)
		printf("%d\n", wyn[i]);
	return 0;
}