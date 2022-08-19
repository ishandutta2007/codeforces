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

int n, m;

vi tab[nax];

ll sum[nax];
ll ory[nax];

int kto[nax];

int mniejsze(int a, int b)
{
	for (int i=1; i<=n; i++)
		if (tab[i][a]>tab[i][b])
			return 0;
	return 1;
}

void test()
{
	scanf("%d%d", &n, &m);
	for (int i=0; i<=n+2; i++)
		tab[i].resize(m+3);
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
			scanf("%d", &tab[i][j]);
	for (int i=1; i<=m; i++)
	{
		kto[i]=i;
		sum[i]=0;
		for (int j=1; j<=n; j++)
			sum[i]+=tab[j][i];
		ory[i]=sum[i];
	}
	sort(sum+1, sum+1+m);
	vi wek;
	for (int i=1; i<=m; i++)
		if (sum[i]!=ory[i])
			wek.push_back(i);
	if (wek.empty())
		wek.push_back(1);
	for (int a=0; a<(int)wek.size() && a<2; a++)
	{
		for (int b=0; b<a+(a==0); b++)
		{
			int x=wek[a];
			int y=wek[b];
			swap(kto[x], kto[y]);
			int spoko=1;
			for (int i=1; i<m; i++)
			{
				if (!mniejsze(kto[i], kto[i+1]))
				{
					spoko=0;
					break;
				}
			}
			if (spoko)
			{
				printf("%d %d\n", x, y);
				return;
			}
			swap(kto[x], kto[y]);
		}
	}
	printf("-1\n");
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}