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

void ff()
{
	fflush(stdout);
}

int n;

vi graf[nax];
int ojc[nax];

int k;

int dpdol[nax];
int dpgor[nax];

int hint=1;

void dfs1(int v)
{
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
	{
		ojc[i]=v;
		dfs1(i);
	}
	static vi pom;
	pom.clear();
	dpdol[v]=1;
	for (int i : graf[v])
		pom.push_back(dpdol[i]);
	sort(pom.begin(), pom.end());
	reverse(pom.begin(), pom.end());
	for (int i=0; i<(int)pom.size(); i++)
		dpdol[v]=max(dpdol[v], pom[i]+i);
}

bool mniej(int a, int b)
{
	return dpdol[a]>dpdol[b];
}

int pre[nax];
int suf[nax];

void dfs2(int v)
{
	static vector<pii> pom;
	pom.clear();
	for (int i : graf[v])
		pom.push_back({dpdol[i], i});
	if (v!=hint)
		pom.push_back({dpgor[v], 0});
	sort(pom.begin(), pom.end());
	reverse(pom.begin(), pom.end());
	pre[0]=0;
	int r=pom.size();
	for (int i=0; i<r; i++)
		pre[i+1]=max(pre[i], pom[i].first+i);
	suf[r]=0;
	for (int i=r-1; i>=0; i--)
		suf[i]=max(suf[i+1]+1, pom[i].first);
	for (int i=0; i<r; i++)
	{
		if (!pom[i].second)
			continue;
		dpgor[pom[i].second]=max(1, max(pre[i], suf[i+1]+i));
	}
	for (int i : graf[v])
		dfs2(i);
}

int f(int v)
{
	static vi pom;
	pom.clear();
	for (int i : graf[v])
		pom.push_back(dpdol[i]);
	if (v!=hint)
		pom.push_back(dpgor[v]);
	sort(pom.begin(), pom.end());
	reverse(pom.begin(), pom.end());
	int ret=0;
	if ((int)pom.size()<=2)
	{
		for (int i=0; i<(int)pom.size(); i++)
			ret+=pom[i];
	}
	else
	{
		for (int i=1; i<(int)pom.size(); i++)
			ret=max(ret, pom[i]+i-1+pom[0]);
	}
	return ret;
}

int pyt(int v)
{
	printf("? %d\n", v);
	ff();
	int ret;
	scanf("%d", &ret);
	return ret;
}

void ans(int a, int b)
{
	printf("! %d %d\n", a, b);
	ff();
	exit(0);
}

vi wyn;

pii szukaj(int v)
{
	if ((int)graf[v].empty())
	{
		int x=pyt(v);
		return {x, x==v};
	}
	for (int i : graf[v])
	{
		pii wez=szukaj(i);
		if (wez.second)
			return wez;
		if (wez.first!=v)
			return wez;
	}
	return {v, 1};
}

int main()
{
	scanf("%d", &n);
	vector<pii> kra;
	for (int i=1; i<n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		kra.push_back({a, b});
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	dfs1(1);
	dfs2(1);
	for (int i=1; i<=n; i++)
		k=max(k, f(i));
	
	printf("%d\n", k);
	ff();
	scanf("%d", &hint);
	for (int i=1; i<=n; i++)
	{
		ojc[i]=0;
		dpdol[i]=0;
		dpgor[i]=0;
		graf[i].clear();
	}
	for (pii i : kra)
	{
		int a=i.first;
		int b=i.second;
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	dfs1(hint);
	dfs2(hint);
	
	for (int i=1; i<=n; i++)
		sort(graf[i].begin(), graf[i].end(), mniej);
	
	for (int i : graf[hint])
	{
		if ((int)wyn.size()==2)
			break;
		pii wez=szukaj(i);
		if (wez.first!=hint)
			wyn.push_back(wez.first);
	}
	
	while((int)wyn.size()<2)
		wyn.push_back(hint);
	ans(wyn[0], wyn[1]);
	return 0;
}