//PRZEMYSL ASSERTY

//SPRAWDZ CORNER CASE'Y, MINIMALNE I MAKSYMALNE WEJCIE I WYJCIE

//MODULO = 1

#include <bits/stdc++.h>
using namespace std;

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

const int nax=307*1000;

int n;
long long tab[2][nax];

vector < pair <int,int> > gor, dol, cal;

map <long long,int> mapa;

map < pair <int,int> , int > dp;

bool mniej(pair <int,int> a, pair <int,int> b)
{
	return a.second<b.second;
}

void czys(vector < pair <int,int> > &wek)
{
	sort(wek.begin(), wek.end(), mniej);
	vector < pair <int,int> > pom;
	for (int i=0; i<wek.size(); i++)
		if (!i || wek[i].first>pom.back().first)
			pom.push_back(wek[i]);
	wek=pom;
}

void consider(int a, int b, int w)
{
	if (!dp.count({a, b}))
		dp[{a, b}]=w;
	else
		dp[{a, b}]=max(dp[{a, b}], w);
}

int znajdz(vector < pair<int,int> > &wek, int a)
{
	if (wek.empty() || wek.back().first<=a)
		return -1;
	int bsa=0;
	int bsb=wek.size()-1;
	int bss;
	while(bsa<bsb)
	{
		bss=(bsa+bsb)>>1;
		if (wek[bss].first>a)
			bsb=bss;
		else
			bsa=bss+1;
	}
	return wek[bsa].second;
}

int main()
{
	scanf("%d", &n);
	for (int h=0; h<2; h++)
	{
		mapa.clear();
		mapa[0]=0;
		for (int i=1; i<=n; i++)
		{
			scanf("%lld", &tab[h][i]);
			tab[h][i]+=tab[h][i-1];
			if (mapa.count(tab[h][i]))
			{
				if (!h)
					gor.push_back({mapa[tab[h][i]]+1, i});
				else
					dol.push_back({mapa[tab[h][i]]+1, i});
			}
			mapa[tab[h][i]]=i;
		}
	}
	mapa.clear();
	mapa[0]=0;
	for (int i=1; i<=n; i++)
	{
		long long x=tab[0][i]+tab[1][i];
		if (mapa.count(x))
			cal.push_back({mapa[x]+1, i});
		mapa[x]=i;
	}
	czys(gor);
	czys(dol);
	czys(cal);
	debug() << imie(gor);
	debug() << imie(dol);
	debug() << imie(cal);
	
	dp[{0, 0}]=0;
	for (map < pair <int,int> , int >::iterator it=dp.begin(); it!=dp.end(); it++)
	{
		int x=it->first.first;
		int y=it->first.second;
		int w=it->second;
		//debug() << x << " " << y << " " << w;
		if (x!=y)
		{
			consider(max(x, y), max(x, y), w);
			if (x>y)
			{
				int g=znajdz(dol, y);
				//debug() << g;
				if (g!=-1)
					consider(x, g, w+1);
			}
			else
			{
				int g=znajdz(gor, x);
				//debug() << g;
				if (g!=-1)
					consider(g, y, w+1);
			}
		}
		else
		{
			if (x!=n)
				consider(x+1, y+1, w);
			int g=znajdz(cal, x);
			if (g!=-1)
				consider(g, g, w+1);
				
			g=znajdz(dol, y);
			//debug() << g;
			if (g!=-1)
				consider(x, g, w+1);
				
			g=znajdz(gor, x);
			//debug() << g;
			if (g!=-1)
				consider(g, y, w+1);
		}
	}
	printf("%d\n", dp[{n, n}]);
	return 0;
}