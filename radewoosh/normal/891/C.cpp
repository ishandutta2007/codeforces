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

const int nax=500*1007;

int n, m;

int ka[nax];
int kb[nax];
int war[nax];

vector <int> kub[nax];

int oj[nax];

int fin(int v)
{
	if (oj[v]!=v)
		oj[v]=fin(oj[v]);
	return oj[v];
}

void uni(int v, int u)
{
	v=fin(v);
	u=fin(u);
	oj[v]=u;
}

set <int> pozy;

void query()
{
	int x, y;
	scanf("%d", &x);
	vector <int> zap;
	pozy.clear();
	while(x--)
	{
		scanf("%d", &y);
		zap.push_back(y);
		kub[war[y]].clear();
		
	}
	int czyok=1;
	for (int i : zap)
	{
		pozy.insert(war[i]);
		kub[war[i]].push_back(i);
	}
	
	debug() << pozy;
	
	for (int i : pozy)
	{
		for (int j : kub[i])
		{
			oj[ka[j]]=ka[j];
			oj[kb[j]]=kb[j];
		}
		for (int j : kub[i])
		{
			if (fin(ka[j])==fin(kb[j]))
				czyok=0;
			uni(ka[j], kb[j]);
		}
	}
	
	if (czyok)
		printf("YES\n");
	else
		printf("NO\n");
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=m; i++)
	{
		scanf("%d%d%d", &ka[i], &kb[i], &war[i]);
		kub[war[i]].push_back(i);
	}
	debug() << "raz";
	for (int i=1; i<=n; i++)
		oj[i]=i;
	debug() << "dwa";
	for (int i=1; i<nax; i++)
	{
		for (int j : kub[i])
		{
			ka[j]=fin(ka[j]);
			kb[j]=fin(kb[j]);
		}
		for (int j : kub[i])
			uni(ka[j], kb[j]);
	}
	debug() << "trz";
	int q;
	scanf("%d", &q);
	while(q--)
		query();
	return 0;
}