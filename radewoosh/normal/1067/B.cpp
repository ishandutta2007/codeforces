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

int n, k;

vi graf[nax];

void nope()
{
	printf("No\n");
	exit(0);
}

void tak()
{
	printf("Yes\n");
	exit(0);
}

int korz=-1;

vi stos;

void dfs1(int v, int oj)
{
	stos.push_back(v);
	if ((int)stos.size()==2*k+1)
		korz=stos[k];
	for (int i : graf[v])
		if (i!=oj)
			dfs1(i, v);
	stos.pop_back();
}

void dfs2(int v, int oj, int odl)
{
	if ((int)graf[v].size()==1 && odl!=k)
		nope();
	for (int i : graf[v])
		if (i!=oj)
			dfs2(i, v, odl+1);
}

int main()
{
	scanf("%d%d", &n, &k);
	for (int i=1; i<n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	if (n<=3)
		nope();
	int lis=0;
	for (int i=1; i<=n; i++)
		if ((int)graf[i].size()==1)
			lis=i;
	dfs1(lis, 0);
	if (korz==-1)
		nope();
	if ((int)graf[korz].size()<3)
		nope();
	for (int i=1; i<=n; i++)
	{
		if ((int)graf[i].size()==1 || i==korz)
			continue;
		if ((int)graf[i].size()<4)
			nope();
	}
	dfs2(korz, 0, 0);
	tak();
	return 0;
}