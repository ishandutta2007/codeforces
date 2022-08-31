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
const int d=21;
const int nax=(1<<21);

int n;

int tab[nax];

vi kied[nax];

int czas;

//~ vi mam[nax];

int wyn;

vi lew[d+1];
vi pra[d+1];

void zrob(int i, int l)
{
	for (int j=0; j<d; j++)
	{
		int x=l>>j;
		pra[j][x]=max(pra[j][x], i);
	}
}

void dfs1(int v)
{
	if ((int)kied[v].size()==2)
		return;
	for (int i : kied[v])
		if (i==czas)
			return;
	kied[v].push_back(czas);
	if ((int)kied[v].size()==2)
	{
		zrob(czas, v);
		//~ mam[czas].push_back(v);
	}
	for (int i=0; i<d; i++)
		if (v&(1<<i))
			dfs1(v^(1<<i));
}

void rek(int v, int a, int b)
{
	if (v==-1)
	{
		wyn=max(wyn, a^b);
		return;
	}
	int juz=0;
	if (lew[v][a*2]<pra[v][b*2+1])
	{
		rek(v-1, a*2, b*2+1);
		juz=1;
	}
	if (lew[v][a*2+1]<pra[v][b*2])
	{
		rek(v-1, a*2+1, b*2);
		juz=1;
	}
	if (lew[v][a*2]<pra[v][b*2] && !juz)
	{
		rek(v-1, a*2, b*2);
	}
	if (lew[v][a*2+1]<pra[v][b*2+1] && !juz)
	{
		rek(v-1, a*2+1, b*2+1);
	}
}

int main()
{
	for (int i=0; i<nax; i++)
		kied[i].reserve(2);
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		scanf("%d", &tab[i]);
	for (int i=0; i<d; i++)
	{
		lew[i].resize(1<<(d-i+1), n+1);
		pra[i].resize(1<<(d-i+1));
	}
	for (int i=n; i; i--)
	{
		czas=i;
		dfs1(tab[i]);
	}
	for (int i=1; i<=n; i++)
	{
		for (int j=0; j<d; j++)
		{
			int x=tab[i]>>j;
			lew[j][x]=min(lew[j][x], i);
		}
	}
	//~ for (int i=1; i<=n; i++)
	//~ {
		//~ for (int l : mam[i])
		//~ {
			//~ for (int j=0; j<d; j++)
			//~ {
				//~ int x=l>>j;
				//~ pra[j][x]=max(pra[j][x], i);
			//~ }
		//~ }
	//~ }
	rek(d-1, 0, 0);
	printf("%d\n", wyn);
	return 0;
}