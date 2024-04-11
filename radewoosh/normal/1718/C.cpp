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

int n, q;

ll tab[nax];

int r;
vi dz;

vll sum[nax];

priority_queue<pll> kol[nax];

int sito[nax];

void wypisz()
{
	ll ret=0;
	for (int i=0; i<r; i++)
	{
		while(1)
		{
			pll w=kol[i].top();
			if (sum[i][w.second]!=w.first)
			{
				kol[i].pop();
			}
			else
			{
				ret=max(ret, w.first*dz[i]);
				break;
			}
		}
	}
	printf("%lld\n", ret);
}

void test()
{
	scanf("%d%d", &n, &q);
	for (int i=0; i<n; i++)
		scanf("%lld", &tab[i]);
	dz.clear();
	for (int i=1; i<n; i++)
		if (!(n%i) && !sito[n/i])
			dz.push_back(i);
	r=dz.size();
	for (int i=0; i<r; i++)
	{
		sum[i].resize(dz[i]);
		for (int j=0; j<dz[i]; j++)
			sum[i][j]=0;
	}
	//~ debug() << imie(dz);
	for (int i=0; i<n; i++)
		for (int j=0; j<r; j++)
			sum[j][i%dz[j]]+=tab[i];
	for (int i=0; i<r; i++)
	{
		while(!kol[i].empty())
			kol[i].pop();
		for (int j=0; j<dz[i]; j++)
			kol[i].push({sum[i][j], j});
	}
	wypisz();
	while(q--)
	{
		int a;
		ll b;
		scanf("%d%lld", &a, &b);
		a--;
		ll zm=b-tab[a];
		tab[a]=b;
		for (int i=0; i<r; i++)
		{
			sum[i][a%dz[i]]+=zm;
			kol[i].push({sum[i][a%dz[i]], a%dz[i]});
		}
		wypisz();
	}
}

int main()
{
	for (int i=2; i<nax; i++)
		if (!sito[i])
			for (int j=2*i; j<nax; j+=i)
				sito[j]=1;
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}