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
const int nax=1000*1007;
const int d=26;

void nope()
{
	printf("NO\n");
}

int n;
char wcz[nax];

set <int> graf[nax];

void test()
{
	scanf("%s", wcz+1);
	n=strlen(wcz+1);
	for (int i=0; i<d; i++)
		graf[i].clear();
	for (int i=1; i<n; i++)
	{
		int a=wcz[i]-'a';
		int b=wcz[i+1]-'a';
		graf[a].insert(b);
		graf[b].insert(a);
	}
	int nie=0;
	for (int i=0; i<d; i++)
		if ((int)graf[i].size()>2)
			nie=1;
	if (nie)
	{
		nope();
		return;
	}
	vi jesz(d);
	vector <char> wyn;
	for (int i=0; i<d; i++)
	{
		if (jesz[i] || (int)graf[i].size()==2)
			continue;
		int ost=-1;
		int v=i;
		while(1)
		{
			int u=-1;
			wyn.push_back(v+'a');
			jesz[v]=1;
			for (int j : graf[v])
				if (j!=ost)
					u=j;
			if (u==-1)
				break;
			ost=v;
			v=u;
		}
	}
	if ((int)wyn.size()<d)
	{
		nope();
		return;
	}
	printf("YES\n");
	for (char i : wyn)
		printf("%c", i);
	printf("\n");
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int i=1; i<=t; i++)
		test();
	return 0;
}