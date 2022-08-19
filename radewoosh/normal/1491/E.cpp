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
const int nax=200*1007;
const ll inf=1e9;
const int d=29;

void ans(int v)
{
	//~ assert(v);
	printf(v ? "YES\n" : "NO\n");
	exit(0);
}

int n;
vi graf[nax];

int fib[nax];

int ile[nax][d+3];

void dfs(int v, int oj)
{
	for (int i : graf[v])
	{
		if (i==oj)
			continue;
		dfs(i, v);
		for (int j=1; j<=d; j++)
			ile[v][j]+=ile[i][j];
	}
	int x=1;
	while(1)
	{
		if (ile[v][max(x-1, 1)])
		{
			ile[v][max(x-1, 1)]--;
			x++;
			continue;
		}
		if (ile[v][x+1] && !ile[v][x])
		{
			ile[v][x+1]--;
			x+=2;
			continue;
		}
		break;
	}
	//~ debug() << v << " " << range(ile[v]+1, ile[v]+1+d) << " " << x;
	for (int i=1; i<x; i++)
		if (ile[v][i])
			ans(0);
	ile[v][x]++;
	//~ debug() << v << " " << range(ile[v]+1, ile[v]+1+d);
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
	fib[1]=1;
	for (int i=2; i<=d; i++)
		fib[i]=fib[i-1]+fib[i-2];
	//~ debug() << range(fib, fib+1+d);
	int g=0;
	for (int i=1; i<=d; i++)
		if (fib[i]==n)
			g=i-1;
	if (!g)
		ans(0);
	dfs(1, 0);
	debug() << imie(g);
	ans(ile[1][g]);
	return 0;
}