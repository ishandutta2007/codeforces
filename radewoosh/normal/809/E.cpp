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

const int nax=1000*1007;
const long long mod=1000*1000*1000+7;

int n;
int tab[nax];

vector <int> graf[nax];

int sito[nax];
int czybez[nax];
long long dziwne[nax];
long long odziwne[nax];
long long magia[nax];
long long phi[nax];
int parz[nax];
vector <int> dzie[nax];

int bylcen[nax];
int roz[nax];
int maxroz[nax];

vector <int> spo;

long long wyn;

long long dziel(long long a, long long b)
{
	long long wyk=mod-2;
	while(wyk)
	{
		if (wyk&1)
		{
			a*=b;
			a%=mod;
		}
		b*=b;
		b%=mod;
		wyk>>=1;
	}
	return a;
}

void dfs1(int v, int oj)
{
	spo.push_back(v);
	roz[v]=1;
	maxroz[v]=0;
	for (int i : graf[v])
	{
		if (i==oj || bylcen[i])
			continue;
		dfs1(i, v);
		roz[v]+=roz[i];
		maxroz[v]=max(maxroz[v], roz[i]);
	}
}

int g;

vector < pair <int,int> > wek[nax];

long long ile[nax];

void dodaj(int v, long long r)
{
	for (int i : dzie[v])
	{
		ile[i]+=r*phi[v];
		ile[i]%=mod;
	}
}

void dfs2(int v, int oj, int dlu)
{
	wek[g].push_back({tab[v], dlu});
	for (int i : graf[v])
	{
		if (i==oj || bylcen[i])
			continue;
		dfs2(i, v, dlu+1);
	}
}

void szuk(int v)
{
	if (bylcen[v])
		return;
	spo.clear();
	dfs1(v, 0);
	int c=-1;
	for (int i : spo)
		if (maxroz[i]*2<=(int)spo.size() && ((int)spo.size()-roz[i])*2<=(int)spo.size())
			c=i;
	assert(c!=-1);
	debug() << c;
	bylcen[c]=1;
	
	g=1;
	wek[1].clear();
	wek[1].push_back({tab[c], 0});
	for (int i : graf[c])
	{
		if (bylcen[i])
			continue;
		g++;
		wek[g].clear();
		dfs2(i, c, 1);
	}
	
	for (int i=1; i<=g; i++)
		debug() << i << " " << wek[i];
	
	for (int i=1; i<=g; i++)
		for (auto j : wek[i])
			dodaj(j.first, 1);
	
	for (int i=1; i<=g; i++)
	{
		for (auto j : wek[i])
			dodaj(j.first, mod-1);
			
		for (auto j : wek[i])
		{
			for (auto l : dzie[j.first])
			{
				wyn+=((magia[l]*phi[j.first])%mod)*((j.second*ile[l])%mod);
				wyn%=mod;
			}
		}
		
		for (auto j : wek[i])
			dodaj(j.first, 1);
	}
	
	for (int i=1; i<=g; i++)
		for (auto j : wek[i])
			dodaj(j.first, mod-1);
	
	
	for (int i : graf[c])
		szuk(i);
}

int main()
{
	scanf("%d", &n);
	for (int i=2; i<=n; i++)
	{
		if (!sito[i])
			for (int j=i; j<=n; j+=i)
				sito[j]=i;
	}
	czybez[1]=1;
	for (int i=2; i<=n; i++)
	{
		czybez[i]=czybez[i/sito[i]];
		if (sito[i/sito[i]]==sito[i])
			czybez[i]=0;
	}
	for (int i=1; i<=n; i++)
	{
		if (czybez[i])
		{
			for (int j=i; j<=n; j+=i)
				dzie[j].push_back(i);
			dziwne[i]=1;
			int v=i;
			while(v>1)
			{
				dziwne[i]=(dziwne[i]*dziel(sito[v]-1, sito[v]))%mod;
				v/=sito[v];
				parz[i]^=1;
			}
			odziwne[i]=dziel(1, dziwne[i]);
			
			for (int j : dzie[i])
			{
				if (parz[j]==parz[i])
					magia[i]+=odziwne[j];
				else
					magia[i]-=odziwne[j];
			}
			magia[i]%=mod;
			magia[i]+=mod;
			magia[i]%=mod;
			
			//debug() << i << " " << dziwne[i] << " " << (dziwne[i]*i)%mod;
		}
	}
	for (int i=1; i<=n; i++)
		phi[i]=(i*dziwne[dzie[i].back()])%mod;
	debug() << range(dzie+1, dzie+1+n);
	for (int i=1; i<=n; i++)
		scanf("%d", &tab[i]);
	for (int i=1; i<n; i++)
	{
		int p1, p2;
		scanf("%d%d", &p1, &p2);
		graf[p1].push_back(p2);
		graf[p2].push_back(p1);
	}
	szuk(1);
	wyn=dziel(wyn, n);
	wyn=dziel(wyn, n-1);
	wyn*=2;
	wyn%=mod;
	printf("%lld\n", wyn);
	return 0;
}