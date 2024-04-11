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
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
const int nax=1500*1507;
const ll mod=998244353;

int k;
int tab[nax];

ll sil[nax];
ll odw[nax];

ll wyn;

ll drz[nax];
ll lazy[nax];

void pisz(int v, ll w)
{
	v+=1;
	for (int i=v; i<nax; i+=(i&(-i)))
		drz[i]+=w;
}

ll czyt(int v)
{
	v+=1;
	ll ret=0;
	for (int i=v; i; i-=(i&(-i)))
		ret+=drz[i];
	return ret;
}

ll dziel(ll a, ll b)
{
	ll wyk=mod-2;
	while(wyk)
	{
		if (wyk&1)
			a=(a*b)%mod;
		b=(b*b)%mod;
		wyk>>=1;
	}
	return a;
}

ll komb(ll a, ll b)
{
	if (b>a || b<0)
		return 0;
	return sil[a]*odw[b]%mod*odw[a-b]%mod;
}

ll komz(ll a, ll b)
{
	if (!a && !b)
		return 1;
	return komb(a+b-1, b);
}

int main()
{
	scanf("%d", &k);
	for (int i=1; i<=k; i++)
		scanf("%d", &tab[i]);
	sort(tab+1, tab+1+k);
	sil[0]=1;
	for (int i=1; i<nax; i++)
		sil[i]=(sil[i-1]*i)%mod;
	odw[nax-1]=dziel(1, sil[nax-1]);
	for (int i=nax-2; i>=0; i--)
		odw[i]=(odw[i+1]*(i+1))%mod;
	for (int i=1; i<=k; i++)
	{
		if (tab[i]<i-1)
			break;
		//~ for (int j=i-1; j<=tab[i]; j++)
		for (int j=0; j<=tab[i]; j++)
		{
			if (lazy[j])
			{
				pisz(j, lazy[j]);
				lazy[j+k]+=lazy[j];
				lazy[j]=0;
			}
			if (j>=i-1)
			{
				ll x=komz(k-1, j-czyt(j));
				wyn=(wyn+x)%mod;
			}
			//~ debug() << i << " " << j << "  " << x;
		}
		
		
		lazy[tab[i]+1]++;
		pisz(0, 1);
		pisz(tab[i]+1, -1);
	}
	
	
	printf("%lld\n", wyn);
	return 0;
}