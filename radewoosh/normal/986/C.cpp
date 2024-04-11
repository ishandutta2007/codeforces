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
const int d=23;
const int nax=(1<<d);

int n, m;
bitset <nax> tak;
vector <int> graf[nax];
int odw;

int l;
int post[nax];
int bylo[nax];

void dfs1(int v)
{
	bylo[v]=1;
	for (int i=0; i<n; i++)
		if ((v&(1<<i)))
			if (!bylo[v^(1<<i)])
				dfs1(v^(1<<i));
	if (tak[v])
		if (!bylo[v^odw])
			dfs1(v^odw);
	l++;
	post[l]=v;
}

int dfs2(int v)
{
	bylo[v]=1;
	int ret=0;
	if (tak[v])
		ret=1;
	for (int i=0; i<n; i++)
		if (!(v&(1<<i)))
			if (!bylo[v^(1<<i)])
				ret|=dfs2(v^(1<<i));
	if (tak[v^odw])
		if (!bylo[v^odw])
			ret|=dfs2(v^odw);
	return ret;
}

int main()
{
	scanf("%d%d", &n, &m);
	odw=(1<<n)-1;
	for (int i=0; i<m; i++)
	{
		int x;
		scanf("%d", &x);
		//~ x=i;
		tak[x]=1;
	}
	dfs1(odw);
	memset(bylo, 0, sizeof(bylo));
	int wyn=0;
	for (int i=(1<<n); i; i--)
	{
		if (bylo[post[i]])
			continue;
		wyn+=dfs2(post[i]);
	}
	printf("%d\n", wyn);
	return 0;
}