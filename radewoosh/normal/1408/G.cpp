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
const int nax=1507;
const ll mod=998244353;

int n;

int tab[nax][nax];

void dod(ll &a, ll b)
{
	a=(a+b)%mod;
}

vll multi(const vll &a, const vll &b)
{
	int ra=a.size();
	int rb=b.size();
	vll ret(ra+rb-1);
	for (int i=0; i<ra; i++)
		for (int j=0; j<rb; j++)
			dod(ret[i+j], a[i]*b[j]);
	return ret;
}

int krul[nax];
int najw[nax];

vi spo[nax];

vll dp[nax];

void merguj(int a, int b)
{
	for (int i : spo[a])
		for (int j : spo[b])
			najw[a]=max(najw[a], tab[i][j]);
	najw[a]=max(najw[a], najw[b]);
	for (int j : spo[b])
	{
		krul[j]=a;
		spo[a].push_back(j);
	}
	dp[a]=multi(dp[a], dp[b]);
	dp[b].clear();
	spo[b].clear();
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			scanf("%d", &tab[i][j]);
	for (int i=1; i<=n; i++)
	{
		krul[i]=i;
		spo[i]={i};
		dp[i]={0, 1};
	}
	vector<pair<int,pii>> kra;
	for (int i=1; i<=n; i++)
		for (int j=1; j<i; j++)
			kra.push_back({tab[i][j], {i, j}});
	sort(kra.begin(), kra.end());
	for (auto h : kra)
	{
		int ko=h.first;
		int a=h.second.first;
		int b=h.second.second;
		a=krul[a];
		b=krul[b];
		if (a!=b)
			merguj(a, b);
		
		
		
		if (najw[a]==ko)
			dod(dp[a][1], 1);
	}
	vll wez=dp[krul[1]];
	for (int i=1; i<=n; i++)
		printf("%lld ", wez[i]);
	printf("\n");
	return 0;
}