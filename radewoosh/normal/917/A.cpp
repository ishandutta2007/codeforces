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

const int nax=5007;

int n;

char wcz[nax];
int wyn;

bitset <nax> psu[nax];

int main()
{
	scanf("%s", wcz+1);
	n=strlen(wcz+1);
	for (int i=1; i<=n; i++)
	{
		int bil=0;
		int tak=0;
		for (int j=i; j<=n; j++)
		{
			if (wcz[j]==')')
				bil--;
			else
				bil++;
			if (bil<0)
				tak=1;
			if (tak)
				psu[i][j]=1;
		}
		bil=0;
		tak=0;
		for (int j=i; j; j--)
		{
			if (wcz[j]=='(')
				bil--;
			else
				bil++;
			if (bil<0)
				tak=1;
			if (tak)
				psu[j][i]=1;
		}
	}
	for (int i=1; i<=n; i++)
		for (int j=i+1; j<=n; j+=2)
			if (!psu[i][j])
			{
				wyn++;
				//~ debug() << i << " " << j;
			}
	printf("%d\n", wyn);
	return 0;
}