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

void ans(int v)
{
	if (v)
		printf("YES\n");
	else
		printf("NO\n");
}

int n, l, r;

int tab[nax][2];

void test()
{
	scanf("%d%d%d", &n, &l, &r);
	for (int i=1; i<=n; i++)
		for (int j=0; j<2; j++)
			tab[i][j]=0;
	for (int i=1; i<=n; i++)
	{
		int x;
		scanf("%d", &x);
		tab[x][i>l]++;
	}
	int wyn=0;
	for (int i=1; i<=n; i++)
	{
		while(tab[i][0] && tab[i][1])
		{
			tab[i][0]--;
			tab[i][1]--;
		}
	}
	int x=l-r;
	for (int i=1; i<=n; i++)
	{
		while(tab[i][0]>1 && x>0)
		{
			x-=2;
			tab[i][0]-=2;
			wyn++;
		}
		while(tab[i][1]>1 && x<0)
		{
			x+=2;
			tab[i][1]-=2;
			wyn++;
		}
	}
	l=0;
	r=0;
	for (int i=1; i<=n; i++)
	{
		l+=tab[i][0];
		r+=tab[i][1];
	}
	//~ debug() << wyn << " " << l << " " << r;
	printf("%d\n", wyn+(l+r)/2+abs(r-l)/2);
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}