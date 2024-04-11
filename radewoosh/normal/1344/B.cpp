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

char wcz[nax][nax];

vi poz[nax];
vi pio[nax];

int takpoz[nax];
int takpio[nax];

int spopoz[nax];
int spopio[nax];

void ans(int v)
{
	printf("%d\n", v);
	exit(0);
}

void nope()
{
	ans(-1);
}

int rx[]={-1, 1, 0, 0};
int ry[]={0, 0, -1, 1};

int bylo[nax][nax];

void znacz(int a, int b)
{
	if (bylo[a][b])
		return;
	bylo[a][b]=1;
	for (int i=0; i<4; i++)
		znacz(a+rx[i], b+ry[i]);
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; i++)
	{
		scanf("%s", wcz[i]+1);
		for (int j=1; j<=m; j++)
		{
			if (wcz[i][j]=='#')
			{
				poz[i].push_back(j);
				pio[j].push_back(i);
			}
		}
	}
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<(int)poz[i].size(); j++)
			if (poz[i][j-1]+1!=poz[i][j])
				nope();
		if (poz[i].empty())
			takpoz[i]=1;
	}
	for (int i=1; i<=m; i++)
	{
		for (int j=1; j<(int)pio[i].size(); j++)
			if (pio[i][j-1]+1!=pio[i][j])
				nope();
		if (pio[i].empty())
			takpio[i]=1;
	}
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=m; j++)
		{
			if (wcz[i][j]=='.' && takpoz[i] && takpio[j])
			{
				spopoz[i]=1;
				spopio[j]=1;
			}
		}
	}
	for (int i=1; i<=n; i++)
		if (takpoz[i] && !spopoz[i])
			nope();
	for (int i=1; i<=m; i++)
		if (takpio[i] && !spopio[i])
			nope();
	for (int i=0; i<=n+1; i++)
		for (int j=0; j<=m+1; j++)
			bylo[i][j]=1;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
			if (wcz[i][j]=='#')
				bylo[i][j]=0;
	int ile=0;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
		{
			if (bylo[i][j])
				continue;
			znacz(i, j);
			ile++;
		}
	ans(ile);
	return 0;
}