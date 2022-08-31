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

int n;

int a[nax];
int b[nax];

set<int> setel;

int odl[nax];
int z[nax];

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i=1; i<=n; i++)
	{
		scanf("%d", &b[i]);
	}
	for (int i=0; i<=n+1; i++)
		if (i!=n)
			setel.insert(i);
	for (int i=0; i<=n; i++)
	{
		odl[i]=-1;
	}
	queue<int> kol;
	kol.push(n);
	odl[n]=0;
	while(!kol.empty())
	{
		int v=kol.front();
		kol.pop();
		int g=min(n, v+b[v]);
		//~ debug() << imie(v);
		while(1)
		{
			auto it=setel.lower_bound(g-a[g]);
			if ((*it)>g)
				break;
			int x=(*it);
			//~ debug() << setel << " " << g-a[g];
			setel.erase(it);
			odl[x]=odl[v]+1;
			z[x]=v;
			kol.push(x);
			//~ debug() << v << " " << g << " " << x;
			if (x==0)
			{
				printf("%d\n", odl[v]+1);
				vi wek;
				while(x!=n)
				{
					wek.push_back(x);
					x=z[x];
				}
				reverse(wek.begin(), wek.end());
				for (int i : wek)
					printf("%d ", i);
				printf("\n");
				
				return 0;
			}
		}
	}
	printf("-1\n");
	return 0;
}