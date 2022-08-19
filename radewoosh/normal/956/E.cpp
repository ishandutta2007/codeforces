//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
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
const int nax=10*1007;

int n, l, r;

bitset <nax> mog;
vector <int> wek;

pair <int,int> tab[nax];

int wyn;

int dp[2][nax];

int pun(int v)
{
	return (v>=l && v<=r);
}

void maxi(int &a, int b)
{
	a=max(a, b);
}

int main()
{
	scanf("%d%d%d", &n, &l, &r);
	for (int i=1; i<=n; i++)
		scanf("%d", &tab[i].first);
	for (int i=1; i<=n; i++)
		scanf("%d", &tab[i].second);
	mog[0]=1;
	int sum=0;
	for (int i=1; i<=n; i++)
	{
		sum+=tab[i].first;
		if (!tab[i].second)
			mog=(mog|(mog<<tab[i].first));
		else
			wek.push_back(tab[i].first);
	}
	sort(wek.begin(), wek.end());
	//~ reverse(wek.begin(), wek.end());
	for (int i=0; i<=sum; i++)
	{
		//~ dp[0][i]=-1e9;
		//~ if (!i)
			//~ dp[0][i]=0;
		dp[0][i]=0;
	}
	int juz=0;
	for (int i=0; i<(int)wek.size(); i++)
	{
		int h=(i&1);
		for (int j=sum; j>=0; j--)
			dp[h^1][j]=-1e9;
		for (int j=sum; j>=0; j--)
		{
			maxi(dp[h^1][j], dp[h][j]+pun(j+juz));
			if (j>=wek[i])
				maxi(dp[h^1][j-wek[i]], dp[h][j]);
			
			//~ dp[h^1][j-wek[i]]=max(dp[h^1][j-wek[i]], dp[h]+pun(j-wek[i]));
		}
		for (int j=0; j<=sum; j++)
			if (mog[j])
				maxi(wyn, dp[h^1][j]);
		juz+=wek[i];
	}
	printf("%d\n", wyn);
	return 0;
}