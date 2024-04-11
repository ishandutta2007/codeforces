//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
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
const int nax=1000*1007;

int n, k;

vector <int> graf[nax];
int oj[nax];

int sto[nax];
int roz[nax];

int juz[nax];

set <int> zle[nax];

void nope()
{
	printf("NO\n");
	exit(0);
}

void dfs(int v)
{
	roz[v]=1;
	for (int i : graf[v])
	{
		dfs(i);
		if (!(roz[i]&1))
			zle[v].insert(i);
		roz[v]+=roz[i];
	}
	if (!((n-roz[v])&1) && v!=k)
		zle[v].insert(oj[v]);
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		scanf("%d", &oj[i]);
		graf[oj[i]].push_back(i);
		if (oj[i])
		{
			sto[i]++;
			sto[oj[i]]++;
		}
	}
	k=graf[0][0];
	if (!(n&1))
		nope();
	dfs(k);
	vector <int> check;
	for (int i=1; i<=n; i++)
		if (i!=k)
			graf[i].push_back(oj[i]);
	vector <int> kol;
	for (int i=1; i<=n; i++)
		if (zle[i].empty())
			check.push_back(i);
	while(!check.empty())
	{
		int v=check.back();
		check.pop_back();
		if ((sto[v]&1) || juz[v])
			continue;
		juz[v]=1;
		kol.push_back(v);
		for (int i : graf[v])
		{
			if (!juz[i])
			{
				sto[i]--;
				zle[i].erase(v);
				if (zle[i].empty())
					check.push_back(i);
			}
		}
	}
	for (int i=1; i<=n; i++)
		if (!juz[i])
			nope();
	printf("YES\n");
	for (int i : kol)
		printf("%d\n", i);
	return 0;
}