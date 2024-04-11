//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
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
const ll inf=1e18;

int n;

ll tab[nax][2][2];

void tak()
{
	printf("YES\n");
	exit(0);
}

void nie()
{
	printf("NO\n");
	exit(0);
}

void rek(int v, vector <set <pll>*> wek)
{
	if (v==1)
		return;
	ll maxi[]={-inf, -inf, -inf, -inf};
	set <pll>::iterator it[4];
	for (int i=0; i<4; i++)
		it[i]=(*wek[i]).begin();
	int okok=0;
	vi wyc;
	for (int i=1; i<v; i++)
	{
		for (int j=0; j<4; j++)
		{
			maxi[j]=max(maxi[j], -tab[(*it[j]).second][j&1][((j>>1)^1)]);
			it[j]++;
		}
		for (int j=0; j<4; j++)
		{
			if (maxi[j]<=(*it[j]).first)
			{
				auto jt=(*wek[j]).begin();
				while(jt!=it[j])
				{
					wyc.push_back((*jt).second);
					jt++;
				}
				okok=1;
				break;
			}
		}
		if (okok)
			break;
	}
	if (!okok)
		nie();
	vector <set <pll>*> nowe;
	for (int i=0; i<4; i++)
		nowe.push_back(new set <pll>);
	for (int i=0; i<4; i++)
	{
		for (int j : wyc)
		{
			(*wek[i]).erase({tab[j][i&1][(i>>1)], j});
			(*nowe[i]).insert({tab[j][i&1][(i>>1)], j});
		}
	}
	rek(v-(int)wyc.size(), wek);
	rek((int)wyc.size(), nowe);
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		scanf("%lld%lld", &tab[i][0][0], &tab[i][1][0]);
		scanf("%lld%lld", &tab[i][0][1], &tab[i][1][1]);
	}
	vector <set <pll>*> start;
	for (int i=0; i<4; i++)
		start.push_back(new set <pll>);
	for (int i=1; i<=n; i++)
	{
		tab[i][0][1]*=-1;
		tab[i][1][1]*=-1;
		(*start[0]).insert({tab[i][0][0], i});
		(*start[1]).insert({tab[i][1][0], i});
		(*start[2]).insert({tab[i][0][1], i});
		(*start[3]).insert({tab[i][1][1], i});
	}
	rek(n, start);
	tak();
	return 0;
}