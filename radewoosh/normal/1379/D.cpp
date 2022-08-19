//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
//~ #pragma GCC optimize("O3")
#pragma GCC target ("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
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
const int nax=1007*1007;

int n;
ll h, m;
ll k;

ll tab[nax];

vector<pll> dos;

int best=nax;

int main()
{
	scanf("%d%lld%lld%lld", &n, &h, &m, &k);
	for (int i=1; i<=n; i++)
	{
		ll a, b;
		scanf("%lld%lld", &a, &b);
		tab[i]=b%(m/2);
		dos.push_back({tab[i], i});
	}
	m/=2;
	//~ debug() << range(tab+1, tab+1+n);
	sort(dos.begin(), dos.end());
	queue<pll> kol;
	for (int p=0; p<3; p++)
	{
		for (pll i : dos)
		{
			ll czas=p*m+i.first;
			int v=i.second;
			while(!kol.empty() && kol.front().first<=czas-k)
				kol.pop();
			if (p==1)
				best=min(best, (int)kol.size());
			if (p==2 && (int)kol.size()==best)
			{
				printf("%d %lld\n", best, i.first);
				while(!kol.empty())
				{
					printf("%lld ", kol.front().second);
					kol.pop();
				}
				printf("\n");
				return 0;
			}
			kol.push({czas, v});
		}
	}
	assert(0);
	return 0;
}