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
const int nax=707;
using bn=bitset<nax>;

int n;

int tab[nax];
bn spok[nax];

bn dp[nax][nax];
bn pra[nax];
bn lew[nax];

void calc(int a, int b)
{
	for (int i=a; i<=b; i++)
	{
		if (lew[i][a] && pra[i][b])
		{
			dp[a][b][i]=1;
			if (spok[i][a-1])
				pra[a-1][b]=1;
			if (spok[i][b+1])
				lew[b+1][a]=1;
		}
	}
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		scanf("%d", &tab[i]);
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			if (__gcd(tab[i], tab[j])>1)
				spok[i][j]=1;
	for (int i=1; i<=n; i++)
		lew[i][i]=pra[i][i]=1;
	for (int i=1; i<=n; i++)
		for (int j=i; j; j--)
			calc(j, i);
	if (dp[1][n]==spok[0])
		printf("No\n");
	else
		printf("Yes\n");
	return 0;
}