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
const int inf=1007*1007*1007;

int n, m;

vi tab[nax];
vi num[nax];

int k;

pii gdz[nax];

vi graf[nax];

int musze[nax];
int sko[nax];

int rx[]={-1, 1, 0, 0};
int ry[]={0, 0, -1, 1};

void kra(int a, int b)
{
	graf[a].push_back(b);
	graf[b].push_back(a);
}

int czas;
int bylo[nax];

int dfs(int v)
{
	bylo[v]=czas;
	for (int i : graf[v])
	{
		if (!sko[i] || (bylo[sko[i]]!=czas && dfs(sko[i])))
		{
			sko[v]=i;
			sko[i]=v;
			return 1;
		}
	}
	return 0;
}

void mas_turbo_matching()
{
	int czy=1;
	while(czy)
	{
		czy=0;
		czas++;
		for (int i=1; i<=k; i++)
		{
			if (!sko[i] && musze[i])
			{
				czy|=dfs(i);
			}
		}
	}
}

vi wynl[nax];

vector<char> wync[nax];

char strz(pii a, pii b)
{
	if (b.first>a.first)
		return 'D';
	if (b.first<a.first)
		return 'U';
	if (b.second>a.second)
		return 'R';
	if (b.second<a.second)
		return 'L';
	assert(0);
}

void test()
{
	scanf("%d%d", &n, &m);
	for (int i=0; i<=n+1; i++)
	{
		tab[i].resize(m+2);
		num[i].resize(m+2);
		fill(tab[i].begin(), tab[i].end(), inf);
		wynl[i].resize(m+2);
		wync[i].resize(m+2);
	}
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=m; j++)
			scanf("%d", &tab[i][j]);
	}
	k=0;
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=m; j++)
		{
			k++;
			graf[k].clear();
			num[i][j]=k;
			sko[k]=0;
			gdz[k]={i, j};
		}
	}
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=m; j++)
		{
			musze[num[i][j]]=1;
			for (int l=0; l<4; l++)
				if (tab[i+rx[l]][j+ry[l]]<tab[i][j])
					musze[num[i][j]]=0;
		}
	}
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=m; j++)
		{
			if (tab[i][j]==tab[i+1][j] && musze[num[i][j]] && musze[num[i+1][j]])
				kra(num[i][j], num[i+1][j]);
			if (tab[i][j]==tab[i][j+1] && musze[num[i][j]] && musze[num[i][j+1]])
				kra(num[i][j], num[i][j+1]);
		}
	}
	mas_turbo_matching();
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=m; j++)
		{
			if (tab[i][j]==tab[i+1][j] && musze[num[i][j]]!=musze[num[i+1][j]])
				kra(num[i][j], num[i+1][j]);
			if (tab[i][j]==tab[i][j+1] && musze[num[i][j]]!=musze[num[i][j+1]])
				kra(num[i][j], num[i][j+1]);
		}
	}
	mas_turbo_matching();
	for (int i=1; i<=k; i++)
	{
		if (musze[i] && !sko[i])
		{
			printf("NO\n");
			return;
		}
	}
	printf("YES\n");
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=m; j++)
		{
			if (sko[num[i][j]])
			{
				wynl[i][j]=tab[i][j]/2;
				wync[i][j]=strz({i, j}, gdz[sko[num[i][j]]]);
				if ((tab[i][j]&1) && (sko[num[i][j]]>num[i][j]))
					wynl[i][j]++;
				continue;
			}
			for (int l=0; l<4; l++)
			{
				pii u={i+rx[l], j+ry[l]};
				if (tab[u.first][u.second]<tab[i][j])
				{
					wynl[i][j]=tab[i][j]-tab[u.first][u.second];
					wync[i][j]=strz({i, j}, u);
				}
			}
		}
	}
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=m; j++)
		{
			printf("%d ", wynl[i][j]);
		}
		printf("\n");
	}
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=m; j++)
		{
			printf("%c ", wync[i][j]);
		}
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