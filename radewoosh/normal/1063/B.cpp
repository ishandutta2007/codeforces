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
const int nax=2007;
const int inf=1e9;

int n, m;
pii sta;
int x, y;

char wcz[nax];

int tab[nax][nax];

int bylo[nax][nax];
int odl[nax][nax];
priority_queue <pair <int,pii>> kol;

int rx[]={1, -1, 0, 0};
int ry[]={0, 0, 1, -1};

int main()
{
	scanf("%d%d", &n, &m);
	scanf("%d%d", &sta.first, &sta.second);
	scanf("%d%d", &x, &y);
	for (int i=1; i<=n; i++)
	{
		scanf("%s", wcz+1);
		for (int j=1; j<=m; j++)
			tab[i][j]=(wcz[j]=='.');
	}
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
			odl[i][j]=inf;
	kol.push({0, sta});
	while(!kol.empty())
	{
		pii v=kol.top().second;
		if (bylo[v.first][v.second])
		{
			kol.pop();
			continue;
		}
		odl[v.first][v.second]=-kol.top().first;
		bylo[v.first][v.second]=1;
		kol.pop();
		for (int i=0; i<4; i++)
		{
			pii u={v.first+rx[i], v.second+ry[i]};
			if (tab[u.first][u.second] && !bylo[u.first][u.second])
				kol.push({-(odl[v.first][v.second]+(i>=2)), u});
		}
	}
	int wyn=0;
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=m; j++)
		{
			if (!bylo[i][j])
				continue;
			int lew, pra;
			if (j<=sta.second)
			{
				int w=sta.second-j;
				lew=w+(odl[i][j]-w)/2;
				pra=(odl[i][j]-w)/2;
			}
			else
			{
				int w=j-sta.second;
				pra=w+(odl[i][j]-w)/2;
				lew=(odl[i][j]-w)/2;
			}
			if (lew<=x && pra<=y)
				wyn++;
		}
	}
	printf("%d\n", wyn);
	return 0;
}