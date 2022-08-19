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
const ll inf=1e15;

int n;
ll tab[nax];

ll dlu[nax];

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		scanf("%lld", &tab[i]);
	for (int i=n+1; i<=3*n; i++)
		tab[i]=tab[i-n];
	ll maxi=0;
	ll mini=inf;
	for (int i=1; i<=n; i++)
	{
		maxi=max(maxi, tab[i]);
		mini=min(mini, tab[i]);
	}
	if (mini*2>=maxi)
	{
		for (int i=1; i<=n; i++)
			printf("-1 ");
		printf("\n");
		return 0;
	}
	
	vi stos;
	stos.push_back(2*n+1);
	for (int i=2*n; i; i--)
	{
		if (tab[stos[0]]*2>=tab[i])
		{
			dlu[i]=inf;
		}
		else
		{
			int bsa=0;
			int bsb=(int)stos.size()-1;
			while(bsa<bsb)
			{
				int bss=(bsa+bsb+2)>>1;
				if (tab[stos[bss]]*2<tab[i])
					bsa=bss;
				else
					bsb=bss-1;
			}
			dlu[i]=stos[bsa]-i;
		}
		while(!stos.empty() && tab[i]<=tab[stos.back()])
			stos.pop_back();
		stos.push_back(i);
		//~ debug() << i << " " << stos;
	}
	for (int h=1; h<=3; h++)
	{
		for (int i=n; i; i--)
		{
			int p=(i%n)+1;
			dlu[i]=min(dlu[i], dlu[p]+1);
		}
	}
	for (int i=1; i<=n; i++)
		printf("%lld ", dlu[i]);
	printf("\n");
	return 0;
}