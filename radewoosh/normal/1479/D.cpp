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
const int nax=300*1007;
const int glod=607;

int n, q;

int tab[nax];
vi graf[nax];

int wyn[nax];

pii sci[nax];
pii prze[nax];
pii rep[nax];

int dos[nax];

int ojc[nax];

int czas;
int pre[nax];
int post[nax];

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
	czas++;
	pre[v]=czas;
	for (int i : graf[v])
	{
		ojc[i]=v;
		dfs1(i);
	}
	czas++;
	post[v]=czas;
}

bool mniej(int a, int b)
{
	return rep[a]<rep[b];
}

int nas[nax];
int parz[nax];

int licz;
int lew[nax];
int pra[nax];
int ile[nax];

int f(int v)
{
	return (v+glod-1)/glod;
}

int ga=1;
int gb=1;

void flip(int v)
{
	ile[f(v)]-=parz[v];
	parz[v]^=1;
	ile[f(v)]+=parz[v];
}

void rusz(int z, int gdz)
{
	if (nas[gdz])
	{
		flip(tab[z]);
		nas[z]=0;
	}
	else
	{
		flip(tab[gdz]);
		nas[gdz]=1;
	}
}

int r;
int pisz[nax];

int przo(int kto, int kogo)
{
	return pre[kto]<=pre[kogo] && post[kto]>=post[kogo];
}

int query(int a, int b)
{
	//~ debug() << "pyt " << a << " " << b;
	for (int i=1; i<=licz; i++)
		if (ile[i] && !(pra[i]<a || lew[i]>b))
			for (int j=lew[i]; j<=pra[i]; j++)
				if (parz[j] && j>=a && j<=b)
				{
					//~ debug() << "mam " << j;
					return j;
				}
	//~ debug() << "kon";
	return -1;
}

int main()
{
	scanf("%d%d", &n, &q);
	for (int i=1; i<=n; i++)
	{
		scanf("%d", &tab[i]);
	}
	for (int i=1; i<n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	debug() << "a";
	dfs1(1);
	debug() << "b";
	for (int i=1; i<=q; i++)
	{
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		sci[i]={a, b};
		prze[i]={c, d};
		rep[i]={pre[a]/glod, pre[b]};
		if (rep[i].first&1)
			rep[i].second*=-1;
		dos[i]=i;
		wyn[i]=-1;
	}
	debug() << "c";
	licz=f(n);
	for (int i=1; i<=licz; i++)
		lew[i]=n+1;
	for (int i=1; i<=n; i++)
	{
		lew[f(i)]=min(lew[f(i)], i);
		pra[f(i)]=max(pra[f(i)], i);
	}
	debug() << "d";
	sort(dos+1, dos+1+q, mniej);
	nas[1]=1;
	flip(tab[1]);
	debug() << "e";
	for (int h=1; h<=q; h++)
	{
		int v=dos[h];
		int p=sci[v].first;
		int q=sci[v].second;
		//~ debug() << "chce " << ga << " " << gb << " " << sci[v];
		for (int w=0; w<2; w++)
		{
			while(!przo(ga, p))
			{
				rusz(ga, ojc[ga]);
				ga=ojc[ga];
			}
			r=0;
			while(p!=ga)
			{
				r++;
				pisz[r]=p;
				p=ojc[p];
			}
			for (int j=r; j; j--)
			{
				rusz(ga, pisz[j]);
				ga=pisz[j];
			}
			swap(ga, gb);
			swap(p, q);
		}
		//~ debug() << imie(ga) << imie(gb) << imie(v);
		//~ debug() << range(parz+1, parz+1+n) << range(nas+1, nas+1+n);
		wyn[v]=query(prze[v].first, prze[v].second);
	}
	//~ debug() << "f";
	
	for (int i=1; i<=q; i++)
		printf("%d\n", wyn[i]);
	return 0;
}