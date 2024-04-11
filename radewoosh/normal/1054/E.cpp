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
const int nax=307;
const int vax=1000*1007;

int n, m;

char wcz[vax];

queue <int> jest[nax][nax];
vi cel[nax][nax];

vector <pair<pii,pii> > wyn;

void zrob(pii a, pii b)
{
	wyn.push_back({a, b});
	assert(a!=b);
	assert(a.first==b.first || a.second==b.second);
	assert(!jest[a.first][a.second].empty());
	jest[b.first][b.second].push(jest[a.first][a.second].front());
	jest[a.first][a.second].pop();
}

vi czyt()
{
	vi ret;
	scanf("%s", wcz+1);
	for (int i=1; wcz[i]; i++)
		ret.push_back(wcz[i]-'0');
	return ret;
}

void zrob_pio(pii a, pii b)
{
	if (a.first!=b.first)
		zrob(a, {b.first, a.second});
	if (a.second!=b.second)
		zrob({b.first, a.second}, b);
}

void zrob_poz(pii a, pii b)
{
	if (a.second!=b.second)
		zrob(a, {a.first, b.second});
	if (a.first!=b.first)
		zrob({a.first, b.second}, b);
}

void check()
{
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=m; j++)
		{
			for (int l : cel[i][j])
			{
				assert(l==jest[i][j].front());
				jest[i][j].pop();
			}
		}
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
		{
			vi pam=czyt();
			while(!pam.empty())
			{
				jest[i][j].push(pam.back());
				pam.pop_back();
			}
		}
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=m; j++)
		{
			cel[i][j]=czyt();
			reverse(cel[i][j].begin(), cel[i][j].end());
		}
	}
	
	while(!jest[1][1].empty())
		zrob({1, 1}, {2, 1});
	while(!jest[n][m].empty())
		zrob({n, m}, {n, m-1});
	while(!jest[1][m].empty())
	{
		if (!jest[1][m].front())
			zrob_pio({1, m}, {1, 1});
		else
			zrob_pio({1, m}, {n, m});
	}
	for (int i=2; i<m; i++)
	{
		while(!jest[1][i].empty())
		{
			if (!jest[1][i].front())
				zrob_poz({1, i}, {1, 1});
			else
				zrob_poz({1, i}, {n, m});
		}
	}
	for (int i=2; i<n; i++)
	{
		while(!jest[i][m].empty())
		{
			if (!jest[i][m].front())
				zrob_pio({i, m}, {1, 1});
			else
				zrob_pio({i, m}, {n, m});
		}
	}
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=m; j++)
		{
			if (i==1 && j==1)
				continue;
			if (i==n && j==m)
				continue;
			while(!jest[i][j].empty())
			{
				if (!jest[i][j].front())
					zrob_pio({i, j}, {1, 1});
				else
					zrob_poz({i, j}, {n, m});
			}
		}
	}
	for (int l : cel[1][1])
	{
		if (!l)
		{
			zrob_pio({1, 1}, {1, m});
		}
		else
		{
			zrob_pio({n, m}, {1, m});
		}
	}
	for (int l : cel[1][1])
		zrob_pio({1, m}, {1, 1});
	for (int l : cel[n][m])
	{
		if (!l)
		{
			zrob_pio({1, 1}, {1, m});
		}
		else
		{
			zrob_pio({n, m}, {1, m});
		}
	}
	for (int l : cel[n][m])
		zrob_pio({1, m}, {n, m});
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=m; j++)
		{
			if (i==1 || j==m)
				continue;
			for (int l : cel[i][j])
			{
				if (!l)
				{
					zrob_poz({1, 1}, {i, j});
				}
				else
				{
					zrob_pio({n, m}, {i, j});
				}
			}
		}
	}
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=m; j++)
		{
			if (i==1 && j==1)
				continue;
			if (i==n && j==m)
				continue;
			if (i!=1)
				continue;
			if (i==1 && j==m)
				continue;
			for (int l : cel[i][j])
			{
				if (!l)
				{
					zrob_pio({1, 1}, {i, j});
				}
				else
				{
					zrob_pio({n, m}, {i, j});
				}
			}
		}
	}
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=m; j++)
		{
			if (i==1 && j==1)
				continue;
			if (i==n && j==m)
				continue;
			if (j!=m)
				continue;
			if (i==1 && j==m)
				continue;
			for (int l : cel[i][j])
			{
				if (!l)
				{
					zrob_poz({1, 1}, {i, j});
				}
				else
				{
					zrob_poz({n, m}, {i, j});
				}
			}
		}
	}
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=m; j++)
		{
			if (i!=1 || j!=m)
				continue;
			for (int l : cel[i][j])
			{
				if (!l)
				{
					zrob_poz({1, 1}, {i, j});
				}
				else
				{
					zrob_poz({n, m}, {i, j});
				}
			}
		}
	}
	
	printf("%d\n", (int)wyn.size());
	check();
	for (auto i : wyn)
		printf("%d %d %d %d\n", i.first.first, i.first.second, i.second.first, i.second.second);
	return 0;
}