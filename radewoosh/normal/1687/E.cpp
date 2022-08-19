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

int n;
ll tab[nax];

int sito[nax];
vector<pii> zaw[nax];

vector<pii> roz;

int wazne[nax];

vector<pair<int,vi>> wyn;

ll cel=1;

int czas;
int jest[nax];

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		scanf("%lld", &tab[i]);
	for (int i=2; i<nax; i++)
		if (!sito[i])
			for (int j=i; j<nax; j+=i)
				sito[j]=i;
	for (int i=1; i<=n; i++)
	{
		int x=tab[i];
		vector<pii> zr;
		while(x>1)
		{
			int y=sito[x];
			if (zr.empty() || zr.back().first!=y)
				zr.push_back({y, 0});
			zr.back().second++;
			x/=y;
		}
		for (pii j : zr)
			zaw[j.first].push_back({j.second, i});
	}
	for (int i=1; i<nax; i++)
	{
		if (sito[i]!=i || zaw[i].empty())
			continue;
		for (int h=0; h<2 && (int)zaw[i].size()<n; h++)
		{
			czas++;
			for (pii j : zaw[i])
				jest[j.second]=czas;
			int brak=1;
			while(jest[brak]==czas)
				brak++;
			zaw[i].push_back({0, brak});
		}
		sort(zaw[i].begin(), zaw[i].end());
		for (int h=0; h<2; h++)
			wazne[zaw[i][h].second]=1;
		if ((int)zaw[i].size()!=n)
			continue;
		int chce=zaw[i][0].first+zaw[i][1].first;
		for (int j=0; j<chce; j++)
			cel*=i;
		if (chce)
			roz.push_back({i, chce});
	}
	vi inte;
	for (int i=1; i<=n; i++)
		if (wazne[i])
			inte.push_back(i);
	//~ debug() << imie(cel);
	//~ debug() << range(wazne+1, wazne+1+n);
	//~ debug() << imie(inte);
	int r=inte.size();
	vi musz(1<<r);
	for (int i=1; i<(1<<r); i++)
	{
		int s=__builtin_popcount(i);
		if (s&1)
			musz[i]++;
		else
			musz[i]--;
	}
	for (int i=1; i<(1<<r); i++)
	{
		int s=__builtin_popcount(i);
		if (!(s&1))
			musz[i]+=s-1;
		else
			musz[i]-=s-1;
	}
	for (int i=1; i<(1<<r); i++)
	{
		vi wek;
		for (int j=0; j<r; j++)
			if (i&(1<<j))
				wek.push_back(inte[j]);
		while(musz[i]>0)
		{
			musz[i]--;
			wyn.push_back({0, wek});
		}
		while(musz[i]<0)
		{
			musz[i]++;
			wyn.push_back({1, wek});
		}
	}
	
	assert((int)wyn.size()<=100*1000);
	printf("%d\n", (int)wyn.size());
	for (auto i : wyn)
	{
		printf("%d %d", i.first, (int)i.second.size());
		for (int j : i.second)
			printf(" %d", j);
		printf("\n");
	}
	return 0;
}