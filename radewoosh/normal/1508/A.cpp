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

int n;

char wcz[3][nax];

void test()
{
	scanf("%d", &n);
	for (int h=0; h<3; h++)
		scanf("%s", wcz[h]+1);
	vector<int> wyn;
	vi wsk{1, 1, 1};
	while((int)wyn.size()<3*n)
	{
		if (wsk[0]<=2*n && wsk[1]<=2*n && wsk[2]<=2*n)
		{
			vi wek;
			for (int i=0; i<3; i++)
				wek.push_back(wcz[i][wsk[i]]-'0');
			sort(wek.begin(), wek.end());
			int x=wek[1];
			wyn.push_back(x);
			for (int i=0; i<3; i++)
				if (wcz[i][wsk[i]]-'0'==x)
					wsk[i]++;
			continue;
		}
		int bie=-1;
		int co=0;
		for (int i=0; i<3; i++)
		{
			if (wsk[i]==2*n+1)
				continue;
			if (wsk[i]>bie)
			{
				bie=wsk[i];
				co=wcz[i][wsk[i]]-'0';
			}
		}
		wyn.push_back(co);
		for (int i=0; i<3; i++)
			if (wsk[i]<=2*n && wcz[i][wsk[i]]-'0'==co)
				wsk[i]++;
	}
	for (int i : wyn)
		printf("%d", i);
	printf("\n");
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}