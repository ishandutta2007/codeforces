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

int n;

char wcz[nax];
int tab[nax];

int gle[nax];

vi gdz[nax];
vi prze[nax];

ll dp[nax];

void dod(ll &a, ll b)
{
	a=(a+b)%mod;
}

int main()
{
	scanf("%s", wcz+1);
	n=strlen(wcz+1);
	for (int i=1; i<=n; i++)
		tab[i]=wcz[i]-'0';
	int mas=0;
	for (int i=1; i<=n; i++)
		mas|=(1<<tab[i]);
	if (mas!=3)
	{
		printf("%d\n", n);
		return 0;
	}
	int sta=1;
	while(!tab[sta])
		sta++;
	for (int i=sta; i<=n; i++)
	{
		if (tab[i])
		{
			gle[i]=0;
		}
		else
		{
			gle[i]=gle[i-1]+1;
		}
	}
	int ost=n;
	while(!tab[ost])
		ost--;
	for (int i=n; i>=sta; i--)
	{
		if (!gdz[0].empty())
		{
			prze[i].push_back(gdz[0].back());
		}
		if (!gdz[gle[i]+1].empty())
		{
			prze[i].push_back(gdz[gle[i]+1].back());
		}
		gdz[gle[i]].push_back(i);
	}
	dp[sta]=1;
	ll sum=0;
	for (int i=sta; i<=n; i++)
	{
		for (int j : prze[i])
			dod(dp[j], dp[i]);
		if (gle[i]>gle[n])
			continue;
		dod(sum, dp[i]);
	}
	debug() << imie(sta);
	debug() << range(dp+1, dp+1+n);
	printf("%lld\n", sum*sta%mod);
	return 0;
}