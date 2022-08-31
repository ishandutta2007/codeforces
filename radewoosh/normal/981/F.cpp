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
const int nax=2000*1007;

int n;
ll l;

ll taba[nax];
ll tabb[nax];

int pi[nax];
int ost[nax];
int zacz[nax];

deque <int> kol;

inline void wrzuc(int v)
{
	//~ debug() << "wrzut " << v;
	while(!kol.empty() && kol.back()<v)
		kol.pop_back();
	kol.push_back(v);
}

inline void usun(int v)
{
	//~ debug() << "usu " << v;
	//~ assert(!kol.empty());
	if (kol.front()==v)
		kol.pop_front();
}

int check(ll v)
{
	//~ debug() << "ter" << v;
	for (int i=n; i<5*n; i++)
	{
		pi[i]=pi[i-1];
		while(tabb[i]-v>taba[pi[i]])
			pi[i]++;
	}
	for (int i=2*n; i<4*n; i++)
	{
		ost[i]=ost[i-1];
		while(tabb[ost[i]+1]+v<taba[i])
			ost[i]++;
		
		zacz[i]=zacz[i-1];
		while(tabb[zacz[i]]-v<=taba[i])
			zacz[i]++;
	}
	//~ debug() << "juz";
	kol.clear();
	zacz[2*n-1]=0;
	ost[2*n-1]=-1;
	for (int i=2*n; i<4*n; i++)
	{
		zacz[i]-=n;
		zacz[i]=min(zacz[i], ost[i]);
	}
	for (int i=2*n; i<4*n; i++)
	{
		//~ zacz[i]-=n;
		//~ debug() << zacz[i] << " " << ost[i];
		for (int j=ost[i-1]+1; j<=ost[i]; j++)
			wrzuc(pi[j]-j);
		for (int j=zacz[i-1]; j<zacz[i]; j++)
			usun(pi[j]-j);
		if (!kol.empty() && kol.front()>i-ost[i]-1)
			return 0;
		//~ for (int j=zacz[i]; j<=ost[i]; j++)
			//~ if (pi[j]-j>i-ost[i]-1)
				//~ return 0;
	}
	return 1;
}

int main(int argc, char *argv[])
{
	//~ srand(atoi(argv[1]));
	scanf("%d%lld", &n, &l);
	for (int i=0; i<n; i++)
		scanf("%lld", &taba[i]);
	for (int i=0; i<n; i++)
		scanf("%lld", &tabb[i]);
	//~ for (int i=0; i<n; i++)
		//~ taba[i]=rand()%l;
	//~ for (int i=0; i<n; i++)
		//~ tabb[i]=rand()%l;
	sort(taba, taba+n);
	sort(tabb, tabb+n);
	for (int i=n; i<6*n; i++)
	{
		taba[i]=taba[i-n]+l;
		tabb[i]=tabb[i-n]+l;
	}
	ll bsa=0;
	ll bsb=l;
	ll bss;
	while(bsa<bsb)
	{
		bss=(bsa+bsb)>>1;
		if (check(bss))
			bsb=bss;
		else
			bsa=bss+1;
	}
	printf("%lld\n", bsa);
	return 0;
}