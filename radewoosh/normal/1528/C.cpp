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
const int nax=1000*1007;

int n;

vi graf[nax];
vi graf2[nax];

int wyn;

int czas;
int pre[nax];
int post[nax];

void dfs1(int v)
{
	czas++;
	pre[v]=czas;
	for (int i : graf2[v])
		dfs1(i);
	post[v]=czas;
}

int ter;

int fen[nax];

int czyt(int a, int b)
{
	int ret=0;
	for (int i=b; i; i-=(i&(-i)))
		ret+=fen[i];
	for (int i=a-1; i; i-=(i&(-i)))
		ret-=fen[i];
	return ret;
}

void pisz(int v, int w)
{
	for (int i=v; i<=n; i+=(i&(-i)))
		fen[i]+=w;
}

int przo(int kto, int kogo)
{
	return (pre[kto]<=pre[kogo] && post[kto]>=post[kogo]);
}

set<pii> setel;

int czy_jest(int v)
{
	return !czyt(pre[v]+1, post[v]);
}

void dfs2(int v)
{
	//~ debug() << v;
	setel.insert({pre[v], v});
	auto it=setel.find({pre[v], v});
	if (it!=setel.begin())
	{
		it--;
		if (przo(it->second, v) && czy_jest(it->second))
		{
			//~ debug() << v << " 2";
			ter--;
		}
	}
	pisz(pre[v], 1);
	if (czy_jest(v))
	{
		//~ debug() << v << " 1";
		ter++;
	}
	
	wyn=max(wyn, ter);
	for (int i : graf[v])
	{
		dfs2(i);
	}
	if (czy_jest(v))
		ter--;
	pisz(pre[v], -1);
	
	it=setel.find({pre[v], v});
	if (it!=setel.begin())
	{
		it--;
		if (przo(it->second, v) && czy_jest(it->second))
		{
			ter++;
		}
	}
	setel.erase({pre[v], v});
}

void test()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		graf[i].clear();
		graf2[i].clear();
	}
	wyn=0;
	for (int i=2; i<=n; i++)
	{
		int x;
		scanf("%d", &x);
		graf[x].push_back(i);
	}
	for (int i=2; i<=n; i++)
	{
		int x;
		scanf("%d", &x);
		graf2[x].push_back(i);
	}
	czas=0;
	dfs1(1);
	dfs2(1);
	
	printf("%d\n", wyn);
	//~ debug();
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}