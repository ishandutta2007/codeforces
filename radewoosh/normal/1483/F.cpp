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
const int alfa=26;

int n;

vi wek[nax];
int miej[nax];

int ktotu[nax];

char wcz[nax];

int m;
vi dz[nax];
int syn[nax][alfa];
int lit[nax];
int ojc[nax];

int suflink[nax];

vi drz[nax];
int czas;
int pre[nax];
int post[nax];

int wgu[nax];

int wyn;

bool mniej(vi &a, vi &b)
{
	return a.size()<b.size();
}

void dfs1(int v)
{
	czas++;
	pre[v]=czas;
	for (int i : drz[v])
		dfs1(i);
	post[v]=czas;
}

int fen[2*nax];

void pisz(int v, int w)
{
	for (int i=v; i<2*nax; i+=(i&(-i)))
		fen[i]+=w;
}

void czys(int v)
{
	for (int i=v; i<2*nax; i+=(i&(-i)))
		fen[i]=0;
}

int czyt(int a, int b)
{
	int ret=0;
	for (int i=b; i; i-=(i&(-i)))
		ret+=fen[i];
	for (int i=a-1; i; i-=(i&(-i)))
		ret-=fen[i];
	return ret;
}

//~ set<int> uni;

int mater[nax];
int powi[nax];

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		scanf("%s", wcz+1);
		for (int j=1; wcz[j]; j++)
			wek[i].push_back(wcz[j]-'a');
	}
	sort(wek+1, wek+1+n, mniej);
	for (int i=1; i<=n; i++)
	{
		int v=0;
		for (int j : wek[i])
		{
			if (!syn[v][j])
			{
				m++;
				syn[v][j]=m;
				ojc[m]=v;
				lit[m]=j;
				dz[v].push_back(m);
			}
			v=syn[v][j];
		}
		miej[i]=v;
		ktotu[v]=i;
	}
	queue<int> kol;
	kol.push(0);
	while(!kol.empty())
	{
		int v=kol.front();
		kol.pop();
		
		if (ojc[v])
		{
			int it=suflink[ojc[v]];
			while(it && !syn[it][lit[v]])
				it=suflink[it];
			suflink[v]=syn[it][lit[v]];
		}
		
		for (int i : dz[v])
			kol.push(i);
		wgu[v]=wgu[suflink[v]];
		if (ktotu[v])
			wgu[v]=ktotu[v];
	}
	
	//~ debug() << imie(m);
	//~ for (int i=0; i<=m; i++)
		//~ debug() << i << "  " << lit[i] << " " << dz[i] << " " << suflink[i];
	for (int i=1; i<=m; i++)
		drz[suflink[i]].push_back(i);
	dfs1(0);
	
	vector<pii> prze;
	for (int i=1; i<=n; i++)
	{
		int v=0;
		prze.clear();
		int jesz=wek[i].size();
		int poz=0;
		for (int j : wek[i])
		{
			poz++;
			jesz--;
			v=syn[v][j];
			int pacz=v;
			if (!jesz)
				pacz=suflink[pacz];
			if (wgu[pacz])
			{
				int x=wgu[pacz];
				int dlu=wek[x].size();
				while(!prze.empty() && poz-dlu<=prze.back().second-(int)wek[prze.back().first].size())
					prze.pop_back();
				prze.push_back({x, poz});
			}
		}
		//~ debug() << i << " " << prze;
		
		v=0;
		for (int j : wek[i])
		{
			v=syn[v][j];
			pisz(pre[v], 1);
			//~ debug() << "rzut " << v << " " << pre[v] << " " << post[v];
		}
		
		for (pii j : prze)
		{
			mater[j.first]=0;
			powi[j.first]=0;
		}
		for (pii j : prze)
		{
			mater[j.first]++;
			if (mater[j.first]==1)
				powi[j.first]=czyt(pre[miej[j.first]], post[miej[j.first]]);
			//~ debug() << "niby " << j << " " << miej[j.first] << "  "  << pre[miej[j.first]] << " " << post[miej[j.first]] << "   " << powi[j.first];
			if (mater[j.first]==powi[j.first])
				wyn++;
		}
		
		v=0;
		for (int j : wek[i])
		{
			v=syn[v][j];
			czys(pre[v]);
		}
	}
	
	
	printf("%d\n", wyn);
	return 0;
}