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

int n;
int tab[nax];

int wyn;

void test()
{
	scanf("%d", &n);
	vi wek;
	wyn=0;
	for (int i=1; i<=n; i++)
	{
		scanf("%d", &tab[i]);
		wek.push_back(tab[i]);
	}
	sort(wek.begin(), wek.end());
	wek.resize(unique(wek.begin(), wek.end())-wek.begin());
	n=wek.size();
	for (int i=0; i<n; i++)
		tab[i+1]=wek[i];
	wyn=tab[n];
	for (int i=n; i; i--)
	{
		for (int j=i-1; j; j--)
		{
			if (tab[i]%tab[j])
			{
				wyn=max(wyn, tab[i]+tab[j]);
				break;
			}
		}
	}
	for (int i=n; i>=3 && tab[i]+tab[i-1]+tab[i-2]>wyn; i--)
	{
		for (int j=i-1; j>=2 && tab[i]+tab[j]+tab[j-1]>wyn; j--)
		{
			if (!(tab[i]%tab[j]))
				continue;
			for (int l=j-1; l>=1 && tab[i]+tab[j]+tab[l]>wyn; l--)
			{
				if (tab[i]%tab[l] && tab[j]%tab[l])
				{
					wyn=max(wyn, tab[i]+tab[j]+tab[l]);
					break;
				}
			}
		}
	}
	
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