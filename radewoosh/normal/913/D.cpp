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
using ll=long long;

int n;
ll t;

pair <int,ll> tab[nax];

vector <ll> wek[nax];

priority_queue <ll> kol;
ll s;

int wyn;

int dos[nax];

bool mniej(int a, int b)
{
	return tab[a].second<tab[b].second;
}

int main()
{
	scanf("%d%lld", &n, &t);
	for (int i=1; i<=n; i++)
	{
		scanf("%d%lld", &tab[i].first, &tab[i].second);
		wek[tab[i].first].push_back(tab[i].second);
		dos[i]=i;
	}
	for (int i=n; i; i--)
	{
		for (ll j : wek[i])
		{
			s+=j;
			kol.push(j);
		}
		while(s>t)
		{
			s-=kol.top();
			kol.pop();
		}
		wyn=max(wyn, min(i, (int)kol.size()));
	}
	printf("%d\n%d\n", wyn, wyn);
	int ile=wyn;
	sort(dos+1, dos+1+n, mniej);
	for (int i=1; i<=n && ile; i++)
	{
		int v=dos[i];
		if (tab[v].first>=wyn)
		{
			printf("%d ", v);
			ile--;
		}
	}
	printf("\n");
	return 0;
}