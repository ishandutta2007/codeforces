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

int n, k, l;

int ile[nax];
char wcz[nax];

vector <char> wyn[nax];

char najw()
{
	for (int i='z'; i>='a'; i--)
		if (ile[i])
		{
			ile[i]--;
			return i;
		}
	assert(0);
}

char najm()
{
	for (int i='a'; i<='z'; i++)
		if (ile[i])
		{
			ile[i]--;
			return i;
		}
	assert(0);
}

int main()
{
	scanf("%d%d%d", &n, &l, &k);
	scanf("%s", wcz+1);
	for (int i=1; i<=n*l; i++)
		ile[wcz[i]]++;
	for (int i=k+1; i<=n; i++)
		for (int j=1; j<=l; j++)
			wyn[i].push_back(najw());
	
	int p=1;
	for (int i=1; i<=l; i++)
	{
		//~ debug() << i << " " << p;
		for (int j=p; j<=k; j++)
		{
			wyn[j].push_back(najm());
		}
		//~ debug() << "e";
		for (int j=p; j<=k; j++)
		{
			if (wyn[j].back()<wyn[k].back())
			{
				while((int)wyn[j].size()<l)
					wyn[j].push_back(najw());
				p++;
			}
		}
	}
	sort(wyn+1, wyn+1+n);
	
	for (int i=1; i<=n; i++)
	{
		for (char j : wyn[i])
			printf("%c", j);
		printf("\n");
	}
	return 0;
}