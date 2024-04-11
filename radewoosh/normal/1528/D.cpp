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

vector<pii> graf[nax];

ll odl[nax];
int juz[nax];

void mini(ll &a, ll b)
{
	a=min(a, b);
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=m; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		graf[a].push_back({b, c});
	}
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
		{
			juz[j]=0;
			odl[j]=inf;
		}
		for (auto j : graf[i])
		{
			for (int p=0; p<n; p++)
			{
				int x=(j.first+p)%n;
				ll dlu=j.second+p;
				mini(odl[x], dlu);
			}
		}
		for (int h=0; h<n; h++)
		{
			int g=-1;
			for (int j=0; j<n; j++)
				if (!juz[j] && (g==-1 || odl[j]<odl[g]))
					g=j;
			juz[g]=1;
			for (int p=1; p<n; p++)
			{
				int x=(g+p)%n;
				mini(odl[x], odl[g]+p);
			}
			for (pii j : graf[g])
			{
				int cel=(odl[g]+j.first)%n;
				mini(odl[cel], odl[g]+j.second);
			}
		}
		odl[i]=0;
		for (int j=0; j<n; j++)
			printf("%lld ", odl[j]);
		printf("\n");
	}
	return 0;
}