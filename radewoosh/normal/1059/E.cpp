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

int n;

int limw;
ll lims;

ll tab[nax];
vi graf[nax];

int wyn;

vector <ll> stos;

int dfs(int v, int oj)
{
	//~ debug() << imie(v);
	ll x=stos.back();
	stos.push_back(x+tab[v]);
	int ret=0;
	for (int i : graf[v])
	{
		//~ debug() << v << " na " << i;
		int w=dfs(i, v);
		ret=max(ret, w-1);
	}
	if (!ret)
	{
		wyn++;
		ll sum=stos.back();
		int bsa=1;
		int bsb=(int)stos.size()-1;
		int bss;
		while(bsa<bsb)
		{
			bss=(bsa+bsb+2)>>1;
			ll wte=sum-stos[(int)stos.size()-1-bss];
			if (wte<=lims && bss<=limw)
				bsa=bss;
			else
				bsb=bss-1;
		}
		ret=bsa;
	}
	stos.pop_back();
	return ret;
}

int main()
{
	scanf("%d%d%lld", &n, &limw, &lims);
	for (int i=1; i<=n; i++)
	{
		scanf("%lld", &tab[i]);
		if (tab[i]>lims)
		{
			printf("-1\n");
			return 0;
		}
	}
	for (int i=2; i<=n; i++)
	{
		int a;
		scanf("%d", &a);
		graf[a].push_back(i);
	}
	stos.push_back(0);
	dfs(1, 0);
	printf("%d\n", wyn);
	return 0;
}