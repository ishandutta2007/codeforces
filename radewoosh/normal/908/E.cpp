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

const int nax=1007;
using ll=long long;
const ll mod=1000*1000*1000+7;

int n, m;

char wcz[nax][nax];

ll tab[nax];

ll wyn=1;

map <ll,int> mapa;

ll kom[nax][nax];
ll bell[nax];

int main()
{
	scanf("%d%d", &n, &m);
	for (int i=0; i<m; i++)
		scanf("%s", wcz[i]);
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<m; j++)
			tab[i]=tab[i]*2+(wcz[j][i]-'0');
		mapa[tab[i]]++;
	}
	for (int i=0; i<=n; i++)
	{
		kom[i][0]=1;
		for (int j=1; j<=i; j++)
			kom[i][j]=(kom[i-1][j-1]+kom[i-1][j])%mod;
	}
	bell[0]=1;
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<=i; j++)
			bell[i+1]=(bell[i+1]+kom[i][j]*bell[j])%mod;
		//~ debug() << i+1 << " " << bell[i+1];
	}
	for (auto i : mapa)
	{
		//~ debug() << i.second;
		wyn=(wyn*bell[i.second])%mod;
	}
	printf("%lld\n", wyn);
	return 0;
}