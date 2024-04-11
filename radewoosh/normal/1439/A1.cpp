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

int n, m;

char wcz[nax];
int tab[nax][nax];

vector<vi> wyn;

void zrob(vi wek)
{
	wyn.push_back(wek);
	tab[wek[0]][wek[1]]^=1;
	tab[wek[2]][wek[3]]^=1;
	tab[wek[4]][wek[5]]^=1;
}

void zrob(pii a, pii b, pii c)
{
	vi wek;
	wek.push_back(a.first);
	wek.push_back(a.second);
	wek.push_back(b.first);
	wek.push_back(b.second);
	wek.push_back(c.first);
	wek.push_back(c.second);
	zrob(wek);
}

void test()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; i++)
	{
		scanf("%s", wcz+1);
		for (int j=1; j<=m; j++)
		{
			tab[i][j]=(wcz[j]-'0');
		}
	}
	wyn.clear();
	for (int i=1; i+2<=n; i++)
	{
		for (int j=1; j<m; j++)
		{
			if (!tab[i][j] && !tab[i][j+1])
			{
				continue;
			}
			if (tab[i][j] && !tab[i][j+1])
			{
				zrob({i, j}, {i+1, j}, {i+1, j+1});
				continue;
			}
			if (!tab[i][j] && tab[i][j+1])
			{
				zrob({i, j+1}, {i+1, j}, {i+1, j+1});
				continue;
			}
			zrob({i, j}, {i, j+1}, {i+1, j+1});
		}
	}
	for (int i=1; i+2<=m; i++)
	{
		if (!tab[n-1][i] && !tab[n][i])
		{
			continue;
		}
		if (tab[n-1][i] && !tab[n][i])
		{
			zrob({n-1, i}, {n-1, i+1}, {n, i+1});
			continue;
		}
		if (!tab[n-1][i] && tab[n][i])
		{
			zrob({n, i}, {n-1, i+1}, {n, i+1});
			continue;
		}
		zrob({n-1, i}, {n, i}, {n, i+1});
	}
	vector<pii> dob, zle;
	for (int i=n-1; i<=n; i++)
	{
		for (int j=m-1; j<=m; j++)
		{
			if (tab[i][j])
				zle.push_back({i, j});
			else
				dob.push_back({i, j});
		}
	}
	if ((int)zle.size()==1)
	{
		vector<pii> tmp=dob;
		tmp.push_back(zle[0]);
		pii nie=zle.back();
		for (pii j : tmp)
		{
			if (j==nie)
				continue;
			vi wek;
			for (pii i : tmp)
			{
				if (i==j)
					continue;
				wek.push_back(i.first);
				wek.push_back(i.second);
			}
			zrob(wek);
		}
	}
	if ((int)zle.size()==2)
	{
		for (pii j : zle)
		{
			vi wek;
			wek.push_back(j.first);
			wek.push_back(j.second);
			for (pii i : dob)
			{
				wek.push_back(i.first);
				wek.push_back(i.second);
			}
			zrob(wek);
		}
	}
	if ((int)zle.size()==3)
	{
		vi wek;
		for (pii i : zle)
		{
			wek.push_back(i.first);
			wek.push_back(i.second);
		}
		zrob(wek);
	}
	if ((int)zle.size()==4)
	{
		for (pii j : zle)
		{
			vi wek;
			for (pii i : zle)
			{
				if (i==j)
					continue;
				wek.push_back(i.first);
				wek.push_back(i.second);
			}
			zrob(wek);
		}
	}
	//~ debug() << wyn;
	//~ for (int i=1; i<=n; i++)
		//~ debug() << range(tab[i]+1, tab[i]+1+n);
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
			assert(!tab[i][j]);
	
	printf("%d\n", (int)wyn.size());
	for (vi i : wyn)
	{
		for (int j : i)
			printf("%d ", j);
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