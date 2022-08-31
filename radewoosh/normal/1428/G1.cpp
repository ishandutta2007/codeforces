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
const int vax=9;
const ll inf=1e18;
const int d=6;
const int m=1000*1000;

int k;
ll fort[vax];

ll dp[vax][nax];

ll pom[nax];

deque<int> kol[3];

int przej(int v)
{
	if (v<=(k-1)*9)
		return (v/3);
	if (v%3)
		return (k-1)*3;
	return v/3;
}

void przejscia(int v)
{
	for (int i=0; i<m; i++)
	{
		if (!(i%10))
			pom[i]=dp[v+1][i/10];
		else
			pom[i]=-inf;
	}
	//~ for (int i=0; i<m; i++)
	//~ {
		//~ dp[v][i]=-inf;
		//~ for (int j=i-k*9; j<=i; j++)
			//~ if (j>=0)
				//~ dp[v][i]=max(dp[v][i], pom[j]+przej(i-j)*fort[v]);
	//~ }
	//~ debug() << v << " " << range(dp[v], dp[v]+60) << " " << imie(pom[30]) << imie(przej(27));
	for (int i=0; i<3; i++)
		kol[i].clear();
	ll f=fort[v];
	const int lim=(k-1)*9;
	for (int i=0; i<m; i++)
	{
		int p=i%3;
		if (!kol[p].empty() && kol[p].front()<i-lim)
			kol[p].pop_front();
		while(!kol[p].empty() && pom[i]-(i/3)*f>=pom[kol[p].back()]-(kol[p].back()/3)*f)
			kol[p].pop_back();
		kol[p].push_back(i);
		dp[v][i]=-inf;
		for (int j=0; j<3; j++)
			if (!kol[j].empty())
				dp[v][i]=max(dp[v][i], pom[kol[j].front()]+przej(i-kol[j].front())*f);
		for (int j=i-k*9; j<=i-lim; j++)
			if (j>=0)
				dp[v][i]=max(dp[v][i], pom[j]+przej(i-j)*f);
	}
}

int main()
{
	scanf("%d", &k);
	for (int i=0; i<d; i++)
		scanf("%lld", &fort[i]);
	if (k>1)
	{
		for (int i=0; i<=d; i++)
			for (int j=0; j<m; j++)
				dp[i][j]=-inf;
		dp[d][0]=0;
		for (int h=d-1; h>=0; h--)
			przejscia(h);
	}
	int q;
	scanf("%d", &q);
	while(q--)
	{
		int x;
		scanf("%d", &x);
		if (k==1)
		{
			ll w=0;
			for (int i=0; i<d; i++)
			{
				int p=x%10;
				x/=10;
				if (!(p%3))
					w+=fort[i]*(p/3);
			}
			printf("%lld\n", w);
		}
		else
		{
			printf("%lld\n", dp[0][x]);
		}
	}
	return 0;
}