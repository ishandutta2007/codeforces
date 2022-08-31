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

const int nax=1000*1007;
using ll=long long;

int n;

ll tab[nax];

ll bsa, bsb, bss;

set <ll> poz;

void przytnij(ll v, ll odl)
{
	while(!poz.empty())
	{
		auto it=poz.begin();
		if (v-(*it)>odl)
			poz.erase(it);
		else
			break;
	}
	while(!poz.empty())
	{
		auto it=poz.end();
		it--;
		if ((*it)-v>odl)
			poz.erase(it);
		else
			break;
	}
}

int check(ll v)
{
	poz.clear();
	poz.insert(tab[1]);
	for (int i=3; i<=n; i++)
	{
		ll ter=tab[i];
		int czy=0;
		if (abs(tab[i]-tab[i-1])<=v)
			czy=1;
		
		przytnij(ter, v);
		if (czy)
			poz.insert(tab[i-1]);
		
		//debug() << i << " " << poz << " " << czy;
		
		if (poz.empty())
			return 0;
	}
	return 1;
}

int main()
{
	scanf("%d", &n);
	n+=2;
	for (int i=1; i<=n; i++)
		scanf("%lld", &tab[i]);
	bsa=(abs(tab[1]-tab[2]));
	bsb=1007*1007*1007;
	//bsb=2;
	while(bsa<bsb)
	{
		bss=(bsa+bsb)/2;
		if (check(bss))
			bsb=bss;
		else
			bsa=bss+1;
	}
	printf("%lld\n", bsa);
	return 0;
}