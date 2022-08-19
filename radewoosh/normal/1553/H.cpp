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
const int nax=2000*1007;
const int inf=1e9;

int n, k;

int tab[nax];

int jest[nax];

pair<vi,pair<vi,vi>> rek(int a, int b)
{
	if (a==b)
	{
		if (jest[a])
			return {{inf}, {{a}, {a}}};
		else
			return {{inf}, {{inf}, {-inf}}};
	}
	auto raz=rek(a, (a+b)>>1);
	auto dwa=rek((a+b+2)>>1, b);
	int r=raz.first.size();
	vi roz(2*r);
	vi ra(2*r);
	vi rb(2*r);
	for (int i=0; i<2*r; i++)
	{
		roz[i]=min(raz.first[i%r], dwa.first[i%r]);
	}
	for (int i=0; i<r; i++)
	{
		ra[i]=min(raz.second.first[i], dwa.second.first[i]);
		rb[i]=max(raz.second.second[i], dwa.second.second[i]);
		ra[i+r]=min(raz.second.first[i]+r, dwa.second.first[i]-r);
		rb[i+r]=max(raz.second.second[i]+r, dwa.second.second[i]-r);
		roz[i]=min(roz[i], dwa.second.first[i]-raz.second.second[i]);
		roz[i+r]=min(roz[i+r], raz.second.first[i]+r-(dwa.second.second[i]-r));
	}
	return {roz, {ra, rb}};
}

int main()
{
	scanf("%d%d", &n, &k);
	for (int i=1; i<=n; i++)
	{
		scanf("%d", &tab[i]);
		//~ tab[i]=rand()%(1<<k);
		jest[tab[i]]=1;
	}
	auto wez=rek(0, (1<<k)-1);
	for (int i : wez.first)
		printf("%d ", i);
	printf("\n");
	return 0;
}