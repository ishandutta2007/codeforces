//~ while (clock()<=69*CLOCKS_PER_SEC)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
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
const int nax=1000*1007;

int n;
char wcz[2][nax];

int s[2][nax];
int ile[2][nax];

int main()
{
	for (int h=0; h<2; h++)
	{
		scanf("%s", wcz[h]+1);
		n=strlen(wcz[h]+1);
		for (int i=1; i<=n; i++)
		{
			int x=(wcz[h][i]!='A');
			s[h][i]=s[h][i-1]+x;
			if (!x)
				ile[h][i]=ile[h][i-1]+1;
		}
	}
	int q;
	scanf("%d", &q);
	while(q--)
	{
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		a--;
		c--;
		int s0=s[0][b]-s[0][a];
		int s1=s[1][d]-s[1][c];
		int i0=min(ile[0][b], b-a);
		int i1=min(ile[1][d], d-c);
		if (s0>s1)
		{
			printf("0");
			continue;
		}
		if ((s0^s1)&1)
		{
			printf("0");
			continue;
		}
		if (s0==s1)
		{
			printf("%d", (int)((i0%3)==(i1%3) && i0>=i1));
		}
		else
		{
			if (!s0)
				i0--;
			printf("%d", (int)(i0>=i1));
		}
	}
	printf("\n");
	return 0;
}