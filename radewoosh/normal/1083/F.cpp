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
const int nax=200*1007;
const int d=1000;
const int vax=(1<<14);

int wyn;
int nanie;

void ans()
{
	if (nanie)
		printf("-1\n");
	else
		printf("%d\n", wyn);
}

struct ogarniacz
{
	bool brut=false;
	
	int r;
	vi wek;
	vi narz;
	vector <vi> bloczek;
	
	void init(int v)
	{
		if (v<=d)
		{
			brut=true;
			r=v;
			wek.resize(r);
			return;
		}
		r=v/d+2;
		wek.resize(r*d, 0);
		narz.resize(r+1, 0);
		bloczek.resize(r, vi(vax, 0));
		for (int i=0; i<r; i++)
			bloczek[i][0]=d;
	}
	void xoruj(int v, int x)
	{
		if (brut)
		{
			int wsz=0;
			for (const int &i : wek)
				wsz^=i;
			if (wsz)
				nanie--;
			
			int s=0;
			for (const int &i : wek)
			{
				s^=i;
				wyn-=(s>0);
			}	
			wek[v]^=x;
			s=0;
			for (const int &i : wek)
			{
				s^=i;
				wyn+=(s>0);
			}	
			
			wsz^=x;
			if (wsz)
				nanie++;
			return;
		}
		if (narz[r])
			nanie--;
		for (int i=0; i<r; i++)
			wyn-=d-bloczek[i][narz[i]];
			
		int g=v/d;
		for (int i=v; i<(g+1)*d; i++)
		{
			bloczek[g][wek[i]]--;
			wek[i]^=x;
			bloczek[g][wek[i]]++;
		}
		for (int i=g+1; i<=r; i++)
			narz[i]^=x;
		
		for (int i=0; i<r; i++)
			wyn+=d-bloczek[i][narz[i]];
		if (narz[r])
			nanie++;
	}
};

int n, k, q;
int tab[2][nax];

int chce[nax];

ogarniacz data[nax];

void myk(int v, int x)
{
	data[v%k].xoruj(v/k, x);
}

void ustaw(int v, int a, int b)
{
	int zm=tab[v][a]^b;
	tab[v][a]=b;
	myk(a-1, zm);
	myk(a, zm);
}

int main()
{
	scanf("%d%d%d", &n, &k, &q);
	for (int i=0; i<=n; i++)
		chce[i%k]++;
	for (int i=0; i<k; i++)
		data[i].init(chce[i]);
	for (int h=0; h<2; h++)
	{
		for (int i=1; i<=n; i++)
		{
			int x;
			scanf("%d", &x);
			ustaw(h, i, x);
		}
	}
	ans();
	while(q--)
	{
		char a;
		int b, c;
		scanf(" %c%d%d", &a, &b, &c);
		ustaw(a-'a', b, c);
		ans();
	}
	return 0;
}