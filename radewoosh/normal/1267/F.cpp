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

int n, m, ka, kb;

int taba[nax];
int tabb[nax];

void nope()
{
	printf("No\n");
	exit(0);
}

int ile[nax];

vector <pii> wyn;

priority_queue <int> kol;

void zmni(int v)
{
	ile[v]--;
	if (!ile[v])
		kol.push(-v);
}

int main()
{
	scanf("%d%d%d%d", &n, &m, &ka, &kb);
	if (ka>=m || kb>=n)
		nope();
	for (int i=1; i<=ka; i++)
		scanf("%d", &taba[i]);
	for (int i=1; i<=kb; i++)
		scanf("%d", &tabb[i]);
	while(ka+1<m)
	{
		ka++;
		taba[ka]=n;
	}
	while(kb+1<n)
	{
		kb++;
		tabb[kb]=n+m;
	}
	for (int i=1; i<=m-1; i++)
		ile[taba[i]]++;
	for (int i=1; i<=n-1; i++)
		ile[tabb[i]]++;
	for (int i=1; i<=n+m; i++)
		if (!ile[i])
			kol.push(-i);
	int a=0;
	int b=0;
	while(a<ka || b<kb)
	{
		int v=-kol.top();
		kol.pop();
		//~ debug() << a << " " << b << "   " << v;
		if (v<=n)
		{
			b++;
			wyn.push_back({v, tabb[b]});
			zmni(v);
			zmni(tabb[b]);
		}
		else
		{
			a++;
			wyn.push_back({v, taba[a]});
			zmni(v);
			zmni(taba[a]);
		}
	}
	vi zbi;
	zbi.push_back(-kol.top());
	kol.pop();
	zbi.push_back(-kol.top());
	kol.pop();
	wyn.push_back({zbi[0], zbi[1]});
	printf("Yes\n");
	for (pii i : wyn)
		printf("%d %d\n", i.first, i.second);
	return 0;
}