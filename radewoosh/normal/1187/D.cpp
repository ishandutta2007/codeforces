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
const int nax=1200*1007;
const int n1=(1<<19);

int n;

int a[nax];
int b[nax];

int gdz[nax];

map <int,int> sta, kon;

void nie()
{
	printf("NO\n");
}

void tak()
{
	printf("YES\n");
}

int drz[nax];

void zmien(int v, int w)
{
	v+=n1-1;
	drz[v]=w;
	v>>=1;
	while(v)
	{
		drz[v]=min(drz[v*2], drz[v*2+1]);
		v>>=1;
	}
}

int czyt(int v, int a, int b, int graa, int grab)
{
	if (a>=graa && b<=grab)
	{
		return drz[v];
	}
	if (a>grab || b<graa)
	{
		return 1e9;
	}
	return min(
		czyt((v<<1), a, (a+b)>>1, graa, grab),
		czyt((v<<1)^1, (a+b+2)>>1, b, graa, grab)
	);
}

void test()
{
	sta.clear();
	kon.clear();
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		scanf("%d", &a[i]);
		sta[a[i]]++;
	}
	for (int i=1; i<=n; i++)
	{
		scanf("%d", &b[i]);
		kon[b[i]]++;
	}
	if (sta!=kon)
	{
		nie();
		return;
	}
	vector <pii> raz, dwa;
	for (int i=1; i<=n; i++)
	{
		raz.push_back({a[i], i});
		dwa.push_back({b[i], i});
	}
	sort(raz.begin(), raz.end());
	sort(dwa.begin(), dwa.end());
	for (int i=1; i<=n; i++)
	{
		a[raz[i-1].second]=i;
		b[dwa[i-1].second]=i;
	}
	for (int i=1; i<=n; i++)
		gdz[a[i]]=i;
	//~ debug() << range(a+1, a+1+n);
	//~ debug() << range(b+1, b+1+n);
	for (int i=1; i<=n; i++)
		zmien(i, a[i]);
	for (int i=1; i<=n; i++)
	{
		int x=gdz[b[i]];
		//~ debug() << imie(x) << czyt(1, 1, n1, 1, x);
		if (czyt(1, 1, n1, 1, x)<b[i])
		{
			nie();
			return;
		}
		zmien(x, 1e9);
	}
	tak();
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}