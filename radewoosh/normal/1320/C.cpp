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
const int nax=700*1007;
const ll inf=1e18;
const int n1=(1<<18);

int n, m, p;

vector <pll> bro, arm;

pair <pll,ll> pot[nax];
pll dos1[nax];
pll dos2[nax];

ll wyn=-inf;

ll musz1[nax];
ll musz2[nax];

ll narz[nax][2];
ll pod[nax][2];

ll daj(int v, int p)
{
	return narz[v][p]+pod[v][p];
}

void upd(int v, int p)
{
	pod[v][p]=max(daj(v*2, p), daj(v*2+1, p));
}

int gdz[nax];

void pisz(int v, int a, int b, int graa, int grab, ll w, int p)
{
	if (a>=graa && b<=grab)
	{
		narz[v][p]+=w;
		return;
	}
	if (a>grab || b<graa)
	{
		return;
	}
	pisz((v<<1), a, (a+b)>>1, graa, grab, w, p);
	pisz((v<<1)^1, (a+b+2)>>1, b, graa, grab, w, p);
	upd(v, p);
}

ll czyt(int v, int a, int b, int graa, int grab, int p)
{
	if (a>=graa && b<=grab)
	{
		return daj(v, p);
	}
	if (a>grab || b<graa)
	{
		return -inf;
	}
	return max(
		czyt((v<<1), a, (a+b)>>1, graa, grab, p),
		czyt((v<<1)^1, (a+b+2)>>1, b, graa, grab, p)
	)+narz[v][p];
}

int main()
{
	scanf("%d%d%d", &n, &m, &p);
	for (int i=1; i<=n; i++)
	{
		ll a, b;
		scanf("%lld%lld", &a, &b);
		bro.push_back({a, b});
	}
	for (int i=1; i<=m; i++)
	{
		ll a, b;
		scanf("%lld%lld", &a, &b);
		arm.push_back({a, b});
	}
	for (int i=1; i<=p; i++)
	{
		ll a, b, c;
		scanf("%lld%lld%lld", &a, &b, &c);
		pot[i]={{a, b}, c};
		dos1[i]={a, i};
		dos2[i]={b, i};
	}
	sort(bro.begin(), bro.end());
	sort(arm.begin(), arm.end());
	sort(dos1+1, dos1+1+p);
	sort(dos2+1, dos2+1+p);
	
	for (int i=0; i<=p; i++)
		musz1[i]=musz2[i]=inf;
	{
		int w=0;
		for (pll i : bro)
		{
			while(w<p && i.first>dos1[w+1].first)
				w++;
			musz1[w]=min(musz1[w], i.second);
		}
	}
	{
		int w=0;
		for (pll i : arm)
		{
			while(w<p && i.first>dos2[w+1].first)
				w++;
			musz2[w]=min(musz2[w], i.second);
		}
	}
	for (int i=p; i; i--)
	{
		musz1[i-1]=min(musz1[i-1], musz1[i]);
		musz2[i-1]=min(musz2[i-1], musz2[i]);
	}
	pisz(1, 1, n1, p+2, n1, -inf, 0);
	for (int i=0; i<=p; i++)
		pisz(1, 1, n1, i+1, i+1, -musz1[i], 0);
	for (int i=1; i<=p; i++)
		gdz[dos1[i].second]=i;
	for (int i=0; i<=p; i++)
	{
		if (i)
		{
			int x=dos2[i].second;
			pisz(1, 1, n1, gdz[x]+1, p+1, pot[x].second, 0);
		}
		wyn=max(wyn, -musz2[i]+daj(1, 0));
	}
	//~ debug() << range(pot+1, pot+1+p);
	//~ debug() << range(dos1+1, dos1+1+p);
	//~ debug() << range(dos2+1, dos2+1+p);
	//~ debug() << range(musz1+1, musz1+1+p);
	//~ debug() << range(musz2+1, musz2+1+p);
	
	
	
	printf("%lld\n", wyn);
	return 0;
}