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
const int nax=300*1007;
const ll mod=998244353;
const int d=250;
using mag=long double;
const ll inf=1e18;
int k;

int n, q;

ll wa[nax];
ll wb[nax];

vi drz[nax];
int czas;
int pre[nax];
int post[nax];

ll a[nax];
ll b[nax];

ll narz[nax];
ll budzik[nax];

vi pos[nax];
vi pos2[nax];
vector <pll> otodod[nax];
vector <pll> otouje[nax];
int gdod[nax];
int guje[nax];

int f(int v)
{
	if (v>n)
		return nax;
	return (v+d-1)/d;
}

int pocz(int v)
{
	return v*d-(d-1);
}

int kon(int v)
{
	return min(v*d, n);
}

void dfs(int v, ll sa, ll sb)
{
	czas++;
	pre[v]=czas;
	sa+=wa[v];
	sb+=wb[v];
	a[czas]=sa;
	b[czas]=abs(sb);
	for (int i : drz[v])
		dfs(i, sa, sb);
	post[v]=czas;
}

bool mniej(int x, int y)
{
	return b[x]<b[y];
}

pll operator - (pll a, pll b)
{
	return {a.first-b.first, a.second-b.second};
}

mag ilowek(pll s, pll a, pll b)
{
	a=a-s;
	b=b-s;
	return a.first*(mag)b.second-a.second*(mag)b.first;
}

int lewo(pll s, pll a, pll b)
{
	return ilowek(s, a, b)>0;
}

void wrzuc(vector <pll> &wek, pll w)
{
	while (!wek.empty() && w.first==wek.back().first && w.second>=wek.back().second)
		wek.pop_back();
	if (!wek.empty() && w.first==wek.back().first && w.second<wek.back().second)
		return;
	int r=wek.size();
	while(r>=2 && lewo(wek[r-2], wek[r-1], w))
	{
		wek.pop_back();
		r--;
	}
	wek.push_back(w);
}

void recalc(int v)
{
	//~ debug() << "licze " << v;
	otodod[v].clear();
	otouje[v].clear();
	budzik[v]=inf;
	for (int i : pos[v])
	{
		a[i]+=narz[v];
		if (a[i]>=0)
		{
			wrzuc(otodod[v], {b[i], a[i]*b[i]});
		}
		else
		{
			//~ wrzuc(otouje[v], {b[i], -a[i]*b[i]});
			//~ budzik[v]=min(budzik[v], -a[i]);
		}
	}
	for (int i : pos2[v])
	{
		if (a[i]>=0)
		{
			//~ wrzuc(otodod[v], {b[i], a[i]*b[i]});
		}
		else
		{
			wrzuc(otouje[v], {-b[i], -a[i]*b[i]});
			budzik[v]=min(budzik[v], -a[i]);
		}
	}
	narz[v]=0;
	gdod[v]=0;
	guje[v]=0;
	//~ debug() << "kon " << v;
}

void shift(int v)
{
	{
		int &x=gdod[v];
		while(x+1<(int)otodod[v].size() && otodod[v][x+1].first*narz[v]+otodod[v][x+1].second>=otodod[v][x].first*narz[v]+otodod[v][x].second)
			x++;
	}
	{
		int &x=guje[v];
		while(x+1<(int)otouje[v].size() && otouje[v][x+1].first*narz[v]+otouje[v][x+1].second>=otouje[v][x].first*narz[v]+otouje[v][x].second)
			x++;
	}
}

void dodaj(int l, int p, ll w)
{
	if (f(l)==f(p))
	{
		for (int i=l; i<=p; i++)
			a[i]+=w;
		recalc(f(l));
		return;
	}
	if (f(l)+1==f(p))
	{
		for (int i=l; i<=p; i++)
			a[i]+=w;
		recalc(f(l));
		recalc(f(p));
		return;
	}
	for (int i=l; f(i)==f(l); i++)
		a[i]+=w;
	for (int i=p; f(i)==f(p); i--)
		a[i]+=w;
	recalc(f(l));
	recalc(f(p));
	for (int i=f(l)+1; i<f(p); i++)
	{
		narz[i]+=w;
		if (narz[i]>=budzik[i])
			recalc(i), debug() << "budze " << i;
	}
}

ll czyt(int v)
{
	shift(v);
	ll ret=0;
	//~ debug() << otodod[v] << " " << gdod[v];
	if (!otodod[v].empty())
		ret=max(ret, otodod[v][gdod[v]].first*narz[v]+otodod[v][gdod[v]].second);
	//~ debug() << otouje[v] << " " << guje[v];
	if (!otouje[v].empty())
		ret=max(ret, otouje[v][guje[v]].first*narz[v]+otouje[v][guje[v]].second);
	//~ debug() << v << " " << ret;
	return ret;
}

void czyt(int l, int p)
{
	ll ret=0;
	if (f(l)+1>=f(p))
	{
		for (int i=l; i<=p; i++)
			ret=max(ret, abs(a[i]+narz[f(i)])*b[i]);
		printf("%lld\n", ret);
		return;
	}
	for (int i=l; f(i)==f(l); i++)
		ret=max(ret, abs(a[i]+narz[f(i)])*b[i]);
	for (int i=p; f(i)==f(p); i--)
		ret=max(ret, abs(a[i]+narz[f(i)])*b[i]);
	for (int i=f(l)+1; i<f(p); i++)
		ret=max(ret, czyt(i));
	printf("%lld\n", ret);
}

int main()
{
	scanf("%d%d", &n, &q);
	for (int i=2; i<=n; i++)
	{
		int x;
		scanf("%d", &x);
		drz[x].push_back(i);
	}
	for (int i=1; i<=n; i++)
		scanf("%lld", &wa[i]);
	for (int i=1; i<=n; i++)
		scanf("%lld", &wb[i]);
	dfs(1, 0, 0);
	k=f(n);
	for (int i=1; i<=k; i++)
	{
		for (int j=pocz(i); j<=kon(i); j++)
			pos[i].push_back(j);
		sort(pos[i].begin(), pos[i].end(), mniej);
		pos2[i]=pos[i];
		reverse(pos2[i].begin(), pos2[i].end());
		recalc(i);
	}
	//~ debug() << range(a+1, a+1+n);
	//~ debug() << range(b+1, b+1+n);
	while(q--)
	{
		int typ;
		scanf("%d", &typ);
		if (typ==1)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			dodaj(pre[x], post[x], y);
		}
		else
		{
			int x;
			scanf("%d", &x);
			czyt(pre[x], post[x]);
		}
	}
	return 0;
}