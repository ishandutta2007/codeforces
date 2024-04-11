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
const int nax=1007;

void ff()
{
	fflush(stdout);
}

int n;
vi graf[nax];

vi moje, jego;

vi read()
{
	vi ret;
	int x, y;
	scanf("%d", &x);
	while(x--)
	{
		scanf("%d", &y);
		ret.push_back(y);
	}
	return ret;
}

int czyw(vi &wek, int v)
{
	for (int i : wek)
		if (i==v)
			return 1;
	return 0;
}

int dfs(int v, int oj)
{
	if (czyw(moje, v))
	{
		printf("A %d\n", v);
		ff();
		int w;
		scanf("%d", &w);
		if (czyw(jego, w))
			return v;
		return -1;
	}
	for (int i : graf[v])
	{
		if (i!=oj)
		{
			int x=dfs(i, v);
			if (x>0)
				return x;
		}
	}
	return -1;
}

void test()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		graf[i].clear();
	for (int i=1; i<n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	moje=read();
	jego=read();
	printf("B %d\n", jego[0]);
	ff();
	int x;
	scanf("%d", &x);
	//~ if (czyw(moje, x))
	//~ {
		//~ printf("C %d\n", x);
		//~ ff();
		//~ return;
	//~ }
	int w=dfs(x, 0);
	printf("C %d\n", w);
	ff();
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}