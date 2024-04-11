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
const int nax=5050*1007;
const int d=6;

int n, q;

int tab[nax];

int sito[nax];
int sile[nax];
int czys[nax];
vi dz[nax];

int pom[nax];

pii zap[nax];

int wyn[nax];

vector <pair <int,int> > odl[nax];
vector <pair <int,int> > niby;

vi kt[nax];

bool mniej(const pii &a, const pii &b)
{
	if (a.first!=b.first)
		return a>b;
	return a<b;
}

void oczy(vector <pair <int,int> > &wek)
{
	niby=wek;
	sort(niby.begin(), niby.end(), mniej);
	wek.clear();
	for (auto i : niby)
	{
		while(!wek.empty() && wek.back().second<=i.second)
			wek.pop_back();
		wek.push_back(i);
	}
}

int drz[nax];

void prze(int l, int r, int war)
{
	//~ debug() << "mam " << l << " " << r << "   " << war;
	for (int i=l; i; i-=(i&(-i)))
		drz[i]=min(drz[i], war);
}

int query(int l, int r)
{
	int ret=1e9;
	for (int i=l; i<=n; i+=(i&(-i)))
		ret=min(ret, drz[i]);
	return ret;
}

void wrzu(int v)
{
	for (int i : dz[tab[v]])
	{
		int ter=sile[tab[v]/i];
		//~ debug() << v << " " << i << "  " << ter;
		for (auto j : odl[i])
			prze(j.second, v, j.first+ter);
		odl[i].push_back({ter, v});
		oczy(odl[i]);
	}
}

void zrob(int v)
{
	wyn[v]=query(zap[v].first, zap[v].second);
}

int main()
{
	scanf("%d%d", &n, &q);
	for (int i=1; i<=n; i++)
	{
		scanf("%d", &tab[i]);
	}
	for (int i=2; i<nax; i++)
	{
		if (!sito[i])
		{
			for (int j=i; j<nax; j+=i)
				sito[j]=i;
		}
	}
	for (int i=1; i<=n; i++)
		drz[i]=1e9;
	for (int i=1; i<nax; i++)
	{
		if (i>1)
			sile[i]=sile[i/sito[i]]+1;
		int v=i;
		int w=1;
		while(v>1)
		{
			int x=sito[v];
			v/=x;
			if (w%x)
				w*=x;
			else
				w/=x;
		}
		czys[i]=w;
	}
	for (int i=1; i<=n; i++)
		tab[i]=czys[tab[i]];
	for (int i=1; i<nax; i++)
	{
		if (czys[i]==i)
		{
			for (int j=i; j<nax; j+=i)
			{
				if (czys[j]==j)
				{
					pom[j]++;
				}
			}
		}
	}
	for (int i=1; i<nax; i++)
		dz[i].resize(pom[i]);
	for (int i=1; i<nax; i++)
	{
		if (czys[i]==i)
		{
			for (int j=i; j<nax; j+=i)
			{
				if (czys[j]==j)
				{
					pom[j]--;
					dz[j][pom[j]]=i;
				}
			}
		}
	}
	//~ debug() << range(tab+1, tab+1+n);
	for (int i=1; i<=q; i++)
	{
		scanf("%d%d", &zap[i].first, &zap[i].second);
		kt[zap[i].second].push_back(i);
	}
	
	for (int i=1; i<=n; i++)
	{
		wrzu(i);
		for (int j : kt[i])
			zrob(j);
	}
	
	for (int i=1; i<=q; i++)
		printf("%d\n", wyn[i]);
	return 0;
}