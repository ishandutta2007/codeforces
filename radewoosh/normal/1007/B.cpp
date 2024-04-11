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
const int nax=200*1007;

ll dz[nax];

ll kwa(ll v)
{
	return v*v;
}

ll komb(ll v, int ile)
{
	ll ret=1;
	for (int i=1; i<=ile; i++)
		ret*=(v-1+i);
	for (int i=1; i<=ile; i++)
		ret/=i;
	return ret;
}

vector <ll> jed, dwa;
	
void test()
{
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	debug() << a << " " << b << " " << c;
	ll wyn=0;
	//~ wyn+=dz[a]*dz[b]*dz[c];
	//~ wyn-=dz[a]*komb(dz[__gcd(b, c)], 2);
	//~ wyn-=dz[b]*komb(dz[__gcd(a, c)], 2);
	//~ wyn-=dz[c]*komb(dz[__gcd(a, b)], 2);
	//~ wyn+=komb(dz[__gcd(__gcd(a, b), c)], 3)*4;
	jed.clear();
	dwa.clear();
	ll wsz;
	jed.push_back(dz[a]);
	jed.push_back(dz[b]);
	jed.push_back(dz[c]);
	dwa.push_back(dz[__gcd(b, c)]);
	//~ debug() << dwa << __gcd(b, c);
	dwa.push_back(dz[__gcd(c, a)]);
	//~ debug() << dwa << __gcd(c, a);
	dwa.push_back(dz[__gcd(a, b)]);
	//~ debug() << dwa << __gcd(a, c);
	wsz=dz[__gcd(__gcd(a, b), c)];
	debug() << jed << dwa << wsz;
	for (int i=0; i<3; i++)
		dwa[i]-=wsz;
	for (int i=0; i<3; i++)
	{
		jed[i]-=wsz;
		for (int j=0; j<2; j++)
			jed[i]-=dwa[(i+1+j)%3];
	}
	debug() << jed << dwa << wsz;
	wyn+=jed[0]*jed[1]*jed[2];
	for (int i=0; i<3; i++)
	{
		for (int j=1; j<3; j++)
			wyn+=dwa[(i+j)%3]*jed[(i+1)%3]*jed[(i+2)%3];
	}
	for (int i=0; i<3; i++)
	{
		//~ for (int j=1; j<2; j++)
		wyn+=wsz*jed[(i+1)%3]*jed[(i+2)%3];
	}
	for (int i=0; i<3; i++)
	{
		for (int j=0; j<3; j++)
			wyn+=jed[i]*dwa[(i+j)%3]*dwa[(i+j+1)%3];
		for (int j=0; j<3; j++)
			wyn+=jed[i]*wsz*dwa[j];
		wyn+=dwa[i]*dwa[(i+1)%3]*wsz;
	}
	wyn+=komb(wsz, 3);
	for (int i=0; i<3; i++)
	{
		wyn+=jed[i]*komb(wsz, 2);
		wyn+=dwa[i]*komb(wsz, 2);
		wyn+=komb(dwa[i], 2)*wsz;
		//~ for (int j=0; j<3; j++)
		wyn+=jed[i]*komb(dwa[i], 2);
	}
	wyn+=dwa[0]*dwa[1]*dwa[2];
	for (int i=0; i<3; i++)
		for (int j=0; j<3; j++)
			if (i!=j)
				wyn+=komb(dwa[i], 2)*dwa[j];
	
	printf("%lld\n", wyn);
}

int main()
{
	for (int i=1; i<nax; i++)
		for (int j=i; j<nax; j+=i)
			dz[j]++;
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}