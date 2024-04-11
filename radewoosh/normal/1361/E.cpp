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

int n, m;
vi graf[nax];

int los()
{
	int ret=0;
	for (int i=0; i<30; i++)
		ret=(ret*2+(rand()&1));
	return ret;
}

int nasto[nax];
int bylo[nax];
int czyok;

vi drz[nax];
vi gor[nax];

void dfs1(int v)
{
	bylo[v]=1;
	nasto[v]=1;
	for (int i : graf[v])
	{
		if (bylo[i])
		{
			if (!nasto[i])
				czyok=0;
		}
		else
		{
			dfs1(i);
		}
	}
	nasto[v]=0;
}

int czyinter(int v)
{
	czyok=1;
	for (int i=1; i<=n; i++)
		bylo[i]=nasto[i]=0;
	dfs1(v);
	return czyok;
}

vi jump[nax];
vi naj[nax];
int gle[nax];

int dajnaj(int v)
{
	if (gor[v].empty())
		return nax;
	int ret=nax;
	for (int i : gor[v])
		ret=min(ret, gle[i]);
	return ret;
}

void dfs2(int v, int ojc=0)
{
	
	bylo[v]=1;
	nasto[v]=1;
	for (int i : graf[v])
	{
		if (bylo[i])
		{
			gor[v].push_back(i);
		}
	}
	//~ jump[v].clear();
	//~ naj[v].clear();
	//~ jump[v].push_back(ojc);
	//~ naj[v].push_back(dajnaj(v));
	//~ while(jump[v].back())
	//~ {
		//~ int a=jump[v].back();
		//~ int b=min(jump[v].size(), jump[a].size())-1;
		//~ jump[v].push_back(jump[a][b]);
		//~ int x=min(naj[v].back(), naj[a][b]);
		//~ naj[v].push_back(x);
	//~ }
	for (int i : graf[v])
	{
		if (!bylo[i])
		{
			gle[i]=gle[v]+1;
			drz[v].push_back(i);
			dfs2(i, v);
		}
	}
	nasto[v]=0;
}

int dob[nax];
vi wyn;

int tamodj[nax];
ll tamodjs[nax];

int skocz(int v, int ile)
{
	int ret=nax;
	for (int i=20; i>=0; i--)
	{
		if (ile&(1<<i))
		{
			ret=min(ret, naj[v][i]);
			v=jump[v][i];
		}
	}
	return ret;
}

int kto[nax];

pll dfs3(int v, int ojc=0)
{
	int ret=0;
	ll rets=0;
	for (int i : drz[v])
	{
		pll wez=dfs3(i, v);
		ret+=wez.first;
		rets+=wez.second;
	}
	ret-=tamodj[v];
	rets-=tamodjs[v];
	tamodj[v]=0;
	tamodjs[v]=0;
	//~ debug() << v << " " << ret << " " << drz[v] << " " << gor[v];
	for (int i : gor[v])
	{
		ret++;
		tamodj[i]++;
		rets+=i;
		tamodjs[i]+=i;
	}
	if (ret==1)
	{
		int g=rets;
		//~ debug() << v << " : " << g;
		//~ if (skocz(v, gle[v]-gle[g])>=gle[g])
			//~ dob[v]=1;
		//~ debug() << "po";
		kto[v]=g;
	}
	else
		kto[v]=0;
	return {ret, rets};
}

void dfs4(int v, int ojc=0)
{
	if (kto[v] && dob[kto[v]])
		dob[v]=1;
	for (int i : drz[v])
	{
		dfs4(i, v);
	}
}

void test()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; i++)
		graf[i].clear();
	for (int i=1; i<=m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graf[a].push_back(b);
	}
	int c=-1;
	for (int h=1; h<=100 && c==-1; h++)
	{
		int x=los()%n+1;
		if (czyinter(x))
			c=x;
	}
	if (c==-1)
	{
		printf("-1\n");
		return;
	}
	//~ c=1;
	for (int i=1; i<=n; i++)
	{
		bylo[i]=0;
		drz[i].clear();
		gor[i].clear();
		dob[i]=0;
	}
	wyn.clear();
	gle[c]=1;
	dfs2(c);
	dob[c]=1;
	debug() << imie(c);
	dfs3(c);
	dfs4(c);
	for (int i=1; i<=n; i++)
		if (dob[i])
		//~ if (czyinter(i))
			wyn.push_back(i);
	debug() << imie(wyn);
	if ((int)wyn.size()*5<n)
	{
		printf("-1\n");
	}
	else
	{
		//~ sort(wyn.begin(), wyn.end());
		for (int i : wyn)
			printf("%d ", i);
		printf("\n");
	}
}

int main()
{
	srand(time(0));
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}