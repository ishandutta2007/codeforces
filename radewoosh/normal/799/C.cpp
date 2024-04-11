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

const int nax=100*1007;

int n;

int mam[2];

vector < pair <int,int> > wek[2];
char wcz[3];

int wyn;

int naj[]={-1, -1};

int main()
{
	scanf("%d%d%d", &n, &mam[0], &mam[1]);
	for (int i=1; i<=n; i++)
	{
		int p1, p2;
		scanf("%d%d%s", &p1, &p2, wcz);
		wek[wcz[0]=='D'].push_back({p1, p2});
	}
	for (int h=0; h<2; h++)
	{
		for (auto i : wek[h])
		{
			if (i.second<=mam[h])
			{
				naj[h]=max(naj[h], i.first);
			}
		}
	}
	if (naj[0]>=0 && naj[1]>=0)
		wyn=max(wyn, naj[0]+naj[1]);
	
	for (int h=0; h<2; h++)
	{
		vector < pair <int,int> > stos;
		sort(wek[h].begin(), wek[h].end());
		for (int i=0; i<(int)wek[h].size(); i++)
		{
			int bsa=-1;
			int bsb=(int)stos.size()-1;
			int bss;
			while(bsa<bsb)
			{
				bss=(bsa+bsb+2)>>1;
				if (wek[h][i].second+stos[bss].second<=mam[h])
					bsa=bss;
				else
					bsb=bss-1;
			}
			if (bsa!=-1)
				wyn=max(wyn, wek[h][i].first+stos[bsa].first);
			while(!stos.empty() && wek[h][i].second<stos.back().second)
				stos.pop_back();
			stos.push_back(wek[h][i]);
		}
	}
	
	printf("%d\n", wyn);
	return 0;
}