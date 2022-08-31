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
const int nax=300*1007;
const int inf=1e9;
const ll mod=998244353;

int n;

ll tab[nax];
ll pre[nax];

ll wyn;

ll sum(int a, int b)
{
	return pre[b]-pre[a-1];
}

ll wpra[nax];

void cp(int a, int b, ll bonus)
{
	if (a>=b)
		return;
	ll wsz=bonus-sum(a, b);
	//~ debug() << "   " << a << " " << b << " " << bonus << " " << wsz;
	for (int i=a; i<b; i++)
	{
		wsz+=2*tab[i];
		if (wsz>=0)
			break;
		int bsa=0;
		int bsb=(b-i-1)/2;
		while(bsa<bsb)
		{
			int bss=(bsa+bsb+2)>>1;
			if (wsz+2*(wpra[i+2]-wpra[i+2*bss+2])<0)
				bsa=bss;
			else
				bsb=bss-1;
		}
		//~ debug() << a << " " << b << " " << i << " " << bsa << " " << wsz;
		wyn+=bsa+1;
	}
}

void test()
{
	scanf("%d", &n);
	for (int i=0; i<=n+7; i++)
		wpra[i]=tab[i]=pre[i]=0;
	for (int i=1; i<=n; i++)
		scanf("%lld", &tab[i]);
	for (int i=1; i<=n; i++)
		pre[i]=pre[i-1]+tab[i];
	for (int i=n+3; i; i--)
		wpra[i]=wpra[i+2]+tab[i];
	wyn=0;
	wyn=1;//same P
	cp(1, n, 0);
	cp(2, n, -tab[1]);
	cp(1, n-1, tab[n]);
	cp(2, n-1, tab[n]-tab[1]);
	{
		ll s=-sum(1, n);
		for (int i=n; i; i--)
		{
			s+=2*tab[i];
			wyn+=(s<0);
			//~ if (s<0)
				//~ debug() << "suf " << i;
		}
	}
	
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