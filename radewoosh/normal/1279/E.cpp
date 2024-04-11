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
const int nax=57;
const ll inf=1007LL*1007LL*1007LL*1007LL*1007LL*1007LL;


ll sil[nax];
ll dp[nax];

ll mno(ll a, ll b)
{
	if (!a || !b)
		return 0;
	if (!((inf/a)/b))
		return inf;
	return a*b;
}

int ter[nax];
int wcho[nax];
int bylo[nax];

ll policz(int n)
{
	for (int i=1; i<=n; i++)
		wcho[i]=bylo[i]=0;
	for (int i=1; i<=n; i++)
		wcho[ter[i]]=1;
	int ile=0;
	int sum=0;
	for (int i=1; i<=n; i++)
	{
		if (wcho[i])
			continue;
		int v=i;
		ile++;
		while(v)
		{
			sum++;
			bylo[v]=1;
			v=ter[v];
		}
	}
	if (sum!=n)
		return 0;
	return sil[ile-1];
}

vi rek(int v, int n, ll k)
{
	if (v==n)
	{
		vi ret;
		for (int i=1; i<=n; i++)
			wcho[i]=0;
		for (int i=1; i<=n; i++)
			wcho[ter[i]]=1;
		for (int i=1; i<=n; i++)
			if (!wcho[i])
				ter[n]=i;
		for (int i=1; i<=n; i++)
			ret.push_back(ter[i]);
		//~ debug() << imie(n) << imie(k) << imie(ret);
		return ret;
	}
	vi zak(n+1);
	for (int i=1; i<=n; i++)
		if (ter[i])
			zak[ter[i]]=1;
	for (int i=1; i<=n; i++)
	{
		if (zak[i])
			continue;
		ter[v]=i;
		ll x=policz(n);
		if (x>=k)
			return rek(v+1, n, k);
		k-=x;
	}
	assert(0);
}

vi dajpoj(int n, ll k)
{
	if (n==1)
		return {1};
	for (int i=1; i<=n; i++)
		ter[i]=0;
	ter[1]=n;
	return rek(2, n, k);
}

ll sufit(ll a, ll b)
{
	return (a+b-1)/b;
}

vi daj(int n, ll k)
{
	if (!n)
		return {};
	for (int i=1; i<=n; i++)
	{
		ll x=mno(dp[n-i], sil[max(i-2, 0)]);
		if (x>=k)
		{
			ll naj=sufit(k, dp[n-i]);
			ll pot=k-dp[n-i]*(naj-1);
			vi raz=dajpoj(i, naj);
			vi dwa=daj(n-i, pot);
			for (int j : dwa)
				raz.push_back(j+i);
			return raz;
		}
		k-=x;
	}
	assert(0);
}

void test()
{
	int n;
	ll k;
	scanf("%d%lld", &n, &k);
	if (dp[n]<k)
	{
		printf("-1\n");
		return;
	}
	vi wez=daj(n, k);
	for (int i : wez)
		printf("%d ", i);
	printf("\n");
}

int main()
{
	sil[0]=1;
	for (int i=1; i<nax; i++)
		sil[i]=mno(sil[i-1], i);
	dp[0]=1;
	for (int i=1; i<nax; i++)
	{
		for (int j=1; j<=i; j++)
		{
			ll x=mno(dp[i-j], sil[max(j-2, 0)]);
			dp[i]=min(dp[i]+x, inf);
		}
		//~ debug() << i << " " << dp[i];
	}
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}