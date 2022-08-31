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
const int nax=100*1007;

void ff()
{
	fflush(stdout);
}

void koniec()
{
	printf("done\n");
	ff();
	exit(0);
}

char wcz[17];
int pam;

vi rusz(vi wek)
{
	printf("next");
	sort(wek.begin(), wek.end());
	for (int i : wek)
		printf(" %d", i);
	printf("\n");
	ff();
	vi ret(10);
	int x;
	scanf("%d", &x);
	pam=x;
	for (int i=0; i<x; i++)
	{
		scanf("%s", wcz);
		for (int j=0; wcz[j]; j++)
			ret[wcz[j]-'0']=i;
	}
	return ret;
}

int main()
{
	vi resz;
	for (int i=2; i<10; i++)
		resz.push_back(i);
		
	vi najp;
	for (int i=1; i<10; i++)
		najp.push_back(i);
		
	vi wsz;
	for (int i=0; i<10; i++)
		wsz.push_back(i);
	
	while(1)
	{
		rusz(najp);
		auto wez=rusz({1});
		if (wez[1]==wez[2])
			break;
	}
	while(1)
	{
		rusz(wsz);
		if (pam==1)
			koniec();
	}
	return 0;
}