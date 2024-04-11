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

ll licz(vll wek)
{
	int k=wek.size();
	ll wyn=1;
	int mam=0;
	for (int i=2; 1; i++)
	{
		while(!wek.empty() && wek.back()<i)
		{
			wek.pop_back();
			mam++;
		}
		wyn*=mam;
		mam--;
		k--;
		if (!k)
			break;
	}
	return wyn;
}

void test()
{
	ll n;
	scanf("%lld", &n);
	vll wek;
	for (int i=2; n; i++)
	{
		wek.push_back(n%i);
		n/=i;
	}
	sort(wek.begin(), wek.end());
	reverse(wek.begin(), wek.end());
	ll mno=1;
	ll ost=-1;
	ll ile=0;
	for (ll i : wek)
	{
		if (i!=ost)
		{
			ost=i;
			ile=0;
		}
		ile++;
		mno*=ile;
	}
	ll wyn=licz(wek)/mno;
	if (!wek.back())
	{
		ll jest=0;
		for (ll i : wek)
			if (!i)
				jest++;
		wek.pop_back();
		wyn-=licz(wek)*jest/mno;
	}
	//~ debug() << wyn << " " << mno;
	//~ printf("%lld\n", wyn/mno-1);
	printf("%lld\n", wyn-1);
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}