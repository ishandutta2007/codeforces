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
const int nax=2000*1007;

int n, m, q;
int k;

vi graf[nax];

int tab[nax];
int star[nax];

int wyn[nax];

vector <pair<int,pii>> eve[nax];

int wnum(int a, int b)
{
	return (a-1)*m+b;
}

void edge(int a, int b)
{
	graf[a].push_back(b);
	graf[b].push_back(a);
}

int oj[nax];

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

int czas;
int ost[nax];

void cons(vector <pair<int,pii> > wek)
{
	//~ debug() << wek;
	{
		czas++;
		vector <pii> sta;
		for (auto i : wek)
			sta.push_back({i.second.first, i.first});
		sort(sta.begin(), sta.end());
		for (auto h : sta)
		{
			int mom=h.first;
			int v=h.second;
			wyn[mom]++;
			ost[v]=czas;
			oj[v]=v;
			for (int i : graf[v])
			{
				if (ost[i]==czas && fin(i)!=fin(v))
				{
					uni(v, i);
					wyn[mom]--;
				}
			}
		}
	}
	{
		czas++;
		vector <pii> now;
		for (auto i : wek)
			now.push_back({i.second.second, i.first});
		sort(now.begin(), now.end());
		reverse(now.begin(), now.end());
		for (auto h : now)
		{
			int mom=h.first;
			int v=h.second;
			wyn[mom+1]--;
			ost[v]=czas;
			oj[v]=v;
			for (int i : graf[v])
			{
				if (ost[i]==czas && fin(i)!=fin(v))
				{
					uni(v, i);
					wyn[mom+1]++;
				}
			}
		}
	}
}

int main()
{
	scanf("%d%d%d", &n, &m, &q);
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=m; j++)
		{
			if (j<m)
				edge(wnum(i, j), wnum(i, j+1));
			if (i<n)
				edge(wnum(i, j), wnum(i+1, j));
		}
	}
	k=n*m;
	for (int i=1; i<=q; i++)
	{
		int x, y, c;
		scanf("%d%d%d", &x, &y, &c);
		int v=wnum(x, y);
		if (c==tab[v])
			continue;
		eve[tab[v]].push_back({v, {star[v], i-1}});
		star[v]=i;
		tab[v]=c;
	}
	for (int i=1; i<=k; i++)
		eve[tab[i]].push_back({i, {star[i], q}});
	//~ for (int i=0; i<nax; i++)
		//~ if (!eve[i].empty())
			//~ debug() << i << " " << eve[i];
	for (int i=0; i<nax; i++)
		if (!eve[i].empty())
			cons(eve[i]);
	//~ debug() << range(wyn, wyn+1+q);
	for (int i=0; i<q; i++)
		wyn[i+1]+=wyn[i];
	for (int i=1; i<=q; i++)
		printf("%d\n", wyn[i]);
	return 0;
}