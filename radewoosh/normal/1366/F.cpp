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
const int nax=6007;
const ll mod=1000*1000*1000+7;
const ll odw=(mod+1)/2;
const ll inf=1e18;
const int d=6000;
using ld=long double;

int n, m, q;

vector<pii> graf[nax];

ll dpn[nax];
ll dps[nax];

ll naj[nax];

ld ilowek(pll s, pll a, pll b)
{
	a.first-=s.first;
	a.second-=s.second;
	b.first-=s.first;
	b.second-=s.second;
	return a.first*(ld)b.second-a.second*(ld)b.first;
}

bool mniej(pll a, pll b)
{
	if (a.second!=b.second)
		return a.second<b.second;
	return a.first<b.first;
}

ll ary(ll a, ll b, int kroki)
{
	ll sum=a+b;
	sum%=mod;
	ll roz=kroki;
	return (sum*roz)%mod*odw%mod;
}

ll daje(pll v, ll g)
{
	return v.first+v.second*g;
}

ll wsumie(pll v, pll g)
{
	return ary(daje(v, g.first), daje(v, g.second), g.second-g.first+1);
}

int main()
{
	scanf("%d%d%d", &n, &m, &q);
	for (int i=1; i<=m; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		graf[a].push_back({b, c});
		graf[b].push_back({a, c});
	}
	for (int i=1; i<=n; i++)
		dpn[i]=-inf;
	dpn[1]=0;
	for (int h=1; h<=d; h++)
	{
		for (int i=1; i<=n; i++)
		{
			dps[i]=dpn[i];
			dpn[i]=-inf;
		}
		for (int i=1; i<=n; i++)
			for (pii j : graf[i])
				dpn[i]=max(dpn[i], dps[j.first]+j.second);
		ll x=0;
		for (int i=1; i<=n; i++)
			x=max(x, dpn[i]);
		naj[h]=x;
	}
	if (q<=d)
	{
		ll wyn=0;
		for (int i=1; i<=q; i++)
			wyn+=naj[i];
		printf("%lld\n", wyn%mod);
		return 0;
	}
	//~ debug() << range(dpn+1, dpn+1+n);
	vector<pll> wek;
	for (int i=1; i<=n; i++)
	{
		ll naj=0;
		for (pii j : graf[i])
			naj=max(naj, (ll)j.second);
		if (dpn[i]>=0)
			wek.push_back({dpn[i]-naj*d, naj});
	}
	//~ debug() << wek;
	sort(wek.begin(), wek.end(), mniej);
	//~ debug() << imie(wek);
	vector<pll> oto;
	for (pll i : wek)
	{
		int r=oto.size();
		while (r && oto.back().first<=i.first)
		{
			oto.pop_back();
			r--;
		}
		while(r>=2 && ilowek(oto[r-2], oto[r-1], i)<=0)
		{
			oto.pop_back();
			r--;
		}
		oto.push_back(i);
	}
	//~ debug() << imie(oto);
	ll sta=0;
	for (int i=1; i<=d; i++)
		sta+=naj[i];
	sta%=mod;
	
	//~ debug() << imie(wsumie({100, 1}, {1, 0}));
	//~ debug() << oto;
	ll v=d+1;
	for (int i=0; i<(int)oto.size() && v<=q; i++)
	{
		if (i+1==(int)oto.size())
		{
			sta+=wsumie(oto[i], {v, q});
			break;
		}
		ll bsa=v-1;
		ll bsb=q;
		while(bsa<bsb)
		{
			ll bss=(bsa+bsb+2)>>1;
			if (daje(oto[i], bss)>=daje(oto[i+1], bss))
				bsa=bss;
			else
				bsb=bss-1;
		}
		debug() << oto[i] << " na " << v << "-" << bsa;
		sta+=wsumie(oto[i], {v, bsa});
		v=bsa+1;
	}
	
	sta%=mod;
	sta+=mod;
	sta%=mod;
	printf("%lld\n", sta);
	return 0;
}