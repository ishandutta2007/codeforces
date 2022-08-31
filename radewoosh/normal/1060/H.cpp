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
const int nax=57;
using ld=double;

ll d, mod;

ll dziel(ll a, ll b)
{
	a%=mod;
	b%=mod;
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

ll pot(ll a, ll b)
{
	a%=mod;
	ll ret=1;
	while(b)
	{
		if (b&1)
			ret=(ret*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return ret;
}

int n=5000;

ll mac[nax][nax];
ll kom[nax][nax];

void zam(int a, int b)
{
	for (int i=0; i<=2*d+3; i++)
		swap(mac[a][i], mac[b][i]);
}

void dod(int a, int b, ll w)
{
	for (int i=0; i<=2*d+3; i++)
		mac[a][i]=(mac[a][i]+mac[b][i]*w)%mod;
}

void mno(int a, ll w)
{
	for (int i=0; i<=2*d+3; i++)
		mac[a][i]=(mac[a][i]*w)%mod;
}

void gauss()
{
	for (int i=0; i<=d; i++)
	{
		for (int j=i; j<=d; j++)
		{
			if (mac[j][i])
			{
				zam(i, j);
				break;
			}
		}
		assert(mac[i][i]);
		ll w=dziel(1, mac[i][i]);
		mno(i, w);
		for (int j=0; j<=d; j++)
			if (j!=i)
				dod(j, i, mod-mac[j][i]);
	}
}

int daj_razy(int x, int v)
{
	if (!x)
		x=mod;
	if (x==1)
		return v;
	printf("+ %d %d %d\n", v, v, n);
	n--;
	if (!(x&1))
		return daj_razy(x/2, n+1);
	int w=daj_razy(x/2, n+1);
	printf("+ %d %d %d\n", w, v, n);
	n--;
	return n+1;
}

int main()
{
	scanf("%lld%lld", &d, &mod);
	
	for (int i=0; i<nax; i++)
	{
		kom[i][0]=1;
		for (int j=1; j<=i; j++)
			kom[i][j]=(kom[i-1][j-1]+kom[i-1][j])%mod;
	}
	for (int i=0; i<=d; i++)
	{
		for (int j=0; j<=d; j++)
		{
			mac[i][j]=(kom[d][j]*pot(i, d-j))%mod;
		}
		mac[i][d+1+i]=1;
	}
	gauss();
	printf("+ %d %d %d\n", 1, 2, 3);
	vi wek[4];
	vi zbi;
	for (int h=1; h<=3; h++)
	{
		wek[h].push_back(h);
		for (int i=1; i<=d; i++)
		{
			printf("+ %d %d %d\n", wek[h].back(), 69, n);
			wek[h].push_back(n);
			n--;
		}
		for (int i : wek[h])
			printf("^ %d %d\n", i, i);
		vi now;
		for (int i=0; i<=d; i++)
			now.push_back(daj_razy(mac[2][d+1+i], wek[h][i]));
		int ost=now[0];
		for (int i=1; i<=d; i++)
			printf("+ %d %d %d\n", ost, now[i], ost);
		zbi.push_back(ost);
	}
	printf("+ %d %d %d\n", zbi[0], zbi[1], n);
	n--;
	int w=daj_razy(mod-1, n+1);
	printf("+ %d %d %d\n", zbi[2], w, n);
	n--;
	int x=daj_razy((mod+1)/2, n+1);
	printf("f %d\n", x);
	return 0;
}