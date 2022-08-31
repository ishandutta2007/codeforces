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

const int nax=200*1007;
const long long inf=1e18;

int n, m, k;

long long tab[nax];
int gru[nax];

int stan[nax];

set < pair <long long,int> > moz[5];
set < pair <long long,int> > zaw[5];

vector < pair <long long,int> > wek;

long long wyn=inf;

long long aktu=0;

int za(int v)
{
	return zaw[v].size();
}

int mo(int v)
{
	return moz[v].size();
}

int nada(int v, int h)
{
	if (gru[v]!=3)
		return ((gru[v]&h)==h);
	return (h==3);
}

void dodaj(int v)
{
	if (stan[v]!=4)
		return;
	aktu+=tab[v];
	for (int h=0; h<4; h++)
		if (nada(v, h))
			moz[h].erase({tab[v], v});
	zaw[gru[v]].insert({tab[v], v});
	stan[v]=gru[v];
}

void usun(int v)
{
	if (stan[v]==4)
		return;
	aktu-=tab[v];
	zaw[gru[v]].erase({tab[v], v});
	for (int h=0; h<4; h++)
		if (nada(v, h))
			moz[h].insert({tab[v], v});
	stan[v]=4;
}

void dorzuc(int v)
{
	int x=(*moz[v].begin()).second;
	debug() << "dorzucam " << x;
	dodaj(x);
}

long long najd(int v)
{
	auto it=zaw[v].end();
	it--;
	return (*it).first;
}

long long najt(int v)
{
	auto it=moz[v].begin();
	return (*it).first;
}

void wyjmij(int v)
{
	if (v==-1)
	{
		long long naj=0;
		for (int i=0; i<3; i++)
		{
			if (!zaw[i].empty() && najd(i)>naj)
			{
				naj=najd(i);
				v=i;
			}
		}
	}
	auto it=zaw[v].end();
	it--;
	int x=(*it).second;
	debug() << "wyjmuje " << x;
	usun(x);
}

int czyfaj()
{
	debug() << "raz";
	if (za(2)+za(3)<k)
		return 0;
	debug() << "dwa";
	if (za(1)+za(3)<k)
		return 0;
	debug() << "trz";
	if (za(0)+za(1)+za(2)+za(3)!=m)
		return 0;
	debug() << "czt";
	return 1;
}

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i=1; i<=n; i++)
	{
		stan[i]=4;
		scanf("%lld", &tab[i]);
	}
	int p1;
	scanf("%d", &p1);
	while(p1--)
	{
		int p2;
		scanf("%d", &p2);
		gru[p2]|=1;
	}
	scanf("%d", &p1);
	while(p1--)
	{
		int p2;
		scanf("%d", &p2);
		gru[p2]|=2;
	}
	for (int i=1; i<=n; i++)
		for (int h=0; h<4; h++)
			if (nada(i, h))
				moz[h].insert({tab[i], i});
	for (auto i : moz[3])
		wek.push_back(i);
	
	for (int h=0; h<=(int)wek.size(); h++)
	{
		
		while(za(0)+za(1)+za(2)+za(3)<m && mo(0))
			dorzuc(0);
			
		while(za(0)+za(1)+za(2)+za(3)>m && (za(0)+za(1)+za(2))>0)
			wyjmij(-1);
			
		while(za(1)+za(3)<k && mo(1))
		{
			dorzuc(1);
			if ((zaw[2].empty() || za(2)+za(3)<=k) && zaw[0].empty())
				break;
			if (zaw[0].empty() || (!zaw[2].empty() && najd(2)>najd(0) && za(2)+za(3)>k))
				wyjmij(2);
			else
				wyjmij(0);
		}
		
		while(za(2)+za(3)<k && mo(2))
		{
			dorzuc(2);
			if ((zaw[1].empty() || za(1)+za(3)<=k) && zaw[0].empty())
				break;
			if (zaw[0].empty() || (!zaw[1].empty() && najd(1)>najd(0) && za(1)+za(3)>k))
				wyjmij(1);
			else
				wyjmij(0);
		}
		
		while(za(2)+za(3)>k && za(2) && mo(0) && najt(0)<najd(2))
		{
			dorzuc(0);
			wyjmij(2);
		}
		
		while(za(1)+za(3)>k && za(1) && mo(0) && najt(0)<najd(1))
		{
			dorzuc(0);
			wyjmij(1);
		}
		
		if (czyfaj())
			wyn=min(wyn, aktu);
		
		if (mo(3))
			dorzuc(3);
	}
	
	if (wyn>(inf/2))
		printf("-1\n");
	else
		printf("%lld\n", wyn);
	return 0;
}