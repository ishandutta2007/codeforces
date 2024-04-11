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
const int nax=100*1007;
const ll mod=1000*1000*1000+7;

int n;

int wej[nax];

ll wyn;

ll tu[nax];

int m;
int tab[nax];

vi dz[nax];

ll sumnad[nax];

ll mag[nax];

ll solve()
{
	for (int i=1; i<=m; i++)
		for (int j : dz[tab[i]])
			sumnad[j]++;
	ll ret=0;
	for (int i=1; i<=m; i++)
		for (int j : dz[tab[i]])
			ret+=sumnad[j]*mag[j];
	for (int i=1; i<=m; i++)
		for (int j : dz[tab[i]])
			sumnad[j]=0;
	return ret;
}

int main()
{
	for (int i=1; i<nax; i++)
		for (int j=i; j<nax; j+=i)
			dz[j].push_back(i);
	for (int i=1; i<nax; i++)
	{
		mag[i]+=i;
		for (int j=2*i; j<nax; j+=i)
			mag[j]-=mag[i];
	}
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		scanf("%d", &wej[i]);
	}
	for (int i=1; i<=n; i++)
	{
		m=0;
		for (int j=i; j<=n; j+=i)
		{
			m++;
			tab[m]=wej[j];
		}
		tu[i]=solve();
	}
	for (int i=n; i; i--)
	{
		for (int j=2*i; j<=n; j+=i)
			tu[i]-=tu[j];
		tu[i]%=mod;
		tu[i]+=mod;
		tu[i]%=mod;
		wyn=(wyn+tu[i]*i)%mod;
	}
	printf("%lld\n", wyn);
	return 0;
}