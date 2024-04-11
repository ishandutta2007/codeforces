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

vector<pll> graf[nax];
vector<pll> farg[nax];

int bylo[nax];
int czas;

int post[nax];

int spo[nax];

ll dz[nax];

ll war[nax];

void dfs1(int v)
{
	if (bylo[v])
		return;
	bylo[v]=1;
	for (pll i : graf[v])
		dfs1(i.first);
	czas++;
	post[czas]=v;
}

void dfs2(int v)
{
	if (spo[v])
		return;
	spo[v]=czas;
	for (pll i : farg[v])
	{
		if (spo[i.first])
		{
			if (spo[i.first]==spo[v])
			{
				int num=spo[v];
				ll w=abs(war[v]+i.second-war[i.first]);
				//~ debug() << war[v] << " " << i.second << " " << war[i.first];
				dz[num]=__gcd(dz[num], w);
			}
			continue;
		}
		war[i.first]=war[v]+i.second;
		dfs2(i.first);
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=m; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		graf[a].push_back({b, c});
		farg[b].push_back({a, c});
	}
	for (int i=1; i<=n; i++)
		dfs1(i);
	czas=0;
	for (int i=n; i; i--)
	{
		int v=post[i];
		if (spo[v])
			continue;
		czas++;
		dfs2(v);
	}
	//~ debug() << range(spo+1, spo+1+n);
	//~ debug() << range(war+1, war+1+n);
	//~ debug() << range(dz+1, dz+1+czas);
	int q;
	scanf("%d", &q);
	while(q--)
	{
		int v;
		ll s, t;
		scanf("%d%lld%lld", &v, &s, &t);
		t=__gcd(t, dz[spo[v]]);
		if (!(s%t))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}