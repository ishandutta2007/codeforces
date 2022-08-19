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
const int nax=100*1007;
const int d=58;
//~ const int d=3;
const ll inf=1e15;

int n;
ll tab[nax];

vector <pair<ll,int>> wek[d];

int juz[d][nax];
ll dp[d][nax];

ll rek(int v, ll w)
{
	if (v==d)
	{
		if (w>=tab[n])
			return 0;
		return inf;
	}
	int g=lower_bound(wek[v].begin(), wek[v].end(), make_pair(w, n+3))-wek[v].begin();
	//~ debug() << v << " " << g << " " << w;
	if (juz[v][g])
		return dp[v][g];
		
	juz[v][g]=1;
	ll ret=inf;
	
	ll djest=g;
	ll d1=0;
	ll d0=0;
	if (g)
	{
		d1=wek[v][g-1].second;
		d0=djest-d1;
	}
	
	ll gjest=n-g;
	ll g1=0;
	ll g0=0;
	if (g)
	{
		g1=wek[v].back().second-wek[v][g-1].second;
		g0=gjest-g1;
	}
	else
	{
		g1=wek[v].back().second;
		g0=gjest-g1;
	}
	ll p0=rek(v+1, w)+g0+d1;
	ll p1=rek(v+1, w+(1LL<<v))+d0+g1;
	ret=min(p0, p1);
	
	//~ debug() << v << " " << g << " " << w << "  " << ret << "     " << imie(d0) << imie(d1) << imie(g0) << imie(g1) << "   " << p0 << " " << p1;
	return dp[v][g]=ret;
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		scanf("%lld", &tab[i]);
	
	//~ n=1e5;
	//~ for (int i=1; i<=n; i++)
		//~ tab[i]=rand()%1000000000+1;
	
	sort(tab+1, tab+1+n);
	for (int i=0; i<d; i++)
	{
		for (int j=1; j<=n; j++)
		{
			ll x=tab[j]%(1LL<<i);
			ll y=(tab[j]%(1LL<<(i+1)))>>i;
			wek[i].push_back({x, y});
		}
		sort(wek[i].begin(), wek[i].end());
		for (int j=1; j<n; j++)
			wek[i][j].second+=wek[i][j-1].second;
	}
	printf("%lld\n", rek(0, 0));
	return 0;
}