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
const int nax=1100*1007;
using ld=double;
using pdd=pair<ld,ld>;
const int n1=(1<<19);

int n;
ll l;

pll prz[nax];
ld pre[nax];

int m;
ll dlu[nax];
ld sp[nax];
ld daje[nax];

ld sum[nax];
ld mini[nax];

ld czas(int v, ld a)
{
	return dlu[v]/(sp[v]+a);
}

ld delta(int v, ld a)
{
	return czas(v, a)*(1-a);
}

ld policz(int v)
{
	ld mini=0;
	ld x=0;
	for (int i=v; i<=m; i++)
	{
		x+=delta(i, daje[i]);
		mini=min(mini, x);
	}
	return mini;
}

void zmien(int v, ld a)
{
	v+=n1-1;
	sum[v]=a;
	mini[v]=min(a, (ld)0);
	v>>=1;
	while(v)
	{
		sum[v]=sum[2*v]+sum[2*v+1];
		mini[v]=min(mini[2*v], sum[2*v]+mini[2*v+1]);
		v>>=1;
	}
}

pdd czyt(int v, int a, int b, int graa, int grab)
{
	if (a>=graa && b<=grab)
	{
		return {sum[v], mini[v]};
	}
	if (a>grab || b<graa)
	{
		return {0, 0};
	}
	pdd raz=czyt((v<<1), a, (a+b)>>1, graa, grab);
	pdd dwa=czyt((v<<1)^1, (a+b+2)>>1, b, graa, grab);
	ld r1=raz.first+dwa.first;
	ld r2=min(raz.second, raz.first+dwa.second);
	return {r1, r2};
}

int main()
{
	scanf("%d%lld", &n, &l);
	for (int i=1; i<=n; i++)
		scanf("%lld%lld%lf", &prz[i].first, &prz[i].second, &pre[i]);
	for (int i=1; i<=n; i++)
	{
		if (prz[i].first!=prz[i-1].second)
		{
			m++;
			dlu[m]=prz[i].first-prz[i-1].second;
			sp[m]=0;
		}
		m++;
		dlu[m]=prz[i].second-prz[i].first;
		sp[m]=pre[i];
	}
	if (prz[n].second!=l)
	{
		m++;
		dlu[m]=l-prz[n].second;
		sp[m]=0;
	}
	for (int i=1; i<=m; i++)
		if (sp[i]<0.05)
			daje[i]=1;
	for (int i=1; i<=m; i++)
		zmien(i, delta(i, daje[i]));
	vector <pair<ld,int>> wek;
	for (int i=1; i<=m; i++)
		wek.push_back({sp[i], i});
	sort(wek.begin(), wek.end());
	for (auto h : wek)
	{
		int g=h.second;
		//~ ld przed2=0;
		//~ for (int i=1; i<g; i++)
			//~ przed2+=delta(i, daje[i]);
		ld przed=czyt(1, 1, n1, 1, g-1).first;
		//~ ld po=policz(g+1);
		ld po=czyt(1, 1, n1, g+1, m).second;
		ld bsa=daje[g];
		ld bsb=2;
		for (int iter=0; iter<60 && bsa+1e-15<bsb; iter++)
		{
			ld bss=(bsa+bsb)/2;
			if (min(przed+delta(g, bss), przed+delta(g, bss)+po)>=0)
				bsa=bss;
			else
				bsb=bss;
		}
		daje[g]=(bsa+bsb)/2;
		zmien(g, delta(g, daje[g]));
	}
	ld wyn=0;
	for (int i=1; i<=m; i++)
		wyn+=czas(i, daje[i]);
	printf("%.11lf\n", (double)wyn);
	return 0;
}