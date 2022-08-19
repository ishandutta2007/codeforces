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

int n, m;

int tab[nax];

int paczy[nax];
int jak[nax];

vi wek[nax];

void test()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		scanf("%d", &tab[i]);
	}
	vi stos;
	for (int i=n; i; i--)
	{
		if (!stos.empty() && tab[stos.back()]==1)
		{
			jak[stos.back()]=1;
			paczy[stos.back()]=i;
			stos.pop_back();
		}
		if (!stos.empty() && tab[stos.back()]==tab[i]+1)
		{
			jak[stos.back()]=2;
			paczy[stos.back()]=i;
			stos.pop_back();
		}
		stos.push_back(i);
	}
	wek[1]={1};
	for (int i=2; i<=n; i++)
	{
		wek[i]=wek[paczy[i]];
		if (jak[i]==1)
			wek[i].push_back(1);
		else
			wek[i].back()++;
	}
	for (int i=1; i<=n; i++)
	{
		for (int j=0; j<(int)wek[i].size(); j++)
		{
			if (j)
				printf(".");
			printf("%d", wek[i][j]);
		}
		printf("\n");
	}
	
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int i=1; i<=t; i++)
	{
		test();
	}
	return 0;
}