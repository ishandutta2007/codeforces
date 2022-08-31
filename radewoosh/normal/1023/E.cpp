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
const int nax=1000*1007;

void ff()
{
	fflush(stdout);
}

char wcz[7];

int pyt(pii a, pii b)
{
	printf("? %d %d %d %d\n", a.first, a.second, b.first, b.second);
	ff();
	scanf("%s", wcz);
	return (wcz[0]=='Y');
}

int n;

vector <pii> tra;

int main()
{
	scanf("%d", &n);
	pii sr;
	pii pocz={1, 1};
	pii kon={n, n};
	
	pii pom=kon;
	while(pom.first+pom.second!=n+1)
	{
		tra.push_back(pom);
		if (pyt(pocz, {pom.first-1, pom.second}))
			pom.first--;
		else
			pom.second--;
	}
	pii raz=pom;
	tra.push_back(pom);
	pom=pocz;
	while(pom.first+pom.second!=n+1)
	{
		tra.push_back(pom);
		if (pyt({pom.first, pom.second+1}, kon))
			pom.second++;
		else
			pom.first++;
	}
	
	assert(raz==pom);
	
	sort(tra.begin(), tra.end());
	printf("! ");
	for (int i=0; i+1<(int)tra.size(); i++)
	{
		if (tra[i].first==tra[i+1].first)
			printf("R");
		else
			printf("D");
	}
	printf("\n");
	ff();
	return 0;
}