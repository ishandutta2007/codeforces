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

using ll=long long;
const int nax=1000*1007;

int n=1;

int q;

int odl[nax];

ll tab[nax];
int oj[nax];

vector < pair <int,ll> > jump[nax];

int last;

void dodaj(int v, ll w)
{
	for (int i=20; i>=0; i--)
		if (i<(int)jump[v].size() && jump[v][i].first && tab[jump[v][i].first]<w)
			v=jump[v][i].first;
	if (tab[v]<w)
		v=oj[v];
	n++;
	
	//~ debug() << n << " " << v << " " << w;
	
	odl[n]=odl[v]+1;
	oj[n]=v;
	tab[n]=w;
	jump[n].push_back({v, w});
	while(jump[n].back().first)
	{
		int p1=jump[n].back().first;
		int p2=min(jump[n].size(), jump[p1].size())-1;
		ll mag=jump[n].back().second+jump[p1][p2].second;
		jump[n].push_back({jump[p1][p2].first, mag});
	}
	//~ debug() << n << " " << jump[n];
}

void pytaj(int v, ll w)
{
	//~ debug() << v << "  " << w;
	int sta=v;
	for (int i=20; i>=0; i--)
	{
		if (i<(int)jump[v].size() && jump[v][i].second<=w)
		{
			w-=jump[v][i].second;
			v=jump[v][i].first;
		}
	}
	last=odl[sta]-odl[v];
	printf("%d\n", last);
}

int main()
{
	tab[0]=-1;
	jump[1].push_back({0, 0});
	odl[1]=1;
	scanf("%d", &q);
	while(q--)
	{
		int typ;
		ll p, q;
		scanf("%d%lld%lld", &typ, &p, &q);
		p^=last;
		q^=last;
		if (typ==1)
			dodaj(p, q);
		else
			pytaj(p, q);
	}
	return 0;
}