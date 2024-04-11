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

ll inv(ll v)
{
	if (v<=1)
		return v;
	return inv(mod%v)*(mod-mod/v)%mod;
}

int n;

ll sil[nax];
ll odw[nax];

int tab[nax];

ll wyn;

ll kom(int a, int b)
{
	if (b<0 || b>a)
		return 0;
	return sil[a]*odw[b]%mod*odw[a-b]%mod;
}

ll doj(int a, int b)
{
	//~ debug() << a << " " << b;
	return kom(a+b, b);
}

int main()
{
	sil[0]=1;
	for (int i=1; i<nax; i++)
		sil[i]=sil[i-1]*i%mod;
	odw[nax-1]=inv(sil[nax-1]);
	for (int i=nax-1; i; i--)
		odw[i-1]=odw[i]*i%mod;
	scanf("%d", &n);
	n++;
	for (int i=0; i<n; i++)
		scanf("%d", &tab[i]);
	while(n && !tab[n-1])
		n--;
	if (!n)
	{
		printf("0\n");
		return 0;
	}
	for (int i=0; i<n; i++)
	{
		wyn+=doj(i, tab[i]-1);
		for (int j=tab[i+1]; j<tab[i]; j++)
			wyn+=doj(i, j);
	}
	wyn--;
	wyn%=mod;
	wyn+=mod;
	wyn%=mod;
	printf("%lld\n", wyn);
	return 0;
}