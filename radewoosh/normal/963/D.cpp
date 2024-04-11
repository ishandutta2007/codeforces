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
char wcz[nax];

int q;

char pom[nax];

int chce[nax];
vector <char> slo[nax];
int wyn[nax];

vector <int> kub[nax];

bitset <nax> lezy[30];
bitset <nax> pus, pel, trz;

int main()
{
	scanf("%s", wcz+1);
	n=strlen(wcz+1);
	scanf("%d", &q);
	for (int i=1; i<=q; i++)
	{
		scanf("%d", &chce[i]);
		scanf("%s", pom+1);
		for (int j=1; pom[j]; j++)
			slo[i].push_back(pom[j]);
	}
	for (int i=1; i<=n; i++)
		pel[i]=i;
	for (int i=1; i<=n; i++)
		lezy[wcz[i]-'a'][i]=1;
	for (int i=1; i<=q; i++)
	{
		trz=pel;
		for (int j=0; j<(int)slo[i].size(); j++)
			trz=(trz&(lezy[slo[i][j]-'a']>>j));
		vector <int> gdz;
		for (int pos = trz._Find_first(); pos != trz.size(); pos = trz._Find_next(pos))
			gdz.push_back(pos);
		if ((int)gdz.size()<chce[i])
			wyn[i]=-1;
		else
		{
			wyn[i]=nax;
			for (int j=chce[i]-1; j<(int)gdz.size(); j++)
				wyn[i]=min(wyn[i], gdz[j]-gdz[j-chce[i]+1]+(int)slo[i].size());
		}
	}
	
	for (int i=1; i<=q; i++)
		printf("%d\n", wyn[i]);
	return 0;
}