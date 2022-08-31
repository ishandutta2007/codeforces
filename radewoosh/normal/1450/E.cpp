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
const int nax=1000*1007;

int n, m;

pii kra[nax];
int typ[nax];

vector<pii> graf[nax];

int odl[nax];

int poki=-1;
int wyn[nax];

void nope()
{
	printf("NO\n");
	exit(0);
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=m; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		if (c)
		{
			graf[a].push_back({b, 1});
			graf[b].push_back({a, -1});
		}
		else
		{
			graf[a].push_back({b, 1});
			graf[b].push_back({a, 1});
		}
		kra[i]={a, b};
		typ[i]=c;
	}
	for (int h=1; h<=n; h++)
	{
		for (int i=1; i<=n; i++)
			odl[i]=nax;
		odl[h]=n+7;
		for (int i=1; i<=n; i++)
			for (int j=1; j<=n; j++)
				for (pii l : graf[j])
					odl[l.first]=min(odl[l.first], odl[j]+l.second);
		int spoko=1;
		for (int i=1; i<=m; i++)
		{
			if (typ[i])
			{
				if (odl[kra[i].second]!=odl[kra[i].first]+1)
					spoko=0;
			}
			else
			{
				if (abs(odl[kra[i].second]-odl[kra[i].first])!=1)
					spoko=0;
			}
		}
		if (!spoko)
			continue;
		int maxi=-nax;
		int mini=nax;
		for (int i=1; i<=n; i++)
		{
			mini=min(mini, odl[i]);
			maxi=max(maxi, odl[i]);
		}
		int r=maxi-mini;
		if (r>poki)
		{
			poki=r;
			for (int i=1; i<=n; i++)
				wyn[i]=odl[i];
		}
	}
	if (poki==-1)
		nope();
	
	printf("YES\n");
	printf("%d\n", poki);
	for (int i=1; i<=n; i++)
		printf("%d ", wyn[i]);
	printf("\n");
	return 0;
}