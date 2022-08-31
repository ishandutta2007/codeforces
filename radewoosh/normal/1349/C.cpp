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

int n, m, q;

char wcz[nax];
int tab[nax][nax];

int odl[nax][nax];

int rx[]={0, 0, -1, 1};
int ry[]={-1, 1, 0, 0};

int ist(pii v)
{
	return (v.first>=1 && v.second>=1 && v.first<=n && v.second<=m);
}

int main()
{
	scanf("%d%d%d", &n, &m, &q);
	for (int i=1; i<=n; i++)
	{
		scanf("%s", wcz+1);
		for (int j=1; j<=m; j++)
			tab[i][j]=(wcz[j]-'0');
	}
	queue<pii> kol;
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=m; j++)
		{
			odl[i][j]=-1;
			for (int l=0; l<4; l++)
			{
				pii w={i+rx[l], j+ry[l]};
				if (ist(w) && tab[w.first][w.second]==tab[i][j])
				{
					//~ debug() << "mam " << i << " " << j << " " << w;
					kol.push({i, j});
					odl[i][j]=0;
					break;
				}
			}
		}
	}
	while(!kol.empty())
	{
		pii v=kol.front();
		kol.pop();
		for (int i=0; i<4; i++)
		{
			pii u={v.first+rx[i], v.second+ry[i]};
			if (ist(u) && odl[u.first][u.second]==-1)
			{
				kol.push(u);
				odl[u.first][u.second]=odl[v.first][v.second]+1;
			}
		}
	}
	//~ for (int i=1; i<=n; i++)
		//~ for (int j=1; j<=m; j++)
			//~ debug() << i << " " << j << " " << odl[i][j];
	while(q--)
	{
		int a, b;
		ll c;
		scanf("%d%d%lld", &a, &b, &c);
		if (odl[a][b]==-1)
		{
			printf("%d\n", tab[a][b]);
			continue;
		}
		if (c<=odl[a][b])
		{
			printf("%d\n", tab[a][b]);
		}
		else
		{
			printf("%lld\n", (tab[a][b]+c-odl[a][b])%2);
		}
	}
	return 0;
}