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
const int nax=1100*1007;
const int n1=(1<<19);

int n;
vi graf[nax];

int l;
int pre[nax];
int post[nax];
int odl[nax];

ll drz[nax];

ll wyn[nax];

vector <pii> zbi;

void pisz(int a, int b, ll w)
{
	for (int i=b+1; i<=n; i+=(i&(-i)))
		drz[i]-=w;
	for (int i=a; i<=n; i+=(i&(-i)))
		drz[i]+=w;
}

ll czyt(int v)
{
	ll ret=0;
	for (int i=v; i; i-=(i&(-i)))
		ret+=drz[i];
	return ret;
}

void dfs1(int v, int oj)
{
	zbi.push_back({odl[v], v});
	l++;
	pre[v]=l;
	for (int i : graf[v])
	{
		if (i==oj)
			continue;
		odl[i]=odl[v]+1;
		dfs1(i, v);
	}
	post[v]=l;
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	dfs1(1, 0);
	int q;
	scanf("%d", &q);
	vector <pair<int,pii>> wek;
	while(q--)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		wek.push_back({odl[a]+b, {a, c}});
	}
	sort(zbi.begin(), zbi.end());
	sort(wek.begin(), wek.end());
	reverse(wek.begin(), wek.end());
	reverse(zbi.begin(), zbi.end());
	int w=0;
	for (auto i : zbi)
	{
		while (w<(int)wek.size() && wek[w].first>=i.first)
		{
			pisz(pre[wek[w].second.first], post[wek[w].second.first], wek[w].second.second);
			w++;
		}
		wyn[i.second]=czyt(pre[i.second]);
	}
	for (int i=1; i<=n; i++)
		printf("%lld ", wyn[i]);
	printf("\n");
	return 0;
}