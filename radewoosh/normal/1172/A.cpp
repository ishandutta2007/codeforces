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

int mam[nax];
int stos[nax];

int wyn=nax;

int kied[nax];

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		scanf("%d", &mam[i]);
	for (int i=1; i<=n; i++)
		scanf("%d", &stos[i]);
	
	
	int g=-1;
	for (int i=1; i<=n; i++)
		if (stos[i]==1)
			g=i;
	for (int i=1; i<=n; i++)
		kied[mam[i]]=0;
	for (int i=1; i<=n; i++)
		kied[stos[i]]=i;
	if (g!=-1)
	{
		int czy=1;
		for (int i=g+1; i<=n; i++)
			if (stos[i]!=stos[i-1]+1)
				czy=0;
		if (czy)
		{
			int s=n-g+1;
			for (int i=s+1; i<=n; i++)
				if (kied[i]>=i-s)
					czy=0;
			if (czy)
				wyn=min(wyn, n-s);
			debug() << imie(czy) << " " << imie(s); 
		}
	}
	debug() << range(kied+1, kied+1+n);
	int x=0;
	for (int i=1; i<=n; i++)
		x=max(x, kied[i]-i+1);
	wyn=min(wyn, x+n);
	
	printf("%d\n", wyn);
	return 0;
}