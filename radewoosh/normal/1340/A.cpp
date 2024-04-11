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

int per[nax];
int gdz[nax];

int lew[nax];

void ans(int v)
{
	if (v)
		printf("Yes\n");
	else
		printf("No\n");
}

int on[nax];

void test()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		scanf("%d", &per[i]);
		gdz[per[i]]=i;
		on[i]=1;
	}
	set<pii> pozy;
	for (int i=0; i<=n+1; i++)
		pozy.insert({i, 1});
	multiset<int> wary;
	for (int i=1; i<=n; i++)
		wary.insert(1);
	for (int h=1; h<=n; h++)
	{
		int p=gdz[h];
		//~ debug() << h << " " << p;
		auto it=wary.end();
		it--;
		//~ debug() << p << " " << imie(*it) << " ";
		if (on[p]!=(*it))
		{
			ans(0);
			return;
		}
		auto pt=pozy.find({p, on[p]});
		auto kt=pt;
		kt++;
		pozy.erase(pt);
		wary.erase(wary.find(on[p]));
		if ((*kt).first<=n)
		{
			int v=(*kt).first;
			wary.erase(wary.find(on[v]));
			pozy.erase(kt);
			pozy.insert({v, on[v]+on[p]});
			on[v]+=on[p];
			wary.insert(on[v]);
			//~ debug() << v << " " << imie(on[v]);
		}
	}
	ans(1);
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}