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
const int nax=1000*1007;
const ll mod=1000*1000*1000+7;

int n, k, q;

ll sil[nax];
ll odw[nax];

vector <int> dzi[nax];

int ile[nax];
ll wyn;
ll mobius[nax];

int sito[nax];
int parz[nax];

ll kom(int a, int b)
{
	if (b<0 || b>a)
		return 0;
	return (sil[a]*((odw[b]*odw[a-b])%mod))%mod;
}

ll licz(int v)
{
	ll ret=0;
	for (int i : dzi[v])
		ret=(ret+mobius[i]*kom(ile[i], k))%mod;
	ret+=mod;
	ret%=mod;
	return ret;
}

void dodaj(int v)
{
	wyn-=licz(v);
	for (int i : dzi[v])
		ile[i]++;
	wyn+=licz(v);
	wyn%=mod;
	wyn+=mod;
	wyn%=mod;
}

int main()
{
	scanf("%d%d%d", &n, &k, &q);
	
	sil[0]=odw[0]=odw[1]=1;
	for (int i=1; i<nax; i++)
		sil[i]=(sil[i-1]*i)%mod;
	for (int i=2; i<nax; i++)
		odw[i]=(odw[mod%i]*(mod-mod/i))%mod;
	for (int i=2; i<nax; i++)
		odw[i]=(odw[i]*odw[i-1])%mod;
	
	debug() << "p";
	for (int i=1; i<nax; i++)
		for (int j=i; j<nax; j+=i)
			dzi[j].push_back(i);
	debug() << "a";
	parz[1]=1;
	for (int i=2; i<nax; i++)
	{
		if (!sito[i])
			for (int j=i; j<nax; j+=i)
				sito[j]=i;
		parz[i]=-parz[i/sito[i]];
		if (!((i/sito[i])%sito[i]))
			parz[i]=0;
	}
	debug() << "b";
	for (int i=1; i<nax; i++)
	{
		for (int j=i; j<nax; j+=i)
			mobius[j]+=i*parz[j/i];
		mobius[i]%=mod;
		mobius[i]+=mod;
		mobius[i]%=mod;
	}
	debug() << "c";
	for (int i=1; i<=n; i++)
	{
		int x;
		scanf("%d", &x);
		dodaj(x);
	}
	for (int i=1; i<=q; i++)
	{
		int x;
		scanf("%d", &x);
		dodaj(x);
		printf("%lld\n", wyn);
	}
	
	return 0;
}