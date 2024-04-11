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
const ll inf=((ll)1e18)+7;

int n;
ll l;
ll tab[nax];

ll wyn=inf;

int main()
{
	scanf("%d%lld", &n, &l);
	for (int i=0; i<70; i++)
		tab[i]=inf;
	for (int i=0; i<n; i++)
		scanf("%lld", &tab[i]);
	for (int i=0; i<50; i++)
		tab[i+1]=min(tab[i+1], tab[i]*2);
	vector <int> wek;
	while(l)
	{
		wek.push_back(l&1);
		l>>=1;
	}
	int k=wek.size();
	for (int i=-1; i<50; i++)
	{
		ll ter=0;
		for (int j=max(i, 0); j<k; j++)
			ter+=tab[j]*wek[j];
		if (i>=0)
			ter+=tab[i];
		wyn=min(wyn, ter);
	}
	
	printf("%lld\n", wyn);
	return 0;
}