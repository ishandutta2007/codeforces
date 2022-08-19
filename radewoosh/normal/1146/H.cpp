//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
//~ #pragma GCC optimize("O3")
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
const int nax=307;
using bn=bitset <nax>;

int n;
pll tab[nax];

bn lewo[nax][nax];

ll wyn;

ll pie;
ll tro;
ll czw;

int spam[nax][nax][nax];

pll operator - (pll a, pll b)
{
	return {a.first-b.first, a.second-b.second};
}

ll ilowek(pll s, pll a, pll b)
{
	a=a-s;
	b=b-s;
	return a.first*b.second-a.second*b.first;
}

int srpre(int i, int j, int l)
{
	return (lewo[i][j]&lewo[j][l]&lewo[l][i]).count();
}

int sr(int i, int j, int l)
{
	return spam[i][j][l];
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		scanf("%lld%lld", &tab[i].first, &tab[i].second);
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			for (int l=1; l<=n; l++)
				lewo[i][j][l]=ilowek(tab[i], tab[j], tab[l])>0;
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=n; j++)
		{
			for (int l=1; l<=n; l++)
			{
				if (lewo[i][j][l])
				{
					if (i<j && i<l)
					{
						spam[i][j][l]=srpre(i, j, l);
					}
					if (j<i && j<l)
					{
						spam[i][j][l]=spam[j][l][i];
					}
					if (l<i && l<i)
					{
						spam[i][j][l]=spam[l][i][j];
					}
				}
			}
		}
	}
	pie=1;
	for (int i=1; i<=5; i++)
		pie*=n+1-i;
	for (int i=1; i<=5; i++)
		pie/=i;
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=n; j++)
		{
			for (int l=1; l<=n; l++)
			{
				if (lewo[i][j][l])
				{
					int x=sr(i, j, l);
					tro+=x*(x-1)/2;
				}
			}
		}
	}
	for (int i=1; i<=n; i++)
	{
		for (int j=i+1; j<=n; j++)
		{
			vector <pii> lew;
			vector <pii> pra;
			for (int l=1; l<=n; l++)
			{
				if (l==i || l==j)
					continue;
				if (lewo[i][j][l])
				{
					int x=sr(i, j, l);
					lew.push_back({l, x});
				}
				else
				{
					int x=sr(i, l, j);
					pra.push_back({l, x});
				}
			}
			for (const pii &aa : lew)
				for (const pii &bb : pra)
				{
					const int a=aa.first;
					const int b=bb.first;
					if (lewo[a][i][b] && lewo[b][j][a] && lewo[i][b][j] && lewo[j][a][i])
						czw+=aa.second+bb.second;
				}
		}
	}
	tro/=3;
	czw/=2;
	wyn=pie-tro-czw;
	printf("%lld\n", wyn);
	return 0;
}