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

const int nax=200*1007;
const int d=30;

int n;
long long tab[nax];

pair <long long,int> dos[nax];

set <int> skr;

int pra[nax][d];
int lew[nax][d];

long long wyn;

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		scanf("%lld", &tab[i]);
		dos[i]={tab[i], i};
	}
	sort(dos+1, dos+1+n);
	reverse(dos+1, dos+1+n);
	skr.insert(0);
	skr.insert(n+1);
	for (int i=0; i<d; i++)
		pra[n+1][i]=n+1;
	for (int i=n; i; i--)
	{
		for (int j=0; j<d; j++)
		{
			pra[i][j]=pra[i+1][j];
			if (tab[i]&(1LL<<j))
				pra[i][j]=i;
		}
	}
	for (int i=0; i<d; i++)
		lew[0][i]=0;
	for (int i=1; i<=n; i++)
	{
		for (int j=0; j<d; j++)
		{
			lew[i][j]=lew[i-1][j];
			if (tab[i]&(1LL<<j))
				lew[i][j]=i;
		}
	}
	for (int h=1; h<=n; h++)
	{
		int v=dos[h].second;
		auto it=skr.lower_bound(v);
		int pr=(*it);
		it--;
		int le=(*it);
		wyn+=((long long)pr-v)*(v-le);
		for (int i=0; i<d; i++)
		{
			if (!(tab[v]&(1LL<<i)))
			{
				pr=min(pr, pra[v][i]);
				le=max(le, lew[v][i]);
			}
		}
		wyn-=((long long)pr-v)*(v-le);
		
		skr.insert(v);
	}
	printf("%lld\n", wyn);
	return 0;
}