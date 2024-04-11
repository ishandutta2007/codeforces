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
const int n1=(1<<20);

int n, m, q;

int per[nax];

pii kra[nax];
int us[nax];

int zap[nax];

vector<pii> wek;

int oj[nax];

int dok[nax];

int k;
vi drz[nax];

int repr[nax];

int fin(int v)
{
	if (v!=oj[v])
		oj[v]=fin(oj[v]);
	return oj[v];
}

void uni(int a, int b)
{
	oj[fin(a)]=fin(b);
}

pii przedz[n1*2];
int czas;
int pre[nax];
int post[nax];

vi jump[nax];

void pisz(int v, pii w)
{
	v+=n1-1;
	przedz[v]=w;
	v>>=1;
	while(v)
	{
		przedz[v]=max(przedz[v*2], przedz[v*2+1]);
		v>>=1;
	}
}

pii czyt(int v, int a, int b, int graa, int grab)
{
	if (a>=graa && b<=grab)
	{
		return przedz[v];
	}
	if (a>grab || b<graa)
	{
		return {0, 0};
	}
	return max(
		czyt((v<<1), a, (a+b)>>1, graa, grab),
		czyt((v<<1)^1, (a+b+2)>>1, b, graa, grab)
	);
}

void dfs1(int v, int ojc)
{
	jump[v].push_back(ojc);
	while(jump[v].back())
	{
		int a=jump[v].back();
		int b=min(jump[v].size(), jump[a].size())-1;
		jump[v].push_back(jump[a][b]);
	}
	czas++;
	pre[v]=czas;
	if (v<=n)
		pisz(pre[v], {per[v], v});
	for (int i : drz[v])
		dfs1(i, v);
	post[v]=czas;
	//~ debug() << v << " " << pre[v] << " " << post[v];
}

int tokorz[nax];

int main()
{
	scanf("%d%d%d", &n, &m, &q);
	for (int i=1; i<=n; i++)
		scanf("%d", &per[i]);
	for (int i=1; i<=m; i++)
	{
		scanf("%d%d", &kra[i].first, &kra[i].second);
	}
	for (int i=1; i<=q; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		if (a==1)
			zap[i]=b;
		else
		{
			zap[i]=-b;
			us[b]=i;
		}
	}
	for (int i=1; i<=m; i++)
		if (!us[i])
			us[i]=q+1;
	for (int i=1; i<=m; i++)
		wek.push_back({us[i], i});
	sort(wek.begin(), wek.end());
	reverse(wek.begin(), wek.end());
	k=n;
	debug() << wek;
	for (int i=1; i<=n; i++)
	{
		oj[i]=i;
		dok[i]=q+1;
		repr[i]=i;
	}
	for (pii h : wek)
	{
		int kied=h.first;
		int i=h.second;
		int a=kra[i].first;
		int b=kra[i].second;
		if (fin(a)==fin(b))
			continue;
		k++;
		drz[k].push_back(repr[fin(a)]);
		drz[k].push_back(repr[fin(b)]);
		dok[k]=kied;
		uni(a, b);
		repr[fin(a)]=k;
	}
	for (int i=1; i<=k; i++)
		tokorz[i]=1;
	for (int i=1; i<=k; i++)
		for (int j : drz[i])
			tokorz[j]=0;
	for (int i=1; i<=k; i++)
		if (tokorz[i])
			dfs1(i, 0);
	//~ dfs1(k, 0);
	for (int i=1; i<=q; i++)
	{
		if (zap[i]<0)
			continue;
		int x=zap[i];
		for (int h=(int)jump[x].size()-1; h>=0; h--)
			if (h<(int)jump[x].size() && dok[jump[x][h]]>=i)
				x=jump[x][h];
		pii wez=czyt(1, 1, n1, pre[x], post[x]);
		//~ debug() << imie(wez);
		printf("%d\n", wez.first);
		if (wez.first)
			pisz(pre[wez.second], {0, 0});
	}
	return 0;
}