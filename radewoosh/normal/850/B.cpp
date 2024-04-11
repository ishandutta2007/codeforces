//PRZEMYSL ASSERTY

//SPRAWDZ CORNER CASE'Y, MINIMALNE I MAKSYMALNE WEJCIE I WYJCIE

//MODULO = 1

//while (clock()<=69*CLOCKS_PER_SEC)

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

const int nax=2000*1007;
const long long inf=1e18;

int n;
long long x, y;

long long ile[nax];
long long suma[nax];

long long wyn;

inline long long mno(long long a, long long b)
{
	if (!a || !b)
		return 0;
	long long r=a*b;
	if ((r/a)!=b || (r/b)!=a)
		return inf;
	return min(r, inf);
}

inline long long dod(long long a, long long b)
{
	return min(a+b, inf);
}

long long polg;

long long mag;

inline long long odle(int v, int u)
{
	long long pol=ile[u]-ile[v-1];
	long long wsu=suma[u]-suma[v-1];
	polg-=pol;
	return u*pol-wsu;
}

int main()
{
	scanf("%d%lld%lld", &n, &x, &y);
	wyn=n*x;
	for (int i=1; i<=n; i++)
	{
		int p;
		scanf("%d", &p);
		ile[p]++;
		suma[p]+=p;
	}
	for (int i=1; i<nax; i++)
	{
		ile[i]+=ile[i-1];
		suma[i]+=suma[i-1];
	}
	int gr=x/y;
	for (int i=2; i<nax; i++)
	{
		long long tu=0;
		
		int r=gr;
		if (r>i-1)
			r=i-1;
			
		polg=n;
		mag=0;
		for (int j=i; j<nax; j+=i)
			mag=dod(mag, odle(j-r, j));
		mag=mno(mag, y);
		tu=dod(mag, mno(polg, x));
		wyn=min(wyn, tu);
	}
	printf("%lld\n", wyn);
	return 0;
}