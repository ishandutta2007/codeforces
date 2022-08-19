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
char wcz[nax];
int tab[nax];

void ans(vector<pii> wek)
{
	printf("%d\n", (int)wek.size());
	for (pii i : wek)
		printf("%d %d\n", i.first, i.second);
}

void test()
{
	scanf("%d", &n);
	scanf("%s", wcz+1);
	for (int i=1; i<=2*n; i++)
	{
		if (wcz[i]=='(')
			tab[i]=1;
		else
			tab[i]=-1;
	}
	int lew=2*n+1;
	int pra=0;
	{
		int b=0;
		int ok=1;
		for (int i=1; i<=2*n; i++)
		{
			b+=tab[i];
			if (b<0)
			{
				ok=0;
				lew=min(lew, i);
				pra=i;
			}
		}
		if (ok)
		{
			ans({});
			return;
		}
	}
	//~ debug() << "no " << lew << " " << pra;
	
	
	pii g{0, 0};
	{
		int b=0;
		for (int i=1; i<=2*n; i++)
		{
			b+=tab[i];
			g=max(g, {b, i});
		}
	}
	int v=g.second;
	vector<pii> wra={{1, v}, {v+1, 2*n}};
	{
		pii g1{0, 0};
		pii g2{0, 0};
		{
			int b=0;
			for (int i=1; i<=lew; i++)
			{
				b+=tab[i];
				g1=max(g1, pii{b, i});
			}
		}
		{
			int b=0;
			for (int i=pra; i<=2*n; i++)
			{
				b+=tab[i];
				g2=max(g2, pii{b, i});
			}
		}
		int a=g1.second;
		int b=g2.second;
		a++;
		//~ debug() << imie(a) << imie(b);
		reverse(tab+a, tab+b+1);
		int pb=b;
		{
			int b=0;
			int ok=1;
			for (int i=1; i<=2*n; i++)
			{
				b+=tab[i];
				if (b<0)
				{
					ok=0;
					lew=min(lew, i);
					pra=i;
				}
			}
			if (ok)
			{
				ans({{a, pb}});
				return;
			}
		}
	}
	ans(wra);
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}