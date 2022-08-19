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
const ll mod=1000*1000*1000+7;

int n;
vi graf[nax];

int pre[nax];
int post[nax];
int czas;

int tab[nax];

int ojc[nax];

vector <pii> pary[nax];

ll wyn=1;

void nope()
{
	printf("0\n");
	exit(0);
}

void dfs1(int v, int o)
{
	czas++;
	pre[v]=czas;
	ojc[v]=o;
	for (int &i : graf[v])
	{
		if (i==ojc[v])
		{
			swap(i, graf[v].back());
			graf[v].pop_back();
			break;
		}
	}
	for (int i : graf[v])
		dfs1(i, v);
	post[v]=czas;
}

int oper;

int lca(int a, int b)
{
	while(a!=b)
	{
		if (pre[a]<pre[b])
			swap(a, b);
		oper++;
		a=ojc[a];
	}
	if (oper>5*1000*1000)
		nope();
	return a;
}

vi sci(int a, int b)
{
	vi ret{a};
	while(a!=b)
	{
		a=ojc[a];
		ret.push_back(a);
	}
	return ret;
}

void rob(int v)
{
	int w=lca(v, tab[v]);
	if (w==v)
	{
		vi wez=sci(tab[v], v);
		int r=wez.size();
		pary[v].push_back({v, wez[r-2]});
		for (int i=r-2; i>0; i--)
			pary[wez[i]].push_back({0, wez[i-1]});
		pary[tab[v]].push_back({0, tab[v]});
		return;
	}
	if (w==tab[v])
	{
		vi wez=sci(v, tab[v]);
		int r=wez.size();
		pary[tab[v]].push_back({wez[r-2], tab[v]});
		for (int i=r-2; i>0; i--)
			pary[wez[i]].push_back({wez[i-1], 0});
		pary[v].push_back({v, 0});
		return;
	}
	vi raz=sci(v, w);
	vi dwa=sci(tab[v], w);
	
	
	for (int i=((int)dwa.size())-2; i>0; i--)
		pary[dwa[i]].push_back({0, dwa[i-1]});
		
	for (int i=((int)raz.size())-2; i>0; i--)
		pary[raz[i]].push_back({raz[i-1], 0});
		
	pary[v].push_back({v, 0});
	pary[tab[v]].push_back({0, tab[v]});
	
	int rr=raz.size();
	int rd=dwa.size();
	
	pary[w].push_back({raz[rr-2], dwa[rd-2]});
}

int foj[nax];

int in[nax];
int out[nax];

int fin(int v)
{
	if (v!=foj[v])
		foj[v]=fin(foj[v]);
	return foj[v];
}

void uni(int a, int b)
{
	foj[fin(a)]=fin(b);
}

void solve(int v)
{
	sort(pary[v].begin(), pary[v].end());
	pary[v].resize(unique(pary[v].begin(), pary[v].end())-pary[v].begin());
	vi wie{v};
	if (v>1)
		wie.push_back(0);
	for (int i : graf[v])
		wie.push_back(i);
	int r=wie.size();
	for (int i : wie)
	{
		foj[i]=i;
		in[i]=0;
		out[i]=0;
	}
	for (pii i : pary[v])
	{
		out[i.first]++;
		in[i.second]++;
	}
	for (int i : wie)
	{
		if (in[i]>1 || out[i]>1)
			nope();
	}
	int lacz=0;
	for (pii i : pary[v])
	{
		int a=i.first;
		int b=i.second;
		if (fin(a)==fin(b))
		{
			lacz++;
		}
		else
		{
			uni(a, b);
		}
	}
	int spo=0;
	for (int i : wie)
		spo+=(foj[i]==i);
	if (lacz && spo>1)
		nope();
	//~ if (v==1)
		//~ spo--;
	//~ debug() << imie(v) << " " << imie(spo);
	for (int i=1; i<spo; i++)
		wyn=(wyn*i)%mod;
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	for (int i=1; i<=n; i++)
		scanf("%d", &tab[i]);
	dfs1(1, 0);
	//~ pary[1].push_back({0, 1});
	for (int i=1; i<=n; i++)
	{
		if (!tab[i])
			continue;
		if (tab[i]==i)
			nope();
		rob(i);
	}
	for (int i=1; i<=n; i++)
		debug() << i << " " << pary[i];
	for (int i=1; i<=n; i++)
		solve(i);
	//~ debug() << "dod";
	printf("%lld\n", wyn);
	return 0;
}