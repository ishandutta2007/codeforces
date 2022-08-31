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
const int n1=(1<<18);

int n, m, k;

int tab[nax];

set<pii> setel;

set<int> wol;
priority_queue<int> zaj;

vi kol;

int wlo[nax];

void poloz(int v)
{
	v=(*wol.lower_bound(v));
	wol.erase(v);
	zaj.push(v);
	wlo[v]=1;
	kol.push_back(v);
}

void usun()
{
	int v=kol.back();
	kol.pop_back();
	wol.insert(v);
	wlo[v]=0;
}

vi wrzu[nax];

vi czeka[nax];

int wyn[nax];

int dajwyn()
{
	while(!zaj.empty())
	{
		int v=zaj.top();
		if (wlo[v])
			return max(0, v-n);
		zaj.pop();
	}
	return 0;
}

void pisz(int v, int a, int b, int graa, int grab, int w)
{
	//~ if (v==1)
		//~ debug() << graa << " " << grab << "  " << w;
	if (a>=graa && b<=grab)
	{
		wrzu[v].push_back(w);
		return;
	}
	if (a>grab || b<graa)
		return;
	pisz((v<<1), a, (a+b)>>1, graa, grab, w);
	pisz((v<<1)^1, (a+b+2)>>1, b, graa, grab, w);
}

void rek(int v, int a, int b)
{
	for (int i : wrzu[v])
		poloz(i);
	if (a==b)
	{
		wyn[a]=dajwyn();
	}
	else
	{
		rek((v<<1), a, (a+b)>>1);
		rek((v<<1)^1, (a+b+2)>>1, b);
	}
	for (int i : wrzu[v])
		usun();
}

int main()
{
	scanf("%d%d%d", &n, &k, &m);
	for (int i=1; i<=m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		int mno;
		if (setel.count({a, b}))
		{
			mno=-1;
			setel.erase({a, b});
		}
		else
		{
			mno=1;
			setel.insert({a, b});
		}
		tab[i]=mno*(b+abs(a-k));
	}
	for (int i=1; i<=n+n+m; i++)
		wol.insert(i);
	debug() << range(tab+1, tab+1+m);
	for (int i=1; i<=m; i++)
	{
		if (tab[i]>0)
		{
			czeka[tab[i]].push_back(i);
		}
		else
		{
			int x=czeka[-tab[i]].back();
			czeka[-tab[i]].pop_back();
			pisz(1, 1, n1, x, i-1, -tab[i]);
		}
	}
	for (int i=0; i<nax; i++)
		for (int j : czeka[i])
			pisz(1, 1, n1, j, n1, i);
	rek(1, 1, n1);
	
	for (int i=1; i<=m; i++)
		printf("%d\n", wyn[i]);
	return 0;
}