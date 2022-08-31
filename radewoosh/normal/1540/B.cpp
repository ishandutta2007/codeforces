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
const ll mod=1000*1000*1000+7;
const ll o2=(mod+1)/2;

int n;

vi graf[nax];

ll wyn;

ll inv(ll v)
{
	if (v<=1)
		return v;
	return inv(mod%v)*(mod-mod/v)%mod;
}

ll szan[nax][nax];

vector<pii> dfs1(int v, int oj)
{
	vector<pii> wek;
	for (int i : graf[v])
	{
		if (i==oj)
			continue;
		vector<pii> wez=dfs1(i, v);
		for (pii j : wez)
		{
			if (j.first<v)
				wyn++;
		}
		for (pii j : wez)
		{
			for (pii l : wek)
			{
				if (j.first<l.first)
					wyn+=szan[j.second+1][l.second];
				else
					wyn+=szan[l.second][j.second+1];
			}
		}
		for (pii l : wez)
			wek.push_back({l.first, l.second+1});
		wyn%=mod;
	}
	
	wek.push_back({v, 0});
	return wek;
}

int main()
{
	scanf("%d", &n);
	szan[0][0]=1;
	for (int i=1; i<=n; i++)
	{
		szan[i][0]=1;
		szan[0][i]=0;
	}
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=n; j++)
		{
			szan[i][j]=(szan[i-1][j]+szan[i][j-1])*o2%mod;
		}
	}
	for (int i=1; i<n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	for (int i=1; i<=n; i++)
		dfs1(i, 0);
	wyn*=inv(n);
	wyn%=mod;
	printf("%lld\n", wyn);
	return 0;
}