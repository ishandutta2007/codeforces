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
const int nax=400*1007;

int n;

pii tab[nax];

vector<pii> pary[nax];

pii sup[nax];

struct ciag
{
	int id=0;
	ciag *lew=NULL;
	ciag *pra=NULL;
	ciag()
	{
		
	}
	ciag(int a, ciag *b, ciag *c)
	{
		id=a;
		lew=b;
		pra=c;
	}
};

ciag *polacz(ciag *a, ciag *b)
{
	ciag *ret=new ciag;
	ret->lew=a;
	ret->pra=b;
	return ret;
}

ciag *pocz[nax/2];
ciag *kon[nax/2];

ciag *wyns=new ciag;

vi wyn;

void nope()
{
	printf("NO\n");
	exit(0);
}

int gdzpom[nax];
int *gdz=gdzpom+(nax/2);

int juz[nax];

void dfs(ciag *v)
{
	if (v==NULL)
		return;
	if (v->id)
		wyn.push_back(v->id);
	dfs(v->lew);
	dfs(v->pra);
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=2*n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		tab[i]={a, b};
		pary[abs(a)].push_back(tab[i]);
	}
	queue<int> kol;
	int k=0;
	for (int i=1; i<=n; i++)
	{
		if (pary[i][0].first<0)
			swap(pary[i][0], pary[i][1]);
		sup[i]={pary[i][0].second, pary[i][1].second};
		//~ debug() << sup[i];
		//~ pocz[i].push_back(sup[i].first);
		//~ kon[i].push_back(sup[i].second);
		pocz[i]=new ciag(sup[i].first, NULL, NULL);
		kon[i]=new ciag(sup[i].second, NULL, NULL);
		gdz[sup[i].first]=i;
		gdz[sup[i].second]=i;
		kol.push(abs(i));
	}
	while(!kol.empty())
	{
		int v=kol.front();
		v=abs(v);
		kol.pop();
		if (juz[v])
			continue;
		if (gdz[-v]==gdz[v])
		{
			int s=gdz[v];
			pii w=sup[s];
			if (w.first<0)
				nope();
			//~ debug() << v << " " << s << " " << sup[s] << " " << pocz[s] << " " << kon[s];
			wyns=polacz(wyns, pocz[s]);
			//~ debug() << imie(wyn);
			wyns=polacz(wyns, kon[s]);
			//~ debug() << imie(wyn);
			juz[v]=1;
			continue;
		}
		int a=gdz[-v];
		int b=gdz[v];
		//~ debug() << imie(v) << imie(sup[a]) << imie(sup[b]);
		if (sup[b].first==v && sup[a].first==-v)
		{
			pocz[b]=polacz(pocz[b], pocz[a]);
			pocz[b]=polacz(pocz[b], kon[a]);
			juz[v]=1;
			sup[b]={sup[a].second, sup[b].second};
			kol.push(sup[b].first);
			kol.push(sup[b].second);
			gdz[sup[b].first]=b;
			gdz[sup[b].second]=b;
			//~ debug() << "a spoko " << v;
			continue;
		}
		if (sup[b].second==v && sup[a].second==-v)
		{
			pocz[b]=polacz(pocz[b], kon[b]);
			pocz[b]=polacz(pocz[b], kon[a]);
			kon[a]=pocz[b];
			juz[v]=1;
			sup[a]={sup[a].first, sup[b].first};
			kol.push(sup[a].first);
			kol.push(sup[a].second);
			gdz[sup[a].first]=a;
			gdz[sup[a].second]=a;
			//~ debug() << "b spoko " << v;
			continue;
		}
		if (sup[b].second==v && sup[a].first==-v)
		{
			pocz[b]=polacz(pocz[b], kon[b]);
			pocz[b]=polacz(pocz[b], pocz[a]);
			kon[b]=kon[a];
			juz[v]=1;
			sup[b]={sup[b].first, sup[a].second};
			kol.push(sup[b].first);
			kol.push(sup[b].second);
			gdz[sup[b].first]=b;
			gdz[sup[b].second]=b;
			//~ debug() << "c spoko " << v;
			continue;
		}
	}
	//~ for (int i=1; i<=n; i++)
	//~ {
	//~ }
	dfs(wyns);
	debug() << wyn;
	if ((int)wyn.size()!=2*n)
		nope();
	printf("YES\n");
	map<int,int> mapa;
	for (int i=1; i<=2*n; i++)
		mapa[tab[i].second]=tab[i].first;
	for (int i : wyn)
		printf("%d %d\n", mapa[i], i);
	return 0;
}