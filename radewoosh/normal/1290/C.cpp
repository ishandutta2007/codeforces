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

int n, k;
char wcz[nax];
int tab[nax];

//~ vi wek[nax];

vi gdz[nax];

int oj[nax];
int roz[nax];

int ile[nax][2];
int zmi[nax];

int wyn;

int fin(int v)
{
	if (v!=oj[v])
	{
		int p=fin(oj[v]);
		roz[v]^=roz[oj[v]];
		oj[v]=p;
	}
	return oj[v];
}

int lep(int v)
{
	v=fin(v);
	if (zmi[v]==-1)
		return min(ile[v][0], ile[v][1]);
	return ile[v][zmi[v]];
}

void uni(int a, int b, int z)
{
	fin(a);
	fin(b);
	if (fin(a)==fin(b))
		return;
	wyn-=lep(a)+lep(b);
	z^=roz[a]^roz[b];
	a=fin(a);
	b=fin(b);
	oj[b]=a;
	roz[b]=z;
	ile[a][0]+=ile[b][z];
	ile[a][1]+=ile[b][1-z];
	if (zmi[b]!=-1)
		zmi[a]=zmi[b]^z;
	wyn+=lep(a);
}

int main()
{
	scanf("%d%d", &n, &k);
	scanf("%s", wcz+1);
	for (int i=1; i<=n; i++)
		tab[i]=wcz[i]-'0';
	for (int i=1; i<=k; i++)
	{
		int x, y;
		scanf("%d", &x);
		while(x--)
		{
			scanf("%d", &y);
			//~ wek[i].push_back(y);
			gdz[y].push_back(i);
		}
		oj[i]=i;
		ile[i][0]=1;
		zmi[i]=-1;
	}
	for (int i=1; i<=n; i++)
	{
		vi &wek=gdz[i];
		if ((int)wek.size()==2)
		{
			int a=wek[0];
			int b=wek[1];
			uni(a, b, tab[i]^1);
		}
		if ((int)wek.size()==1)
		{
			int a=wek[0];
			wyn-=lep(a);
			int z=roz[a]^tab[i];
			a=fin(a);
			zmi[a]=z;
			wyn+=lep(a);
		}
		printf("%d\n", wyn);
	}
	return 0;
}