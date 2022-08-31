//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
//~ #pragma GCC target ("avx2")
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

int n, m;

vector<pii> graf[nax];

int wagwie[nax];

pii kra[nax];
int wagkra[nax];

int suma[nax];

int juz[nax];

void wypisz()
{
	vi wek;
	for (int i=1; i<=n; i++)
		if (wagwie[i])
			wek.push_back(i);
	printf("%d\n", (int)wek.size());
	for (int i : wek)
		printf("%d ", i);
	printf("\n");
	for (int i=1; i<=m; i++)
		printf("%d %d %d\n", kra[i].first, kra[i].second, wagkra[i]);
	exit(0);
}

int spoko(int v, int waga)
{
	for (pii i : graf[v])
		if (juz[i.first] && suma[i.first]==waga)
			return 0;
	return 1;
}

int spoko(int v, int waga, const vi &tylko)
{
	for (int i : tylko)
		if (suma[i]==waga)
			return 0;
	return 1;
}

int los(int a, int b)
{
	return a+rand()%(b-a+1);
}

void zmienwie(int v, int waga)
{
	if (wagwie[v]==waga)
		return;
	suma[v]-=wagwie[v];
	wagwie[v]=waga;
	suma[v]+=wagwie[v];
}

void zmienkra(int v, int waga)
{
	if (wagkra[v]==waga)
		return;
	suma[kra[v].first]-=wagkra[v];
	suma[kra[v].second]-=wagkra[v];
	wagkra[v]=waga;
	suma[kra[v].first]+=wagkra[v];
	suma[kra[v].second]+=wagkra[v];
}

int bylo[nax];

void dfs(int v, vi &kol)
{
	if (bylo[v])
		return;
	bylo[v]=1;
	for (pii i : graf[v])
		dfs(i.first, kol);
	kol.push_back(v);
}

void proba()
{
	debug() << "proba";
	for (int i=1; i<=n; i++)
		wagwie[i]=suma[i]=juz[i]=0;
	for (int i=1; i<=m; i++)
		wagkra[i]=0;
	vi kolp(n);
	iota(kolp.begin(), kolp.end(), 1);
	shandom_ruffle(kolp.begin(), kolp.end());
	for (int i=1; i<=n; i++)
		shandom_ruffle(graf[i].begin(), graf[i].end());
	vi kol;
	for (int i=1; i<=n; i++)
		bylo[i]=0;
	for (int i : kolp)
		dfs(i, kol);
		
	static int pier=0;
	if (!pier)
	{
		pier=1;
		for (int i=1; i<=m; i++)
			zmienkra(i, (kra[i].first+kra[i].second<=n)*2);
		zmienwie(n/2, 1);
	}
	else
	{
		for (int i=1; i<=n; i++)
			zmienwie(i, los(0, 1));
		for (int i=1; i<=m; i++)
			zmienkra(i, los(0, 2));
	}
	int ile=0;
	for (int v : kol)
	{
		vi poki;
		for (pii i : graf[v])
			if (juz[i.first])
				poki.push_back(i.first);
		int wdol=0;
		int wgor=0;
		for (pii i : graf[v])
		{
			if (!juz[i.first])
			{
				wdol+=wagkra[i.second];
				wgor+=2-wagkra[i.second];
			}
		}
		if (wagwie[v])
			wdol++;
		else
			wgor++;
		vector<pii> poki2;
		for (pii i : graf[v])
			if (juz[i.first])
				poki2.push_back(i);
		for (int h=0; h<20 && !spoko(v, suma[v], poki); h++)
		{
			set<int> jest;
			for (int i : poki)
				jest.insert(suma[i]);
			for (int w=suma[v]-wdol; w<=suma[v]+wgor; w++)
			{
				if (!jest.count(w))
				{
					if (w<suma[v] && wagwie[v])
						zmienwie(v, 0);
					if (w>suma[v] && !wagwie[v])
						zmienwie(v, 1);
					for (pii i : graf[v])
					{
						if (!juz[i.first])
						{
							while(wagkra[i.second] && suma[v]>w)
								zmienkra(i.second, wagkra[i.second]-1);
							while(wagkra[i.second]<2 && suma[v]<w)
								zmienkra(i.second, wagkra[i.second]+1);
						}
					}
					break;
				}
			}
			if (spoko(v, suma[v], poki))
				break;
			for (int x=0; x<(int)poki.size(); x++)
			{
				pii kra=poki2[x];
				int nowa=(wagkra[kra.second]+los(1, 2))%3;
				int zmiana=nowa-wagkra[kra.second];
				if (spoko(kra.first, suma[kra.first]+zmiana))
					zmienkra(kra.second, nowa);
				if (los(0, 1) && spoko(kra.first, suma[kra.first]-wagwie[kra.first]+(1^wagwie[kra.first])))
					zmienwie(kra.first, 1^wagwie[kra.first]);
			}
		}
		ile++;
		if (!spoko(v, suma[v], poki))
		{
			debug() << ile << " z " << n << " " << poki.size() << " " << graf[v].size();
			return;
		}
		juz[v]=1;
	}
	wypisz();
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		kra[i]={a, b};
		graf[a].push_back({b, i});
		graf[b].push_back({a, i});
	}
	while(1)
		proba();
	return 0;
}