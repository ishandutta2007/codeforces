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
    tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

void ff()
{
	fflush(stdout);
}

void wiem(int v)
{
	if (v==1)
		printf("First\n");
	else
		printf("Second\n");
	ff();
}

int n;

vi wek[nax];
int jak[nax];

int bylo[nax];

int gdz[nax];

void ustal(int v)
{
	if (v==wek[gdz[v]][0])
		jak[gdz[v]]=0;
	else
		jak[gdz[v]]=1;
}

int shift(int v)
{
	if (v<=n)
		v+=n;
	else
		v-=n;
	return v;
}

void rob(int v)
{
	if (bylo[gdz[v]])
		return;
	bylo[gdz[v]]=1;
	ustal(v);
	v=shift(v);
	rob(wek[gdz[v]][0]^wek[gdz[v]][1]^v);
}

void wylosuj()
{
	for (int i=1; i<=n; i++)
		bylo[i]=0;
	for (int i=1; i<=n; i++)
		for (int j=0; j<2; j++)
			gdz[wek[i][j]]=i;
	for (int i=1; i<=n; i++)
	{
		if (bylo[i])
			continue;
		rob(wek[i][rand()&1]);
	}
	//~ debug() << range(jak+1, jak+1+n);
}

int main()
{
	srand(time(0));
	scanf("%d", &n);
	if (n%2==0)
	{
		wiem(1);
		for (int i=0; i<2*n; i++)
			printf("%d ", i%n+1);
		printf("\n");
		ff();
		return 0;
	}
	wiem(2);
	for (int i=1; i<=2*n; i++)
	{
		int x;
		scanf("%d", &x);
		wek[x].push_back(i);
	}
	while(1)
	{
		wylosuj();
		ll sum=0;
		for (int i=1; i<=n; i++)
			sum+=wek[i][jak[i]];
		if (!(sum%(2*n)))
			break;
	}
	for (int i=1; i<=n; i++)
		printf("%d ", wek[i][jak[i]]);
	printf("\n");
	ff();
	return 0;
}