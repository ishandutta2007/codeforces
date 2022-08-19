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
const int nax=1007;
using bn=bitset<nax>;

int n;
int tab[nax];

bn wyn[nax];

void rek(vi wek)
{
	int k=wek.size();
	if (!k)
		return;
	vi naj;
	for (int i : wek)
		if (tab[i]==k)
			naj.push_back(i);
	//~ debug() << k << " " << naj << " " << wek;
	if (naj.empty())
	{
		//~ debug() << "raz";
		int x=wek.back();
		wek.pop_back();
		rek(wek);
		for (int i=1; i<=tab[x]; i++)
			wyn[k+1-i][x]=1;
		return;
	}
	if ((int)naj.size()>1 || 1)
	{
		//~ debug() << "dwa";
		int x=naj[0];
		for (int &i : wek)
		{
			if (i==x)
			{
				swap(i, wek.back());
				wek.pop_back();
				break;
			}
		}
		//~ debug() << x << " " << wek;
		for (int i : naj)
		{
			wyn[k][i]=1;
			tab[i]--;
		}
		rek(wek);
		for (int i=k-1; i>=0 && tab[x]; i--)
		{
			int czy=1;
			wyn[i][x]=1;
			for (int j=i+1; j<=k; j++)
				if (wyn[j]==wyn[i])
					czy=0;
			if (czy)
				tab[x]--;
			else
				wyn[i][x]=0;
		}
	}
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		scanf("%d", &tab[i]);
	vi wek(n);
	iota(wek.begin(), wek.end(), 1);
	rek(wek);
	printf("%d\n", n+1);
	for (int i=0; i<=n; i++)
	{
		for (int j=1; j<=n; j++)
			printf("%d", (int)wyn[i][j]);
		printf("\n");
	}
	return 0;
}