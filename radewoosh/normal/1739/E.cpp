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
const int nax=300*1007;
const int inf=1e9;

int n;
char wcz[nax];
int tab[2][nax];

int wyn;

void maxi(int &a, int b)
{
	a=max(a, b);
}

int juz[2][nax][4][4];
int dp[2][nax][4][4];

int pyt(int x, int kt)
{
	return (x>>kt)&1;
}

int zgas(int x, int kt)
{
	return x&(x^(1<<kt));
}

vi mozliwe(int v)
{
	int m=tab[0][v]+tab[1][v]*2;
	vi ret;
	for (int i=0; i<4; i++)
		if ((m&i)==i)
			ret.push_back(i);
	return ret;
}

int rek(int h, int v, int ma, int mb)
{
	if (juz[h][v][ma][mb])
		return dp[h][v][ma][mb];
	if (v>n)
		return 0;
	int ret=0;
	if (pyt(ma, h))
		return 1+rek(h, v, zgas(ma, h), mb);
	if (pyt(ma, h^1) && pyt(mb, h))
		return -inf;
	if (pyt(ma, h^1))
		return rek(h^1, v, ma, mb);
	for (int i : mozliwe(v+2))
		ret=max(ret, rek(h, v+1, mb, i));
	juz[h][v][ma][mb]=1;
	return dp[h][v][ma][mb]=ret;
}

int main()
{
	scanf("%d", &n);
	for (int h=0; h<2; h++)
	{
		scanf("%s", wcz+1);
		for (int i=1; i<=n; i++)
			tab[h][i]=wcz[i]-'0';
	}
	int wez=0;
	for (int i : mozliwe(1))
		for (int j : mozliwe(2))
			wez=max(wez, rek(0, 1, i, j));
	printf("%d\n", wez);
	return 0;
}