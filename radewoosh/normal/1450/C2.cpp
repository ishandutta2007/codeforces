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
const int nax=1007;

int n;

char wcz[nax][nax];

vector<pii> wek[2][3];

void zmien(pii v)
{
	int a=v.first;
	int b=v.second;
	wcz[a][b]^='O'^'X';
}

void test()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		scanf("%s", wcz[i]+1);
	}
	for (int i=0; i<3; i++)
	{
		wek[0][i].clear();
		wek[1][i].clear();
	}
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			if (wcz[i][j]!='.')
				wek[wcz[i][j]=='X'][(i+j)%3].push_back({i, j});
	int ile=1e9;
	pii par;
	for (int i=0; i<3; i++)
	{
		for (int j=0; j<3; j++)
		{
			if (i==j)
				continue;
			if ((int)wek[0][i].size()+(int)wek[1][j].size()<ile)
			{
				par={i, j};
				ile=(int)wek[0][i].size()+(int)wek[1][j].size();
			}
		}
	}
	//~ assert(ile<=k/3);
	for (pii i : wek[0][par.first])
		zmien(i);
	for (pii i : wek[1][par.second])
		zmien(i);
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=n; j++)
			printf("%c", wcz[i][j]);
		printf("\n");
	}
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}