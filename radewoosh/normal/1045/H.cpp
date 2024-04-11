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
const int nax=1000*1007;
const ll mod=1000*1000*1000+7;

int n;

char raz[nax], dwa[nax];

int tab[nax];

ll wyn;

int m=1;
int mac[2][2];

ll sil[nax];

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

ll komb(int a, int b)
{
	if (b<0 || b>a)
		return 0;
	return dziel(sil[a], (sil[b]*sil[a-b])%mod);
}

ll komz(int a, int b)
{
	if (!b)
		return 1;
	return komb(a+b-1, b);
}

//~ int li=0;

int ponad;

ll rek(int v, int w, int nier)
{
	//~ li++;
	if (!nier)
	{
		if (w>tab[v])
			nier=-1;
		if (w<tab[v])
			nier=1;
	}
	if (nier==-1)
		return 0;
	if (v==1)
		return (nier>=ponad);
	
	if (nier==1)
	{
		int z_ja=mac[w][w^1];
		int z_on=mac[w^1][w];
		int ja=mac[w][w];
		int on=mac[w^1][w^1];
		if (z_on!=z_ja && z_on!=z_ja-1)
			return 0;
		int na_ja=1+z_on;
		int na_on=z_ja;
		return (komz(na_ja, ja)*komz(na_on, on))%mod;
		
	}
	
	ll ret=0;
	
	for (int i=0; i<2; i++)
	{
		if (mac[w][i])
		{
			mac[w][i]--;
			ret+=rek(v-1, i, nier);
			mac[w][i]++;
		}
	}
	return ret%mod;
}

ll licz()
{
	int r=nax-1;
	while(!tab[r])
		r--;
	
	if (r<m)
		return rek(m, 1, -1);//zero
	if (r>m)
		return rek(m, 1, 1);//wsz
	if (r==m)
		return rek(m, 1, 0);//cos_tam
	assert(0);
}

int main()
{
	sil[0]=1;
	for (int i=1; i<nax; i++)
		sil[i]=(sil[i-1]*i)%mod;
	scanf("%s%s", raz+1, dwa+1);
	for (int i=0; i<2; i++)
	{
		for (int j=0; j<2; j++)
		{
			scanf("%d", &mac[i][j]);
			m+=mac[i][j];
		}
	}
	int r=strlen(dwa+1);
	for (int i=1; i<=r; i++)
		tab[i]=dwa[r+1-i]-'0';
	ponad=0;
	wyn+=licz();
	memset(tab, 0, sizeof(tab));
	if (r!=1)
	{
		ponad=1;
		r=strlen(raz+1);
		for (int i=1; i<=r; i++)
			tab[i]=raz[r+1-i]-'0';
		wyn=(wyn-licz()+mod)%mod;
	}
	//~ debug() << imie(li);
	printf("%lld\n", wyn);
	return 0;
}