//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
//~ #pragma GCC optimize("O3")
#pragma GCC target ("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
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
const int nax=1007*1007;

int n, m;

int tab[5][nax];

char wcz[nax];

void nope()
{
	printf("-1\n");
	exit(0);
}

int wej[nax];

int juz[nax][8];
int dp[nax][8];

int pop(int v)
{
	return __builtin_popcount(v);
}

int czyok(int a, int b)
{
	a^=b;
	for (int i=1; i<n; i++)
	{
		int x=(a>>i)&1;
		int y=(a>>(i-1))&1;
		if (x==y)
			return 0;
	}
	return 1;
}

int rek(int v, int mas)
{
	if (juz[v][mas])
		return dp[v][mas];
	if (v==m)
		return 0;
	int ret=nax;
	for (int i=0; i<(1<<n); i++)
		if (czyok(mas, i))
			ret=min(ret, rek(v+1, i)+pop(i^wej[v+1]));
	
	
	juz[v][mas]=1;
	return dp[v][mas]=ret;
}

int main()
{
	scanf("%d%d", &n, &m);
	if (n>=4 && m>=4)
		nope();
	for (int i=1; i<=n; i++)
	{
		scanf("%s", wcz+1);
		for (int j=1; j<=m; j++)
		{
			tab[i][j]=wcz[j]-'0';
		}
	}
	int wyn=nax;
	for (int j=1; j<=m; j++)
		for (int i=1; i<=n; i++)
			wej[j]=(wej[j]*2+tab[i][j]);
	for (int i=0; i<(1<<n); i++)
		wyn=min(wyn, rek(1, i)+pop(i^wej[1]));
	if (wyn>=nax)
		wyn=-1;
	printf("%d\n", wyn);
	return 0;
}