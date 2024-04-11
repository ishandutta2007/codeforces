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

int tab[nax];
vi wek[nax];

int oj[nax];

int per[nax];

int fin(int v)
{
	if (v!=oj[v])
		oj[v]=fin(oj[v]);
	return oj[v];
}

void uni(int a, int b)
{
	oj[fin(a)]=fin(b);
}

void ans(int v)
{
	if (v)
		printf("YES\n");
	else
		printf("NO\n");
}

int daj(int v)
{
	int ret=wek[v].back();
	wek[v].pop_back();
	return ret;
}

int spojne()
{
	int ret=0;
	for (int i=1; i<=n; i++)
		ret+=(oj[i]==i);
	return ret;
}

void test()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		wek[i].clear();
		per[i]=0;
		oj[i]=i;
	}
	for (int i=1; i<=n; i++)
	{
		scanf("%d", &tab[i]);
		wek[tab[i]].push_back(i);
	}
	vi niep;
	for (int i=1; i<=n; i++)
		if (wek[i].size()&1)
			niep.push_back(i);
	if ((int)niep.size()>(n&1))
	{
		ans(0);
		return;
	}
	if (n&1)
	{
		int x=daj(niep[0]);
		per[(n+1)/2]=x;
	}
	int wsk=1;
	for (int i=1; i*2<=n; i++)
	{
		while(wek[wsk].empty())
			wsk++;
		per[i]=daj(wsk);
		per[n+1-i]=daj(wsk);
	}
	for (int i=1; i<=n; i++)
		uni(i, per[i]);
	for (int i=1; i<=n; i++)
		wek[tab[per[i]]].push_back(i);
	//~ debug() << imie(spojne());
	for (int i=1; i<=n; i++)
	{
		vi &tu=wek[i];
		for (int j=1; j<(int)tu.size(); j++)
		{
			int a=tu[0];
			int b=tu[j];
			if (fin(a)!=fin(b))
			{
				swap(per[a], per[b]);
				uni(a, b);
			}
		}
	}
	//~ debug() << imie(spojne());
	for (int i=2; i*2<=n; i++)
	{
		int a=1;
		int b=n;
		int c=i;
		int d=n+1-i;
		if (fin(a)!=fin(c))
		{
			swap(per[c], per[b]);
			swap(per[c], per[d]);
			swap(per[c], per[a]);
			uni(c, a);
		}
	}
	if (spojne()>1)
	{
		ans(0);
		return;
	}
	ans(1);
	//~ debug() << imie(spojne());
	for (int i=1; i<=n; i++)
		printf("%d ", per[i]);
	printf("\n");
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}