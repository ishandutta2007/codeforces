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
const int nax=100*1007;
const int vax=10*1000*1007;
const ll mod=1000*1000*1000+7;

int n, q;
vector <int> graf[nax];

int tab[nax];

int sito[vax];

int l;
int pre[nax];
int post[nax];
int odl[nax];
vector <int> jump[nax];

ll wyn[nax];
pair <int,int> zap[nax];
int zapw[nax];
vector < pair <int,int> > wla[nax];

unordered_map <int, vector <int> > mapa;

//stru
int drz[nax];

void pisz(int a, int b)
{
	for (int i=a; i<=n; i+=(i&(-i)))
		drz[i]++;
	for (int i=b+1; i<=n; i+=(i&(-i)))
		drz[i]--;
}

void zeruj(int a, int b)
{
	for (int i=a; i<=n; i+=(i&(-i)))
		drz[i]=0;
	for (int i=b+1; i<=n; i+=(i&(-i)))
		drz[i]=0;
}

int czyt(int v)
{
	int ret=0;
	for (int i=v; i>0; i-=(i&(-i)))
		ret+=drz[i];
	return ret;
}

//koniec

ll pot(ll a, ll b)
{
	ll ret=1;
	while(b)
	{
		if (b&1)
			ret=(ret*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return ret;
}

void dfs1(int v, int oj)
{
	jump[v].push_back(oj);
	while(jump[v].back())
	{
		int p1=jump[v].back();
		int p2=min(jump[v].size(), jump[p1].size())-1;
		jump[v].push_back(jump[p1][p2]);
	}
	l++;
	pre[v]=l;
	for (int i : graf[v])
	{
		if (i!=oj)
		{
			odl[i]=odl[v]+1;
			dfs1(i, v);
		}
	}
	post[v]=l;
}

int lca(int v, int u)
{
	for (int h=0; h<2; h++)
	{
		swap(v, u);
		for (int i=20; i>=0; i--)
		{
			i=min(i, (int)jump[v].size()-1);
			if (odl[jump[v][i]]>=odl[u])
				v=jump[v][i];
		}
	}
	for (int i=20; i>=0; i--)
	{
		i=min(i, (int)jump[v].size()-1);
		if (jump[v][i]!=jump[u][i])
		{
			v=jump[v][i];
			u=jump[u][i];
		}
	}
	if (v!=u)
		v=jump[v][0];
	return v;
}

vector < pair<int,int> > rozloz(int v)
{
	int pam=v;
	vector < pair<int,int> > ret;
	while(v>1)
	{
		if (ret.empty() || ret.back().first!=sito[v])
			ret.push_back({sito[v], 0});
		ret.back().second++;
		v/=sito[v];
	}
	debug() << pam << " to " << ret;
	return ret;
}

int main()
{
	for (int i=2; i<vax; i++)
		if (!sito[i])
			for (int j=i; j<vax; j+=i)
				sito[j]=i;
	scanf("%d", &n);
	for (int i=1; i<n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	for (int i=1; i<=n; i++)
	{
		scanf("%d", &tab[i]);
		for (auto j : rozloz(tab[i]))
		{
			ll mno=1;
			for (int l=1; l<=j.second; l++)
			{
				mno*=j.first;
				mapa[mno].push_back(-i);
			}
		}
	}
	odl[1]=1;
	dfs1(1, 0);
	scanf("%d", &q);
	for (int i=1; i<=q; i++)
	{
		wyn[i]=1;
		scanf("%d%d%d", &zap[i].first, &zap[i].second, &zapw[i]);
		wla[i].push_back({zap[i].first, 1});
		wla[i].push_back({zap[i].second, 1});
		int w=lca(zap[i].first, zap[i].second);
		wla[i].push_back({w, -1});
		if (w!=1)
			wla[i].push_back({jump[w][0], -1});
		for (auto j : rozloz(zapw[i]))
		{
			ll mno=1;
			for (int l=1; l<=j.second; l++)
			{
				mno*=j.first;
				mapa[mno].push_back(i);
			}
		}
	}
	//~ debug() << mapa;
	for (const auto &i : mapa)
	{
		vector <int> raz, dwa;
		for (const int &j : i.second)
		{
			if (j>0)
				dwa.push_back(j);
			else
				raz.push_back(-j);
		}
		if (dwa.empty())
			continue;
		for (int j : raz)
			pisz(pre[j], post[j]);
		for (int j : dwa)
		{
			ll zbi=0;
			for (auto l : wla[j])
				zbi+=l.second*czyt(pre[l.first]);
			if (j==2)
				debug() << j << " powinno " << sito[i.first] << " razy " << zbi;
			wyn[j]=(wyn[j]*pot(sito[i.first], zbi))%mod;
		}
		for (int j : raz)
			zeruj(pre[j], post[j]);
	}
	for (int i=1; i<=q; i++)
		printf("%lld\n", wyn[i]);
	return 0;
}