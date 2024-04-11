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
int tab[nax];

char wcz[nax];

int kt[nax];
int dp[nax];

void ans(int v)
{
	printf("%d\n", v);
}

int fen[10*nax];

void reset()
{
	for (int i=1; i<=20*(n+17); i++)
		fen[i]=nax;
}

void pisz(int v, int w)
{
	v+=(n+17)*10;
	for (int i=v; i<=20*(n+17); i+=(i&(-i)))
		fen[i]=min(fen[i], w);
}

int czyt(int v)
{
	int ret=nax;
	v+=(n+17)*10;
	for (int i=v; i; i-=(i&(-i)))
		ret=min(fen[i], ret);
	return ret;
}

void test()
{
	scanf("%d", &n);
	scanf("%s", wcz+1);
	for (int i=1; i<=n; i++)
		tab[i]=wcz[i]-'0';
	vi ile{0, 1};
	for (int i=1; i<=n; i++)
		ile[tab[i]]++;
	if (ile[1]>ile[0])
	{
		reverse(tab+1, tab+1+n);
		for (int i=1; i<=n; i++)
			tab[i]^=1;
	}
	//~ debug() << range(tab+1, tab+1+n);
	{
		int zero=1;
		for (int i=2; i<=n; i++)
			if (tab[i]<tab[i-1])
				zero=0;
		if (zero)
		{
			ans(0);
			return;
		}
	}
	for (int i=1; i<=n; i++)
	{
		kt[i]=kt[i-1]+tab[i];
		dp[i]=nax;
	}
	int p=1;
	while(!tab[p])
		p++;
	dp[p]=0;
	reset();
	for (int i=p+1; i<=n; i++)
	{
		pisz((i-1)-kt[i-1], dp[i-1]-((i-1)-kt[i-1]));
		dp[i]=czyt(i-2*kt[i])+i-2*kt[i]+1;
	}
	//~ for (int i=p+1; i<=n; i++)
	//~ {
		//~ for (int j=p; j<i; j++)
		//~ {
			//~ if (i-2*kt[i]>=(j-kt[j]))
				//~ dp[i]=min(dp[i], dp[j]+abs(i-j-2*kt[i]+kt[j])+1);
		//~ }
	//~ }
	//~ debug() << range(kt+1, kt+1+n);
	//~ debug() << range(dp+1, dp+1+n);
	int wyn=dp[n];
	for (int i=p; i<=n; i++)
	{
		//~ if (kt[i]!=kt[n])
			//~ continue;
		//~ debug() << i << " " << 
		wyn=min(wyn, dp[i]+max(n-i-2*kt[n]+kt[i], 0)+1);
	}
	printf("%d\n", wyn);
	//~ exit(0);
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}