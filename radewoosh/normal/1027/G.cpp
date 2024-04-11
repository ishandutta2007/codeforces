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
const int nax=1007;

vector<ll> witness = {2, 325, 9375, 28178, 450775, 9780504, 1795265022}; // < 2^64

ll mul(ll a, ll b, ll mod) {
	//~ return (__int128) a * b % mod;
	a%=mod;
	b%=mod;
	ll ret=0;
	while(a)
	{
		if (a&1)
		{
			ret+=b;
			if (ret>=mod)
				ret-=mod;
		}
		b+=b;
		if (b>=mod)
			b-=mod;
		a>>=1;
	}
	return ret;
}
ll my_pow(ll a, ll b, ll mod) {
	ll res = 1%mod;
	while(b) {
		if(b % 2) res = mul(res, a, mod);
		a = mul(a, a, mod);
		b /= 2;
	}
	return res;
}
bool test(ll n) {
	if(n == 2) return true;
	if(n < 2 || n % 2 == 0) return false;
	ll d = n - 1, s = 0;
	while(d % 2 == 0) {
		d /= 2;
		++s;
	}
	for(auto i : witness) if(i % n) {
		ll x = my_pow(i, d, n);
		if(x == 1) continue;
		bool zlozona = true;
		for(int j = 0; j < s; ++j) {
			if(x == n - 1) {
				zlozona = false;
				break;
			}
			x = mul(x, x, n);
		}
		if(zlozona) return false;
	}
	return true;
}
ll f(ll x, ll mod, ll c) {
	ll y = mul(x, x, mod) + c;
	if(y > mod) y -= mod;
	return y;
}
void rho(ll n, vector<ll> & w) {
	if(n <= 1) return;
	if(test(n)) {
		w.push_back(n);
		return;
	}
	for(ll c = 1; true; ++c) {
		ll x = 2, y = 2, d = 1;
		while(d == 1) {
			x = f(x, n, c);
			y = f( f(y,n,c), n, c);
			d = __gcd(abs(x - y), n);
		}
		if(d < n) {
			rho(d, w);
			rho(n / d, w);
			return;
		}
	}
}
vector<ll> rozklad(ll n) {
	vector<ll> w;
	for(int i = 2; i <= 100; ++i) while(n % i == 0) {
		n /= i;
		w.push_back(i);
	}
	rho(n, w);
	sort(w.begin(), w.end());
	return w;
}

ll wyn;

ll x;

vector < pair <ll,int> > wek;
int ile[nax];

void check()
{
	ll n=1;
	ll phi=1;
	for (int i=0; i<(int)wek.size(); i++)
	{
		for (int j=1; j<=ile[i]; j++)
		{
			n*=wek[i].first;
			phi*=(wek[i].first-(j==1));
		}
	}
	//~ debug() << n << " " << phi;
	auto daj=rozklad(phi);
	ll ter=1;
	for (ll i : daj)
	{
		if (my_pow(x, phi/i, n)==(1%n))
		{
			ter*=i;
			phi/=i;
		}
	}
	wyn+=ter;
}

void rek(int v)
{
	if (v==wek.size())
	{
		check();
		return;
	}
	for (int i=0; i<=wek[v].second; i++)
	{
		ile[v]=i;
		rek(v+1);
	}
}

int main()
{
	ll m;
	scanf("%lld%lld", &m, &x);
	auto wez=rozklad(m);
	for (ll i : wez)
	{
		if (wek.empty() || wek.back().first!=i)
			wek.push_back({i, 0});
		wek.back().second++;
	}
	rek(0);
	
	printf("%lld\n", wyn);
	return 0;
}