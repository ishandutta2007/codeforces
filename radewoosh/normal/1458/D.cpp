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

int n;

char wcz[nax];

int tab[nax];

int pom[2*nax];
int *zli=pom+nax;

vi pomg[2*nax];
vi *graf=pomg+nax;

int ost;

vi stos;

int in(int v)
{
	return zli[v];
}

int out(int v)
{
	return zli[v]+(v==0)-(v==ost);
}

void dfs(int v)
{
	while(!graf[v].empty())
	{
		int u=graf[v].back();
		graf[v].pop_back();
		dfs(u);
	}
	stos.push_back(v);
}

void test()
{
	scanf("%s", wcz+1);
	n=strlen(wcz+1);
	for (int i=1; i<=n; i++)
	{
		if (wcz[i]=='0')
			tab[i]=tab[i-1]-1;
		else
			tab[i]=tab[i-1]+1;
	}
	for (int i=-n; i<=n; i++)
	{
		zli[i]=0;
		graf[i].clear();
	}
	for (int i=1; i<=n; i++)
		zli[tab[i]]++;
	ost=tab[n];
	stos.clear();
	int wchodzi=0;
	for (int i=-n; i<=n; i++)
	{
		int chcein=in(i)-wchodzi;
		int chceout=out(i)-(int)graf[i].size();
		for (int j=1; j<=chcein; j++)
			graf[i+1].push_back(i);
		for (int j=1; j<=chceout; j++)
			graf[i].push_back(i+1);
		wchodzi=chceout;
	}
	for (int i=-n; i<=n; i++)
		reverse(graf[i].begin(), graf[i].end());
	dfs(0);
	reverse(stos.begin(), stos.end());
	for (int i=1; i<=n; i++)
		tab[i]=(stos[i]>stos[i-1]);
	for (int i=1; i<=n; i++)
		printf("%d", tab[i]);
	printf("\n");
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}