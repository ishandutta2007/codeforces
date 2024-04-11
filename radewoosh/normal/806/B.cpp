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

const int nax=127;
const int dax=12;
const int d=4000;
const long long inf=1000*1000*1007;

int n;

int tab[nax][dax];

int trze[]={1, 2, 4, 8, 16, 32, 1000*100};
int war[]={500, 1000, 1500, 2000, 2500, 3000};

int wyn=inf;

int chce[dax];

int zro[dax];

void check()
{
	int jed=0;
	int dwa=0;
	for (int i=0; i<5; i++)
	{
		if (tab[1][i]==-1)
			continue;
		jed+=war[chce[i]]-(tab[1][i]*war[chce[i]])/250;
	}
	for (int i=0; i<5; i++)
	{
		if (tab[2][i]==-1)
			continue;
		dwa+=war[chce[i]]-(tab[2][i]*war[chce[i]])/250;
	}
	if (jed<=dwa)
		return;
	for (int i=0; i<=d; i++)
	{
		int ok=1;
		for (int j=0; j<5; j++)
		{
			if (!zro[j])
				continue;
			if (!(zro[j]*trze[chce[j]]<=(n+i)))
				ok=0;
			if (!((zro[j]+i)*trze[chce[j]+1]>(n+i)))
				ok=0;
			if (tab[1][j]==-1 && !(zro[j]*trze[chce[j]+1]>(n+i)))
			{
				ok=-1;
				break;
			}
		}
		if (!ok)
			continue;
		if (ok==-1)
			break;
		wyn=min(wyn, i);
		break;
	}
}

void rek(int v)
{
	if (v==5)
	{
		check();
		return;
	}
	for (int i=0; i<6; i++)
	{
		chce[v]=i;
		rek(v+1);
	}
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		for (int j=0; j<5; j++)
		{
			scanf("%d", &tab[i][j]);
			zro[j]+=(tab[i][j]!=-1);
		}
	rek(0);
	if (wyn==inf)
		wyn=-1;
	printf("%d\n", wyn);
	return 0;
}