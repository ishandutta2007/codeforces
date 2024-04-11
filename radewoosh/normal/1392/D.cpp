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

int n;

char wcz[nax];
int tab[nax];//0 to na minus, 1 to na plus

int ter[nax];

int hasz(int v)
{
	return ter[1]*1+ter[2]*2+ter[v-1]*4+ter[v]*8;
}

int juz[nax][16];
int dp[nax][16];

int zle(int a, int b, int c)
{
	return (ter[a]==ter[b] && ter[b]==ter[c]);
}

int rek(int v)
{
	if (v==n)
	{
		if (zle(n-1, n, 1) || zle(n, 1, 2))
			return nax;
		return 0;
	}
	int h=hasz(v);
	if (juz[v][h])
		return dp[v][h];
	int ret=nax;
	for (int i=0; i<2; i++)
	{
		ter[v+1]=i;
		int dod=(ter[v+1]!=tab[v+1]);
		if (!zle(v-1, v, v+1))
			ret=min(ret, rek(v+1)+dod);
	}
	juz[v][h]=1;
	//~ debug() << v << " " << range(ter+1, ter+1+v) << imie(ret);
	return dp[v][h]=ret;
}

void test()
{
	scanf("%d", &n);
	scanf("%s", wcz+1);
	for (int i=1; i<=n; i++)
		tab[i]=(wcz[i]=='R');
	int wyn=nax;
	for (int i=1; i<=n; i++)
		for (int j=0; j<16; j++)
			juz[i][j]=0;
	for (int i=0; i<2; i++)
	{
		for (int j=0; j<2; j++)
		{
			ter[1]=i;
			ter[2]=j;
			wyn=min(wyn, rek(2)+(ter[1]!=tab[1])+(ter[2]!=tab[2]));
		}
	}
	printf("%d\n", wyn);
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}