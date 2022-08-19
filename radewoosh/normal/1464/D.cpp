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

int tab[nax];
int bylo[nax];

int k;
int dlu[nax];

int licz[7];

int nie;

int rek(int dwa)
{
	if (dwa==2 && licz[4] && !nie)
	{
		licz[4]--;
		int ret=rek(0);
		licz[4]++;
		return ret;
	}
	if (licz[4])
	{
		int x=licz[4];
		licz[4]-=x;
		licz[1]+=x;
		licz[3]+=x;
		int ret=rek(dwa)+x;
		licz[1]-=x;
		licz[4]+=x;
		licz[3]-=x;
		return ret;
	}
	if (dwa && licz[2])
	{
		licz[2]--;
		int ret=rek(dwa-1);
		licz[2]++;
		return ret;
	}
	if (dwa && licz[1]>1)
	{
		licz[1]-=2;
		int ret=rek(dwa-1)+1;
		licz[1]+=2;
		return ret;
	}
	if (dwa && licz[1]==1)
	{
		assert(dwa==2);
		licz[1]--;
		licz[3]--;
		int ret=rek(0)+1;
		licz[1]++;
		licz[3]++;
		return ret;
	}
	assert(!dwa);
	if (licz[3])
	{
		licz[3]--;
		int ret=rek(dwa);
		licz[3]++;
		return ret;
	}
	if (licz[1] && licz[2])
	{
		licz[1]--;
		licz[2]--;
		int ret=rek(dwa)+1;
		licz[1]++;
		licz[2]++;
		return ret;
	}
	if (licz[1])
	{
		licz[1]-=3;
		int ret=rek(dwa)+2;
		licz[1]+=3;
		return ret;
	}
	if (licz[2])
	{
		licz[2]-=3;
		int ret=rek(dwa)+3;
		licz[2]+=3;
		return ret;
	}
	return 0;
}

void test()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		bylo[i]=0;
		scanf("%d", &tab[i]);
	}
	k=0;
	for (int i=1; i<=n; i++)
	{
		if (bylo[i])
			continue;
		int v=i;
		int ile=0;
		while(!bylo[v])
		{
			bylo[v]=1;
			v=tab[v];
			ile++;
		}
		k++;
		dlu[k]=ile;
	}
	//~ debug() << range(dlu+1, dlu+1+k);
	for (int i=1; i<=4; i++)
	{
		licz[i]=0;
	}
	int dru=0;
	int c3=n/3;
	int c2=0;
	if (n%3==1)
	{
		c3--;
		c2=2;
	}
	if (n%3==2)
	{
		c2=1;
	}
	for (int i=1; i<=k; i++)
	{
		int x=dlu[i];
		while(x>4)
		{
			x-=3;
			dru++;
		}
		licz[x]++;
	}
	ll res=1;
	for (int i=1; i<=c3; i++)
		res=(res*3)%mod;
	for (int i=1; i<=c2; i++)
		res=(res*2)%mod;
	int a=rek(c2);
	nie=1;
	int b=rek(c2);
	nie=0;
	dru+=min(a, b);
	printf("%lld %d\n", res, dru);
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}