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

int n, m, q;

vector <int> graf[nax];
vector <int> drz[nax];

int l;
int pre[nax];
int post[nax];
int low[nax];

int sum[nax];

vi jump[nax];

void dfs1(int v, int oj)
{
	l++;
	pre[v]=low[v]=l;
	for (int i : graf[v])
	{
		if (i==oj)
			continue;
		if (pre[i])
		{
			low[v]=min(low[v], pre[i]);
		}
		else
		{
			drz[v].push_back(i);
			debug() << "z " << v << " do " << i;
			dfs1(i, v);
			low[v]=min(low[v], low[i]);
		}
	}
	post[v]=l;
}

void dfs2(int v, int oj=0)
{
	jump[v].push_back(oj);
	while(jump[v].back())
	{
		int a=jump[v].back();
		int b=min(jump[v].size(), jump[a].size())-1;
		jump[v].push_back(jump[a][b]);
	}
	
	for (int i : drz[v])
	{
		sum[i]=sum[v];
		if (low[i]>=pre[v])
		{
			sum[i]++;
			debug() << "Tak " << v << " " << i;
		}
		dfs2(i, v);
	}
}

int przo(int a, int b)
{
	return (pre[a]<=pre[b] && post[a]>=post[b]);
}

int lca(int a, int b)
{
	if (przo(a, b))
		return a;
	for (int i=20; i>=0; i--)
		if (i<(int)jump[a].size() && jump[a][i] && !przo(jump[a][i], b))
			a=jump[a][i];
	return jump[a][0];
}

int kt(int a, int b)
{
	assert(przo(a, b));
	int bsa=0;
	int bsb=(int)drz[a].size()-1;
	int bss;
	while(bsa<bsb)
	{
		bss=(bsa+bsb)>>1;
		if (post[drz[a][bss]]>=post[b])
			bsb=bss;
		else
			bsa=bss+1;
	}
	return drz[a][bsa];
}

int mag(int v, int u)
{
	return sum[v]!=sum[u];
}

int main()
{
	scanf("%d%d%d", &n, &m, &q);
	for (int i=1; i<=m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	dfs1(1, 0);
	debug() << "a";
	dfs2(1);
	debug() << "b";
	while(q--)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		int c=lca(a, b);
		//~ debug() << imie(lca(a, b));
		int w=sum[a]+sum[b]-2*sum[c];
		if (b==c)
			swap(a, b);
		if (a==c)
		{
			int g=kt(a, b);
			if (!mag(a, g))
				w++;
		}
		else
		{
			if (!mag(c, kt(c, a)) || !mag(c, kt(c, b)))
				w++;
		}
		printf("%d\n", w);
	}
	return 0;
}