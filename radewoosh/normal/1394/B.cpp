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

int n, m, k;

vector<pii> dos[nax];
vi graf[nax];
vi farg[nax];

int wyn;

void nope()
{
	printf("0\n");
	exit(0);
}

int kt(int a, int b)
{
	for (int i=0; i<(int)graf[a].size(); i++)
		if (graf[a][i]==b)
			return i;
	assert(0);
}

vector<pair<pii,pii>> pary;

void siej(vector<pii> &wek)
{
	auto pom=wek;
	wek.clear();
	for (pii i : pom)
	{
		int r=wek.size();
		if (r<2 || wek[r-1]!=i || wek[r-2]!=i)
			wek.push_back(i);
	}
}

int chce[nax];

void check()
{
	for (auto i : pary)
	{
		pii a=i.first;
		pii b=i.second;
		if (chce[a.first]==a.second && chce[b.first]==b.second)
			return;
	}
	wyn++;
}

void rek(int v)
{
	if (v==k)
	{
		check();
		return;
	}
	for (int i=0; i<=v; i++)
	{
		chce[v]=i;
		rek(v+1);
	}
}

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i=1; i<=m; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		dos[a].push_back({c, b});
		farg[b].push_back(a);
	}
	for (int i=1; i<=n; i++)
	{
		sort(dos[i].begin(), dos[i].end());
		for (pii j : dos[i])
			graf[i].push_back(j.second);
		//~ debug() << i << " " << graf[i];
	}
	for (int i=1; i<=n; i++)
	{
		vector<pii> wek;
		for (int j : farg[i])
			wek.push_back({((int)graf[j].size())-1, kt(j, i)});
		sort(wek.begin(), wek.end());
		siej(wek);
		for (int j=0; j<(int)wek.size(); j++)
		{
			for (int l=j+1; l<(int)wek.size(); l++)
			{
				pary.push_back({wek[j], wek[l]});
			}
		}
	}
	sort(pary.begin(), pary.end());
	pary.resize(unique(pary.begin(), pary.end())-pary.begin());
	//~ debug() << pary;
	rek(0);
	
	printf("%d\n", wyn);
	return 0;
}