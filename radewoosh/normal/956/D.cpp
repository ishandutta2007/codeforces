//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
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
const int nax=100*1007;

int n;
ll w;

ll gdz[nax];
ll spe[nax];

struct U
{
	ll li;
	ll mi;
	void fix()
	{
		li=abs(li);
		mi=abs(mi);
	}
	void wyp()
	{
		debug() << li << "/" << mi;
	}
};

bool operator <(U a, U b)
{
	return a.li*b.mi<b.li*a.mi;
}

bool operator >(U a, U b)
{
	return a.li*b.mi>b.li*a.mi;
}

bool operator ==(U a, U b)
{
	return !(a<b || b<a);
}

U lew[nax];
U pra[nax];

ll wyn;

int pier[nax];
int kon[nax];

int per[nax];
int kie[nax];
int licz[nax];

bool mniej1(int a, int b)
{
	if (!(lew[a]==lew[b]))
		return lew[a]<lew[b];
	if (!(pra[a]==pra[b]))
		return pra[a]>pra[b];
	return a<b;
}

bool mniej2(int a, int b)
{
	if (!(pra[a]==pra[b]))
		return pra[a]<pra[b];
	if (!(lew[a]==lew[b]))
		return lew[a]>lew[b];
	return a>b;
}

int main()
{
	scanf("%d%lld", &n, &w);
	for (int i=1; i<=n; i++)
	{
		scanf("%lld%lld", &gdz[i], &spe[i]);
	}
	for (int i=1; i<=n; i++)
	{
		lew[i]=U{gdz[i], spe[i]-w};
		pra[i]=U{gdz[i], spe[i]+w};
		lew[i].fix();
		pra[i].fix();
		//~ if (pra[i]<lew[i])
			//~ swap(lew[i], pra[i]);
		debug() << i;
		lew[i].wyp();
		pra[i].wyp();
	}
	for (int i=1; i<=n; i++)
		pier[i]=kon[i]=i;
	
	sort(pier+1, pier+1+n, mniej1);
	sort(kon+1, kon+1+n, mniej2);
	
	debug() << range(pier+1, pier+1+n);
	debug() << range(kon+1, kon+1+n);
	
	for (int i=1; i<=n; i++)
		kie[kon[i]]=i;
	for (int i=1; i<=n; i++)
		per[i]=kie[pier[i]];
	debug() << range(per+1, per+1+n);
	
	for (int h=0; h<20; h++)
	{
		memset(licz, 0, sizeof(licz));
		for (int i=1; i<=n; i++)
		{
			if (!(per[i]&1))
				wyn+=licz[per[i]+1];
			else
				licz[per[i]]++;
			per[i]/=2;
		}
	}
	
	printf("%lld\n", wyn);
	return 0;
}