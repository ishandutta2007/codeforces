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
const int nax=5000*1007;
const ll mod=1000*1000*1000+7;

int n;

int team[nax];
ll tab[nax];

ll seed;
ll base;

ll ans[nax];

ll rnd()
{
	ll ret=seed;
	seed=(seed*base+233)%mod;
	return ret;
}

void gener()
{
	int m;
	scanf("%d", &m);
	int ost=0;
	for (int i=1; i<=m; i++)
	{
		int ter;
		ll k;
		scanf("%d%lld%lld%lld", &ter, &k, &seed, &base);
		for (int j=ost+1; j<=ter; j++)
		{
			team[j]=rnd()%2+1;
			tab[j]=rnd()%k+1;
		}
		
		ost=ter;
	}
}

ll ma[nax];

int main()
{
	scanf("%d", &n);
	gener();
	
	if (team[1]==2)
	{
		for (int i=1; i<=n; i++)
			team[i]^=3;
	}
	//~ debug() << range(team+1, team+1+n);
	//~ debug() << range(tab+1, tab+1+n);
	
	
	
	
	ll su[]={0, 0, 0};
	for (int i=1; i<=n; i++)
		su[team[i]]+=tab[i];
	debug() << imie(su[1]) << imie(su[2]);
	int bierze;
	if (su[1]<=su[2])
	{
		bierze=2;
	}
	else
	{
		bierze=1;
		ans[1]=1;
	}
	for (int i=1; i<=n; i++)
	{
		if (team[i]!=bierze)
		{
			ans[i]=tab[i];
			ma[i]=tab[i];
		}
	}
	ll s=0;
	for (int h=0; h<3; h++)
	for (int i=1; i<=n; i++)
	{
		if (team[i]==bierze)
		{
			ll x=min(tab[i]-ans[i], s);
			ans[i]+=x;
			s-=x;
		}
		else
		{
			s+=ma[i];
			ma[i]=0;
		}
	}
	//~ debug() << range(ans+1, ans+1+n);
	//~ for (int i=1; i<=n; i++)
		//~ assert(ans[i]==(i==1));
	
	ll wyn=1;
	for (ll i=1; i<=n; i++)
	{
		ll x=(ans[i]^(i*i))+1;
		x%=mod;
		wyn=(wyn*x)%mod;
	}
	
	printf("%lld\n", wyn);
	return 0;
}