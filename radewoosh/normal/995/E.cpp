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
const int nax=1007;
using pii=pair<int,int>;
ll mod;

ll dod(ll a)
{
	return (a+1)%mod;
}

ll odj(ll a)
{
	return (a-1+mod)%mod;
}

ll odw(ll a)
{
	ll wyk=mod-2;
	ll ret=1;
	while(wyk)
	{
		if (wyk&1)
			ret=(ret*a)%mod;
		a=(a*a)%mod;
		wyk>>=1;
	}
	return ret;
}

ll f(ll v, int jaka)
{
	if (jaka==1)
		return dod(v);
	if (jaka==2)
		return odj(v);
	if (jaka==3)
		return odw(v);
}

ll sta, kon;

unordered_map <ll,ll > mapa[2];

vector <ll> wek[2][nax];

void solve(ll v)
{
	debug() << imie(v);
	vector <ll> odp{v};
	ll pam=v;
	while(mapa[0][v]!=-1)
	{
		v=mapa[0][v];
		odp.push_back(v);
	}
	reverse(odp.begin(), odp.end());
	v=pam;
	while(mapa[1][v]!=-1)
	{
		v=mapa[1][v];
		odp.push_back(v);
	}
	debug() << odp;
	printf("%d\n", (int)odp.size()-1);
	for (int i=1; i<(int)odp.size(); i++)
	{
		for (int j=1; 1; j++)
		{
			if (f(odp[i-1], j)==odp[i])
			{
				printf("%d ", j);
				break;
			}
			assert(j<4);
		}
	}
	printf("\n");
	
	exit(0);
}

void rozwaz(int v, int u, ll co, ll wzio)
{
	if (!mapa[v].count(co))
	{
		mapa[v][co]=wzio;
		wek[v][u].push_back(co);
	}
	if (mapa[0].count(co) && mapa[1].count(co))
		solve(co);
}

int main()
{
	scanf("%lld%lld%lld", &sta, &kon, &mod);
	rozwaz(0, 0, sta, -1);
	rozwaz(1, 0, kon, -1);
	for (int h=0; 1; h++)
	{
		for (int i=0; i<2; i++)
		{
			shandom_ruffle(wek[i][h].begin(), wek[i][h].end());
			for (ll j : wek[i][h])
			{
				for (int l=1; l<=3; l++)
				{
					rozwaz(i, h+1, f(j, l), j);
				}
			}
		}
	}
	
	return 0;
}