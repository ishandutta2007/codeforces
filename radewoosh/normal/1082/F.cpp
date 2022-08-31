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
const int nax=507;
const int alfa=10;
const int kax=17;

int n, k;

int m;
vi graf[nax];
int syn[nax][alfa];

char wcz[nax];

int ile[nax];
int gle[nax];

ll dp[nax][nax][kax];

void dfs1(int v)
{
	for (int i : graf[v])
	{
		gle[i]=gle[v]+1;
		dfs1(i);
		ile[v]+=ile[i];
	}
}

ll naj1[kax];
ll naj2[kax];

void scal(int v, int u)
{
	for (int i=0; i<=m+1; i++)
		for (int j=0; j<=k+1; j++)
			dp[m+1][i][j]=0;
	for (int i=0; i<=m; i++)
		for (int j=0; j<=k; j++)
			dp[m+1][i][j]=dp[v][i][j];
	for (int i=0; i<=k; i++)
		naj1[i]=naj2[i]=0;
	for (int i=0; i<=m; i++)
	{
		for (int j=0; j<=k; j++)
		{
			naj1[j]=max(naj1[j], dp[m+1][i][j]);
			naj2[j]=max(naj2[j], dp[u][i][j]);
			naj2[j]=max(naj2[j], dp[u][i+1][j]);
		}
		for (int j=0; j<=k; j++)
			for (int l=0; j+l<=k; l++)
				dp[v][i][j+l]=max(dp[v][i][j+l], naj1[j]+naj2[l]);
	}
}

void dfs2(int v)
{
	for (int i : graf[v])
	{
		dfs2(i);
		scal(v, i);
	}
	for (int j=k; j>=0; j--)
		for (int l=1; l<=m; l++)
			dp[v][l][j+1]=max(dp[v][l][j+1], dp[v][0][j]+ile[v]*l);
}

int main()
{
	scanf("%d%d", &n, &k);
	for (int i=1; i<=n; i++)
	{
		scanf("%s", wcz+1);
		int v=0;
		for (int j=1; wcz[j]; j++)
		{
			int c=wcz[j]-'0';
			if (!syn[v][c])
			{
				m++;
				graf[v].push_back(m);
				syn[v][c]=m;
			}
			v=syn[v][c];
		}
		int x;
		scanf("%d", &x);
		ile[v]+=x;
	}
	dfs1(0);
	ll sum=0;
	for (int i=1; i<=m; i++)
		sum+=ile[i];
	ll wyn=0;
	dfs2(0);
	for (int j=0; j<=k; j++)
		wyn=max(wyn, dp[0][0][j]);
	
	
	printf("%lld\n", sum-wyn);
	return 0;
}