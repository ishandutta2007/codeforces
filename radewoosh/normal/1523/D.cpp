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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand cipka

int n, m, p;

char wcz[nax];
vi lubi[nax];

ll mam=0;
ll maska;

ll sos[nax];
int kt[nax];

int main()
{
	scanf("%d%d%d", &n, &m, &p);
	for (int i=1; i<=n; i++)
	{
		scanf("%s", wcz);
		for (int j=0; j<m; j++)
			if (wcz[j]=='1')
				lubi[i].push_back(j);
	}
	for (int h=0; h<1000 && clock()<=2.5*CLOCKS_PER_SEC; h++)
	{
		int x=rng()%n+1;
		for (int i=0; i<(1<<p); i++)
			sos[i]=0;
		int r=lubi[x].size();
		for (int i=0; i<m; i++)
			kt[i]=-1;
		for (int i=0; i<r; i++)
			kt[lubi[x][i]]=i;
		for (int i=1; i<=n; i++)
		{
			int tu=0;
			for (int j : lubi[i])
				if (kt[j]>=0)
					tu|=(1<<kt[j]);
			sos[tu]++;
		}
		for (int i=0; i<r; i++)
			for (int j=0; j<(1<<r); j++)
				if (j&(1<<i))
					sos[j^(1<<i)]+=sos[j];
		for (int i=0; i<(1<<r); i++)
		{
			if (sos[i]*2<n || __builtin_popcount(i)<=mam)
				continue;
			mam=__builtin_popcount(i);
			maska=0;
			for (int j=0; j<r; j++)
				if (i&(1<<j))
					maska|=(1LL<<lubi[x][j]);
		}
	}
	
	
	for (int i=0; i<m; i++)
		printf("%lld", (maska>>i)&1);
	printf("\n");
	return 0;
}