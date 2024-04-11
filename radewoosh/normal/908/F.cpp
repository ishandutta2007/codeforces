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

const int nax=300*1007;
using ll=long long;
const ll mod=1000*1000*1000+7;

int n;

ll tab[nax];
int typ[nax];

vector <int> wek[3];

ll wyn;

vector <ll> pozy[3];

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		char c;
		scanf("%lld %c", &tab[i], &c);
		if (c=='G')
			typ[i]=0;
		if (c=='R')
			typ[i]=1;
		if (c=='B')
			typ[i]=2;
		wek[typ[i]].push_back(i);
	}
	if (wek[0].empty())
	{
		for (int i=1; i<3; i++)
			if (!wek[i].empty())
				wyn+=tab[wek[i].back()]-tab[wek[i][0]];
		printf("%lld\n", wyn);
		return 0;
	}
	int k=wek[0].size();
	for (int i=1; i<k; i++)
	{
		pozy[1].clear();
		pozy[2].clear();
		ll ost[]={0, tab[wek[0][i-1]], tab[wek[0][i-1]]};
		for (int j=wek[0][i-1]+1; j<wek[0][i]; j++)
		{
			pozy[typ[j]].push_back(tab[j]-ost[typ[j]]);
			ost[typ[j]]=tab[j];
		}
		pozy[1].push_back(tab[wek[0][i]]-ost[1]);
		pozy[2].push_back(tab[wek[0][i]]-ost[2]);
		ll kum=0;
		for (int h=1; h<=2; h++)
		{
			debug() << pozy[h];
			sort(pozy[h].begin(), pozy[h].end());
			for (int j=0; j+1<(int)pozy[h].size(); j++)
				wyn+=pozy[h][j];
			kum+=pozy[h].back();
		}
		wyn+=min(kum, tab[wek[0][i]]-tab[wek[0][i-1]]);
	}
	for (int h=1; h<=2; h++)
	{
		if (wek[h].empty())
			continue;
		if (wek[h][0]<wek[0][0])
			wyn+=tab[wek[0][0]]-tab[wek[h][0]];
		if (wek[h].back()>wek[0].back())
			wyn-=tab[wek[0].back()]-tab[wek[h].back()];
	}
	printf("%lld\n", wyn);
	return 0;
}