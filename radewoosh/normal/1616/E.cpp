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
const int alfa=26;
const ll inf=1e18;

int n;

char s[nax];
char t[nax];

ll wyn;

vi gdz[alfa];

int fen[nax];

void pisz(int v, int w)
{
	for (int i=v; i<=n; i+=(i&(-i)))
		fen[i]+=w;
}

int czyt(int v)
{
	int ret=0;
	for (int i=v; i; i-=(i&(-i)))
		ret+=fen[i];
	return ret;
}

void test()
{
	scanf("%d", &n);
	scanf("%s", s+1);
	scanf("%s", t+1);
	wyn=inf;
	for (int i=0; i<alfa; i++)
		gdz[i].clear();
	for (int i=1; i<=n; i++)
		fen[i]=0;
	for (int i=n; i; i--)
	{
		gdz[s[i]-'a'].push_back(i);
		pisz(i, 1);
	}
	ll tmp=0;
	for (int i=1; i<=n; i++)
	{
		int pier=n+1;
		int g=t[i]-'a';
		for (int j=0; j<g; j++)
			if (!gdz[j].empty())
				pier=min(pier, gdz[j].back());
		if (pier<=n)
			wyn=min(wyn, tmp+czyt(pier-1));
		if (gdz[g].empty())
			break;
		int x=gdz[g].back();
		gdz[g].pop_back();
		tmp+=czyt(x-1);
		pisz(x, -1);
		//~ debug() << i << " " << g << " " << pier << " " << tmp << " " << x;
	}
	
	if (wyn==inf)
		wyn=-1;
	printf("%lld\n", wyn);
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}