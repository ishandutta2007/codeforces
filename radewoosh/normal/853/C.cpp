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

const int nax=1000*1007;

////////
int drz[nax];

void pisz(int v, int w)
{
	for (int i=v; i<nax; i+=(i&(-i)))
		drz[i]+=w;
}

int czyt(int v, int u)
{
	int ret=0;
	for (int i=u; i; i-=(i&(-i)))
		ret+=drz[i];
	for (int i=(v-1); i; i-=(i&(-i)))
		ret-=drz[i];
	return ret;
}

void czys()
{
	memset(drz, 0, sizeof(drz));
}////////

int n, q;
int per[nax];

pair <int,int> sze[nax];
pair <int,int> wys[nax];

vector <int> raz[nax];
vector <int> dwa[nax];

long long zle[nax];

inline long long bino(long long v)
{
	return v*(v-1)/2;
}

int main()
{
	scanf("%d%d", &n, &q);
	for (int i=1; i<=n; i++)
		scanf("%d", &per[i]);
	for (int i=1; i<=q; i++)
	{
		scanf("%d%d%d%d", &sze[i].first, &wys[i].first, &sze[i].second, &wys[i].second);
		raz[sze[i].first-1].push_back(i);
		dwa[sze[i].second].push_back(i);
		zle[i]=bino(sze[i].first-1)+bino(wys[i].first-1)+bino(n-sze[i].second)+bino(n-wys[i].second);
	}
	for (int i=1; i<=n; i++)
	{
		pisz(per[i], 1);
		for (int j : raz[i])
			zle[j]-=bino(czyt(1, wys[j].first-1))+bino(czyt(wys[j].second+1, n));
		for (int j : dwa[i])
			zle[j]-=bino((wys[j].first-1)-czyt(1, wys[j].first-1))+bino((n-wys[j].second)-czyt(wys[j].second+1, n));
	}
	for (int i=1; i<=q; i++)
		printf("%lld\n", bino(n)-zle[i]);
	return 0;
}