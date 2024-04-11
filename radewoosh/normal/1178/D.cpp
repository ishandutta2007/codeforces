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
int sito[nax];

vi pie;

int sto[nax];

void rek(int v, int kt, int m)
{
	if (v==n+1)
	{
		if (m&1)
			return;
		m/=2;
		if (sito[m] || sto[n]*2>m*2)
			return;
		printf("%d\n", m);
		vector <pii> wek;
		for (int i=1; i<=n; i++)
			wek.push_back({sto[i], i});
		while(!wek.empty())
		{
			sort(wek.begin(), wek.end());
			reverse(wek.begin(), wek.end());
			for (int i=1; i<=wek[0].first; i++)
				printf("%d %d\n", wek[0].second, wek[i].second), wek[i].first--;
			reverse(wek.begin(), wek.end());
			wek.pop_back();
		}
		
		
		exit(0);
	}
	for (int i=kt; i<(int)pie.size(); i++)
	{
		sto[v]=pie[i];
		rek(v+1, i, m+pie[i]);
	}
}

int main()
{
	scanf("%d", &n);
	for (int i=2; i<=n*n; i++)
		if (!sito[i])
			for (int j=2*i; j<=n*n; j+=i)
				sito[j]=1;
	for (int i=2; i<n; i++)
		if (!sito[i])
			pie.push_back(i);
	rek(1, 0, 0);
	printf("-1\n");
	return 0;
}