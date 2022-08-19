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
const ll inf=1e18;
const ll mod=998244353;

int n, q;

vi graf[nax];
int pre[nax];
int post[nax];
int czas;

int roz[nax];

vector <pair<int,pii> > waz[nax];

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

ll drz[nax];

void dod(int a, int b, ll w)
{
	w%=mod;
	for (int i=a; i<=n; i+=(i&(-i)))
		drz[i]+=w;
	for (int i=b+1; i<=n; i+=(i&(-i)))
		drz[i]-=w;
}

ll czyt(int v)
{
	ll ret=0;
	for (int i=v; i; i-=(i&(-i)))
		ret+=drz[i];
	ret%=mod;
	if (ret<0)
		ret+=mod;
	return ret;
}

void dfs1(int v, int oj)
{
	roz[v]=1;
	for (int i : graf[v])
	{
		if (i==oj)
			continue;
		dfs1(i, v);
		roz[v]+=roz[i];
	}
}

bool mniej(int a, int b)
{
	return roz[a]<roz[b];
}

void dfs2(int v, int oj)
{
	sort(graf[v].begin(), graf[v].end(), mniej);
	if (!graf[v].empty() && graf[v].back()==oj)
		graf[v].pop_back();
	czas++;
	pre[v]=czas;
	for (int i : graf[v])
		dfs2(i, v);
	post[v]=czas;
	
	if (v!=1)
	{
		waz[v].push_back({n-roz[v], {1, pre[v]-1}});
		waz[v].push_back({n-roz[v], {post[v]+1, n}});
	}
	int g;
	for (int i=0; i<(int)graf[v].size(); i=g)
	{
		g=i;
		while(g<(int)graf[v].size() && roz[graf[v][i]]==roz[graf[v][g]])
			g++;
		waz[v].push_back({roz[graf[v][i]], {pre[graf[v][i]], post[graf[v][g-1]]}});
	}
}

int main()
{
	scanf("%d%d", &n, &q);
	for (int i=1; i<n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	dfs1(1, 0);
	dfs2(1, 0);
	//~ for (int i=1; i<=n; i++)
		//~ debug() << pre[i] << " " << waz[i];
	ll dzn=dziel(1, n);
	while(q--)
	{
		int typ;
		scanf("%d", &typ);
		if (typ==1)
		{
			int v;
			ll d;
			scanf("%d%lld", &v, &d);
			dod(1, n, n*d);
			for (const auto i : waz[v])
				dod(i.second.first, i.second.second, -i.first*d);
		}
		else
		{
			int v;
			scanf("%d", &v);
			ll x=czyt(pre[v]);
			x%=mod;
			x+=mod;
			x%=mod;
			printf("%lld\n", (x*dzn)%mod);
		}
	}
	return 0;
}