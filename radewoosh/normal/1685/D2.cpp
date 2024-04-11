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
const int nax=1007;

int n;
int tab[nax];
int odw[nax];

int ojf[nax];

int wyn[nax];

int fin(int v)
{
	if (v!=ojf[v])
		ojf[v]=fin(ojf[v]);
	return ojf[v];
}

void uni(int a, int b)
{
	ojf[fin(a)]=fin(b);
}

int pocz[nax];
int kon[nax];

int jest[nax];
int zyje[nax];

int solve(int p)
{
	for (int i=1; i<=n; i++)
	{
		ojf[i]=i;
		jest[i]=0;
		zyje[i]=0;
	}
	for (int i=1; i<=n; i++)
		uni(i, tab[i]);
	int ret=0;
	for (int i=1; i<p; i++)
		ret+=abs(wyn[i]-tab[wyn[i+1]]);
	for (int i=1; i<=p; i++)
	{
		jest[wyn[i]]=1;
	}
	zyje[tab[wyn[1]]]=1;
	zyje[wyn[p]]=1;
	for (int i=1; i<=n; i++)
		pocz[i]=kon[i]=0;
	pocz[wyn[p]]++;
	kon[tab[wyn[1]]]++;
	for (int i=1; i<=n; i++)
	{
		if (jest[i])
			continue;
		zyje[i]=1;
		zyje[tab[i]]=1;
		pocz[i]++;
		kon[tab[i]]++;
	}
	int b=0;
	vi inte;
	for (int i=1; i<=n; i++)
	{
		b+=pocz[i]-kon[i];
		ret+=abs(b);
		if (b)
			uni(i, i+1);
		if (zyje[i])
			inte.push_back(i);
	}
	vector<pair<int,pii>> kra;
	for (int i=1; i<(int)inte.size(); i++)
	{
		int b=inte[i];
		int a=inte[i-1];
		if (fin(a)!=fin(b))
			kra.push_back({b-a, {a, b}});
	}
	sort(kra.begin(), kra.end());
	for (auto h : kra)
	{
		int a=h.second.first;
		int b=h.second.second;
		if (fin(a)!=fin(b))
		{
			ret+=h.first*2;
			uni(a, b);
		}
	}
	return ret;
}

void test()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		scanf("%d", &tab[i]);
		odw[tab[i]]=i;
	}
	wyn[1]=1;
	vi juz(n+1);
	juz[1]=1;
	int chce=solve(1);
	for (int h=2; h<=n; h++)
	{
		for (int i=1; i<=n; i++)
		{
			if (juz[i])
				continue;
			wyn[h]=i;
			if (solve(h)==chce)
			{
				juz[i]=1;
				break;
			}
		}
	}
	for (int i=1; i<=n; i++)
		printf("%d ", wyn[i]);
	printf("\n");
	//~ debug() << solve(1);
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}