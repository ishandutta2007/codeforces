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
const int nax=200*1007;
const ll inf=1e18;

int n;

vi graf[nax];
ll tab[nax];

ll dpwsz[nax];
ll dpbez[nax];

int lis[nax];

vi opt;

void minuj(ll &a, ll b)
{
	a=min(a, b);
}

void maxuj(ll &a, ll b)
{
	a=max(a, b);
}

void dfs1(int v, int oj)
{
	for (int &i : graf[v])
	{
		if (i==oj)
		{
			swap(i, graf[v].back());
			graf[v].pop_back();
			break;
		}
	}
	lis[v]=(graf[v].empty());
	if (lis[v])
	{
		dpwsz[v]=tab[v];
		dpbez[v]=0;
		return;
	}
	dpwsz[v]=0;
	dpbez[v]=0;
	vector <pll> wek;
	for (int i : graf[v])
	{
		dfs1(i, v);
		wek.push_back({dpwsz[i], dpbez[i]});
	}
	ll sum=0;
	for (pll i : wek)
		sum+=i.first;
	dpwsz[v]=sum;
	dpbez[v]=inf;
	for (pll i : wek)
		minuj(dpbez[v], sum-i.first+i.second);
	minuj(dpwsz[v], dpbez[v]+tab[v]);
}

void dfs2(int v, ll kwsz, ll kbez)
{
	//~ debug() << v << " " << kwsz << " " << kbez;
	vector <pll> wek;
	for (int i : graf[v])
		wek.push_back({dpwsz[i], dpbez[i]});
	ll sum=0;
	for (pll i : wek)
		sum+=i.first;
	if (kwsz==dpbez[v]+tab[v])
		opt.push_back(v);
	//~ if (dpwsz[v]==sum)
	//~ {
		//~ for (int i : graf[v])
			//~ dfs2(i, dpwsz[i]);
		//~ return;
	//~ }
	
	vector <pair<ll,int> > wek2;
	for (int i : graf[v])
		wek2.push_back({-dpwsz[i]+dpbez[i], i});
	sort(wek2.begin(), wek2.end());
	for (int i : graf[v])
	{
		ll x=-inf;
		ll y=-inf;
		maxuj(y, kbez-(sum-dpwsz[i]));
		maxuj(y, kwsz-(sum-dpwsz[i])-tab[v]);
		maxuj(x, kwsz-(sum-dpwsz[i]));
		int num=0;
		for (auto j : wek2)
		{
			if (j.second==i)
				continue;
			maxuj(x, kbez-(sum-dpwsz[i])-j.first);
			maxuj(x, kwsz-(sum-dpwsz[i])-j.first-tab[v]);
			//~ maxuj(y, kbez-(sum-dpwsz[i])-j.first);
			
			num++;
			if (num>3)
				break;
		}
		
		dfs2(i, x, y);
	}
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		scanf("%lld", &tab[i]);
	for (int i=1; i<n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	dfs1(1, 0);
	dfs2(1, dpwsz[1], -inf);
	
	
	printf("%lld %d\n", dpwsz[1], (int)opt.size());
	sort(opt.begin(), opt.end());
	for (int i : opt)
		printf("%d ", i);
	printf("\n");
	return 0;
}