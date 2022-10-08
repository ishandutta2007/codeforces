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
const int nax=1000*1007;
using ull=long double;
int n1;

int n, m;

vector <pair<int,pll>> graf[nax];

int bylcen[nax];
int roz[nax];
int maxr[nax];

vi spo;

int pie[nax];
vi kied[nax];
ll wyn[nax];

pll najp[nax];

pll operator - (pll a, pll b)
{
	return {a.first-b.first, a.second-b.second};
}

pll operator + (pll a, pll b)
{
	return {a.first+b.first, a.second+b.second};
}

inline bool ilowek(const pll &s, pll a, pll b)
{
	a=a-s;
	b=b-s;
	const ull raz=((ull)a.first)*((ull)b.second);
	const ull dwa=((ull)b.first)*((ull)a.second);
	return (raz>=dwa);
}

void dfs1(int v, int oj, pll trz)
{
	najp[v]=trz;
	for (auto i : graf[v])
		if (i.first!=oj)
			dfs1(i.first, v, trz+i.second);
}

bool mniej1(int a, int b)
{
	return najp[a]<najp[b];
}

vi oto(const vi &wek, pll *wsp)
{
	vi ret;
	for (int i : wek)
	{
		while(!ret.empty() && wsp[i].second>=wsp[ret.back()].second)
			ret.pop_back();
		int r=ret.size();
		while(r>1 && ilowek(wsp[ret[r-2]], wsp[ret[r-1]], wsp[i]))
		{
			r--;
			ret.pop_back();
		}
		ret.push_back(i);
	}
	return ret;
}

inline ll eva(const pll &v, const ll &dzien)
{
	return v.first*dzien+v.second;
}

pii znajdz(const vi &wek, ll dzien, pll *wsp, int start=0)
{
	int tsa=start;
	int tsb=(int)wek.size()-1;
	int ts1, ts2;
	while(tsa<tsb)
	{
		ts1=(tsa+tsb)/2;
		ts2=ts1+1;
		if (eva(wsp[wek[ts1]], dzien)>eva(wsp[wek[ts2]], dzien))
			tsb=ts1;
		else
			tsa=ts2;
	}
	return {wek[tsa], tsa};
}

void dfs2(int v, int oj)
{
	spo.push_back(v);
	roz[v]=1;
	maxr[v]=0;
	for (auto i : graf[v])
	{
		if (i.first==oj || bylcen[i.first])
			continue;
		dfs2(i.first, v);
		roz[v]+=roz[i.first];
		maxr[v]=max(maxr[v], roz[i.first]);
	}
}

pll odl[nax];

void dfs3(int v, int oj, pll trz)
{
	odl[v]=trz;
	for (auto i : graf[v])
		if (i.first!=oj && !bylcen[i.first])
			dfs3(i.first, v, trz+i.second);
}

int num[nax];
vector <int> drz[nax];

void dfs4(int v, int oj, int gdz)
{
	debug() << v << " do " << gdz;
	num[v]=gdz;
	drz[gdz+n1-1].push_back(v);
	for (auto i : graf[v])
		if (i.first!=oj && !bylcen[i.first])
			dfs4(i.first, v, gdz);
}

bool mniej2(int a, int b)
{
	return odl[a]<odl[b];
}

void lacz(int v, int w)
{
	debug() << drz[v] << "  " << w << "  " << num[w];
	int ost=0;
	for (int i : kied[w])
	{
		pii wez=znajdz(drz[v], i, odl, ost);
		int x=wez.first;
		ost=wez.second;
		debug() << w << " " << x;
		wyn[i]=max(wyn[i], eva(odl[w], i)+eva(odl[x], i));
	}
}

void rek(int v, int a, int b, int graa, int grab, int w)
{
	if (graa>grab)
		return;
	if (a>grab || b<graa)
		return;
	if (drz[v].empty())
		return;
	if (a>=graa && b<=grab)
	{
		lacz(v, w);
		return;
	}
	rek((v<<1), a, (a+b)>>1, graa, grab, w);
	rek((v<<1)^1, (a+b+2)>>1, b, graa, grab, w);
}

void opierdol(int v)
{
	if (kied[v].empty())
		return;
	rek(1, 1, n1, 1, num[v]-1, v);
	rek(1, 1, n1, num[v]+1, n1, v);
}

void szuk(int v)
{
	if (bylcen[v])
		return;
	spo.clear();
	dfs2(v, 0);
	int ss=spo.size();
	int c=-1;
	for (int i : spo)
		if (maxr[i]*2<=ss && (ss-roz[i])*2<=ss)
			c=i;
	
	assert(c!=-1);
	debug() << imie(c);
	
	dfs3(c, 0, {0LL, 0LL});
	
	n1=1;
	while(n1<=(int)graf[c].size()+2)
		n1<<=1;
	
	for (int i=0; i<=2*n1; i++)
		drz[i].clear();
	
	for (int i : spo)
		for (int j : kied[i])
			wyn[j]=max(wyn[j], eva(odl[i], j));
	
	
	int k=0;
	num[c]=0;
	for (auto i : graf[c])
	{
		if (bylcen[i.first])
			continue;
		k++;
		dfs4(i.first, c, k);
		sort(drz[k+n1-1].begin(), drz[k+n1-1].end(), mniej2);
		drz[k+n1-1]=oto(drz[k+n1-1], odl);
	}
	for (int i=n1-1; i; i--)
	{
		int a=i*2;
		int b=i*2+1;
		drz[i].resize(drz[a].size()+drz[b].size());
		merge(drz[a].begin(), drz[a].end(), drz[b].begin(), drz[b].end(), drz[i].begin(), mniej2);
		drz[i]=oto(drz[i], odl);
		if (!drz[i].empty())
			debug() << i << " " << drz[i];
	}
	for (int i : spo)
		opierdol(i);
	
	bylcen[c]=1;
	
	for (auto i : graf[c])
		szuk(i.first);
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		pll fun;
		scanf("%lld%lld", &fun.first, &fun.second);
		graf[a].push_back({b, fun});
		graf[b].push_back({a, fun});
	}
	dfs1(1, 0, {0LL, 0LL});
	vi dos;
	for (int i=1; i<=n; i++)
		dos.push_back(i);
	sort(dos.begin(), dos.end(), mniej1);
	auto wez=oto(dos, najp);
	for (int i=0; i<m; i++)
		pie[i]=znajdz(wez, i, najp).first;
	debug() << range(pie, pie+m);
	for (int i=0; i<m; i++)
		kied[pie[i]].push_back(i);
	szuk(1);
	
	for (int i=0; i<m; i++)
		printf("%lld ", wyn[i]);
	printf("\n");
	return 0;
}