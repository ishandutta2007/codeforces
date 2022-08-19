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
const ll mod=1000*1000*1000+7;

ll inv(ll v)
{
	if (v<=1)
		return v;
	return inv(mod%v)*(mod-mod/v)%mod;
}

int n;
ll k;
int tab[nax];

ll fm[nax];
ll fd[nax];

ll oczek[nax];

map<ll,int> mapa;
map<ll,ll> ile;

int wolne;

ll pk[nax];
ll pk1[nax];

ll sil[nax];
ll odw[nax];

void dod(ll &a, ll b)
{
	a=(a+b)%mod;
}

ll kom(int a, int b)
{
	if (b<0 || b>a)
		return 0;
	return sil[a]*odw[b]%mod*odw[a-b]%mod;
}

ll wyn;

int main()
{
	srand(time(0));
	scanf("%d%lld", &n, &k);
	for (int i=1; i<=n; i++)
		scanf("%d", &tab[i]);
	fm[1]=1;
	ll dk=inv(k);
	ll dn=inv(n);
	for (int i=1; i<n; i++)
	{
		ll tu=((n-i)*dn%mod*dk+i*dn%mod*(k-1)%mod*dk)%mod;
		ll pop=i*dn%mod*dk%mod;
		ll nast=(n-i)*dn%mod*(k-1)%mod*dk%mod;
		for (int j=i-1; j<=i; j++)
		{
			ll x;
			if (j<i)
				x=(mod-pop)*inv(nast);
			else
				x=(mod+1-tu)*inv(nast);
			x%=mod;
			dod(fm[i+1], fm[j]*x);
			dod(fd[i+1], fd[j]*x);
		}
		dod(fd[i+1], (mod-1)*inv(nast));
	}
	debug() << range(fm+1, fm+1+n);
	debug() << range(fd+1, fd+1+n);
	ll rm=(fm[n]-fm[n-1]+mod)%mod;
	ll rd=(fd[n]-fd[n-1]+mod)%mod;
	oczek[1]=(k+mod-rd)*inv(rm)%mod;
	for (int i=2; i<=n; i++)
		oczek[i]=(oczek[1]*fm[i]+fd[i])%mod;
	
	debug() << range(oczek+1, oczek+1+n);
	wyn=(mod-((k-1)*oczek[n])%mod)%mod;
	for (int i=1; i<=n; i++)
	{
		if (tab[i]==-1)
			wolne++;
		else
			mapa[tab[i]]++;
	}
	pk[0]=pk1[0]=1;
	for (int i=1; i<=n; i++)
	{
		pk[i]=(pk[i-1]*k)%mod;
		pk1[i]=(pk1[i-1]*(k-1))%mod;
	}
	sil[0]=1;
	for (int i=1; i<=n; i++)
		sil[i]=(sil[i-1]*i)%mod;
	odw[n]=inv(sil[n]);
	for (int i=n; i; i--)
		odw[i-1]=(odw[i]*i)%mod;
	ll wsz=k;
	for (auto i : mapa)
	{
		wsz--;
		ile[i.second]++;
	}
	if (wsz)
		ile[0]=wsz;
	ll proby=inv(pk[wolne]);
	for (auto i : ile)
	{
		ll mno=i.second;
		int baza=i.first;
		for (int j=0; j<=wolne; j++)
		{
			int mam=baza+j;
			ll szan=kom(wolne, j)*proby%mod*pk1[wolne-j]%mod;
			wyn=(wyn+mno*szan%mod*oczek[n-mam])%mod;
		}
	}
	wyn=(wyn*dk)%mod;
	printf("%lld\n", wyn);
	return 0;
}