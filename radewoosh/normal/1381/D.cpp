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

int n, x, y;

vi graf[nax];

int nasc[nax];
vi sci;
int wonsz;

vi stos;

vi kole;
 
void tak()
{
	printf("YES\n");
}
 
void nie()
{
	printf("NO\n");
}

int gle[nax];

int ok[nax];
int okx[nax];
int oky[nax];

void dfs1(int v, int oj)
{
	stos.push_back(v);
	if (v==y)
		sci=stos;
	for (int i : graf[v])
		if (i!=oj)
			dfs1(i, v);
	stos.pop_back();
}

void dfs_gle(int v, int oj)
{
	gle[v]=1;
	vi jakie;
	for (int i : graf[v])
	{
		if (i==oj || nasc[i])
			continue;
		dfs_gle(i, v);
		gle[v]=max(gle[v], gle[i]+1);
		jakie.push_back(gle[i]);
		if (ok[i])
			ok[v]=1;
	}
	sort(jakie.begin(), jakie.end());
	reverse(jakie.begin(), jakie.end());
	//~ debug() << v << " " << jakie;
	if ((int)jakie.size()>=2 && jakie[1]>=wonsz-1)
		ok[v]=1;
}

int lin[nax];
int lew[nax];
int pra[nax];

void test()
{
	scanf("%d%d%d", &n, &x, &y);
	for (int i=1; i<=n; i++)
		graf[i].clear();
	for (int i=1; i<n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	for (int i=1; i<=n; i++)
		nasc[i]=ok[i]=0;
	dfs1(x, 0);
	wonsz=sci.size();
	for (int i : sci)
		nasc[i]=1;
	for (int i : sci)
		dfs_gle(i, 0);
	//~ debug() << range(ok+1, ok+1+n);
	//~ if (ok[x] || ok[y])
	//~ {
		//~ tak();
		//~ return;
	//~ }
	for (int i=1; i<=wonsz; i++)
	{
		lin[i]=gle[sci[i-1]];
	}
	int zl=1;
	int zp=wonsz;
	int najl=zp;
	int najp=1;
	//~ debug() << range(lin+1, lin+1+wonsz);
	for (int h=0; h<700; h++)
	{
		if (h&1)
		{
			int naj=0;
			for (int i=1; i<=zl && i<=wonsz; i++)
			{
				naj=max(naj, lin[i]-i);
			}
			zl=1-naj;
			zp=wonsz-naj;
		}
		else
		{
			int naj=0;
			for (int i=max(zp, 1); i<=wonsz; i++)
			{
				naj=max(naj, lin[i]-(wonsz+1-i));
			}
			zl=1+naj;
			zp=wonsz+naj;
		}
		najp=max(najp, zl);
		najl=min(najl, zp);
		//~ if (h>694)
			//~ debug() << imie(zl) << imie(zp);
	}
	//~ debug() << imie(najl);
	//~ debug() << imie(najp);
	for (int i=1; i<=min(najp, wonsz); i++)
	{
		if (ok[sci[i-1]])
		{
			debug() << "a";
			tak();
			return;
		}
	}
	for (int i=max(1, najl); i<=wonsz; i++)
	{
		if (ok[sci[i-1]])
		{
			debug() << "b";
			tak();
			return;
		}
	}
	for (int i=0; i<=wonsz+1; i++)
		lew[i]=pra[i]=0;
	for (int i=1; i<=wonsz; i++)
		lew[i]=max(lew[i-1]+1, lin[i]);
	for (int i=wonsz; i; i--)
		pra[i]=max(pra[i+1]+1, lin[i]);
	//~ debug() << range(lew+1, lew+1+wonsz);
	//~ debug() << range(pra+1, pra+1+wonsz);
	for (int i=max(1, najl); i<=min(najp, wonsz); i++)
	{
		if (lin[i]>=wonsz && lew[i-1]+1>=wonsz && pra[i+1]+1>=wonsz)
		{
			debug() << "c";
			tak();
			return;
		}
	}
	nie();
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}