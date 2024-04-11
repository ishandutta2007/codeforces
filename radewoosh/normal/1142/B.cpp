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
const ll inf=1e18;

int n, m, q;

int kt[nax];
int tab[nax];

vi gdz[nax];

vi graf[nax];

int kon[nax];

vi stos;

void dfs(int v)
{
	debug() << v;
	stos.push_back(v);
	if ((int)stos.size()>=n)
		kon[v]=stos[(int)stos.size()-n];
	else
		kon[v]=m+1;
	for (int i : graf[v])
		dfs(i);
	stos.pop_back();
}

int main()
{
	scanf("%d%d%d", &n, &m, &q);
	for (int i=1; i<=n; i++)
	{
		int x;
		scanf("%d", &x);
		kt[x]=i;
	}
	for (int i=1; i<=m; i++)
	{
		int x;
		scanf("%d", &x);
		tab[i]=kt[x]-1;
	}
	debug() << range(tab+1, tab+1+m);
	for (int i=0; i<n; i++)
		gdz[i].push_back(m+1);
	for (int i=m; i; i--)
	{
		int x=gdz[(tab[i]+1)%n].back();
		//~ gdz[(tab[i]+1)%n].pop_back();
		gdz[tab[i]].push_back(i);
		graf[x].push_back(i);
	}
	dfs(m+1);
	debug() << range(kon+1, kon+1+m);
	for (int i=m-1; i; i--)
		kon[i]=min(kon[i], kon[i+1]);
	debug() << range(kon+1, kon+1+m);
	while(q--)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%d", (int)(kon[a]<=b));
	}
	printf("\n");
	return 0;
}