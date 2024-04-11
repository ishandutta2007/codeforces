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
const ll inf=5e18;

int n, k;

ll wyn;

ll sc(ll v)
{
	ll ret=0;
	while(v)
	{
		ret+=(v%10);
		v/=10;
	}
	return ret;
}

vll dos;
ll wych[20007][20];

void check(ll v)
{
	ll ret=0;
	for (int i=0; i<=k; i++)
		ret+=sc(v+i);
	if (ret==n)
		wyn=min(wyn, v);
}

void test()
{
	scanf("%d%d", &n, &k);
	wyn=inf;
	for (int i=0; i<(int)dos.size(); i++)
		if (wych[i][k]==n)
			wyn=min(wyn, dos[i]);
	if (wyn>=inf)
		wyn=-1;
	printf("%lld\n", wyn);
}

int main()
{
	for (int pier=0; pier<10; pier++)
	{
		for (int j=0; j<=16; j++)
		{
			for (int ost=0; ost<10; ost++)
			{
				for (int odej=-1; odej<18; odej++)
				{
					ll pot=1;
					ll w=0;
					w+=pier*pot;
					pot*=10;
					for (int p=0; p<j; p++)
					{
						w+=9*pot;
						pot*=10;
					}
					w+=ost*pot;
					pot*=10;
					pot=1;
					for (int p=0; p<odej; p++)
						pot*=10;
					if (odej>=0)
						w-=pot;
					if (w>=0 && w<inf)
						dos.push_back(w);
				}
			}
		}
	}
	for (int i=0; i<(int)dos.size(); i++)
	{
		ll s=0;
		for (int j=0; j<10; j++)
		{
			s+=sc(dos[i]+j);
			wych[i][j]=s;
		}
	}
	debug() << imie(dos.size());
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}