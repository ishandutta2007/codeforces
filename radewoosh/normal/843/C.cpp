//PRZEMYSL ASSERTY

//SPRAWDZ CORNER CASE'Y, MINIMALNE I MAKSYMALNE WEJCIE I WYJCIE

//MODULO = 1

//while (clock()<=69*CLOCKS_PER_SEC)

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

const int nax=200*1007;

int n;
vector <int> graf[nax];

set <int> sgraf[nax];

int roz[nax];

vector <int> ceny;
int iscen[nax];

vector <pair <int, pair <int,int> > > ops;

vector <int> lisy;

void dfs1(int v, int oj)
{
	roz[v]=1;
	int ok=1;
	for (int i : graf[v])
	{
		if (i==oj)
			continue;
		dfs1(i, v);
		if (roz[i]*2>n)
			ok=0;
		roz[v]+=roz[i];
	}
	if ((n-roz[v])*2>n)
		ok=0;
	if (ok)
	{
		iscen[v]=1;
		ceny.push_back(v);
	}
}

void usu(int a, int b)
{
	sgraf[a].erase(b);
	sgraf[b].erase(a);
}

void dod(int a, int b)
{
	sgraf[a].insert(b);
	sgraf[b].insert(a);
}

void dfs2(int v, int oj)
{
	if (graf[v].size()==1)
		lisy.push_back(v);
	for (int i : graf[v])
	{
		if (i==oj)
			continue;
		dfs2(i, v);
	}
}

void dfs3(int v, int oj)
{
	//debug() << "z " << oj << " w " << v;
	if ((int)sgraf[v].size()<=2)
	{
		for (int i : sgraf[v])
			if (i!=oj)
			{
				dfs3(i, v);
				break;
			}
		return;
	}
	else
	{
		int x=lisy.back();
		lisy.pop_back();
		ops.push_back({oj,{v, x}});
		usu(oj, v);
		dod(oj, x);
		dfs3(x, oj);
	}
}

int dfs4(int v, int oj)
{
	if (sgraf[v].size()==1)
	{
		return v;
	}
	else
	{
		int x;
		for (int i : sgraf[v])
			if (i!=oj)
				x=dfs4(i, v);
		ops.push_back({oj,{v, x}});
		return x;
	}
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
		sgraf[a].insert(b);
		sgraf[b].insert(a);
	}
	if (n<=3)
	{
		printf("0\n");
		return 0;
	}
	dfs1(1, 0);
	debug() << imie(ceny);
	for (int i : ceny)
	{
		for (int j : graf[i])
		{
			//debug() << " pacze1 z " << i << " na " << j;
			if (!iscen[j])
			{
				lisy.clear();
				dfs2(j, i);
				dfs3(j, i);
			}
		}
	}
	for (int i : ceny)
	{
		set <int> ter=sgraf[i];
		for (int j : ter)
		{
			//debug() << " pacze2 z " << i << " na " << j;
			if (!iscen[j])
			{
				dfs4(j, i);
			}
		}
	}
	printf("%d\n", (int)ops.size());
	for (auto i : ops)
		printf("%d %d %d\n", i.first, i.second.first, i.second.second);
	return 0;
}