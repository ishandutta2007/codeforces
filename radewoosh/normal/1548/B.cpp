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
ll tab[nax];

int wyn;

void rek(int a, int b)
{
	if (a==b)
		return;
	int s=(a+b)/2;
	rek(a, s);
	rek(s+1, b);
	//~ ll r=tab[s];
	//~ ll g=abs(tab[s+1]-r);
	ll r, g;
	if (tab[s]<tab[r])
	{
		r=tab[s];
		g=abs(tab[s+1]-r);
	}
	else
	{
		r=tab[s+1];
		g=abs(tab[s]-r);
	}
	if (g==1)
		return;
	vector<pll> lew, pra;
	ll pam=g;
	for (int i=s; i>=a; i--)
	{
		ll x=__gcd(abs(tab[i]-r), pam);
		if (x!=pam)
		{
			lew.push_back({pam, s-i});
			pam=x;
		}
	}
	lew.push_back({pam, s-a+1});
	pam=g;
	for (int i=s+1; i<=b; i++)
	{
		ll x=__gcd(abs(tab[i]-r), pam);
		if (x!=pam)
		{
			pra.push_back({pam, i-s-1});
			pam=x;
		}
	}
	pra.push_back({pam, b-s});
	for (pll i : lew)
		for (pll j : pra)
			if (__gcd(i.first, j.first)!=1)
				wyn=max((ll)wyn, i.second+j.second);
}

void test()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		scanf("%lld", &tab[i]);
	if (n==1)
	{
		printf("1\n");
		return;
	}
	wyn=1;
	rek(1, n);
	printf("%d\n", wyn);
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}