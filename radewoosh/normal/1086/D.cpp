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

int n, q;

char wcz[nax];

ordered_set <int> setel[3];

int tlu(char c)
{
	if (c=='R')
		return 0;
	if (c=='S')
		return 1;
	if (c=='P')
		return 2;
	assert(0);
}

int pyt(int v, pii w)
{
	return setel[v].order_of_key(w.second+1)-setel[v].order_of_key(w.first);
}

int pyt2(int v, vector <pii> wek)
{
	if (wek.empty())
		return 0;
	if ((int)wek.size()==1)
		return pyt(v, wek[0]);
	if (wek[0]>wek[1])
		swap(wek[0], wek[1]);
	if (wek[0].second<wek[1].first)
		return pyt(v, wek[0])+pyt(v, wek[1]);
	return pyt(v, {wek[0].first, wek[1].second});
}

int ost(int v)
{
	auto it=setel[v].end();
	it--;
	return (*it);
}

int pier(int v)
{
	auto it=setel[v].begin();
	return (*it);
}

void calc()
{
	int wyn=n;
	for (int i=0; i<3; i++)
	{
		int prz=(i+2)%3;
		int pom=(i+1)%3;
		if (setel[prz].empty())
			continue;
		if (setel[pom].empty())
		{
			wyn-=(int)setel[i].size();
			continue;
		}
		vector <pii> daj;
		
		pii raz={ost(pom), ost(prz)};
		if (raz.first<=raz.second)
			daj.push_back(raz);
			
		pii dwa={pier(prz), pier(pom)};
		if (dwa.first<=dwa.second)
			daj.push_back(dwa);
		wyn-=pyt2(i, daj);
	}
	
	
	printf("%d\n", wyn);
}

int main()
{
	scanf("%d%d", &n, &q);
	scanf("%s", wcz+1);
	for (int i=1; i<=n; i++)
		setel[tlu(wcz[i])].insert(i);
	calc();
	while(q--)
	{
		int a;
		char b;
		scanf("%d %c", &a, &b);
		setel[tlu(wcz[a])].erase(a);
		wcz[a]=b;
		setel[tlu(wcz[a])].insert(a);
		calc();
	}
	return 0;
}