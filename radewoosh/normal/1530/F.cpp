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
const int nax=107;
const ll mod=31607;

int n;

ll tab[nax][nax];

ll inv[mod];

vector<vector<pii>> ciek;

ll wyn;

ll szan[nax];

int wz[nax][nax];

void rek(int v, int ile, ll og)
{
	if (v==(int)ciek.size())
	{
		for (int i=1; i<=n; i++)
			og=(og*(1-szan[i]+mod))%mod;
		//~ debug() << og << " " << ile;
		if (ile&1)
			wyn=(wyn-og+mod)%mod;
		else
			wyn=(wyn+og)%mod;
		//~ debug() << og << " " << ile << " " << range(szan+1, szan+1+n);
		return;
	}
	rek(v+1, ile, og);
	for (pii i : ciek[v])
	{
		if (!wz[i.first][i.second])
		{
			szan[i.first]=(szan[i.first]*inv[tab[i.first][i.second]])%mod;
			og=(og*tab[i.first][i.second])%mod;
		}
		wz[i.first][i.second]++;
	}
	rek(v+1, ile+1, og);
	for (pii i : ciek[v])
	{
		if (wz[i.first][i.second]==1)
			szan[i.first]=(szan[i.first]*tab[i.first][i.second])%mod;
		wz[i.first][i.second]--;
	}
}

int main()
{
	inv[1]=1;
	for (int i=2; i<mod; i++)
		inv[i]=(inv[mod%i]*(mod-mod/i))%mod;
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=n; j++)
		{
			scanf("%lld", &tab[i][j]);
			//~ tab[i][j]=5000;
			tab[i][j]=(tab[i][j]*inv[10000])%mod;
		}
		debug() << range(tab[i]+1, tab[i]+1+n);
	}
	for (int i=1; i<=n; i++)
	{
		vector<pii> ter;
		for (int j=1; j<=n; j++)
			ter.push_back({j, i});
		ciek.push_back(ter);
	}
	{
		vector<pii> ter1, ter2;
		for (int i=1; i<=n; i++)
		{
			ter1.push_back({i, i});
			ter2.push_back({n+1-i, i});
		}
		ciek.push_back(ter1);
		ciek.push_back(ter2);
	}
	for (int i=1; i<=n; i++)
	{
		szan[i]=1;
		for (int j=1; j<=n; j++)
			szan[i]=(szan[i]*tab[i][j])%mod;
	}
	rek(0, 0, 1);
	wyn=1-wyn;
	wyn%=mod;
	wyn+=mod;
	wyn%=mod;
	printf("%lld\n", wyn);
	return 0;
}