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
const int nax=20*1007;

int n;

int tab[nax];
int ile[nax];

int s;
int dp[207][nax];

int wyn;

void dod(int &a, int b)
{
	a=min(a+b, 2);
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		scanf("%d", &tab[i]);
		s+=tab[i];
		ile[tab[i]]++;
	}
	sort(tab+1, tab+1+n);
	dp[0][0]=1;
	vi war;
	for (int i=1; i<=100; i++)
	{
		if (!ile[i])
			continue;
		war.push_back(i);
		for (int j=n; j>=0; j--)
		{
			for (int l=0; l<=s; l++)
			{
				for (int w=1; w<=ile[i]; w++)
				{
					dod(dp[j+w][l+w*i], dp[j][l]);
				}
			}
		}
	}
	for (int i : war)
	{
		for (int j=1; j<=ile[i]; j++)
		{
			if (dp[j][j*i]==1)
			{
				wyn=max(wyn, j);
			}
		}
	}
	
	if ((int)war.size()==2)
		wyn=n;
	
	printf("%d\n", wyn);
	return 0;
}