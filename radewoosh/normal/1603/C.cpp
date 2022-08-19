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
const ll mod=998244353;

int n;
ll tab[nax];

ll ile[nax];

ll wyn;

ll dol(ll v, ll dz)
{
	return v/dz;
}

ll gor(ll v, ll dz)
{
	return (v+dz-1)/dz;
}

void test()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		scanf("%lld", &tab[i]);
		//~ tab[i]=rand()%100000+1;
	wyn=0;
	ll s=0;
	ll si=0;
	for (int i=1; i<=n; i++)
		ile[i]=1;
	for (int i=1; i<=n; i++)
	{
		//~ debug() << i;
		for (int j=i-1; j; j--)
		{
			if (gor(tab[j], ile[j])<=dol(tab[j+1], ile[j+1]))
				break;
			ll musze=dol(tab[j+1], ile[j+1]);
			//~ debug() << i << " " << j << "   " << tab[j+1] << " " << ile[j+1] << " " << musze;
			ll bylo=ile[j];
			ile[j]=max(ile[j], tab[j]/musze-3);
			while(gor(tab[j], ile[j])>musze)
				ile[j]++;
			s+=ile[j]-bylo;
			si+=(ile[j]-bylo)*j;
			si%=mod;
		}
		wyn+=si;
		wyn%=mod;
		//~ debug() << range(ile+1, ile+1+i) << " " << s;
	}
	wyn%=mod;
	wyn+=mod;
	wyn%=mod;
	
	printf("%lld\n", wyn);
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}