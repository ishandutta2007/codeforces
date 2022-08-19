//PRZEMYSL ASSERTY

//SPRAWDZ CORNER CASE'Y, MINIMALNE I MAKSYMALNE WEJCIE I WYJCIE

//MODULO = 1

//while (clock()<=69*CLOCKS_PER_SEC)

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
  for (auto it = d.b; it != d.e; ++it) 
    *this << ", \0[" + 3 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};

#define imie(x) "[" << #x ": " << (x) << "] "

#define shandom_ruffle random_shuffle

const int nax=100*1007;
const long long mod=1000*1000*1000+7;

int potenga(int v)
{
	for (int i=1; 1; i<<=1)
		if (i>=v)
			return i;
}

struct prze
{
	vector <long long> drzewo[3][3];
	int n1;
	prze(){}
	prze(int v)
	{
		n1=potenga(v+1);
		for (int i=0; i<3; i++)
			for (int j=i; j<3; j++)
				drzewo[i][j].resize(n1*2+3, 0);
	}
	void scal_tu(int v)
	{
		for (int i=0; i<3; i++)
		{
			for (int j=i; j<3; j++)
			{
				drzewo[i][j][v]=0;
				drzewo[i][j][v]+=drzewo[i][j][(v<<1)];
				drzewo[i][j][v]+=drzewo[i][j][(v<<1)^1];
			}
		}
		drzewo[0][1][v]+=drzewo[0][0][(v<<1)]*drzewo[1][1][(v<<1)^1];
		drzewo[1][2][v]+=drzewo[1][1][(v<<1)]*drzewo[2][2][(v<<1)^1];
		drzewo[0][2][v]+=drzewo[0][0][(v<<1)]*drzewo[1][2][(v<<1)^1];
		drzewo[0][2][v]+=drzewo[0][1][(v<<1)]*drzewo[2][2][(v<<1)^1];
		for (int i=0; i<3; i++)
			for (int j=i; j<3; j++)
				drzewo[i][j][v]%=mod;
	}
	void zapal(int v, long long l, long long p)
	{
		v+=n1-1;
		drzewo[0][0][v]=l;
		drzewo[1][1][v]=1;
		drzewo[2][2][v]=p;
		v>>=1;
		while(v)
		{
			scal_tu(v);
			v>>=1;
		}
	}
	void wypisz(int v)
	{
		for (int i=0; i<3; i++)
			for (int j=0; j<3; j++)
				debug() << i << " " << j << " " << drzewo[i][j][v];
	}
	void zgas(int v)
	{
		v+=n1-1;
		drzewo[0][0][v]=0;
		drzewo[1][1][v]=0;
		drzewo[2][2][v]=0;
		v>>=1;
		while(v)
		{
			scal_tu(v);
			v>>=1;
		}
	}
	long long wyni()
	{
		return drzewo[0][2][1];
	}
};


int n, m;

int tab[nax];
int lew[nax];
int pra[nax];

int kt[nax];

map <int,int> ska;

int drzewo[nax];

prze tre[nax];

long long wyn;

void cle()
{
	for (int i=1; i<=n; i++)
		drzewo[i]=0;
}

void pisz(int v)
{
	for (int i=v; i<=n; i+=(-i&i))
		drzewo[i]++;
}

int czytaj(int v)
{
	int ret=0;
	for (int i=v; i; i-=(-i&i))
		ret+=drzewo[i];
	return ret;
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		scanf("%d", &tab[i]);
		ska[tab[i]]=1;
	}
	int li=0;
	for (map<int,int>::iterator it=ska.begin(); it!=ska.end(); it++)
	{
		li++;
		it->second=li;
	}
	for (int i=1; i<=n; i++)
		tab[i]=ska[tab[i]];
	for (int i=1; i<=n; i++)
	{
		lew[i]=czytaj(tab[i]);
		pisz(tab[i]);
	}
	cle();
	for (int i=n; i; i--)
	{
		pra[i]=czytaj(tab[i]);
		pisz(tab[i]);
	}
	debug() << range(lew+1, lew+1+n);
	debug() << range(pra+1, pra+1+n);
	cle();
	for (int i=1; i<=n; i++)
	{
		drzewo[tab[i]]++;
		kt[i]=drzewo[tab[i]];
	}
	for (int i=1; i<=n; i++)
		tre[i]=prze(drzewo[i]);
	for (int i=1; i<=n; i++)
		tre[tab[i]].zapal(kt[i], lew[i], pra[i]);
	for (int i=1; i<=n; i++)
		wyn+=tre[i].wyni();
	wyn%=mod;
	scanf("%d", &m);
	while(m--)
	{
		int typ, x;
		scanf("%d%d", &typ, &x);
		wyn-=tre[tab[x]].wyni();
		if (typ==1)
			tre[tab[x]].zgas(kt[x]);
		else
			tre[tab[x]].zapal(kt[x], lew[x], pra[x]);
		wyn+=tre[tab[x]].wyni();
		wyn%=mod;
		wyn+=mod;
		wyn%=mod;
		printf("%lld\n", wyn);
	}
	return 0;
}