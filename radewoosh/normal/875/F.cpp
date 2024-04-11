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

const int nax=1000*1007;

int n, m;

pair <int,int> kra[nax];
int kosz[nax];
int dos[nax];

int hack[nax];

long long wyn;

int oj[nax];

bool mniej(int a, int b)
{
	return kosz[a]>kosz[b];
}

int fin(int v)
{
	if (v!=oj[v])
		oj[v]=fin(oj[v]);
	return oj[v];
}

void uni(int a, int b)
{
	a=fin(a);
	b=fin(b);
	oj[a]=b;
	hack[b]|=hack[a];
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=m; i++)
	{
		scanf("%d%d%d", &kra[i].first, &kra[i].second, &kosz[i]);
		dos[i]=i;
	}
	for (int i=1; i<=n; i++)
		oj[i]=i;
	sort(dos+1, dos+1+m, mniej);
	for (int h=1; h<=m; h++)
	{
		int i=dos[h];
		int x=fin(kra[i].first);
		int y=fin(kra[i].second);
		if (x==y)
		{
			if (!hack[x])
			{
				hack[x]=1;
				wyn+=kosz[i];
			}
			continue;
		}
		if (hack[x] && hack[y])
			continue;
		uni(x, y);
		wyn+=kosz[i];
	}
	printf("%lld\n", wyn);
	return 0;
}