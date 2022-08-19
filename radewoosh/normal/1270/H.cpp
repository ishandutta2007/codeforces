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
const int nax=2100*1007;
const int n1=(1<<19);

int n, q;

int tab[nax];

set <pii> setel;

int narz[nax];
int pod[nax];

int daj(int v)
{
	if (narz[v])
		return 0;
	return pod[v];
}

void pisz(int v, int a, int b, int graa, int grab, int w)
{
	if (a>=graa && b<=grab)
	{
		narz[v]+=w;
		return;
	}
	if (a>grab || b<graa)
	{
		return;
	}
	pisz((v<<1), a, (a+b)>>1, graa, grab, w);
	pisz((v<<1)^1, (a+b+2)>>1, b, graa, grab, w);
	pod[v]=daj((v<<1))+daj((v<<1)^1);
}

void usun(int v)
{
	auto it=setel.find({tab[v], v});
	int lew=-1;
	int pra=-1;
	if (it!=setel.begin())
	{
		it--;
		lew=(*it).second;
		it++;
	}
	it++;
	if (it!=setel.end())
	{
		pra=(*it).second;
	}
	it--;
	if (lew!=-1)
		pisz(1, 1, n1, lew, v-1, -1);
	if (pra!=-1)
		pisz(1, 1, n1, v, pra-1, -1);
	if (lew!=-1 && pra!=-1)
		pisz(1, 1, n1, lew, pra-1, 1);
	setel.erase(it);
}

void dodaj(int v)
{
	setel.insert({tab[v], v});
	auto it=setel.find({tab[v], v});
	int lew=-1;
	int pra=-1;
	if (it!=setel.begin())
	{
		it--;
		lew=(*it).second;
		it++;
	}
	it++;
	if (it!=setel.end())
	{
		pra=(*it).second;
	}
	it--;
	if (lew!=-1)
		pisz(1, 1, n1, lew, v-1, 1);
	if (pra!=-1)
		pisz(1, 1, n1, v, pra-1, 1);
	if (lew!=-1 && pra!=-1)
		pisz(1, 1, n1, lew, pra-1, -1);
}

int main()
{
	scanf("%d%d", &n, &q);
	for (int i=1; i<=n; i++)
		scanf("%d", &tab[i]);
	for (int i=1; i<=n1; i++)
		pod[i+n1-1]=1;
	for (int i=n1-1; i; i--)
		pod[i]=pod[2*i]+pod[2*i+1];
	pisz(1, 1, n1, n+1, n1, 1);
	for (int i=1; i<=n; i++)
		setel.insert({tab[i], i});
	int ost=n+7;
	for (pii i : setel)
	{
		pisz(1, 1, n1, ost, i.second-1, 1);
		ost=i.second;
	}
	debug() << imie(daj(1));
	while(q--)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		usun(a);
		tab[a]=b;
		dodaj(a);
		printf("%d\n", daj(1));
	}
	return 0;
}