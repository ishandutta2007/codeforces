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
const ll mod=1000*1000*1000+7;
using ui=unsigned int;
const int d=32;

int n, m;

vector <pii> graf[nax];

vi cyk;
int bylo[nax];
int jak[nax];

int k;

ui ich[nax];
vector <pii> pol[nax];
int fakt[nax];

map <pii,int> sup;

//~ unordered_map <ui,ll> sta, now;

set <ui> setel;
vector <ui> wsz;
map <ui,int> numuj;
int gdz[1007][1007];
ll now[1007];
ll sta[1007];

void dod(ll &a, ll b)
{
	a=(a+b)%mod;
}

void dfs(int v, int z, int oj)
{
	if (bylo[v])
	{
		cyk.push_back(z^jak[v]);
		return;
	}
	bylo[v]=k;
	jak[v]=z;
	//~ debug() << v;
	for (pii i : graf[v])
		if (i.first!=1 && i.first!=oj)
			dfs(i.first, z^i.second, v);
}

ui lacz(ui a, ui b)
{
	ui ret=(a|b);
	for (int i=0; i<d; i++)
		for (int j=0; j<d; j++)
			if (((a>>i)&1) && ((b>>j)&1))
				ret|=(((ui)1)<<(i^j));
	return ret;
}

void prepro()
{
	wsz.push_back(0);
	setel.insert(0);
	numuj[0]=0;
	for (int i=0; i<d; i++)
	{
		ui x=((ui)1)<<i;
		wsz.push_back(x);
		setel.insert(x);
		numuj[x]=i+1;
	}
	for (int j=0; j<(int)wsz.size(); j++)
	{
		for (int l=0; l<=j; l++)
		{
			ui x=lacz(wsz[j], wsz[l]);
			if (!setel.count(x))
			{
				numuj[x]=wsz.size();
				setel.insert(x);
				wsz.push_back(x);
			}
			gdz[l][j]=gdz[j][l]=numuj[x];
		}
	}
	//~ exit(0);
}

int main()
{
	prepro();
	scanf("%d%d", &n, &m);
	for (int i=1; i<=m; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		graf[a].push_back({b, c});
		graf[b].push_back({a, c});
		sup[{a, b}]=sup[{b, a}]=c;
	}
	for (pii h : graf[1])
	{
		int i=h.first;
		cyk.clear();
		if (bylo[i])
		{
			pol[bylo[i]].push_back(h);
			continue;
		}
		k++;
		pol[k].push_back(h);
		dfs(i, 0, 1);
		sort(cyk.begin(), cyk.end());
		for (int j=0; j<(int)cyk.size(); j+=2)
			ich[k]=lacz(ich[k], ((ui)1)<<cyk[j]);
		fakt[k]=numuj[ich[k]];
	}
	now[0]=1;
	for (int i=1; i<=k; i++)
	{
		for (int j=0; j<(int)wsz.size(); j++)
		{
			sta[j]=now[j];
			now[j]=0;
		}
		assert((int)pol[i].size()<=2);
		if ((int)pol[i].size()==1)
		{
			//~ for (auto j : sta)
			for (int j=0; j<(int)wsz.size(); j++)
			{
				//~ dod(now[j.first], j.second);
				//~ dod(now[lacz(j.first, ich[i])], j.second);
				dod(now[j], sta[j]);
				dod(now[gdz[j][fakt[i]]], sta[j]);
			}
		}
		else
		{
			int a=pol[i][0].first;
			int b=pol[i][1].first;
			int x=pol[i][0].second;
			int y=pol[i][1].second;
			//~ for (auto j : sta)
			for (int j=0; j<(int)wsz.size(); j++)
			{
				//~ dod(now[j.first], j.second);
				//~ dod(now[lacz(j.first, ich[i])], j.second);
				//~ dod(now[lacz(j.first, ich[i])], j.second);
				dod(now[j], sta[j]);
				dod(now[gdz[j][fakt[i]]], sta[j]);
				dod(now[gdz[j][fakt[i]]], sta[j]);
			}
			if (sup.count({a, b}))
			{
				int z=sup[{a, b}];
				ui mas=((ui)1)<<(x^y^z);
				int w=gdz[numuj[mas]][fakt[i]];
				//~ for (auto j : sta)
				for (int j=0; j<(int)wsz.size(); j++)
				{
					dod(now[gdz[j][w]], sta[j]);
					//~ dod(now[lacz(lacz(j.first, ich[i]), ((ui)1)<<(x^y^z))], j.second);
				}
			}
			else
			{
				assert(0);
			}
		}
	}
	ll wyn=0;
	for (int i=0; i<(int)wsz.size(); i++)
		if (!(wsz[i]&1))
			dod(wyn, now[i]);
	printf("%lld\n", wyn);
	return 0;
}