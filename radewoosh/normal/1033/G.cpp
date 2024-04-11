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
ll m;

ll tab[nax];
ll w[nax];

ll wyn[nax];

pll przetnij(pll a, pll b)
{
	return {max(a.first, b.first), min(a.second, b.second)};
}

int dlu(pll v)
{
	return max(0LL, v.second-v.first+1);
}

int res(ll a, ll b)
{
	assert(a<b);
	for (int i=1; i<=n; i++)
		if (w[i]>=a && w[i]<b)
			return 0;
	int czy=0;
	int parz=0;
	for (int i=1; i<=n; i++)
	{
		if (w[i]/a!=w[i]/b)
			czy++;
		if (w[i]>=a)
			parz^=1;
	}
	if (!czy)
	{
		if (!parz)
			return 3;
		return 2;
	}
	if (czy>1)
		return 0;
	int og=0;
	for (int i=1; i<=n; i++)
		og+=(w[i]>=b);
	if (og&1)
		return 2;
	return 0;
}

int main()
{
	scanf("%d%lld", &n, &m);
	for (int i=1; i<=n; i++)
		scanf("%lld", &tab[i]);
	for (int i=3; i<=2*m; i++)
	{
		pii mniej=przetnij({1, (i-1)/2}, {i-m, i});
		for (int j=1; j<=n; j++)
			w[j]=tab[j]%i;
		if (!dlu(mniej))
			continue;
		//~ debug() << i << " " << mniej;
		//~ for (int j=mniej.first; j<=mniej.second; j++)
		//~ {
			//~ wyn[res(j, i-j)]++;
			//~ debug() << j << " " << i-j << ": " << res(j, i-j);
		//~ }
		//~ debug();
		int a=mniej.first;
		int b=mniej.second;
		if (res(a, i-a)>=2)
		{
			wyn[res(a, i-a)]+=dlu(mniej);
			continue;
		}
		if (res(b, i-b)==0)
		{
			wyn[0]+=dlu(mniej);
			continue;
		}
		int bsa=a;
		int bsb=b;
		int bss;
		while(bsa<bsb)
		{
			bss=(bsa+bsb+2)>>1;
			if (!res(bss, i-bss))
				bsa=bss;
			else
				bsb=bss-1;
		}
		wyn[0]+=bsa-a+1;
		wyn[res(b, i-b)]+=b-bsa;
	}
	
	wyn[1]=wyn[0];
	wyn[2]*=2;
	wyn[3]*=2;
	for (int i=1; i<=m; i++)
	{
		ll p=0;
		for (int j=1; j<=n; j++)
			p+=tab[j]/i;
		p&=1;
		if (p)
			wyn[2]++;
		else
			wyn[3]++;
	}
	assert(wyn[0]+wyn[1]+wyn[2]+wyn[3]==m*m);
	for (int i=0; i<4; i++)
		printf("%lld ", wyn[i]);
	printf("\n");
	return 0;
}