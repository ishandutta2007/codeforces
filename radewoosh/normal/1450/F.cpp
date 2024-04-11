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

int ile[nax];

int cut[nax];

void ans(int v)
{
	printf("%d\n", v);
}

void test()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		scanf("%d", &tab[i]);
	for (int i=1; i<=n; i++)
		ile[i]=0;
	for (int i=1; i<=n; i++)
		ile[tab[i]]++;
	for (int i=1; i<=n; i++)
	{
		if (ile[i]*2-1>n)
		{
			ans(-1);
			return;
		}
	}
	for (int i=1; i<=n+1; i++)
		cut[i]=0;
	cut[1]=cut[n+1]=1;
	for (int i=1; i<n; i++)
	{
		if (tab[i]==tab[i+1])
			cut[i+1]++;
	}
	int k=0;
	for (int i=2; i<=n; i++)
		if (cut[i])
			k++;
	for (int i=1; i<=n; i++)
		ile[i]=0;
	for (int i=1; i<=n; i++)
	{
		if (cut[i])
			ile[tab[i]]++;
		if (cut[i+1])
			ile[tab[i]]++;
	}
	int x=0;
	for (int i=1; i<=n; i++)
		if (ile[i]>ile[x])
			x=i;
	//~ debug() << range(cut+1, cut+2+n);
	//~ debug() << range(ile+1, ile+1+n);
	vi wek;
	for (int i=2; i<=n; i++)
	{
		if (cut[i])
			continue;
		int y=0;
		y+=(tab[i]!=x);
		y+=(tab[i-1]!=x);
		wek.push_back(y);
	}
	sort(wek.begin(), wek.end());
	//~ debug() << imie(wek) << imie(x) << imie(ile[x]) << imie(k);
	int wyn=0;
	while(ile[x]>k+2)
	{
		k++;
		ile[x]+=2-wek.back();
		wek.pop_back();
		wyn++;
	}
	printf("%d\n", k);
	
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}