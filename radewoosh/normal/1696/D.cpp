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
const int inf=1e9;
//~ const int n1=(1<<18);

int n;

int tab[nax];

int mni[nax];
int wie[nax];

int pramni[nax];
int prawie[nax];

int dp[nax];

int n1;
int drz[2][nax];

vi umni[nax];
vi uwie[nax];

void pisz(int g, int v, int x)
{
	v+=n1-1;
	drz[g][v]=x;
	v>>=1;
	while(v)
	{
		drz[g][v]=min(drz[g][2*v], drz[g][2*v+1]);
		v>>=1;
	}
}

int czyt(int g, int v, int a, int b, int graa, int grab)
{
	if (a>=graa && b<=grab)
	{
		return drz[g][v];
	}
	if (a>grab || b<graa)
	{
		return inf;
	}
	return min(
		czyt(g, (v<<1), a, (a+b)>>1, graa, grab),
		czyt(g, (v<<1)^1, (a+b+2)>>1, b, graa, grab)
	);
}

void test()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		umni[i].clear();
		uwie[i].clear();
		scanf("%d", &tab[i]);
	}
	for (int i=2; i<=n; i++)
	{
		mni[i]=i-1;
		while(mni[i] && tab[mni[i]]>tab[i])
			mni[i]=mni[mni[i]];
		
		wie[i]=i-1;
		while(wie[i] && tab[wie[i]]<tab[i])
			wie[i]=wie[wie[i]];
	}
	for (int i=n; i; i--)
	{
		pramni[i]=i+1;
		while(pramni[i]<=n && tab[pramni[i]]>tab[i])
			pramni[i]=pramni[pramni[i]];
		
		prawie[i]=i+1;
		while(prawie[i]<=n && tab[prawie[i]]<tab[i])
			prawie[i]=prawie[prawie[i]];
	}
	n1=2;
	while(n1<=n)
		n1<<=1;
	for (int i=1; i<2*n1; i++)
		drz[0][i]=drz[1][i]=inf;
	for (int i=1; i<=n; i++)
	{
		for (int j : umni[i])
			pisz(0, j, inf);
		for (int j : uwie[i])
			pisz(1, j, inf);
		if (i==1)
		{
			dp[i]=0;
		}
		else
		{
			dp[i]=min(
				czyt(0, 1, 1, n1, wie[i]+1, i),
				czyt(1, 1, 1, n1, mni[i]+1, i)
			)+1;
		}
		pisz(0, i, dp[i]);
		pisz(1, i, dp[i]);
		umni[pramni[i]].push_back(i);
		uwie[prawie[i]].push_back(i);
		
	}
	printf("%d\n", dp[n]);
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}