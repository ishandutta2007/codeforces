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
const int d=600*1000+7;

int n;

pii tab[nax];

char wcz[nax];

vector<pii> waz;

pii czyt()
{
	scanf("%s", wcz+1);
	int a=0;
	int b=0;
	for (int i=1; wcz[i]; i++)
	{
		if (wcz[i]=='B')
			a++;
		else
			b++;
	}
	return {a, b};
}

int odl(pii a, pii b)
{
	if (a>b)
		swap(a, b);
	if (b.second>=a.second)
		return max(b.first-a.first, b.second-a.second);
	return (b.first-a.first)+(a.second-b.second);
}

void wypisz(int w, pii v)
{
	printf("%d\n", w);
	for (int i=1; i<=v.first; i++)
		printf("B");
	for (int i=1; i<=v.second; i++)
		printf("N");
	printf("\n");
	exit(0);
}

int eval(pii v)
{
	int ret=0;
	for (pii i : waz)
		ret=max(ret, odl(i, v));
	return ret;
}

int best=nax;
pii jak;

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		tab[i]=czyt();
	//~ debug() << range(tab+1, tab+1+n);
	for (int a=-1; a<=1; a++)
	{
		for (int b=-1; b<=1; b++)
		{
			if (!a && !b)
				continue;
			int g=1;
			for (int i=1; i<=n; i++)
				if (tab[i].first*a+tab[i].second*b<tab[g].first*a+tab[g].second*b)
					g=i;
			waz.push_back(tab[g]);
		}
	}
	for (int i=1; i<=d; i++)
	{
		//~ if (!(i%100))
			//~ debug() << imie(i);
		int tsa=0;
		int tsb=i;
		while(tsa+3<tsb)
		{
			int ts1=(tsa+tsb)/2;
			int ts2=ts1+1;
			if (eval({i-ts1, ts1})<eval({i-ts2, ts2}))
				tsb=ts2;
			else
				tsa=ts1;
		}
		for (int j=tsa; j<=tsb; j++)
		{
			pii x={i-j, j};
			if (eval(x)<best)
			{
				best=eval(x);
				jak=x;
			}
		}
	}
	
	wypisz(best, jak);
	return 0;
}