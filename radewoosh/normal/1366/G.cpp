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
const int nax=10*1007;
const ll mod=998244353;

int n, m;

char raz[nax];
char dwa[nax];

int dp[nax][nax];

int nast[nax];

void mini(int &a, int b)
{
	a=min(a, b);
}

void test()
{
	scanf("%s", raz+1);
	scanf("%s", dwa+1);
	n=strlen(raz+1);
	m=strlen(dwa+1);
	for (int i=0; i<=n; i++)
		for (int j=0; j<=m; j++)
			dp[i][j]=nax;
	dp[0][0]=0;
	for (int i=1; i<=n; i++)
	{
		if (raz[i]=='.')
			continue;
		int bil=0;
		for (int j=i; j<=n; j++)
		{
			if (raz[j]!='.')
			{
				bil++;
			}
			else
			{
				bil--;
			}
			if (!bil)
			{
				nast[i]=j;
				break;
			}
		}
	}
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<=m; j++)
		{
			if (j<m && raz[i+1]==dwa[j+1])
				mini(dp[i+1][j+1], dp[i][j]);
			mini(dp[i+1][j], dp[i][j]+1);
			if (nast[i+1])
				mini(dp[nast[i+1]][j], dp[i][j]);
		}
	}
	
	printf("%d\n", dp[n][m]);
}

int main()
{
	int t;
	//~ scanf("%d", &t);
	t=1;
	while(t--)
		test();
	return 0;
}