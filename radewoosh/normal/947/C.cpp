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
const int d=30;
const int n1=(1<<d);

int n;

int tab[nax];
int klu[nax];

unordered_map <int,int> mapa;

int pyt(int v)
{
	if (!mapa.count(v))
		return 0;
	return mapa[v];
}

void odej(int v)
{
	v+=n1;
	while(v)
	{
		mapa[v]--;
		v>>=1;
	}
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		scanf("%d", &tab[i]);
	for (int i=1; i<=n; i++)
		scanf("%d", &klu[i]);
	
	for (int i=1; i<=n; i++)
	{
		int w=klu[i]+n1;
		while(w)
		{
			mapa[w]++;
			w>>=1;
		}
	}
	for (int i=1; i<=n; i++)
	{
		int v=1;
		for (int j=d-1; j>=0; j--)
		{
			int x=((tab[i]&(1<<j))>0);
			//~ debug() << v << " " << pyt(v*2) << " " << pyt(v*2+1) << "   " << x;
			if (x)
			{
				if (pyt(v*2+1))
					v=v*2+1;
				else
					v=v*2;
			}
			else
			{
				if (pyt(v*2))
					v=v*2;
				else
					v=v*2+1;
			}
		}
		printf("%d ", tab[i]^(v-n1));
		odej(v-n1);
	}
	printf("\n");
	return 0;
}