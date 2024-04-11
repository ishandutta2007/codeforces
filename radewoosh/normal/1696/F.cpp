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
const int nax=107;

int n;

int tab[nax][nax][nax];//pierwsze to srodek
vector<vi> gru[nax];

char wcz[nax];

int kt[nax][nax];

void ans(int v)
{
	if (v)
		printf("Yes\n");
	else
		printf("No\n");
}

vi graf[nax];

int kto[nax];

int odl[nax][nax];

void znacz(int v, int u, int ile)
{
	if (odl[v][u]>=0)
		return;
	odl[v][u]=ile;
	for (int i : graf[u])
		znacz(v, i, ile+1);
}

int check()
{
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			odl[i][j]=-1;
	for (int i=1; i<=n; i++)
		znacz(i, i, 0);
	for (int i=1; i<=n; i++)
		for (int j=i+1; j<=n; j++)
			for (int l=1; l<=n; l++)
				if ((odl[i][l]==odl[j][l])!=tab[l][i][j])
					return 0;
	return 1;
}

void test()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			for (int l=1; l<=n; l++)
				tab[i][j][l]=0;
	
	for (int i=1; i<=n; i++)
	{
		for (int j=i+1; j<=n; j++)
		{
			scanf("%s", wcz+1);
			for (int l=1; l<=n; l++)
			{
				if (wcz[l]=='1')
					tab[l][i][j]=tab[l][j][i]=1;
			}
		}
	}
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=n; j++)
		{
			if (j!=i && (tab[i][i][j] || tab[i][j][i]))
			{
				ans(0);
				return;
			}
		}
	}
	for (int i=1; i<=n; i++)
	{
		gru[i].clear();
		vi bylo(n+2);
		for (int j=1; j<=n; j++)
		{
			if (bylo[j] || j==i)
				continue;
			vi ter;
			for (int l=1; l<=n; l++)
			{
				if (l==j || tab[i][j][l])
				{
					bylo[l]=1;
					ter.push_back(l);
				}
			}
			gru[i].push_back(ter);
		}
		for (int j=0; j<(int)gru[i].size(); j++)
		{
			for (int l=0; l<j; l++)
			{
				for (int a : gru[i][j])
				{
					for (int b : gru[i][l])
					{
						if (tab[i][a][b])
						{
							ans(0);
							return;
						}
					}
				}
			}
			for (int a : gru[i][j])
			{
				for (int b : gru[i][j])
				{
					if (a==b)
						break;
					if (!tab[i][a][b])
					{
						ans(0);
						return;
					}
				}
			}
		}
		for (int j=0; j<(int)gru[i].size(); j++)
			for (int l : gru[i][j])
				kt[i][l]=j;
	}
	for (int p=0; p<(int)gru[1].size(); p++)
	{
		for (int i=1; i<=n; i++)
		{
			graf[i].clear();
			kto[i]=-1;
		}
		kto[1]=p;
		vector<pii> wyn;
		for (int j : gru[1][p])
			wyn.push_back({1, j});
		for (int h=0; h<(int)wyn.size() && (int)wyn.size()<n; h++)
		{
			int a=wyn[h].first;
			int b=wyn[h].second;
			for (int c : gru[b][kt[b][a]])
				if (c!=a)
					wyn.push_back({b, c});
		}
		if ((int)wyn.size()!=n-1)
			continue;
		//~ debug() << wyn;
		for (pii i : wyn)
		{
			graf[i.first].push_back(i.second);
			graf[i.second].push_back(i.first);
		}
		if (check())
		{
			ans(1);
			for (pii i : wyn)
				printf("%d %d\n", i.first, i.second);
			return;
		}
	}
	ans(0);
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}