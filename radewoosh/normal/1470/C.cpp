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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void ff()
{
	fflush(stdout);
}

int n;
ll k;

ll ile[nax];
ll tmp[nax];
int moze[nax];

int mod(int v)
{
	v%=n;
	
	if (v<=0)
		v+=n;
	return v;
}

ll pyt(int v)
{
	printf("? %d\n", v);
	ff();
	ll x;
	scanf("%lld", &x);
	return x;
}

void ans(int v)
{
	printf("! %d\n", v);
	ff();
	exit(0);
}

void runda()
{
	for (int i=1; i<=n; i++)
	{
		if (i==1)
		{
			tmp[mod(i+1)]+=ile[i];
		}
		else
		{
			tmp[mod(i-1)]+=ile[i]/2;
			tmp[mod(i+1)]+=(ile[i]+1)/2;
		}
	}
	for (int i=1; i<=n; i++)
	{
		ile[i]=tmp[i];
		tmp[i]=0;
	}
}

int main()
{
	scanf("%d%lld", &n, &k);
	for (int i=1; i<=n; i++)
	{
		moze[i]=1;
	}
	for (int i=1; i<=n; i++)
		ile[i]=k;
	while(1)
	{
		debug() << range(ile+1, ile+1+n) << range(moze+1, moze+1+n);
		int licz=0;
		vi opc;
		for (int i=1; i<=n; i++)
		{
			licz+=moze[i];
			if (moze[i])
				opc.push_back(i);
		}
		shuffle(opc.begin(), opc.end(), rng);
		int g=opc[0];
		if (licz==1)
			ans(g);
		if (rng()&1)
			g=mod(g+1);
		else if (rng()&1)
			g=mod(g-1);
		ll wez=pyt(g);
		for (int i=1; i<=n; i++)
			if (ile[i]!=wez)
				moze[mod(g-i+1)]=0;
		runda();
	}
	return 0;
}