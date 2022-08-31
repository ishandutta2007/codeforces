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
const ll mod=1000*1000*1000+7;

int n, m;

vi wek[nax];

int oj[nax];

int pam[nax];
int juz[nax];

int fin(int v)
{
	if (v!=oj[v])
		oj[v]=fin(oj[v]);
	return oj[v];
}

void uni(int a, int b)
{
	a=fin(a);
	b=fin(b);
	if (a>b)
		swap(a, b);
	if (a==b)
		return;
	oj[a]=b;
	juz[b]|=juz[a];
}

ll roz=1;
vi wyn;

int main()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=m; i++)
		oj[i]=i;
	for (int i=1; i<=n; i++)
	{
		int a, b;
		scanf("%d", &a);
		for (int h=0; h<a; h++)
		{
			scanf("%d", &b);
			wek[i].push_back(b);
		}
	}
	//~ debug() << range(pam+1, pam+1+m);
	for (int i=1; i<=n; i++)
	{
		if ((int)wek[i].size()==1)
		{
			int a=wek[i][0];
			a=fin(a);
			if (!juz[a])
			{
				roz=(roz*2)%mod;
				juz[a]=1;
				wyn.push_back(i);
			}
		}
		else
		{
			int a=wek[i][0];
			int b=wek[i][1];
			a=fin(a);
			b=fin(b);
			if (a!=b && (!juz[a] || !juz[b]))
			{
				roz=(roz*2)%mod;
				uni(a, b);
				wyn.push_back(i);
			}
		}
	}
	printf("%lld %d", roz, (int)wyn.size());
	printf("\n");
	for (int i : wyn)
		printf("%d ", i);
	printf("\n");
	return 0;
}