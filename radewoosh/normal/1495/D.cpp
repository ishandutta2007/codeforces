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
const int nax=1007;
const int inf=1e9;
const ll mod=998244353;

int n, m;

vi graf[nax];

int mac[nax][nax];

ll wyn[nax][nax];

ll f(int a, int b)
{
	ll ret=1;
	int ile=0;
	int ory=mac[a][b];
	for (int i=1; i<=n; i++)
		ile+=(mac[a][i]+mac[b][i]==ory);
	if (ile!=ory+1)
		return 0;
	for (int i=1; i<=n; i++)
	{
		if (mac[a][i]+mac[b][i]==ory)
			continue;
		ll tu=0;
		for (int j : graf[i])
			if (mac[a][j]+1==mac[a][i] && mac[b][j]+1==mac[b][i])
				tu++;
		ret=(ret*tu)%mod;
	}
	
	return ret;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			mac[i][j]=(i!=j)*inf;
	for (int i=1; i<=m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		mac[a][b]=mac[b][a]=1;
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			for (int l=1; l<=n; l++)
				mac[j][l]=min(mac[j][l], mac[j][i]+mac[i][l]);
	for (int i=1; i<=n; i++)
		for (int j=1; j<=i; j++)
			wyn[i][j]=wyn[j][i]=f(i, j);
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=n; j++)
			printf("%lld ", wyn[i][j]);
		printf("\n");
	}
	return 0;
}