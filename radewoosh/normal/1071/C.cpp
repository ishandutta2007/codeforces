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
const int nax=100*1007;

int n;
int tab[nax];

vector <vi> wyn;

void nope()
{
	printf("NO\n");
	exit(0);
}

void zrob(int a, int b, int c)
{
	tab[a]^=1;
	tab[b]^=1;
	tab[c]^=1;
	wyn.push_back({a, b, c});
}

void zrob(int a, int b)
{
	if ((a&1)==(b&1))
		zrob(a, (a+b)/2, b);
}

void zbruc(int a, int b)
{
	vector <vi> moz;
	for (int i=a; i<=b; i++)
		for (int j=i+1; j+j-i<=b; j++)
			moz.push_back({i, j, j+j-i});
	//~ debug() << imie(moz.size());
	int pot=0;
	for (int i=a; i<=b; i++)
		pot^=(tab[i]<<(i-a));
	int k=moz.size();
	for (int i=0; i<(1<<k); i++)
	{
		int mas=0;
		for (int j=0; j<k; j++)
			if (i&(1<<j))
				for (int l : moz[j])
					mas^=(1<<(l-a));
		if (mas==pot)
		{
			//~ debug() << range(tab+a, tab+b+1);
			for (int j=0; j<k; j++)
				if (i&(1<<j))
					zrob(moz[j][0], moz[j][1], moz[j][2]);
			return;
		}
	}
	nope();
}

void rek(int a, int b)
{
	if (a>b)
		return;
	if (b-a<=7)
	{
		zbruc(a, b);
		return;
	}
	if (!tab[a])
	{
		rek(a+1, b);
		return;
	}
	if (!tab[b])
	{
		rek(a, b-1);
		return;
	}
	if (!tab[b-1])
	{
		if (tab[b-2])
			zrob(b-4, b-2, b);
		else
			zrob(b-6, b-3, b);
		rek(a, b);
		return;
	}
	if (!tab[a+1])
	{
		if (tab[a+2])
			zrob(a, a+2, a+4);
		else
			zrob(a, a+3, a+6);
		rek(a, b);
		return;
	}
	if (tab[b-2])
	{
		zrob(b-2, b-1, b);
		rek(a, b);
		return;
	}
	if (tab[a+2])
	{
		zrob(a, a+1, a+2);
		rek(a, b);
		return;
	}
	zrob(a, b);
	zrob(a, b-1);
	zrob(a+1, b);
	zrob(a+1, b-1);
	rek(a, b);
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		scanf("%d", &tab[i]);
		//~ tab[i]=rand()%2;
		//~ tab[i]=1;
	rek(1, n);
	for (int i=1; i<=n; i++)
		assert(!tab[i]);
	
	printf("YES\n");
	printf("%d\n", (int)wyn.size());
	for (vi &i : wyn)
	{
		sort(i.begin(), i.end());
		printf("%d %d %d\n", i[0], i[1], i[2]);
	}
	return 0;
}