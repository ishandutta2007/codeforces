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

const int nax=2000*1007;

char wcz[nax];

int n;

int d;

int dlu[nax];
string slo[nax];
vector <int> wys[nax];

char wyn[nax];

int co=-1;
int gdz;

string readS()
{
	string ret="";
	scanf("%s", wcz);
	for (int i=0; wcz[i]; i++)
		ret.push_back(wcz[i]);
	return ret;
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		slo[i]=readS();
		dlu[i]=slo[i].size();
		int x;
		scanf("%d", &x);
		while(x--)
		{
			int y;
			scanf("%d", &y);
			y--;
			d=max(d, dlu[i]+y);
			wys[y].push_back(i);
		}
		debug() << i << " " << slo[i];
	}
	for (int i=0; i<d; i++)
		wyn[i]='a';
	for (int i=0; i<d; i++)
	{
		for (int j : wys[i])
		{
			if (co==-1 || i+dlu[j]>dlu[co]+gdz)
			{
				co=j;
				gdz=i;
			}
		}
		if (co!=-1 && gdz+dlu[co]>i)
		{
			debug() << "tak";
			wyn[i]=slo[co][i-gdz];
		}
		debug() << i << " " << co << " " << gdz;
	}
	for (int i=0; i<d; i++)
		printf("%c", wyn[i]);
	printf("\n");
	return 0;
}