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

int n;
int p[nax];

int juz[nax];

vector <int> wek[5];

bool mniej(int a, int b)
{
	return p[a]>p[b];
}

void czys()
{
	for (int i=1; i<=3; i++)
		while(!wek[i].empty() && juz[wek[i].back()])
			wek[i].pop_back();
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		scanf("%d", &p[i]);
	}
	for (int i=1; i<=n; i++)
	{
		int a;
		scanf("%d", &a);
		wek[a].push_back(i);
	}
	for (int i=1; i<=n; i++)
	{
		int a;
		scanf("%d", &a);
		wek[a].push_back(i);
	}
	for (int i=1; i<=3; i++)
		sort(wek[i].begin(), wek[i].end(), mniej);
	int m;
	scanf("%d", &m);
	while(m--)
	{
		int x;
		scanf("%d", &x);
		czys();
		if (wek[x].empty())
		{
			printf("-1 ");
		}
		else
		{
			printf("%d ", p[wek[x].back()]);
			juz[wek[x].back()]=1;
		}
	}
	printf("\n");
	return 0;
}