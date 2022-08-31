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
const int nax=2007;
const ll mod=998244353;
using bn=bitset<nax>;

int n;

char wcz[nax];
bn graf[nax];
bn farg[nax];

bn wsz, pus;

ll sil[nax];

void dot(int v)
{
	for (int i=1; i<=n; i++)
	{
		if (i==v)
			continue;
		graf[v][i]=(!graf[v][i]);
		farg[v][i]=(!farg[v][i]);
		graf[i][v]=(!graf[i][v]);
		farg[i][v]=(!farg[i][v]);
	}
}

void nope()
{
	printf("-1\n");
	exit(0);
}

void ans(int v, ll w)
{
	w%=mod;
	printf("%d %lld\n", v, w);
	exit(0);
}

int test()
{
	{
		queue <int> kol;
		bn bylem;
		kol.push(1);
		bylem[1]=1;
		bn now;
		while(!kol.empty())
		{
			int v=kol.front();
			kol.pop();
			now=graf[v]&(bylem^wsz);
			for (int i=now._Find_first(); i!=now.size(); i=now._Find_next(i))
			{
				kol.push(i);
				bylem[i]=1;
			}
		}
		if (bylem!=wsz)
			return 0;
	}
	{
		queue <int> kol;
		bn bylem;
		kol.push(1);
		bylem[1]=1;
		bn now;
		while(!kol.empty())
		{
			int v=kol.front();
			kol.pop();
			now=farg[v]&(bylem^wsz);
			for (int i=now._Find_first(); i!=now.size(); i=now._Find_next(i))
			{
				kol.push(i);
				bylem[i]=1;
			}
		}
		if (bylem!=wsz)
			return 0;
	}
	return 1;
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		scanf("%s", wcz+1);
		for (int j=1; j<=n; j++)
		{
			if (wcz[j]=='1')
			{
				graf[i][j]=1;
				farg[j][i]=1;
			}
		}
	}
	for (int i=1; i<=n; i++)
		wsz[i]=1;
	if (test())
		ans(0, 1);
	ll ile=0;
	for (int i=1; i<=n; i++)
	{
		dot(i);
		if (test())
			ile++;
		dot(i);
	}
	if (ile)
		ans(1, ile);
	int mini=n;
	sil[0]=1;
	for (int i=1; i<=n; i++)
		sil[i]=(sil[i-1]*i)%mod;
	for (int i=1; i<(1<<n); i++)
	{
		int p=__builtin_popcount(i);
		if (p>mini)
			continue;
		for (int j=0; j<n; j++)
			if (i&(1<<j))
				dot(j+1);
		if (test())
		{
			if (p<mini)
			{
				mini=p;
				ile=0;
			}
			ile=(ile+sil[p])%mod;
		}
		for (int j=0; j<n; j++)
			if (i&(1<<j))
				dot(j+1);
	}
	
	if (!ile)
		nope();
	ans(mini, ile);
	return 0;
}