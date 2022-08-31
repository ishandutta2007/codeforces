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

int n, k;
vector < pair<int,int> > graf[nax];

pair <int,int> dfs(int v, int oj)
{
	vector < pair<int,int> > wek;
	for (auto i : graf[v])
	{
		if (i.first==oj)
			continue;
		auto x=dfs(i.first, v);
		x.first+=i.second;
		x.second+=i.second;
		wek.push_back(x);
	}
	if ((int)wek.size()<k)
	{
		pair <int,int> ret={0,0};
		int naj=0;
		for (auto i : wek)
		{
			ret.first+=i.first;
			ret.second+=i.first;
			naj=max(naj, i.second-i.first);
		}
		ret.second+=naj;
		debug() << v << " zwraca1 " << ret;
		return ret;
	}
	pair <int,int> ret={0,0};
	sort(wek.begin(), wek.end());
	reverse(wek.begin(), wek.end());
	for (int i=0; i<k-1; i++)
		ret.first+=wek[i].first;
	for (int i=0; i<(int)wek.size(); i++)
	{
		if (i<k-1)
			ret.second=max(ret.second, ret.first+wek[i].second-wek[i].first+wek[k-1].first);
		else
			ret.second=max(ret.second, ret.first+wek[i].second);
	}
	debug() << v << " zwraca2 " << ret;
	return ret;
}

int main()
{
	scanf("%d%d", &n, &k);
	for (int i=1; i<n; i++)
	{
		int p1, p2, p3;
		scanf("%d%d%d", &p1, &p2, &p3);
		graf[p1].push_back({p2, p3});
		graf[p2].push_back({p1, p3});
	}
	printf("%d\n", dfs(0, 0).second);
	return 0;
}