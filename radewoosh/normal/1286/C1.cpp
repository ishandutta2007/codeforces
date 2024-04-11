//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
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
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
const int nax=107;
const int inf=1e9;

void ff()
{
	fflush(stdout);
}

int n;

map <string,int> mapa;

char wcz[nax];

string dlu[nax];

string czyt()
{
	scanf("%s", wcz+1);
	string ret="";
	for (int i=1; wcz[i]; i++)
		ret+=wcz[i];
	sort(ret.begin(), ret.end());
	return ret;
}

void pyt(int a, int b)
{
	printf("? %d %d\n", a, b);
	ff();
}

void odp(string s)
{
	cout << "! " << s << endl;
	ff();
	exit(0);
}

int main()
{
	scanf("%d", &n);
	pyt(1, n);
	if (n==1)
	{
		string w=czyt();
		odp(w);
	}
	for (int i=1; i<=n; i++)
		for (int j=i; j<=n; j++)
			mapa[czyt()]++;
	pyt(2, n);
	for (int i=2; i<=n; i++)
		for (int j=i; j<=n; j++)
			mapa[czyt()]--;
	for (auto i : mapa)
		if (i.second)
			dlu[i.first.size()]=i.first;
	string wyn="";
	for (int i=1; i<=n; i++)
	{
		map <char,int> pomoc;
		for (char j : dlu[i])
			pomoc[j]++;
		for (char j : dlu[i-1])
			pomoc[j]--;
		for (auto j : pomoc)
			if (j.second)
				wyn+=j.first;
	}
	odp(wyn);
	return 0;
}