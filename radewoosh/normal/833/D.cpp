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
const int vax=500*1007;
const long long mod=1000*1000*1000+7;

//potengowe
int drzewo[nax];

void pisz(int v, int w)
{
	v+=vax;
	for (int i=v; i; i-=(-i&i))
		drzewo[i]+=w;
}

int czyt(int v)
{
	v+=vax;
	int ret=0;
	for (int i=v; i<nax; i+=(-i&i))
		ret+=drzewo[i];
	return ret;
}
//kuniec potengi

int n;
vector <pair <int,int> > graf[nax];

int kol[nax];
long long wag[nax];
long long nailu[nax];

long long wyn=1;

long long pot(long long v, long long wyk)
{
	long long ret=1;
	while(wyk)
	{
		if (wyk&1)
		{
			ret*=v;
			ret%=mod;
		}
		v*=v;
		v%=mod;
		wyk>>=1;
	}
	return ret;
}

int bylcen[nax];

vector <int> spo;
int roz[nax];
int maxroz[nax];

void dfs1(int v, int oj)
{
	roz[v]=1;
	maxroz[v]=0;
	spo.push_back(v);
	for (auto i : graf[v])
	{
		if (i.first==oj || bylcen[i.first])
			continue;
		dfs1(i.first, v);
		roz[v]+=roz[i.first];
		maxroz[v]=max(maxroz[v], roz[i.first]);
	}
}

long long dp[nax];
int bila[nax];
int bilb[nax];
int l;

vector <int> wek;

void dfs2(int v, int oj)
{
	wek.push_back(v);
	for (auto i : graf[v])
	{
		if (i.first==oj || bylcen[i.first])
			continue;
		bila[i.first]=bila[v];
		bilb[i.first]=bilb[v];
		if (kol[i.second])
		{
			bila[i.first]+=2;
			bilb[i.first]-=1;
		}
		else
		{
			bila[i.first]-=1;
			bilb[i.first]+=2;
		}
		dfs2(i.first, v);
	}
}

bool mniej(int a, int b)
{
	return bilb[a]<bilb[b];
}

void opierdol(int raz)
{
	//debug() <<  wek << " " << raz;
	sort(wek.begin(), wek.end(), mniej);
	int wsk=wek.size();
	for (int i : wek)
	{
		while(wsk && bilb[i]+bilb[wek[wsk-1]]>=0)
		{
			wsk--;
			pisz(bila[wek[wsk]], 1);
		}
		dp[i]+=raz*czyt(-bila[i]);
	}
	while(wsk<(int)wek.size())
	{
		pisz(bila[wek[wsk]], -1);
		wsk++;
	}
}

long long dfs3(int v, int oj)
{
	long long ret=dp[v];
	for (auto i : graf[v])
	{
		if (i.first==oj || bylcen[i.first])
			continue;
		long long w=dfs3(i.first, v);
		nailu[i.second]+=w;
		ret+=w;
	}
	return ret;
}

inline void jebaj(int c)
{
	for (int i : spo)
		dp[i]=0;
	l=0;
	bila[c]=bilb[c]=0;
	wek.clear();
	dfs2(c, 0);
	opierdol(1);
	for (auto i : graf[c])
	{
		if (bylcen[i.first])
			continue;
		wek.clear();
		dfs2(i.first, c);
		opierdol(-1);
	}
	//for (int i : spo)
	//	debug() << i << " " << dp[i];
	dfs3(c, 0);
}

void szuk(int v)
{
	if (bylcen[v])
		return;
	spo.clear();
	dfs1(v, 0);
	int c=-1;
	for (int i : spo)
		if (maxroz[i]*2<=roz[v] && (roz[v]-roz[i])*2<=roz[v])
			c=i;
	assert(c>0);
	//debug() << imie(c);
	
	jebaj(c);
	
	bylcen[c]=1;
	for (auto i : graf[c])
		szuk(i.first);
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graf[a].push_back({b, i});
		graf[b].push_back({a, i});
		scanf("%lld%d", &wag[i], &kol[i]);
	}
	szuk(1);
	for (int i=1; i<n; i++)
		wyn=(wyn*pot(wag[i], nailu[i]))%mod;
	printf("%lld\n", wyn);
	return 0;
}