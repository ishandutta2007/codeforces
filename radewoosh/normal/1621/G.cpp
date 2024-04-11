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
//~ const int n1=(1<<18);
const ll inf=1e18;
const ll mod=1000*1000*1000+7;

int n;
ll tab[nax];

ll wyn;

int k;
map<ll,int> ska;

pll fen[nax];

pll dp[nax];

ll suf[nax];

set<ll> maxima;
map<ll,vi> zbi;

pll operator +(pll a, pll b)
{
	a.first=(a.first+b.first)%mod;
	a.second=(a.second+b.second)%mod;
	return a;
}

void pisz(int v, pll w)
{
	for (int i=v; i<=n; i+=(i&(-i)))
		fen[i]=(fen[i]+w);
}

void czysc(int v)
{
	for (int i=v; i<=n; i+=(i&(-i)))
		fen[i]={0LL, 0LL};
}

pll czyt(int v)
{
	pll ret{0LL, 0LL};
	for (int i=v; i; i-=(i&(-i)))
		ret=(ret+fen[i]);
	return ret;
}

void dod(ll &a, ll b)
{
	a=(a+b)%mod;
}

void test()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		scanf("%lld", &tab[i]);
		tab[i]=tab[i]*(n+7)+n-i;
	}
	wyn=0;
	k=0;
	ska.clear();
	for (int i=1; i<=n; i++)
		ska[tab[i]]=0;
	for (auto i : ska)
	{
		k++;
		ska[i.first]=k;
	}
	for (int i=1; i<=n; i++)
		fen[i]={0LL, 0LL};
	for (int i=1; i<=n; i++)
	{
		int x=ska[tab[i]];
		pll wez=czyt(x-1);
		wez.second=(wez.second+1)%mod;
		wez.first=(wez.first+wez.second)%mod;
		dp[i]=wez;
		pisz(x, wez);
		dod(wyn, wez.first);
	}
	//~ debug() << range(dp+1, dp+1+n);
	
	suf[n+1]=0;
	for (int i=n; i; i--)
		suf[i]=max(suf[i+1], tab[i]);
	
	maxima.clear();
	for (int i=1; i<=n; i++)
		maxima.insert(suf[i]);
	zbi.clear();
	for (int i=1; i<=n; i++)
	{
		if (tab[i]==suf[i])
		{
			zbi[tab[i]].push_back(i);
		}
		else
		{
			ll x=(*maxima.upper_bound(tab[i]));
			zbi[x].push_back(i);
		}
	}
	for (int i=1; i<=n; i++)
		fen[i]={0LL, 0LL};
	vi docz;
	for (auto i : zbi)
	{
		vi poz=i.second;
		reverse(poz.begin(), poz.end());
		
		for (int j : poz)
		{
			int x=k+1-ska[tab[j]];
			docz.push_back(x);
			pll wez=czyt(x-1);
			if (suf[j]==tab[j])
				dod(wez.first, 1);
			pisz(x, wez);
			wyn=(wyn-(wez.first*dp[j].second))%mod;
			//~ debug() << " " << (wez.first*dp[j].second);
		}
		while(!docz.empty())
		{
			czysc(docz.back());
			docz.pop_back();
		}
	}
	
	wyn%=mod;
	wyn+=mod;
	wyn%=mod;
	printf("%lld\n", wyn);
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}