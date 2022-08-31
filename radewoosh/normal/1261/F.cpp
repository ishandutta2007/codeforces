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
const ll mod=998244353;
ll doczek;
const ll inv=(mod+1)/2;
const int d=60;

vector <pll> czyt()
{
	int n;
	vector <pll> ret;
	scanf("%d", &n);
	for (int i=0; i<n; i++)
	{
		ll a, b;
		scanf("%lld%lld", &a, &b);
		ret.push_back({b+1, 1});
		ret.push_back({a, doczek-1});
	}
	return ret;
}

//~ vector <pll> wych;

map <ll,ll> mapa;

ll ary(ll a, ll b)
{
	ll dlu=(b-a+1)%mod;
	ll sum=(a+b)%mod;
	return (dlu*sum%mod*inv)%mod;
}

void dorz(ll a, ll b, ll w)
{
	//~ debug() << a << " " << b << " " << imie(w);
	mapa[a]=(mapa[a]+w)%doczek;
	mapa[b]=(mapa[b]-w+doczek)%doczek;
}

void cons(ll a, ll b, ll w)
{
	//~ debug() << imie(a) << imie(b) << imie(w);
	ll prz=0;
	for (int i=d-1; i>=0; i--)
	{
		int za=(a>>i)&1;
		int zb=(b>>i)&1;
		ll pa=(a%(1LL<<i))%doczek;
		ll pb=(b%(1LL<<i))%doczek;
		ll pot=(1LL<<i)%doczek;
		if (za && zb)
		{
			dorz(prz+(1LL<<i), prz+(1LL<<i)*2, w*(pa+pb)%doczek);
			dorz(prz, prz+(1LL<<i), w*(pot)%doczek);
			continue;
		}
		if (!za && !zb)
		{
			continue;
		}
		if (za)
		{
			dorz(prz, prz+(1LL<<i), w*(pb)%doczek);
			prz|=(1LL<<i);
			continue;
		}
		if (zb)
		{
			dorz(prz, prz+(1LL<<i), w*(pa)%doczek);
			prz|=(1LL<<i);
			continue;
		}
	}
}

int pie(ll v)
{
	if (v<=1)
		return 0;
	for (ll i=2; i*i<=v; i++)
		if (!(v%i))
			return 0;
	return 1;
}

int main()
{
	srand(time(0));
	while(1)
	{
		doczek=0;
		for (int i=1; i<=9; i++)
			doczek=(doczek*10+(rand()%10))%mod;
		doczek+=1e9;
		if (pie(doczek))
			break;
	}
	auto raz=czyt();
	auto dwa=czyt();
	for (auto i : raz)
	{
		for (auto j : dwa)
		{
			ll x=i.first;
			ll y=j.first;
			cons(x, y, i.second*j.second%doczek);
			//~ debug() << x << " " << y;
		}
	}
	ll wyn=0;
	ll trz=0;
	ll ost=0;
	debug() << imie(doczek);
	for (auto i : mapa)
	{
		if (trz)
			wyn=(wyn+ary(ost, i.first-1))%mod;
		//~ debug() << trz << " " << ost << "-" << i.first-1 << " ";
		ost=i.first;
		trz=(trz+i.second)%doczek;
	}
	printf("%lld\n", wyn);
	return 0;
}