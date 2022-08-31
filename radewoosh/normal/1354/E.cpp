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
const int nax=5007;

int n, m;
int k1, k2, k3;

vi graf[nax];

int w;
vi gdz[nax][2];
int kol[nax];

int bylo[nax];

void nope()
{
	printf("NO\n");
	exit(0);
}

void dfs(int v, int k)
{
	if (bylo[v])
	{
		if (bylo[v]!=k)
			nope();
		return;
	}
	bylo[v]=k;
	gdz[w][k&1].push_back(v);
	for (int i : graf[v])
		dfs(i, 3-k);
}

int dp[nax][nax];

void test()
{
	scanf("%d%d", &n, &m);
	scanf("%d%d%d", &k1, &k2, &k3);
	for (int i=1; i<=m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	for (int i=1; i<=n; i++)
	{
		if (bylo[i])
			continue;
		w++;
		dfs(i, 1);
	}
	dp[0][0]=1;
	for (int i=1; i<=w; i++)
	{
		for (int j=0; j<=n; j++)
		{
			if (dp[i-1][j])
			{
				dp[i][j+gdz[i][0].size()]=1;
				dp[i][j+gdz[i][1].size()]=1;
			}
		}
	}
	if (!dp[w][k2])
		nope();
	int v=k2;
	for (int i=w; i; i--)
	{
		int tu;
		if (v-(int)gdz[i][0].size()>=0 && dp[i-1][v-(int)gdz[i][0].size()])
		{
			tu=0;
			v-=gdz[i][0].size();
		}
		else
		{
			tu=1;
			v-=gdz[i][1].size();
		}
		for (int j : gdz[i][tu])
			kol[j]=2;
		for (int j : gdz[i][tu^1])
			kol[j]=1;
	}
	printf("YES\n");
	for (int i=1; i<=n; i++)
	{
		if (kol[i]==1 && k3)
		{
			k3--;
			kol[i]=3;
		}
		printf("%d", kol[i]);
	}
	printf("\n");
}

int main()
{
	int t;
	t=1;
	//~ scanf("%d", &t);
	while(t--)
		test();
	return 0;
}