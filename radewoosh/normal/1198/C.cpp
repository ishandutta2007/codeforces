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

int n, m;

vector <pii> graf[nax];
int out[nax];

void test()
{
	vi ma, in;
	scanf("%d%d", &n, &m);
	n*=3;
	for (int i=1; i<=n; i++)
	{
		out[i]=0;
		graf[i].clear();
	}
	for (int i=1; i<=m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graf[a].push_back({b, i});
		graf[b].push_back({a, i});
	}
	for (int i=1; i<=n; i++)
	{
		if (out[i])
			continue;
		pii som={-1, -1};
		for (pii j : graf[i])
			if (!out[j.first])
				som=j;
		if (som.first>0)
		{
			out[i]=out[som.first]=1;
			ma.push_back(som.second);
		}
		else
		{
			out[i]=1;
			in.push_back(i);
		}
	}
	if ((int)ma.size()>(int)in.size())
	{
		printf("Matching\n");
		for (int i=0; i<n/3; i++)
			printf("%d ", ma[i]);
		printf("\n");
	}
	else
	{
		printf("IndSet\n");
		for (int i=0; i<n/3; i++)
			printf("%d ", in[i]);
		printf("\n");
	}
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}