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
const int alfa=20;

int n;

char sta[nax];
char kon[nax];

int prze[alfa][alfa];

int bylo[alfa];

void dfs(int v)
{
	if (bylo[v])
		return;
	bylo[v]=1;
	for (int i=0; i<alfa; i++)
		if (prze[v][i] || prze[i][v])
			dfs(i);
}

void test()
{
	scanf("%d", &n);
	scanf("%s", sta+1);
	scanf("%s", kon+1);
	for (int i=0; i<alfa; i++)
		for (int j=0; j<alfa; j++)
			prze[i][j]=0;
	for (int i=1; i<=n; i++)
		prze[sta[i]-'a'][kon[i]-'a']++;
	for (int i=0; i<alfa; i++)
	{
		for (int j=0; j<alfa; j++)
		{
			if (j<i && prze[i][j])
			{
				printf("-1\n");
				return;
			}
		}
	}
	for (int i=0; i<alfa; i++)
		bylo[i]=0;
	int wyn=alfa;
	for (int i=0; i<alfa; i++)
	{
		if (bylo[i])
			continue;
		//~ debug() << i;
		wyn--;
		dfs(i);
	}
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