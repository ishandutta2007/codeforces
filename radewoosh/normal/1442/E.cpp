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
const int inf=1e9;

int n;
int tab[nax];
vi graf[nax];

int dp[nax][3];

int wyn;

int glolim;

void dfs(int v, int oj)
{
	for (int i : graf[v])
	{
		if (i==oj)
			continue;
		dfs(i, v);
	}
	for (int h=1; h<=2; h++)
	{
		if ((tab[v]^h)==3)
		{
			dp[v][h]=inf;
			continue;
		}
		int a=0;
		int b=0;
		for (int i : graf[v])
		{
			if (i==oj)
				continue;
			int x=min(dp[i][h], dp[i][h^3]+1);
			if (x>=b)
			{
				a=b;
				b=x;
				continue;
			}
			if (x>=a)
				a=x;
		}
		if (a+b<=glolim)
			dp[v][h]=b;
		else
			dp[v][h]=inf;
	}
	for (int h=1; h<=2; h++)
		dp[v][h]=min(dp[v][h], inf);
	//~ debug() << v << "   " << dp[v][1] << " " << dp[v][2];
}

int check(int v)
{
	glolim=v;
	//~ debug() << imie(glolim);
	dfs(1, 0);
	return (dp[1][1]<inf || dp[1][2]<inf);
}

void test()
{
	scanf("%d", &n);
	int end=0;
	for (int i=1; i<=n; i++)
	{
		scanf("%d", &tab[i]);
		graf[i].clear();
		end|=tab[i];
	}
	for (int i=1; i<n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	if (end<3)
	{
		printf("1\n");
		return;
	}
	int bsa=0;
	int bsb=n;
	while(bsa<bsb)
	{
		int bss=(bsa+bsb)>>1;
		if (check(bss))
			bsb=bss;
		else
			bsa=bss+1;
	}
	//~ debug() << imie(bsa);
	printf("%d\n", (bsa+3)/2);
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}