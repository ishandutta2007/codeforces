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
const int nax=107;

void ff()
{
	fflush(stdout);
}

int n;

ll tab[nax][nax];

void query()
{
	ll x;
	scanf("%lld", &x);
	vector<pii> wek;
	pii v={1, 1};
	wek.push_back(v);
	while(v.first<n && v.second<n)
	{
		int da=0;
		int db=0;
		if (tab[v.first+1][v.second])
			da=1;
		else
			db=1;
		ll y=tab[v.first+1][v.second]+tab[v.first][v.second+1];
		if (x&y)
		{
			v.first+=da;
			v.second+=db;
		}
		else
		{
			v.first+=(da^1);
			v.second+=(db^1);
		}
		wek.push_back(v);
	}
	while(v.first<n)
	{
		v.first++;
		wek.push_back(v);
	}
	while(v.second<n)
	{
		v.second++;
		wek.push_back(v);
	}
	for (pii i : wek)
		printf("%d %d\n", i.first, i.second);
	ff();
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=n; j++)
		{
			ll sum=i+j-2;
			ll roz=(i-j+n)/2;
			if (roz&1)
				tab[i][j]=(1LL<<sum);
		}
	}
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=n; j++)
			printf("%lld ", tab[i][j]);
		printf("\n");
	}
	ff();
	int q;
	scanf("%d", &q);
	while(q--)
		query();
	return 0;
}