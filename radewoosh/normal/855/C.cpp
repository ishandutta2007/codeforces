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
const int nax=100*1007;
const ll mod=1000*1000*1000+7;

int n;
vi graf[nax];

ll m, k;
int x;

ll wla[nax][12];
ll mal[nax][12];
ll duz[nax][12];

void dod(ll &a, ll b)
{
	a=(a+b)%mod;
}

void pisz(int v, int u)
{
	for (int i=0; i<=x; i++)
	{
		wla[0][i]=wla[v][i];
		wla[v][i]=0;
		
		mal[0][i]=mal[v][i];
		mal[v][i]=0;
		
		duz[0][i]=duz[v][i];
		duz[v][i]=0;
	}
	for (int i=0; i<=x; i++)
	{
		for (int j=0; i+j<=x; j++)
		{
			dod(wla[v][i+j], wla[0][i]*mal[u][j]);
			dod(mal[v][i+j], mal[0][i]*(wla[u][j]+mal[u][j]+duz[u][j]));
			dod(duz[v][i+j], duz[0][i]*(mal[u][j]+duz[u][j]));
		}
	}
}

void dfs(int v, int oj)
{
	wla[v][1]=1;
	mal[v][0]=k-1;
	duz[v][0]=m-k;
	for (int i : graf[v])
	{
		if (i==oj)
			continue;
		dfs(i, v);
		pisz(v, i);
	}
}

int main()
{
	scanf("%d%lld", &n, &m);
	for (int i=1; i<n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	scanf("%lld%d", &k, &x);
	dfs(1, 0);
	ll wyn=0;
	for (int i=0; i<=x; i++)
		dod(wyn, wla[1][i]+mal[1][i]+duz[1][i]);
	printf("%lld\n", wyn);
	return 0;
}