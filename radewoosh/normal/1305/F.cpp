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
#include <sys/time.h>

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

double rem_time;
 
void init_time()
{
    timeval tv;
    gettimeofday(&tv, 0);
    rem_time=tv.tv_sec+tv.tv_usec*1e-6;
}
 
inline double get_time()
{
    timeval tv;
    gettimeofday(&tv, 0);
    return tv.tv_sec+tv.tv_usec*1e-6 - rem_time;
}

int n;
ll tab[nax];

ll wyn;

void ans(ll v)
{
	printf("%lld\n", v);
	exit(0);
}

unordered_set <ll> bylo;

void check_sup(ll v)
{
	if (bylo.count(v))
		return;
	ll licz=0;
	bylo.insert(v);
	for (int i=1; i<=n && licz<wyn; i++)
	{
		ll d=tab[i]-tab[i]%v;
		if (!d)
			d+=v;
		licz+=min(abs(tab[i]-d), abs(tab[i]-(d+v)));
	}
	wyn=min(wyn, licz);
}

void check(ll v)
{
	v=abs(v);
	if (v<=1)
		return;
	vll wek;
	for (ll i=2; i*i<=v; i++)
	{
		if (!(v%i))
		{
			wek.push_back(i);
			v/=i;
			i--;
		}
	}
	wek.push_back(v);
	for (ll i : wek)
		check_sup(i);
}

int main()
{
	init_time();
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	scanf("%d", &n);
	ll g=0;
	for (int i=1; i<=n; i++)
	{
		scanf("%lld", &tab[i]);
		g=__gcd(g, tab[i]);
	}
	if (g>1)
		ans(0);
	wyn=n;
	while(get_time()<2)
	{
		shuffle(tab+1, tab+1+n, rng);
		//~ check(tab[rng()%n+1]);
		check(tab[rng()%n+1]-tab[rng()%n+1]);
		int x=rng()%n+1;
		for (int j=-3; j<=3; j++)
			check(tab[x]+j);
	}
	ans(wyn);
	return 0;
}