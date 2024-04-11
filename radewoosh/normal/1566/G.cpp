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
const ll inf=1e18;
const int d=5;
const int k=42;

int n, m, q;

multiset<ll> setel[nax];

ll f(int v)
{
	if ((int)setel[v].size()<3)
		return inf;
	auto it=setel[v].begin();
	ll ret=0;
	ret+=(*it);
	it++;
	ret+=(*it);
	it++;
	ret+=(*it);
	return ret;
}

pii stapara[nax];
ll stawag[nax];

map<pii,ll> mapa;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int hasz[nax];

ll wyn[nax];

int typ[nax];
pii para[nax];
ll wag[nax];

void usun(multiset<ll> &s, ll v)
{
	s.erase(s.find(v));
}

void wstaw(multiset<ll> &s, ll v)
{
	s.insert(v);
}

void special()
{
	for (int i=1; i<=m; i++)
	{
		setel[stapara[i].first].insert(stawag[i]);
		setel[stapara[i].second].insert(stawag[i]);
	}
	multiset<ll> wsz;
	for (int i=1; i<=n; i++)
		wsz.insert(f(i));
	wyn[0]=min(wyn[0], (*wsz.begin()));
	for (int i=1; i<=q; i++)
	{
		usun(wsz, f(para[i].first));
		usun(wsz, f(para[i].second));
		if (!typ[i])
		{
			usun(setel[para[i].first], wag[i]);
			usun(setel[para[i].second], wag[i]);
		}
		else
		{
			wstaw(setel[para[i].first], wag[i]);
			wstaw(setel[para[i].second], wag[i]);
		}
		wstaw(wsz, f(para[i].first));
		wstaw(wsz, f(para[i].second));
		wyn[i]=min(wyn[i], (*wsz.begin()));
	}
}

multiset<ll> zawiera[d][d];
ll best[d][d];

int moge[d][d][d][d];

ll znajdz()
{
	ll ret=inf;
	for (int i=0; i<d; i++)
		for (int j=0; j<=i; j++)
			for (int a=0; a<d; a++)
				for (int b=0; b<=a; b++)
					if (moge[i][j][a][b])
						ret=min(ret, best[i][j]+best[a][b]);
	return ret;
}

void randomizowane()
{
	for (int i=1; i<=n; i++)
		hasz[i]=rng()%d;
	for (int i=0; i<d; i++)
	{
		for (int j=0; j<d; j++)
		{
			zawiera[i][j].clear();
			zawiera[i][j].insert(inf);
			best[i][j]=inf;
		}
	}
	for (int i=1; i<=m; i++)
	{
		int a=hasz[stapara[i].first];
		int b=hasz[stapara[i].second];
		if (a<b)
			swap(a, b);
		zawiera[a][b].insert(stawag[i]);
		best[a][b]=(*zawiera[a][b].begin());
	}
	wyn[0]=min(wyn[0], znajdz());
	for (int i=1; i<=q; i++)
	{
		int a=hasz[para[i].first];
		int b=hasz[para[i].second];
		if (a<b)
			swap(a, b);
		if (!typ[i])
		{
			usun(zawiera[a][b], wag[i]);
		}
		else
		{
			wstaw(zawiera[a][b], wag[i]);
		}
		best[a][b]=(*zawiera[a][b].begin());
		wyn[i]=min(wyn[i], znajdz());
	}
}

int main()
{
	//~ int ok=0;
	//~ int w=5;
	//~ for (int a=0; a<w; a++)
		//~ for (int b=0; b<w; b++)
			//~ for (int c=0; c<w; c++)
				//~ for (int d=0; d<w; d++)
					//~ if (a!=c && b!=d && a!=d && b!=c)
						//~ ok++;
	//~ debug() << ok << " " << ok/(double)(w*w*w*w);
	auto start=clock();
	scanf("%d%d", &n, &m);
	for (int i=1; i<=m; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		if (a>b)
			swap(a, b);
		stapara[i]={a, b};
		stawag[i]=c;
		mapa[{a, b}]=c;
	}
	scanf("%d", &q);
	for (int i=1; i<=q; i++)
	{
		int t;
		scanf("%d", &t);
		typ[i]=t;
		if (!t)
		{
			int a, b, c;
			scanf("%d%d", &a, &b);
			if (a>b)
				swap(a, b);
			para[i]={a, b};
			wag[i]=mapa[{a, b}];
		}
		else
		{
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			if (a>b)
				swap(a, b);
			para[i]={a, b};
			wag[i]=c;
			mapa[{a, b}]=c;
		}
	}
	for (int i=0; i<=q; i++)
		wyn[i]=inf;
	special();
	for (int i=0; i<d; i++)
		for (int j=0; j<=i; j++)
			for (int a=0; a<d; a++)
				for (int b=0; b<=a; b++)
					if (i!=a && i!=b && j!=a && j!=b)
						moge[i][j][a][b]=1;
	for (int h=0; h<k && (clock()-start<=1.85*CLOCKS_PER_SEC); h++)
		randomizowane();
	
	
	for (int i=0; i<=q; i++)
		printf("%lld\n", wyn[i]);
	return 0;
}