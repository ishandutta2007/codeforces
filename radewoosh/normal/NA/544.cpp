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
const int nax=100*1007;

int n, m, k, s;

vector <int> graf[nax];

vector <int> rodz[nax];
int ost[nax];

vector <int> wyn[nax];

int main()
{
	scanf("%d%d%d%d", &n, &m, &k, &s);
	for (int i=1; i<=n; i++)
	{
		int a;
		scanf("%d", &a);
		rodz[a].push_back(i);
	}
	for (int i=1; i<=m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	for (int h=1; h<=k; h++)
	{
		queue <int> start;
		for (int i=1; i<=n; i++)
			ost[i]=-1;
		for (int i : rodz[h])
		{
			ost[i]=0;
			start.push(i);
		}
		while(!start.empty())
		{
			int v=start.front();
			start.pop();
			for (int i : graf[v])
			{
				if (ost[i]==-1)
				{
					ost[i]=ost[v]+1;
					start.push(i);
				}
			}
		}
		for (int i=1; i<=n; i++)
			wyn[i].push_back(ost[i]);
	}
	for (int i=1; i<=n; i++)
	{
		sort(wyn[i].begin(), wyn[i].end());
		int x=0;
		for (int j=0; j<s; j++)
			x+=wyn[i][j];
		printf("%d ", x);
	}
	printf("\n");
	return 0;
}