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

ll k;
ll tab[nax];

void ans(int v)
{
	if (v)
		printf("yes\n");
	else
		printf("no\n");
}

void test()
{
	scanf("%d%lld", &n, &k);
	for (int i=1; i<=n; i++)
	{
		scanf("%lld", &tab[i]);
		if (tab[i]<k)
		{
			tab[i]=-1;
			continue;
		}
		if (tab[i]==k)
		{
			tab[i]=0;
			continue;
		}
		if (tab[i]>k)
		{
			tab[i]=1;
			continue;
		}
		assert(0);
	}
	if (n==1)
	{
		ans(!tab[1]);
		return;
	}
	for (int i=1; i<n; i++)
		if (!tab[i] && tab[i+1]==1)
			tab[i+1]=0;
	for (int i=n-1; i; i--)
		if (!tab[i+1] && tab[i]==1)
			tab[i]=0;
	int czy=0;
	for (int i=1; i<=n; i++)
		if (!tab[i])
			czy=1;
	if (!czy)
	{
		ans(0);
		return;
	}
	vi wek;
	for (int i=1; i<=n; i++)
		if (tab[i]>=0)
			wek.push_back(i);
	for (int i=1; i<(int)wek.size(); i++)
	{
		int a=wek[i-1];
		int b=wek[i];
		vi sor;
		for (int j=a; j<=b; j++)
			sor.push_back(tab[j]);
		sort(sor.begin(), sor.end());
		int r=b-a+1;
		int ile=(r+1)/2;
		int w=sor[ile-1];
		if (w>=0)
		{
			ans(1);
			return;
		}
	}
	
	ans(0);
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}