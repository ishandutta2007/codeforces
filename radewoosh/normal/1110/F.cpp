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
const ll inf=1e18;

int n;
int q;
vector<pii> graf[nax];

int sko[nax];
pii zap[nax];
ll wyn[nax];

int bylcen[nax];
int roz[nax];
int maxr[nax];
vi spo;

ll drz[nax];

ll odl[nax];

int zmien(int v, ll w)
{
	//~ debug() << v << " na " << w;
	v+=n1-1;
	//~ debug() << imie(v);
	drz[v]=w;
	v>>=1;
	while(v)
	{
		drz[v]=min(drz[v<<1], drz[(v<<1)^1]);
		//~ debug() << imie(drz[v]);
		v>>=1;
	}
}

void dfs1(int v, int oj)
{
	spo.push_back(v);
	roz[v]=1;
	maxr[v]=0;
	for (auto i : graf[v])
	{
		if (bylcen[i.first] || i.first==oj)
			continue;
		dfs1(i.first, v);
		roz[v]+=roz[i.first];
		maxr[v]=max(maxr[v], roz[i.first]);
	}
}

int rep[nax];
vi pot[nax];


void znacz(int v, int oj, int kim)
{
	rep[v]=kim;
	for (auto i : graf[v])
		if (i.first!=oj && !bylcen[i.first])
			znacz(i.first, v, kim);
}


vi tutaj[nax];

void liczodl(int v, int oj, ll w)
{
	odl[v]=w;
	for (auto i : graf[v])
		if (i.first!=oj && !bylcen[i.first])
			liczodl(i.first, v, w+i.second);
}

ll glo;
int graa, grab;

inline void czyt(const int &v, const int &a, const int &b)
{
	if (a>=graa && b<=grab)
	{
		glo=min(glo, drz[v]);
		return;
	}
	if (a>grab || b<graa)
		return;
	czyt((v<<1), a, (a+b)>>1);
	czyt((v<<1)^1, (a+b+2)>>1, b);
}

void szuk(int v)
{
	if (bylcen[v])
		return;
	spo.clear();
	dfs1(v, 0);
	int c=-1;
	int ss=spo.size();
	for (int i : spo)
		if (maxr[i]*2<=ss && (ss-roz[i])*2<=ss)
			c=i;
	assert(c>0);
	
	bylcen[c]=1;
	
	
	vi lis;
	
	for (int i : spo)
		if ((int)graf[i].size()==1)
			lis.push_back(i);
	
	liczodl(c, 0, 0);
	if (!lis.empty())
	{
		if ((int)lis.size()>7)
		{
			for (int &i : lis)
			{
				if (i<lis[0])
					swap(i, lis[0]);
				if (i>lis.back())
					swap(i, lis.back());
			}
			for (int i : lis)
				zmien(i, odl[i]);
			for (int j : spo)
			{
				for (int i : pot[j])
				{
					if (zap[i].first>lis.back() || zap[i].second<lis[0])
						continue;
					if (zap[i].first<=lis[0] && zap[i].second>=lis.back())
					{
						glo=drz[1];
					}
					else
					{
						glo=inf;
						graa=zap[i].first;
						grab=zap[i].second;
						czyt(1, 1, n1);
					}
					wyn[i]=min(wyn[i], odl[j]+glo);
				}
			}
			for (int i : lis)
				zmien(i, inf);
		}
		else
		{
			for (int j : spo)
				for (int i : pot[j])
					for (int l : lis)
						if (l>=zap[i].first && l<=zap[i].second)
							wyn[i]=min(wyn[i], odl[j]+odl[l]);
		}
	}
	
	for (auto i : graf[c])
	{
		if (bylcen[i.first])
			continue;
		szuk(i.first);
	}
}


int main()
{
	for (int i=1; i<nax; i++)
		drz[i]=inf;
	scanf("%d%d", &n, &q);
	for (int i=2; i<=n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		//~ a=i-1;
		//~ b=1e9;
		graf[a].push_back({i, b});
		graf[i].push_back({a, b});
	}
	for (int i=1; i<=q; i++)
	{
		scanf("%d%d%d", &sko[i], &zap[i].first, &zap[i].second);
		wyn[i]=inf;
		pot[sko[i]].push_back(i);
	}
	szuk(1);
	
	for (int i=1; i<=q; i++)
		printf("%lld\n", wyn[i]);
	return 0;
}