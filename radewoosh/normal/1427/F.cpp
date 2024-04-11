//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
//~ #pragma GCC target ("avx2")
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
const int nax=1207;

int n;
int tab[nax];

vi graf[nax];

vi kto[nax];
int typ[nax];

vector<vi> wyn;

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=3*n; i++)
	{
		int x;
		scanf("%d", &x);
		tab[x]=1;
	}
	vector<pii> stos;
	stos.push_back({0, -1});
	int v=0;
	for (int i=1; i<=6*n; i++)
	{
		if (stos.back().second!=tab[i])
		{
			v++;
			typ[v]=tab[i];
			stos.push_back({v, tab[i]});
		}
		kto[stos.back().first].push_back(i);
		if ((int)kto[stos.back().first].size()==3)
		{
			int x=stos.back().first;
			stos.pop_back();
			graf[stos.back().first].push_back(x);
		}
	}
	assert(stos.size()==1);
	vi korz=graf[0];
	for (int h=0; !korz.empty(); h^=1)
	{
		int g=-1;
		for (int i=0; i<(int)korz.size(); i++)
			if (typ[korz[i]]==h && (g==-1 || graf[korz[g]].size()<graf[korz[i]].size()))
				g=i;
		assert(g>=0);
		int x=korz[g];
		swap(korz[g], korz.back());
		korz.pop_back();
		wyn.push_back(kto[x]);
		for (int i : graf[x])
			korz.push_back(i);
	}
	reverse(wyn.begin(), wyn.end());
	for (vi i : wyn)
		printf("%d %d %d\n", i[0], i[1], i[2]);
	return 0;
}