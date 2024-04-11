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

const int nax=100*1007;
const long long inf=1007LL*1007*1007*1007*1007LL;

int n;

long long c[nax];

string s[nax][2];

long long dp[nax][2];

int main()
{
	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> c[i];
	for (int i=1; i<=n; i++)
	{
		cin >> s[i][0];
		s[i][1]=s[i][0];
		reverse(s[i][1].begin(), s[i][1].end());
	}
	dp[1][0]=0;
	dp[1][1]=c[1];
	for (int i=2; i<=n; i++)
	{
		for (int j=0; j<2; j++)
			dp[i][j]=inf;
		for (int j=0; j<2; j++)
			for (int l=0; l<2; l++)
				if (s[i][l]>=s[i-1][j])
					dp[i][l]=min(dp[i][l], dp[i-1][j]+l*c[i]);
	}
	long long wyn=min(dp[n][0], dp[n][1]);
	if (wyn==inf)
		wyn=-1;
	printf("%lld\n", wyn);
	return 0;
}