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
const int nax=607;
const ll inf=1e18;

int n, m;

ll mac[nax][nax];
ll floyd[nax][nax];

int q;
ll macpath[nax][nax];

int main()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			mac[i][j]=(i!=j)*inf;
	for (int i=1; i<=m; i++)
	{
		int a, b;
		ll c;
		scanf("%d%d%lld", &a, &b, &c);
		mac[a][b]=mac[b][a]=c;
	}
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			macpath[i][j]=-inf;
	scanf("%d", &q);
	for (int i=1; i<=q; i++)
	{
		int a, b;
		ll c;
		scanf("%d%d%lld", &a, &b, &c);
		macpath[a][b]=macpath[b][a]=c;
	}
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			floyd[i][j]=mac[i][j];
	for (int l=1; l<=n; l++)
		for (int i=1; i<=n; i++)
			for (int j=1; j<=n; j++)
				floyd[i][j]=min(floyd[i][j], floyd[i][l]+floyd[l][j]);
	for (int h=1; h<=2; h++)
	{
		for (int i=1; i<=n; i++)
			for (int j=1; j<=n; j++)
				for (int l=1; l<=n; l++)
					macpath[i][l]=max(macpath[i][l], macpath[i][j]-floyd[j][l]);
		for (int i=1; i<=n; i++)
			for (int j=1; j<=n; j++)
				macpath[j][i]=max(macpath[j][i], macpath[i][j]);
	}
	//~ for (int i=1; i<=n; i++)
		//~ debug() << range(floyd[i]+1, floyd[i]+1+n);
	//~ debug();
	//~ for (int i=1; i<=n; i++)
		//~ debug() << range(macpath[i]+1, macpath[i]+1+n);
	//~ debug();
	int wyn=0;
	for (int i=1; i<=n; i++)
		for (int j=1; j<i; j++)
			if (mac[i][j]<inf && mac[i][j]<=macpath[i][j])
				wyn++;
	
	printf("%d\n", wyn);
	return 0;
}