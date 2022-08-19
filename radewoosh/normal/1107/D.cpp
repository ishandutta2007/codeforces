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
const int nax=5207;

int n;

bitset <nax> tab[nax];

char wcz[nax];

int check(int v)
{
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			if (tab[i][j]!=tab[i-((i%v)>0)][j-((j%v)>0)])
				return 0;
	return 1;
}

map <char,int> mapa;

int main()
{
	int li=0;
	for (char i='0'; i<='9'; i++)
	{
		mapa[i]=li;
		li++;
	}
	for (char i='A'; i<='F'; i++)
	{
		mapa[i]=li;
		li++;
	}
	scanf("%d", &n);
	vi wek;
	int pom=n;
	for (int i=2; i<=pom; i++)
	{
		if (!(pom%i))
		{
			wek.push_back(i);
			pom/=i;
			i--;
		}
	}
	debug() << wek;
	for (int i=1; i<=n; i++)
	{
		int x=0;
		scanf("%s", wcz+1);
		for (int j=1; j<=n/4; j++)
		{
			char c=wcz[j];
			int p=mapa[c];
			for (int l=3; l>=0; l--)
			{
				x++;
				tab[i-1][x-1]=((p&(1<<l))>0);
			}
		}
	}
	int wyn=1;
	for (int i : wek)
		if (check(wyn*i))
			wyn*=i;
	//~ for (int i=2; i<=n; i++)
		//~ if (!(n%i) && check(i))
			//~ wyn=i;
	printf("%d\n", wyn);
	return 0;
}