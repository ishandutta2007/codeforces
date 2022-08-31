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
const int nax=3007;
const int inf=1e9;

int n;

int tab[nax];

int dpdow[nax][nax];
int dplew[nax][nax];
int dppra[nax][nax];

vi gdz[nax];

void mini(int &a, int b)
{
	a=min(a, b);
}

void test()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		gdz[i].clear();
	for (int i=1; i<=n; i++)
	{
		scanf("%d", &tab[i]);
		gdz[tab[i]].push_back(i);
	}
	for (int i=0; i<=n+1; i++)
	{
		for (int j=0; j<=n+1; j++)
		{
			dpdow[i][j]=dplew[i][j]=dppra[i][j]=inf;
		}
	}
	for (int i=1; i<=n; i++)
		dpdow[i][i]=dplew[i][i]=dppra[i][i]=0;
	for (int i=n; i; i--)
	{
		for (int j=i+1; j<=n; j++)
		{
			mini(dplew[i][j], dplew[i][j-1]+(tab[j]!=tab[i]));
			mini(dppra[i][j], dppra[i+1][j]+(tab[j]!=tab[i]));
			
			mini(dplew[i][j], dpdow[i+1][j]+1);
			mini(dppra[i][j], dpdow[i][j-1]+1);
			
			for (int l : gdz[tab[i]])
			{
				if (l>i && l<j)
					mini(dplew[i][j], dplew[i][l]+dplew[l][j]);
			}
			
			for (int l : gdz[tab[j]])
			{
				if (l>i && l<j)
					mini(dppra[i][j], dppra[l][j]+dppra[i][l]);
			}
			
			
			mini(dpdow[i][j], dplew[i][j]);
			mini(dpdow[i][j], dppra[i][j]);
		}
	}
	printf("%d\n", dpdow[1][n]);
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}