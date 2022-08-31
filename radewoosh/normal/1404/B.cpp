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

int n, sa, sb, da, db;

vi graf[nax];

void ans(int v)
{
	if (v)
		printf("Alice\n");
	else
		printf("Bob\n");
}

int sre;
int ichodl;

int dfs1(int v, int oj, int cel, int gle)
{
	if (v==cel)
		ichodl=gle;
	int ret=0;
	for (int i : graf[v])
	{
		if (i==oj)
			continue;
		int x=dfs1(i, v, cel, gle+1)+1;
		sre=max(sre, ret+x);
		ret=max(ret, x);
	}
	return ret;
}

void test()
{
	scanf("%d%d%d%d%d", &n, &sa, &sb, &da, &db);
	for (int i=1; i<=n; i++)
		graf[i].clear();
	for (int i=1; i<n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	sre=0;
	dfs1(sa, 0, sb, 0);
	//~ debug() << sre << " " << da << " " << db << " " << ichodl;
	if (ichodl<=da)
	{
		ans(1);
	}
	else
	{
		if (2*da>=min(db, sre))
			ans(1);
		else
			ans(0);
	}
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}