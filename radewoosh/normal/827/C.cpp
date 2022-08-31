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

const int nax=1000*1007;
const int vax=30;
const int d=10;

int n;
char wcz[nax];

ordered_set <int> s[vax][vax][vax];

int q;

int wyn;

char wcz2[vax];

/*string readS()
{
	string ret="";
	scanf("%s", wcz);
	for (int i=0; wcz[i]; i++)
		ret.push_back(wcz[i]);
	return ret;
}*/

inline int kt(ordered_set <int> &ss, int u)
{
	if (ss.lower_bound(u)==ss.end())
		return ss.size();
	//debug() << " daje " << *ss.lower_bound(u) << " i " << ss.order_of_key(*ss.lower_bound(u));
	return ss.order_of_key(*ss.lower_bound(u));
}

inline int ile(int c, int pocz, int kon, int powta)
{
	if (pocz>kon)
		return 0;
	kon++;
	//debug() << kt(s[c][powta][pocz%powta], kon) << " - " << kt(s[c][powta][pocz%powta], pocz);
	return kt(s[c][powta][pocz%powta], kon)-kt(s[c][powta][pocz%powta], pocz);
}

inline int deco(char c)
{
	if (c=='T')
		return 0;
	if (c=='A')
		return 1;
	if (c=='C')
		return 2;
	if (c=='G')
		return 3;
}

int main()
{
	scanf("%s", wcz+1);
	n=strlen(wcz+1);
	for (int i=1; i<=n; i++)
		for (int j=1; j<=d; j++)
			s[deco(wcz[i])][j][i%j].insert(i);
	//debug() << s[1][2][0];
	//debug() << s[1][2][1];
	scanf("%d", &q);
	while(q--)
	{
		int typ;
		scanf("%d", &typ);
		if (typ==1)
		{
			int x;
			int sta, now;
			char w;
			scanf("%d %c", &x, &w);
			now=deco(w);
			sta=deco(wcz[x]);
			for (int j=1; j<=d; j++)
				s[sta][j][x%j].erase(x);
			for (int j=1; j<=d; j++)
				s[now][j][x%j].insert(x);
			wcz[x]=w;
		}
		else
		{
			wyn=0;
			int l, r;
			scanf("%d%d%s", &l, &r, wcz2);
			int dlu=strlen(wcz2);
			for (int j=0; j<dlu; j++)
			{
				int tu=deco(wcz2[j]);
				wyn+=ile(tu, l+j, r, dlu);
			}
			printf("%d\n", wyn);
		}
	}
	return 0;
}