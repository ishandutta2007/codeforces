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

void eukl(ll &x, ll &y, ll a, ll b) {
  if (!a) { x = 0; y = 1; return; }
  eukl(y, x, b % a, a);
  x -= y * (b / a);
}

ll mno(ll a, ll b, ll mod) {//a moze byc ujemne
  //~ return (__int128(a)*b)%mod;
  ll ret=0;
  a%=mod;
  a+=mod;
  a%=mod;
  while(b)
  {
	if (b&1)
	  ret=(ret+a)%mod;
	a=(a+a)%mod;
	b>>=1;
  }
  return ret;
}

pll crt2(ll p, ll a, ll q, ll b) {
	if (a==-1)
		return {-1, -1};
	ll x, y;
	eukl(x, y, a, b);
	ll nwd=x*a+y*b;
	if ((p%nwd)!=(q%nwd))
		return {-1, -1};
	a/=nwd;
	b/=nwd;
	ll nww=a*b;
	ll ret=mno(x*a, q/nwd, nww)+mno(y*b, p/nwd, nww);
	if ((ret%=nww)<0)
		ret+=nww;
	return {ret*nwd+(p%nwd), nww*nwd};
}

pll crt(vector <pll> wek) {
	pll ret={0, 1};
	for (auto i : wek)
		ret=crt2(ret.first, ret.second, i.first, i.second);
	return ret;
}

ll n, m;

int k;
ll tab[nax];

void nope()
{
	printf("NO\n");
	exit(0);
}

ll mno(ll a, ll b)
{
	ll r=a*b;
	if ((r/a)!=b || (r/b)!=a || r>n || r<0)
		nope();
	return r;
}

int main()
{
	scanf("%lld%lld%d", &n, &m, &k);
	for (int i=1; i<=k; i++)
		scanf("%lld", &tab[i]);
	ll w=1;
	for (int i=1; i<=k; i++)
	{
		w/=__gcd(w, tab[i]);
		w=mno(w, tab[i]);
	}
	if (w>n)
		nope();
	vector <pll> wek;
	for (int i=1; i<=k; i++)
		wek.push_back({(tab[i]-(i%tab[i]))%tab[i], tab[i]});
	auto wez=crt(wek);
	if (wez.first==-1)
		nope();
	ll g=wez.first;
	if (g+k>m)
		nope();
	for (int i=1; i<=k; i++)
		if (__gcd(w, g+i)!=tab[i])
			nope();
	printf("YES\n");
	
	return 0;
}