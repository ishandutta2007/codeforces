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
const int k=nax/2;

int n, c;

int tab[nax];

int wyn;

int mapa[nax];
int ile[nax];

void rek(int a, int b, int dod)
{
	if (a==b)
	{
		wyn=max(wyn, dod+1);
		return;
	}
	int s=(a+b)>>1;
	int lew=0;
	int pra=0;
	for (int i=a; i<=s; i++)
		lew+=(!tab[i]);
	for (int i=s+1; i<=b; i++)
		pra+=(!tab[i]);
	rek(a, s, dod+pra);
	rek(s+1, b, dod+lew);
	int juz=lew;
	for (int i=b; i>=a; i--)
		ile[tab[i]+k]=mapa[tab[i]+k]=0;
	for (int i=s; i>=a; i--)
	{
		if (!tab[i])
		{
			juz--;
		}
		else
		{
			ile[tab[i]+k]++;
			mapa[tab[i]+k]=max(mapa[tab[i]+k], ile[tab[i]+k]+juz);
		}
	}
	juz=pra;
	for (int i=s+1; i<=b; i++)
		ile[tab[i]+k]=0;
	for (int i=s+1; i<=b; i++)
	{
		if (!tab[i])
		{
			juz--;
		}
		else
		{
			ile[tab[i]+k]++;
			wyn=max(wyn, ile[tab[i]+k]+mapa[tab[i]+k]+juz+dod);
		}
	}
}

int main()
{
	scanf("%d%d", &n, &c);
	for (int i=1; i<=n; i++)
	{
		scanf("%d", &tab[i]);
		tab[i]-=c;
		wyn+=(!tab[i]);
	}
	rek(1, n, 0);
	
	printf("%d\n", wyn);
	return 0;
}