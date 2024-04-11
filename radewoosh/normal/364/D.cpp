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

const int nax=1000*1007;

int n;

long long tab[nax];

long long wyn;

int mapa1[nax];
int mapa2[nax];

vector <long long> wek;

long long x, y;

int &mapa(long long v)
{
	if (v<nax)
		return mapa1[v];
	return mapa2[x/v];
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		scanf("%lld", &tab[i]);
	while(clock()<=3.4*CLOCKS_PER_SEC)
	{
		x=tab[(rand()*100LL+rand())%n+1];
		memset(mapa1, 0, sizeof(mapa1));
		memset(mapa2, 0, sizeof(mapa2));
		for (int i=1; i<=n; i++)
			mapa(__gcd(tab[i], x))++;
		wek.clear();
		for (int i=1; i<nax; i++)
			if (mapa1[i])
				wek.push_back(i);
		for (int i=1; i<nax; i++)
			if (mapa2[i])
				wek.push_back(x/i);
		for (long long i : wek)
		{
			int zbi=0;
			for (long long j : wek)
				if (!(j%i))
					zbi+=mapa(j);
			if (zbi*2>=n)
				wyn=max(wyn, i);
		}
	}
	printf("%lld\n", wyn);
	return 0;
}