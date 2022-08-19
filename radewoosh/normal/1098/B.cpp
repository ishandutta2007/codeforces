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
const int nax=1000*1007;


using pla=vector<vi>;

int n, m;

pla tab;

int pam;
pla wyn;

char wcz[nax];
char zn[]={'A', 'C', 'T', 'G'};

int tlu(char v)
{
	for (int i=0; i<4; i++)
		if (zn[i]==v)
			return i;
	assert(0);
}

int roz(const pla &a, const pla &b)
{
	int ret=0;
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
			ret+=(a[i][j]!=b[i][j]);
	return ret;
}

int rozr(const pla &a, const pla &b, int r)
{
	int ret=0;
	for (int i=r; i<=r; i++)
		for (int j=0; j<m; j++)
			ret+=(a[i][j]!=b[i][j]);
	return ret;
}

int rozc(const pla &a, const pla &b, int c)
{
	int ret=0;
	for (int i=0; i<n; i++)
		for (int j=c; j<=c; j++)
			ret+=(a[i][j]!=b[i][j]);
	return ret;
}

void cons(pla v)
{
	int x=roz(v, tab);
	if (wyn.empty() || x<pam)
	{
		wyn=v;
		pam=x;
	}
}

void dajr(int a, int b)
{
	vi tu[2];
	tu[0]={a, b};
	for (int i=0; i<4; i++)
		if (i!=a && i!=b)
			tu[1].push_back(i);
	pla gen(n, vi(m, 0));
	for (int i=0; i<n; i++)
	{
		vi rozy;
		for (int j=0; j<2; j++)
		{
			for (int l=0; l<m; l++)
				gen[i][l]=(tu[i&1][(l+j)&1]);
			rozy.push_back(rozr(gen, tab, i));
		}
		int w=(rozy[0]>rozy[1]);
		for (int l=0; l<m; l++)
			gen[i][l]=(tu[i&1][(l+w)&1]);
	}
	cons(gen);
}

void dajc(int a, int b)
{
	vi tu[2];
	tu[0]={a, b};
	for (int i=0; i<4; i++)
		if (i!=a && i!=b)
			tu[1].push_back(i);
	pla gen(n, vi(m, 0));
	for (int i=0; i<m; i++)
	{
		vi rozy;
		for (int j=0; j<2; j++)
		{
			for (int l=0; l<n; l++)
				gen[l][i]=(tu[i&1][(l+j)&1]);
			rozy.push_back(rozc(gen, tab, i));
		}
		int w=(rozy[0]>rozy[1]);
		for (int l=0; l<n; l++)
			gen[l][i]=(tu[i&1][(l+w)&1]);
	}
	cons(gen);
}

int main()
{
	scanf("%d%d", &n, &m);
	tab.resize(n, vi(m, 0));
	for (int i=0; i<n; i++)
	{
		scanf("%s", wcz);
		for (int j=0; j<m; j++)
			tab[i][j]=tlu(wcz[j]);
	}
	
	for (int i=0; i<4; i++)
	{
		for (int j=0; j<i; j++)
		{
			dajr(i, j);
			dajc(i, j);
		}
	}
	
	
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<m; j++)
			printf("%c", zn[wyn[i][j]]);
		printf("\n");
	}
	return 0;
}