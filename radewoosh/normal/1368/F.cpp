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

int n;

void ff()
{
	fflush(stdout);
}

int zap[nax];

int main()
{
	scanf("%d", &n);
	if (n<=3)
	{
		printf("0\n");
		ff();
		return 0;
	}
	int naj=0;
	vi cel;
	for (int i=1; i<n; i++)
	{
		vi ter;
		for (int j=0; j<n; j++)
		{
			if (j!=n-1 && j%(i+1)<i)
				ter.push_back(j+1);
		}
		if ((int)ter.size()-i>=naj)
		{
			naj=(int)ter.size()-i;
			cel=ter;
		}
	}
	debug() << imie(naj);
	while(1)
	{
		int licz=0;
		for (int i=1; i<=n; i++)
			licz+=zap[i];
		if (licz>=naj)
			break;
		vi ter;
		for (int i : cel)
			if (!zap[i])
				ter.push_back(i);
		int k=ter.size();
		printf("%d\n", k);
		for (int i : ter)
			zap[i]=1;
		for (int i : ter)
			printf("%d ", i);
		printf("\n");
		ff();
		int x;
		scanf("%d", &x);
		while(k--)
		{
			zap[x]=0;
			x++;
			if (x>n)
				x=1;
		}
	}
	
	
	printf("0\n");
	ff();
	return 0;
}