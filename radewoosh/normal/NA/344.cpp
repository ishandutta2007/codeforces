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
const int nax=1000*1007;

int n;

char wcz[nax];

ll a[nax];
ll b[nax];

ll tab[nax];

ll ile[nax];

void nope()
{
	printf("-1\n");
	exit(0);
}

int jesz=1e5;

void dfs(int v)
{
	if (!ile[v] || !v || v==n)
		return;
	if (ile[v]>0)
	{
		if (a[v]>(v==1) && a[v+1]>0)
		{
			a[v]--;
			a[v+1]--;
			ile[v]--;
			printf("%d -1\n", v);
			jesz--;
			if (!jesz)
				exit(0);
			dfs(v-1);
			dfs(v);
			dfs(v+1);
		}
	}
	else
	{
		if (a[v]<9 && a[v+1]<9)
		{
			ile[v]++;
			a[v]++;
			a[v+1]++;
			printf("%d 1\n", v);
			jesz--;
			if (!jesz)
				exit(0);
			dfs(v-1);
			dfs(v);
			dfs(v+1);
		}
	}
}

int main()
{
	scanf("%d", &n);
	scanf("%s", wcz+1);
	for (int i=1; i<=n; i++)
		a[i]=wcz[i]-'0';
	scanf("%s", wcz+1);
	for (int i=1; i<=n; i++)
		b[i]=wcz[i]-'0';
	for (int i=1; i<=n; i++)
		tab[i]=a[i];
	for (int i=1; i<n; i++)
	{
		ll x=tab[i]-b[i];
		ile[i]=x;
		tab[i]-=x;
		tab[i+1]-=x;
	}
	//~ debug() << range(ile+1, ile+1+n);
	if (tab[n]!=b[n])
		nope();
	ll wyn=0;
	for (int i=1; i<n; i++)
		wyn+=abs(ile[i]);
	printf("%lld\n", wyn);
	for (int i=1; i<n; i++)
		dfs(i);
	return 0;
}