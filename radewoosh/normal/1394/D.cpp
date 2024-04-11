//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
//~ #pragma GCC target ("avx2")
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
const ll inf=1e12;

int n;

ll trud[nax];
ll wys[nax];

vi graf[nax];

ll dpros[nax];
ll dpmal[nax];

bool mniej(pll a, pll b)
{
	return a.second<b.second;
}

ll wyn=inf;

void dfs1(int v, int oj)
{
	for (int &i : graf[v])
	{
		if (i==oj)
		{
			swap(i, graf[v].back());
			graf[v].pop_back();
			break;
		}
	}
	vector<pll> wek;
	for (int i : graf[v])
	{
		dfs1(i, v);
		ll a=dpros[i];
		ll b=dpmal[i];
		wek.push_back({a, b-a});
	}
	dpros[v]=inf;
	dpmal[v]=inf;
	sort(wek.begin(), wek.end(), mniej);
	ll s=0;
	for (pll i : wek)
		s+=i.first;
	for (int i=0; i<=(int)wek.size(); i++)
	{
		int rosy=(int)wek.size()-i;
		int maly=i;
		//~ debug() << imie(v) << imie(rosy) << imie(maly) << imie(i) << imie(s);
		dpros[v]=min(dpros[v], s+max(rosy, maly)*trud[v]+trud[v]);
		dpmal[v]=min(dpmal[v], s+max(rosy, maly)*trud[v]+trud[v]);
		
		if (rosy)
		{
			rosy--;
			dpros[v]=min(dpros[v], s+max(rosy, maly)*trud[v]+trud[v]);
			rosy++;
		}
		if (maly)
		{
			maly--;
			dpmal[v]=min(dpmal[v], s+max(rosy, maly)*trud[v]+trud[v]);
			maly++;
		}
		
		if (i<(int)wek.size())
			s+=wek[i].second;
	}
	if (v==1)
	{
		s=0;
		for (pll i : wek)
			s+=i.first;
		for (int i=0; i<=(int)wek.size(); i++)
		{
			int rosy=(int)wek.size()-i;
			int maly=i;
			//~ debug() << imie(v) << imie(rosy) << imie(maly) << imie(i) << imie(s);
			wyn=min(wyn, s+max(rosy, maly)*trud[v]);
			wyn=min(wyn, s+max(rosy, maly)*trud[v]);
			
			if (i<(int)wek.size())
				s+=wek[i].second;
		}
	}
	
	if (wys[oj]>wys[v])
		dpmal[v]=inf;
	if (wys[oj]<wys[v])
		dpros[v]=inf;
	
	//~ debug() << v << " " << dpros[v] << " " << dpmal[v];
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		scanf("%lld", &trud[i]);
	for (int i=1; i<=n; i++)
		scanf("%lld", &wys[i]);
	for (int i=1; i<n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	dfs1(1, 0);
	
	//~ printf("%lld\n", min(dpmal[1], dpros[1]));
	printf("%lld\n", wyn);
	return 0;
}