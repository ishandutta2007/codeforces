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

map <int,int> mapa;

int fast(int v)
{
	if (mapa.count(v))
		return mapa[v];
	int ret=0;
	for (int i=1; i<=v-i; i++)
		ret=max(ret, __gcd(v&i, v^i));
	return mapa[v]=ret;
}

void test()
{
	int n;
	scanf("%d", &n);
	vi wek;
	int m=n;
	while(m)
	{
		wek.push_back(m&1);
		m>>=1;
	}
	int czy=0;
	for (int i : wek)
		if (!i)
			czy=1;
	if (czy)
	{
		int w=(1<<(int)wek.size())-1;
		printf("%d\n", w);
		return;
	}
	printf("%d\n", fast(n));
}

int main()
{   mapa[1]=0;
   mapa[3]=1;
   mapa[7]=1;
   mapa[15]=5;
   mapa[31]=1;
   mapa[63]=21;
   mapa[127]=1;
   mapa[255]=85;
   mapa[511]=73;
   mapa[1023]=341;
   mapa[2047]=89;
   mapa[4095]=1365;
   mapa[8191]=1;
   mapa[16383]=5461;
   mapa[32767]=4681;
   mapa[65535]=21845;
   mapa[131071]=1;
   mapa[262143]=87381;
   mapa[524287]=1;
   mapa[1048575]=349525;
   mapa[2097151]=299593;
   mapa[4194303]=1398101;
   mapa[8388607]=178481;
   mapa[16777215]=5592405;
   mapa[33554431]=1082401;
   mapa[67108863]=22369621;
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}