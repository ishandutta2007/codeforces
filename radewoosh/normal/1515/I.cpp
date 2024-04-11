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
const int nax=(1<<19)+7;
const int n1=(1<<18);
const int d=20;
const ll inf=1007LL*1007LL*1007LL*1007LL*1007LL*1007LL;

int n, q;

ll maga[nax];
ll waga[nax];
ll war[nax];

pair<pll,int> dos[nax];
int ktu[nax];

ll plecak;
ll wyn;

int typ(ll v)
{
	return min(64-__builtin_clzll(v), d-1);
}

pll drz_sum[nax][d];
ll drz_min[nax][d];

void zmien_min(int v, int kt, ll w)
{
	v+=n1-1;
	drz_min[v][kt]=w;
	v>>=1;
	while(v)
	{
		drz_min[v][kt]=min(drz_min[2*v][kt], drz_min[2*v+1][kt]);
		v>>=1;
	}
}

void dodaj(int v, int kt, pll w)
{
	v+=n1-1;
	while(v)
	{
		drz_sum[v][kt].first+=w.first;
		drz_sum[v][kt].second+=w.second;
		v>>=1;
	}
}

void rek(int v, int a, int b)
{
	//~ debug() << v << " " << a << " " << b << " " << plecak << " " << wyn;
	if (a>n || !plecak)
		return;
	if (a==b)
	{
		int g=dos[v-n1+1].second;
		ll x=min(maga[g], plecak/waga[g]);
		plecak-=x*waga[g];
		wyn+=x*war[g];
		return;
	}
	int wazne=0;
	int t=typ(plecak);
	if (drz_min[v][t]<=plecak && 2*drz_min[v][t]>=plecak)
		wazne=1;
	if (drz_sum[v][t-1].first>plecak)
		wazne=1;
	//~ debug() << imie(wazne);
	if (wazne)
	{
		rek((v<<1), a, (a+b)>>1);
		rek((v<<1)^1, (a+b+2)>>1, b);
	}
	else
	{
		plecak-=drz_sum[v][t-1].first;
		wyn+=drz_sum[v][t-1].second;
		//~ debug() << drz_sum[v][t-1];
	}
}

int main()
{
	scanf("%d%d", &n, &q);
	for (int i=1; i<=n; i++)
	{
		scanf("%lld%lld%lld", &maga[i], &waga[i], &war[i]);
		dos[i]={{-war[i], waga[i]}, i};
	}
	sort(dos+1, dos+1+n);
	for (int i=1; i<=n; i++)
		ktu[dos[i].second]=i;
	//~ debug() << range(dos+1, dos+1+n);
	for (int i=0; i<nax; i++)
		for (int j=0; j<d; j++)
			drz_min[i][j]=inf;
	for (int i=1; i<=n; i++)
	{
		for (int j=typ(waga[i]); j<d; j++)
			dodaj(ktu[i], j, {waga[i]*maga[i], war[i]*maga[i]});
		if (maga[i])
			zmien_min(ktu[i], typ(waga[i]), waga[i]);
	}
	map<ll,ll> mapa;
	while(q--)
	{
		int t;
		scanf("%d", &t);
		if (t==1)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			for (int j=typ(waga[b]); j<d; j++)
				dodaj(ktu[b], j, {waga[b]*a, war[b]*a});
			maga[b]+=a;
			if (maga[b])
				zmien_min(ktu[b], typ(waga[b]), waga[b]);
			else
				zmien_min(ktu[b], typ(waga[b]), inf);
			mapa.clear();
			continue;
		}
		if (t==2)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			for (int j=typ(waga[b]); j<d; j++)
				dodaj(ktu[b], j, {-waga[b]*a, -war[b]*a});
			maga[b]-=a;
			if (maga[b])
				zmien_min(ktu[b], typ(waga[b]), waga[b]);
			else
				zmien_min(ktu[b], typ(waga[b]), inf);
			mapa.clear();
			continue;
		}
		wyn=0;
		scanf("%lld", &plecak);
		ll spam=plecak;
		if (mapa.count(plecak))
		{
		    printf("%lld\n", mapa[plecak]);
		}
		else
		{
    		rek(1, 1, n1);
    		printf("%lld\n", mapa[spam]=wyn);
		}
	}
	return 0;
}