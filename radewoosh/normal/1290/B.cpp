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
const int nax=200*1007;
const int alfa=26;

char wcz[nax];
int n, q;

int ile[alfa][nax];

int main()
{
	scanf("%s", wcz+1);
	n=strlen(wcz+1);
	for (int i=1; i<=n; i++)
		ile[wcz[i]-'a'][i]++;
	for (int i=0; i<alfa; i++)
		for (int j=1; j<=n; j++)
			ile[i][j]+=ile[i][j-1];
	scanf("%d", &q);
	while(q--)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		int roz=0;
		for (int i=0; i<alfa; i++)
			roz+=(ile[i][b]!=ile[i][a-1]);
		if (a==b)
		{
			printf("Yes\n");
			continue;
		}
		if (roz==1)
		{
			printf("No\n");
			continue;
		}
		if (roz>=3)
		{
			printf("Yes\n");
			continue;
		}
		//~ int x=0;
		//~ for (int i=0; i<alfa; i++)
			//~ x^=(ile[i][b]-ile[i][a-1]);
		//~ debug() << imie(x);
		if (wcz[a]!=wcz[b])
		{
			printf("Yes\n");
			continue;
		}
		else
		{
			printf("No\n");
			continue;
		}
	}
	return 0;
}