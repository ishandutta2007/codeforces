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
const int nax=107;

int n, m;

char wcz[nax][nax];

int rx[]={-1, 1, 0, 0};
int ry[]={0, 0, -1, 1};

void ans(int v)
{
	if (v)
		printf("Yes\n");
	else
		printf("No\n");
}

int dasie[nax][nax];

void dfs(int a, int b)
{
	if (dasie[a][b] || wcz[a][b]=='#')
		return;
	dasie[a][b]=1;
	for (int i=0; i<4; i++)
		dfs(a+rx[i], b+ry[i]);
}

void test()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
			dasie[i][j]=0;
	for (int i=1; i<=n; i++)
		scanf("%s", wcz[i]+1);
	for (int i=0; i<=m+1; i++)
		wcz[0][i]=wcz[n+1][i]='#';
	for (int i=0; i<=n+1; i++)
		wcz[i][0]=wcz[i][m+1]='#';
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=m; j++)
		{
			if (wcz[i][j]!='B')
				continue;
			for (int l=0; l<4; l++)
			{
				int a=i+rx[l];
				int b=j+ry[l];
				if (wcz[a][b]=='G')
				{
					ans(0);
					return;
				}
				if (wcz[a][b]=='B')
					continue;
				wcz[a][b]='#';
			}
		}
	}
	dfs(n, m);
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=m; j++)
		{
			if (wcz[i][j]=='G' && !dasie[i][j])
			{
				ans(0);
				return;
			}
		}
	}
	ans(1);
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}