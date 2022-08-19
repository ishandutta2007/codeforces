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

int tab[nax];
vi wcho[nax];

int wyb[nax];
int odw[nax];

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void test()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		wcho[i].clear();
	for (int i=1; i<=n; i++)
	{
		scanf("%d", &tab[i]);
		wcho[tab[i]].push_back(i);
	}
	while(1)
	{
		for (int i=1; i<=n; i++)
			wyb[i]=odw[i]=0;
		for (int i=1; i<=n; i++)
		{
			if (wcho[i].empty())
				continue;
			wyb[i]=wcho[i][rng()%wcho[i].size()];
			odw[wyb[i]]=i;
		}
		vi pocz, kon;
		for (int i=1; i<=n; i++)
		{
			if (!wyb[i])
				pocz.push_back(i);
			if (!odw[i])
				kon.push_back(i);
		}
		if ((int)pocz.size()==1 && pocz[0]==kon[0])
			continue;
		while(1)
		{
			shuffle(kon.begin(), kon.end(), rng);
			int ok=1;
			for (int i=0; i<(int)pocz.size(); i++)
				if (pocz[i]==kon[i])
				{
					ok=0;
					break;
				}
			if (!ok)
				continue;
			for (int i=0; i<(int)pocz.size(); i++)
				odw[kon[i]]=pocz[i];
			break;
		}
		break;
	}
	
	
	int res=0;
	for (int i=1; i<=n; i++)
		res+=(odw[i]==tab[i]);
	printf("%d\n", res);
	for (int i=1; i<=n; i++)
		printf("%d ", odw[i]);
	printf("\n");
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}