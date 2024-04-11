//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
//~ #pragma GCC optimize("O3")
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
const int nax=1007;

void ff()
{
	fflush(stdout);
}

const ll p=1e18;
//~ const ll p=5;

int n;
ll l;

ll k;

unordered_map <ll,ll> wiem[nax];

pll wyn[nax];

ll pyt(int v, ll x)
{
	if (wiem[v].count(x))
		return wiem[v][x];
	printf("? %d %lld\n", v, x);
	ff();
	ll w;
	scanf("%lld", &w);
	wiem[v][x]=w;
	return w;
}

ll szuk(int v, ll graa, ll grab, ll wa, ll wb, ll cel)
{
	ll bsa=graa;
	ll bsb=grab;
	while(bsa<bsb)
	{
		ll bss=(bsa+bsb)>>1;
		ll wez=pyt(v, bss);
		wez=min(wez, wb);
		wez=max(wez, wa);
		if (wez==cel)
			return bss;
		if (wez>cel)
			bsb=bss-1;
		else
			bsa=bss+1;
	}
	return bsa;
}

void rek(vi wek, ll graa, ll grab, ll wa, ll wb)
{
	if (wek.empty())
		return;
	if (wek.size()==1)
	{
		wyn[wek[0]]={graa, grab};
		return;
	}
	int r=wek.size();
	shandom_ruffle(wek.begin(), wek.end());
	int x=wek.back();
	int pa=1;
	int pb=r-1;
	while(1)
	{
		//~ assert(pa<=pb);
		int ps=(pa+pb)>>1;
		if (pa>pb)
		{
			pa=1;
			pb=r-1;
			shandom_ruffle(wek.begin(), wek.end());
			x=wek.back();
			continue;
		}
		
		ll m=szuk(x, graa, grab, wa, wb, wa+ps*k);
		vi mni;
		vi wie;
		vi row;
		for (int i : wek)
		{
			ll wez=pyt(i, m);
			if (wez<wa+ps*k)
				mni.push_back(i);
			if (wez==wa+ps*k)
				row.push_back(i);
			if (wez>wa+ps*k)
				wie.push_back(i);
		}
		if ((int)wie.size()>ps || (int)mni.size()>r-ps)
		{
			int oa=0;
			int ob=0;
			if ((int)wie.size()>ps)
				oa=1;
			if ((int)mni.size()>r-ps)
				ob=1;
			assert(oa+ob==1);
			if (oa)
				pa=ps+1;
			else
				pb=ps-1;
			continue;
		}
		for (int i : row)
		{
			if ((int)wie.size()<ps)
				wie.push_back(i);
			else
				mni.push_back(i);
		}
		rek(wie, graa, m, wa, wa+ps*k);
		rek(mni, m, grab, wa+ps*k, wb);
		//div
		return;
	}
	assert(0);
}

int main()
{
	scanf("%d%lld", &n, &l);
	k=l/n;
	for (int i=1; i<=n; i++)
	{
		wiem[i][0]=0;
		wiem[i][p]=l;
	}
	vi start(n);
	iota(start.begin(), start.end(), 1);
	rek(start, 0, p, 0, l);
	
	printf("!\n");
	for (int i=1; i<=n; i++)
		printf("%lld %lld\n", wyn[i].first, wyn[i].second);
	ff();
	return 0;
}