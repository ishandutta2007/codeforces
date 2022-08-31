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
const int d=500;
const int inf=1e9;

int n;

int sito[nax];

vector <vi> setel;

vi stos;

void rek(int ogr, int dz)
{
	setel.push_back(stos);
	for (int i=2; i<=ogr && dz*i<=d; i++)
	{
		stos.push_back(i-1);
		rek(i, dz*i);
		stos.pop_back();
	}
}

map <vi,vi> mapa;

void uzu(const vi &wek)
{
	mapa[wek].resize(d+1, inf);
	vi &widze=mapa[wek];
	for (const vi &i : setel)
	{
		int odl=0;
		int ma=1;
		for (int j=0; j<(int)i.size(); j++)
			ma*=(i[j]+1);
		for (int j=0; j<(int)max(i.size(), wek.size()); j++)
		{
			int x=0;
			int y=0;
			if (j<(int)i.size())
				x=i[j];
			if (j<(int)wek.size())
				y=wek[j];
			odl+=abs(x-y);
		}
		widze[ma]=min(widze[ma], odl);
	}
}

vi daj(int w)
{
	vi ter;
	int v=w;
	while(v>1)
	{
		int a=sito[v];
		ter.push_back(0);
		while(!(v%a))
		{
			ter.back()++;
			v/=a;
		}
	}
	sort(ter.begin(), ter.end());
	reverse(ter.begin(), ter.end());
	if (!mapa.count(ter))
		uzu(ter);
	return ter;
}

void query()
{
	int a, b;
	scanf("%d%d", &a, &b);
	vi raz=daj(a);
	vi dwa=daj(b);
	int wyn=inf;
	vi &x=mapa[raz];
	vi &y=mapa[dwa];
	for (int i=0; i<=d; i++)
		wyn=min(x[i]+y[i], wyn);
	printf("%d\n", wyn);
}

int main()
{
	for (int i=2; i<nax; i++)
		if (!sito[i])
			for (int j=i; j<nax; j+=i)
				sito[j]=i;
	rek(240, 1);
	debug() << imie(setel.size());
	int t;
	scanf("%d", &t);
	while(t--)
		query();
	return 0;
}