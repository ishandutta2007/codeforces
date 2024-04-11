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

const int nax=100*1007;

int n;

char typ[nax];
vector <int> wek[nax];

char wcz[nax];

int moz;

int wie;

int wyn;

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		scanf(" %c%s", &typ[i], wcz);
		for (int j=0; wcz[j]; j++)
			wek[i].push_back(wcz[j]-'a');
	}
	moz=(1<<26)-1;
	for (int i=1; i<n; i++)
	{
		if (typ[i]=='.')
		{
			if (wie)
			{
				
			}
			else
			{
				for (int j : wek[i])
					if (moz&(1<<j))
						moz^=(1<<j);
			}
		}
		if (typ[i]=='!')
		{
			if (wie)
			{
				wyn++;
			}
			else
			{
				int zbi=0;
				for (int j : wek[i])
					zbi|=(1<<j);
				moz&=zbi;
			}
		}
		if (typ[i]=='?')
		{
			if (wie)
				wyn++;
			if (moz&(1<<wek[i][0]))
				moz^=(1<<wek[i][0]);
		}
		if (__builtin_popcount(moz)==1)
			wie=1;
	}
	printf("%d\n", wyn);
	return 0;
}