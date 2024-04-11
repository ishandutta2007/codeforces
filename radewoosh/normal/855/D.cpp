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
const int nax=100*1007;

int n;

int oj[nax];
int typ[nax];

vi graf[nax][3];
int l;
int pre[nax][3];
int post[nax][3];

void tak()
{
	printf("YES\n");
}

void nie()
{
	printf("NO\n");
}

void dfs1(int v, int t)
{
	l++;
	pre[v][t]=l;
	for (int i : graf[v][t])
		dfs1(i, t);
	l++;
	post[v][t]=l;
	//~ debug() << v << " " << t << " " << pre[v][t] << " " << post[v][t];
}

int przo(int dol, int gora, int t)
{
	return pre[gora][t]<=pre[dol][t] && post[gora][t]>=post[dol][t];
}

int fast[nax][2];

void query()
{
	int t, a, b;
	scanf("%d%d%d", &t, &a, &b);
	if (przo(a, b, 0) || przo(a, b, 1))
	{
		nie();
		return;
	}
	if (t==1)
	{
		//~ debug() << imie(a) << imie(b);
		if (przo(b, a, 0))
			tak();
		else
			nie();
		return;
	}
	if (przo(b, a, 1))
	{
		tak();
		return;
	}
	if (przo(a, fast[b][1], 0) || przo(b, fast[a][0], 1))
		tak();
	else
		nie();
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		scanf("%d%d", &oj[i], &typ[i]);
		if (typ[i]!=-1)
			graf[oj[i]][typ[i]].push_back(i);
		for (int h=0; h<2; h++)
		{
			fast[i][h]=i;
			if (typ[i]==h)
				fast[i][h]=fast[oj[i]][h];
		}
	}
	for (int h=0; h<2; h++)
	{
		l=0;
		for (int i=1; i<=n; i++)
			if (!pre[i][h])
				dfs1(i, h);
	}
	int m;
	scanf("%d", &m);
	while(m--)
		query();
	return 0;
}