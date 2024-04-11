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
const long long inf=1e12;

struct lot
{
	int kied;
	int cel;
	long long kosz;
};

bool operator < (lot a, lot b)
{
	return a.kied<b.kied;
}

int n, m, k;

lot tab[nax];
long long pre[nax];
long long suf[nax];

long long wyn=inf;

long long aktu;
long long ile[nax];

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i=1; i<=m; i++)
	{
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		if (!b)
			b=-c;
		
		tab[i].kied=a;
		tab[i].cel=b;
		tab[i].kosz=d;
	}
	sort(tab+1, tab+1+m);
	
	aktu=n*inf;
	for (int i=1; i<=n; i++)
		ile[i]=inf;
	for (int i=1; i<=m; i++)
	{
		if (tab[i].cel<0)
		{
			pre[i]=aktu;
			continue;
		}
		aktu-=ile[tab[i].cel];
		ile[tab[i].cel]=min(ile[tab[i].cel], tab[i].kosz);
		aktu+=ile[tab[i].cel];
		pre[i]=aktu;
	}
	
	aktu=n*inf;
	for (int i=1; i<=n; i++)
		ile[i]=inf;
	for (int i=m; i; i--)
	{
		if (tab[i].cel>0)
		{
			suf[i]=aktu;
			continue;
		}
		aktu-=ile[-tab[i].cel];
		ile[-tab[i].cel]=min(ile[-tab[i].cel], tab[i].kosz);
		aktu+=ile[-tab[i].cel];
		suf[i]=aktu;
	}
	//debug() << range(pre+1, pre+1+m);
	//debug() << range(suf+1, suf+1+m);
	
	int w=1;
	
	for (int i=1; i<=m; i++)
	{
		while(w<=m && tab[i].kied+k>=tab[w].kied)
			w++;
		if (w>m)
			break;
		wyn=min(wyn, pre[i]+suf[w]);
	}
	if (wyn>=inf)
		wyn=-1;
	printf("%lld\n", wyn);
	
	return 0;
}