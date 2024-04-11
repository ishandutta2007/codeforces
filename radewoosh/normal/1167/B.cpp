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

int pyt(int a, int b)
{
	printf("? %d %d\n", a, b);
	ff();
	int x;
	scanf("%d", &x);
	return x;
}

vi wek{4, 8, 15, 16, 23, 42};

pii daj(int v)
{
	for (int i=0; i<6; i++)
		for (int j=0; j<i; j++)
			if (wek[i]*wek[j]==v)
				return {wek[i], wek[j]};
	assert(0);
}

int wyn;

int main()
{
	pii a=daj(pyt(1, 2));
	pii b=daj(pyt(3, 4));
	pii c=daj(pyt(1, 3));
	if (c.second==a.first || c.second==a.second)
		swap(c.first, c.second);
	if (a.second==c.first)
		swap(a.second, a.first);
	if (b.second==c.second)
		swap(b.second, b.first);
	int x=pyt(1, 5)/a.first;
	int y=1;
	for (int i : wek)
		y*=i;
	y/=a.first;
	y/=a.second;
	y/=b.first;
	y/=b.second;
	y/=x;
	printf("! %d %d %d %d %d %d\n", a.first, a.second, b.first, b.second, x, y);
	ff();
	return 0;
}