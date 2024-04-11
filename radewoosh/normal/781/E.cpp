#ifndef LOCAL
#define NDEBUG
#endif

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

const int nax=1000*1007;
long long mod=1000*1000*1000+7;

struct bar
{
	long long wys;
	int l, r;
	long long s;
	void wczytaj()
	{
		scanf("%lld%d%d%lld", &wys, &l, &r, &s);
	}
};

bool operator < (bar a, bar b)
{
	return a.wys>b.wys;
}

int potenga(int v)
{
	for (int i=1; 1; i<<=1)
		if (i>=v)
			return i;
}

struct kamien
{
	long long wys;
	long long ile;
	int us;
	kamien()
	{
		us=0;
	}
	kamien(int a, long long b)
	{
		wys=a;
		ile=b;
		us=0;
	}
};

long long h;
int w;
int n;

bar tab[nax];

int n1;
vector < kamien* > drzewo[nax];

void dodaj(int v, int wys, long long ile)
{
	kamien * ten=new kamien(wys, ile);
	v+=n1-1;
	while(v)
	{
		drzewo[v].push_back(ten);
		v>>=1;
	}
}

long long sum;

void odswiez(int v)
{
	while(!drzewo[v].empty() && drzewo[v].back()->us)
		drzewo[v].pop_back();
}

void dziabaj(int v, long long przy)
{
	while(!drzewo[v].empty())
	{
		if (drzewo[v].back()->wys>przy)
			break;
		sum+=drzewo[v].back()->ile;
		if (sum>=mod)
			sum-=mod;
		drzewo[v].back()->us=1;
		
		odswiez(v);
	}
}

void zbierz(int v, int a, int b, int graa, int grab, long long przy)
{
	odswiez(v);
	if (a>=graa && b<=grab)
	{
		dziabaj(v, przy);
		return;
	}
	if (a>grab || b<graa)
	{
		return;
	}
	zbierz((v<<1), a, (a+b)>>1, graa, grab, przy);
	zbierz((v<<1)^1, (a+b+2)>>1, b, graa, grab, przy);
}

int main()
{
	scanf("%lld%d%d", &h, &w, &n);
	n1=potenga(w);
	for (int i=1; i<=n; i++)
		tab[i].wczytaj();
	sort(tab+1, tab+1+n);
	for (int i=1; i<=w; i++)
		dodaj(i, h+1, 1);
	for (int i=1; i<=n; i++)
	{
		sum=0;
		zbierz(1, 1, n1, tab[i].l, tab[i].r, tab[i].wys+tab[i].s);
		
		if (tab[i].l>1)
			dodaj(tab[i].l-1, tab[i].wys, sum);
		else
			dodaj(tab[i].r+1, tab[i].wys, sum);
			
		if (tab[i].r<w)
			dodaj(tab[i].r+1, tab[i].wys, sum);
		else
			dodaj(tab[i].l-1, tab[i].wys, sum);
	}
	sum=0;
	zbierz(1, 1, n1, 1, n1, h+2);
	printf("%lld\n", sum);
	return 0;
}