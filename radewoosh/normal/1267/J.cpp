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
const int nax=2000*1007;

int n;

int tab[nax];

int wyn;

int ok[nax];
int wyj[nax];

void test()
{
	scanf("%d", &n);
	for (int i=1; i<=n+1; i++)
		tab[i]=ok[i]=wyj[i]=0;
	for (int i=1; i<=n; i++)
	{
		int x;
		scanf("%d", &x);
		tab[x]++;
	}
	wyn=n;
	int x=0;
	for (int i=1; i<=n; i++)
	{
		if (!tab[i])
			continue;
		x++;
		ok[1]++;
		wyj[1]+=tab[i];
		for (int j=2; j<=tab[i]+1; j++)
		{
			for (int l=max(tab[i]/j, 1); l*(j-1)<=tab[i]; l++)
			{
				int mini=l*(j-1);
				int maxi=l*j;
				if (mini<=tab[i] && tab[i]<=maxi)
				{
					ok[j]++;
					wyj[j]+=l;
					break;
				}
			}
		}
	}
	
	for (int i=1; i<=n+1; i++)
		if (ok[i]==x)
			wyn=min(wyn, wyj[i]);
	
	printf("%d\n", wyn);
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}