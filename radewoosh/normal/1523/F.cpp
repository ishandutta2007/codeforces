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
#define int ll
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
const int nax=1000*1007;
const int inf=1007*1007*1007*(ll)1007;

int n, m;

pii wie[nax];
pair<int,pii> que[nax];

int wlasnie[1<<14][107];
int dopodz[1<<14][107];
int dopodz2[1<<14][17];
int dppod[1<<14][107];

int odl(pii a, pii b)
{
	return abs(a.first-b.first)+abs(a.second-b.second);
}

void mini(int &a, int b)
{
	a=min(a, b);
}

void maxi(int &a, int b)
{
	a=max(a, b);
}

signed main()
{
	scanf("%lld%lld", &n, &m);
	for (int i=0; i<n; i++)
		scanf("%lld%lld", &wie[i].first, &wie[i].second);
	for (int i=1; i<=m; i++)
	{
		int a, b, c;
		scanf("%lld%lld%lld", &a, &b, &c);
		que[i]={c, {a, b}};
	}
	sort(que+1, que+1+m);
	for (int i=1; i<=m; i++)
	{
		dopodz[0][i]=inf;
		for (int j=1; j<(1<<n); j++)
		{
			int x=__builtin_ctzll((ll)j);
			dopodz[j][i]=min(dopodz[j^(1<<x)][i], odl(que[i].second, wie[x]));
		}
	}
	for (int i=0; i<n; i++)
	{
		dopodz2[0][i]=inf;
		for (int j=1; j<(1<<n); j++)
		{
			int x=__builtin_ctzll((ll)j);
			dopodz2[j][i]=min(dopodz2[j^(1<<x)][i], odl(wie[i], wie[x]));
		}
	}
	for (int i=0; i<(1<<n); i++)
		for (int j=1; j<=m; j++)
			wlasnie[i][j]=-inf;
	for (int i=1; i<=m; i++)
		wlasnie[0][i]=1;
	for (int i=0; i<=m; i++)
		for (int j=0; j<(1<<n); j++)
			dppod[j][i]=inf;
	for (int i=0; i<n; i++)
		dppod[1<<i][0]=0;
	for (int i=0; i<(1<<n); i++)
	{
		for (int j=0; j<=m; j++)
		{
			for (int l=1; l<=m; l++)
			{
				if (dppod[i][j]+dopodz[i][l]<=que[l].first)
					maxi(wlasnie[i][l], j+1);
			}
		}
		for (int j=1; j<=m; j++)
		{
			for (int l=j+1; l<=m; l++)
			{
				if (min(odl(que[j].second, que[l].second), dopodz[i][l])<=que[l].first-que[j].first)
					maxi(wlasnie[i][l], wlasnie[i][j]+1);
			}
			if (wlasnie[i][j]>=0)
			{
				mini(dppod[i][wlasnie[i][j]], que[j].first);
				for (int l=0; l<n; l++)
					if (!(i&(1<<l)))
						mini(dppod[i^(1<<l)][wlasnie[i][j]], que[j].first+min(dopodz2[i][l], odl(que[j].second, wie[l])));
			}
		}
		for (int l=0; l<=m; l++)
			for (int j=0; j<n; j++)
				if (!(i&(1<<j)))
					mini(dppod[i^(1<<j)][l], dppod[i][l]+dopodz2[i][j]);
	}
	int wyn=0;
	for (int i=0; i<(1<<n); i++)
		for (int j=1; j<=m; j++)
			maxi(wyn, wlasnie[i][j]);
	printf("%lld\n", wyn);
	return 0;
}