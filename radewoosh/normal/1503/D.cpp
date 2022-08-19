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
const int nax=1200*1007;
const int n1=(1<<19);

int n;

void nope()
{
	printf("-1\n");
	exit(0);
}

pii tab[nax];
int flip[nax];

vi raz[nax];
vi dwa[nax];

vector<pii> pary;
int bylo[nax];

vi kol[2];

int konflikt(int a, int b)
{
	if (tab[a].first<tab[b].first && tab[b].first<tab[a].second && tab[a].second<tab[b].second)
		return 1;
	swap(a, b);
	if (tab[a].first<tab[b].first && tab[b].first<tab[a].second && tab[a].second<tab[b].second)
		return 1;
	return 0;
}

bool mni1(int a, int b)
{
	return tab[a].second<tab[b].second;
}

bool mni2(int a, int b)
{
	return tab[a].first>tab[b].first;
}

void dfs(int v, int k);

vi zbi;

void czyt(int v, int a, int b, int graa, int grab, int kto, int k)
{
	if (a>=graa && b<=grab)
	{
		while(!raz[v].empty() && konflikt(kto, raz[v].back()))
		{
			int x=raz[v].back();
			raz[v].pop_back();
			zbi.push_back(x);
		}
		while(!dwa[v].empty() && konflikt(kto, dwa[v].back()))
		{
			int x=dwa[v].back();
			dwa[v].pop_back();
			zbi.push_back(x);
		}
		return;
	}
	if (a>grab || b<graa)
	{
		return;
	}
	czyt((v<<1), a, (a+b)>>1, graa, grab, kto, k);
	czyt((v<<1)^1, (a+b+2)>>1, b, graa, grab, kto, k);
}

void dfs(int v, int k)
{
	if (bylo[v])
		return;
	bylo[v]=1;
	kol[k].push_back(v);
	czyt(1, 1, n1, tab[v].first, tab[v].second, v, k);
	vi moje;
	moje.swap(zbi);
	for (int i : moje)
		dfs(i, k^1);
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		tab[i]={a, b};
		if (a>b)
		{
			tab[i]={b, a};
			flip[i]=1;
		}
	}
	for (int i=1; i<=n; i++)
	{
		{
			int v=tab[i].first+n1-1;
			while(v)
			{
				raz[v].push_back(i);
				v>>=1;
			}
		}
		{
			int v=tab[i].second+n1-1;
			while(v)
			{
				dwa[v].push_back(i);
				v>>=1;
			}
		}
	}
	for (int i=1; i<2*n1; i++)
	{
		sort(raz[i].begin(), raz[i].end(), mni1);
		sort(dwa[i].begin(), dwa[i].end(), mni2);
	}
	int wyn=0;
	for (int i=1; i<=n; i++)
	{
		if (bylo[i])
			continue;
		kol[0].clear();
		kol[1].clear();
		dfs(i, 0);
		int ka=0;
		int kb=0;
		for (int j : kol[0])
		{
			ka+=(!flip[j]);
			kb+=(flip[j]);
		}
		for (int j : kol[1])
		{
			ka+=(flip[j]);
			kb+=(!flip[j]);
		}
		//~ debug() << kol[0] << " " << kol[1] << " " << ka << " " << kb;
		if (ka<kb)
		{
			wyn+=ka;
			for (int j : kol[1])
				pary.push_back(tab[j]);
			for (int j : kol[0])
				pary.push_back({tab[j].second, tab[j].first});
		}
		else
		{
			wyn+=kb;
			for (int j : kol[0])
				pary.push_back(tab[j]);
			for (int j : kol[1])
				pary.push_back({tab[j].second, tab[j].first});
		}
	}
	sort(pary.begin(), pary.end());
	//~ debug() << pary;
	for (int i=1; i<n; i++)
		if (pary[i].second>pary[i-1].second)
			nope();
	
	
	printf("%d\n", wyn);
	return 0;
}