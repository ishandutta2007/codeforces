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
const int n1=(1<<17);
const ll inf=1e18;

int n, m, q;

ll ta[nax];
ll tb[nax];

ll sta, sup;

ll narz[nax];
pll pod[nax];
ll sum[nax];

ll wyn;

pll lacz(pll a, pll b)
{
	return {min(a.first, b.first), max(a.second, b.second)};
}

pll moc(pll a, ll b)
{
	return {a.first+b, a.second+b};
}

pll daj(int v)
{
	return moc(pod[v], narz[v]);
}

ll dajsum(int v, ll x)
{
	return sum[v]+narz[v]*x;
}

void dod(int v, int a, int b, int graa, int grab, ll w)
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
	dod((v<<1), a, (a+b)>>1, graa, grab, w);
	dod((v<<1)^1, (a+b+2)>>1, b, graa, grab, w);
	int dlu=b-a+1;
	pod[v]=lacz(daj(2*v), daj(2*v+1));
	sum[v]=dajsum(2*v, dlu>>1)+dajsum(2*v+1, dlu>>1);
}

ll mniejsze(int v, int a, int b, ll w, ll zbi=0)
{
	pll wez=moc(daj(v), zbi);
	if (wez.second<=w)
		return dajsum(v, b-a+1)+(b-a+1)*zbi;
	if (wez.first>=w)
		return (b-a+1)*w;
	return mniejsze((v<<1), a, (a+b)>>1, w, zbi+narz[v])+mniejsze((v<<1)^1, (a+b+2)>>1, b, w, zbi+narz[v]);
}

int main()
{
	scanf("%d%d%d", &n, &m, &q);
	for (int i=1; i<=n; i++)
		scanf("%lld", &ta[i]);
	for (int i=1; i<=m; i++)
		scanf("%lld", &tb[i]);
	sta=ta[1]+tb[1];
	for (int i=1; i<n; i++)
		ta[i]=ta[i+1]-ta[i];
	for (int i=1; i<m; i++)
		tb[i]=tb[i+1]-tb[i];
	for (int i=1; i<m; i++)
		dod(1, 1, n1, i, i, tb[i]);
	n--;
	m--;
	dod(1, 1, n1, m+1, n1, inf);
	for (int i=1; i<=m; i++)
		sup+=(m+1-i)*tb[i];
	while(q--)
	{
		int typ, k, x;
		scanf("%d%d%d", &typ, &k, &x);
		if (typ==1)
		{
			if (k==n+1)
			{
				sta+=x;
				k--;
			}
			for (int i=n-k+1; i<=n; i++)
				ta[i]+=x;
		}
		else
		{
			if (k==m+1)
			{
				sta+=x;
				k--;
			}
			dod(1, 1, n1, m-k+1, m, x);
			//~ for (int i=m-k+1; i<=m; i++)
				//~ tb[i]+=x;
			sup+=x*(k*(ll)(k+1)/2);
		}
		wyn=(n+1+m)*sta+sup;
		for (int i=1; i<=n; i++)
			wyn+=(n+1-i)*ta[i];
		//~ for (int i=1; i<=n; i++)
			//~ for (int j=1; j<=m; j++)
				//~ wyn+=min(ta[i], tb[j]);
		//~ vll wek;
		for (int i=1; i<=n; i++)
		{
			ll wez=mniejsze(1, 1, n1, ta[i])-ta[i]*(n1-m);
			wyn+=wez;
			//~ wek.push_back(wez);
		}
		//~ debug() << range(tb+1, tb+1+m) << " " << range(ta+1, ta+1+n) << " " << wek;
		
		printf("%lld\n", wyn);
	}
	return 0;
}