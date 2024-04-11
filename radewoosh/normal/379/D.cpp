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
const int nax=107;
const ll mod=1000*1000*1000+7;

void nope()
{
	printf("Happy new year!\n");
	exit(0);
}

int k, x, n, m;

vector<string> zbi[nax];

set<vll> juz[nax];

vll opisz(string s)
{
	if (s.empty())
		return {};
	int pocz=(s[0]=='C');
	int kon=(s.back()=='A');
	int ile=0;
	for (int i=1; i<(int)s.size(); i++)
		if (s[i-1]=='A' && s[i]=='C')
			ile++;
	return {pocz, kon, ile};
}

void rek(int v, string s)
{
	if (v==nax)
		return;
	vll wez=opisz(s);
	if (juz[v].count(wez))
		return;
	juz[v].insert(wez);
	zbi[v].push_back(s);
	for (char i='A'; i<='C'; i++)
	{
		s.push_back(i);
		rek(v+1, s);
		s.pop_back();
	}
}

vll tu[nax];

vll lacz(vll a, vll b)
{
	vll ret(3);
	ret[2]=a[2]+b[2];
	ret[0]=a[0];
	ret[1]=b[1];
	ret[2]+=(a[1] && b[0]);
	return ret;
}

int main()
{
	scanf("%d%d%d%d", &k, &x, &n, &m);
	rek(0, "");
	for (string i : zbi[n])
	{
		for (string j : zbi[m])
		{
			tu[1]=opisz(i);
			tu[2]=opisz(j);
			for (int l=3; l<=k; l++)
				tu[l]=lacz(tu[l-2], tu[l-1]);
			if (tu[k][2]==x)
			{
				cout << i << endl << j << endl;
				return 0;
			}
		}
	}
	nope();
	return 0;
}