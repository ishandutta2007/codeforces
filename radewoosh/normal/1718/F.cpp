//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
//~ #pragma GCC optimize("O3")
//~ #pragma GCC target ("avx2")
#pragma GCC optimize("Ofast")
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
const int lim=100*1000;
const int pier=310;
const int gra=2155;

int n, m, c, q;
int tab[nax];
vi roz[nax];

pii zap[nax];
vector<pair<pii,int>> pos;
int wyn[nax];

int sito[nax];
vi pie, male, sred;

int poziom[nax];
int otak[nax];

int licz[nax];
int gl=1;
int gp=0;

vector<pii> pacz;

void bt(int v, int w, int zn, int mas)
{
	if (!w)
		return;
	if (v==(int)male.size())
	{
		pacz.push_back({w*zn, mas});
		return;
	}
	bt(v+1, w, zn, mas);
	bt(v+1, w/male[v], -zn, mas|(1<<v));
}

void zmien(int v, int ile)
{
	if (poziom[v]==2 && licz[v])
		otak[c/v]--;
	licz[v]+=ile;
	if (poziom[v]==2 && licz[v])
		otak[c/v]++;
}

int spok[nax];
int pref[nax];

int liczwyn()
{
	//~ int ret=bt(0, c, 1);
	int ret=0;
	int mas=0;
	for (int i=0; i<(int)male.size(); i++)
		if (licz[male[i]])
			mas|=(1<<i);
	for (pii i : pacz)
		if ((mas&i.second)==i.second)
			ret+=i.first;
	for (int i=1; i<=gra; i++)
		spok[i]=1;
	for (int i : male)
		if (licz[i])
			for (int j=i; j<=gra; j+=i)
				spok[j]=0;
	for (int i : sred)
		if (licz[i])
			for (int j=i; j<=gra; j+=i)
				spok[j]=0;
	for (int i=1; i<=gra; i++)
	{
		pref[i]=pref[i-1]+spok[i];
		ret-=otak[i]*pref[i];
		//~ if (otak[i])
		//~ {
			//~ for (int j : sred)
			//~ {
				//~ if (j>i)
					//~ break;
				//~ if (licz[j])
					//~ ret-=otak[i]*pref[i/j];
			//~ }
		//~ }
	}
	int wsk=(int)sred.size()-1;
	for (int i : sred)
	{
		if (licz[i])
		{
			ret-=pref[c/i];
			for (int j : sred)
			{
				if (!licz[j])
					continue;
				ret-=pref[c/(i*j)];
				if (j==i || j*i>c)
					break;
			}
		}
	}
	return ret;
	
	//~ return ret;
	//~ int ret=0;
	//~ for (int i=1; i<=c; i++)
	//~ {
		//~ int ok=1;
		//~ for (int j : pie)
			//~ if (licz[j] && !(i%j))
				//~ ok=0;
		//~ ret+=ok;
	//~ }
	//~ return ret;
	//~ int ret=0;
}

int main()
{
	for (int i=2; i<nax; i++)
		if (!sito[i])
			for (int j=i; j<nax; j+=i)
				sito[j]=i;
	for (int i=2; i<nax; i++)
		if (sito[i]==i && i<=lim)
			pie.push_back(i);
	for (int i : pie)
	{
		if (i*(ll)i*(ll)i<=lim)
		{
			male.push_back(i);
			poziom[i]=0;
			continue;
		}
		if (i*(ll)i<=lim)
		{
			sred.push_back(i);
			poziom[i]=1;
			continue;
		}
		poziom[i]=2;
	}
	debug() << male;
	scanf("%d%d%d%d", &n, &m, &c, &q);
	bt(0, c, 1, 0);
	for (int i=1; i<=n; i++)
	{
		scanf("%d", &tab[i]);
		int x=tab[i];
		while(x>1)
		{
			roz[i].push_back(sito[x]);
			x/=sito[x];
		}
		roz[i].resize(unique(roz[i].begin(), roz[i].end())-roz[i].begin());
	}
	for (int i=1; i<=q; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		zap[i]={a, b};
		a=a/pier;
		if (a&1)
			b=-b;
		pos.push_back({{a, b}, i});
	}
	sort(pos.begin(), pos.end());
	for (auto hh : pos)
	{
		int v=hh.second;
		while(gp<zap[v].second)
		{
			gp++;
			for (int i : roz[gp])
				zmien(i, 1);
		}
		while(gl>zap[v].first)
		{
			gl--;
			for (int i : roz[gl])
				zmien(i, 1);
		}
		while(gp>zap[v].second)
		{
			for (int i : roz[gp])
				zmien(i, -1);
			gp--;
		}
		while(gl<zap[v].first)
		{
			for (int i : roz[gl])
				zmien(i, -1);
			gl++;
		}
		
		
		wyn[v]=liczwyn();
	}
	
	for (int i=1; i<=q; i++)
		printf("%d\n", wyn[i]);
	return 0;
}