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
const int nax=1007;

int n, k;
char wcz[nax];

void ff()
{
	fflush(stdout);
}

void ans(int v)
{
	printf("! %d\n", v);
	ff();
}

int pyt(vi a, vi b)
{
	printf("? %d %d\n", (int)a.size(), (int)b.size());
	for (int i : a)
		printf("%d ", i);
	printf("\n");
	for (int i : b)
		printf("%d ", i);
	printf("\n");
	ff();
	scanf("%s", wcz);
	if (wcz[0]=='F')
		return -1;
	if (wcz[0]=='S')
		return 1;
	if (wcz[0]=='E')
		return 0;
	assert(0);
}

int czy_to_kamien(int v)
{
	int juz=0;
	while(juz<15)
	{
		int x=rand()%n+1;
		if (x==v)
			continue;
		if (pyt({v}, {x})==1)
			return 0;
		juz++;
	}
	return 1;
}

vi daj(int a, int b)
{
	vi ret;
	for (int i=a; i<=b; i++)
		ret.push_back(i);
	return ret;
}

int test(int a, int b)
{
	int dlu=b-a+1;
	vi kam=daj(a-dlu, a-1);
	vi moze=daj(a, b);
	return pyt(kam, moze);
}

void test()
{
	scanf("%d%d", &n, &k);
	if (n==2)
	{
		if (pyt({1}, {2})==1)
			ans(1);
		else
			ans(2);
		return;
	}
	if (!czy_to_kamien(1))
	{
		ans(1);
		return;
	}
	int m=1;
	while(1)
	{
		int a=m+1;
		int b=min(2*m, n);
		if (!test(a, b))
		{
			m=b;
			continue;
		}
		int bsa=a;
		int bsb=b;
		while(bsa<bsb)
		{
			int bss=(bsa+bsb)>>1;
			if (test(a, bss))
				bsb=bss;
			else
				bsa=bss+1;
		}
		ans(bsa);
		break;
	}
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}