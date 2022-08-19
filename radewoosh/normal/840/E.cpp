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

const int nax=50*1007;
const int vax=270;
const int d=256;

int n, q;

int tab[nax];

vector <int> graf[nax];

int oj[nax];
int jump[nax];

int odl[nax];

int naj[nax][vax];

vector <int> dys;

int czy[vax][vax];
int bes[vax];

void licz(int v)
{
	//debug() << "licze " << v;
	//debug() << dys;
	for (int i=0; i<d; i++)
		bes[i]=0;
	for (int i=1; i<=8; i++)
		for (int j=0; j<(1<<i); j++)
			czy[i][j]=0;
	for (int i : dys)
	{
		bes[i>>8]=max(bes[i>>8], i);
		for (int j=1; j<=8; j++)
			czy[j][i>>(16-j)]=1;
	}
	for (int i=0; i<d; i++)
	{
		int zm=0;
		//debug() << "start " << i; 
		for (int j=1; j<=8; j++)
		{
			zm*=2;
			int tu=((i&(1<<(8-j)))>0);
			if (czy[j][zm^1^tu])
				zm=zm^1^tu;
			else
				zm=zm^tu;
			//debug() << "ide w " << zm;
			
		}
		naj[v][i]=(bes[zm]^(i<<8));
	}
	//debug() << "licze " << v;
	//debug() << range(naj[v], naj[v]+7);
}

void dfs(int v)
{
	int u=v;
	dys.clear();
	for (int i=0; i<d; i++)
	{
		dys.push_back(tab[u]^i);
		u=oj[u];
	}
	jump[v]=u;
	if (odl[v]>=d)
		licz(v);
	
	for (int i : graf[v])
	{
		if (i==oj[v])
			continue;
		odl[i]=odl[v]+1;
		oj[i]=v;
		dfs(i);
	}
}

int main()
{
	scanf("%d%d", &n, &q);
	//n=256;
	//q=0;
	for (int i=1; i<=n; i++)
		scanf("%d", &tab[i]);
	//	tab[i]=i;
	for (int i=1; i<n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		//a=i;
		//b=i+1;
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	odl[1]=1;
	dfs(1);
	while(q--)
	{
		int wyn=0;
		int u, v;
		scanf("%d%d", &u, &v);
		int jesz=odl[v]-odl[u]+1;
		int ter=0;
		while(jesz>vax)
		{
			wyn=max(wyn, naj[v][ter>>8]);
			v=jump[v];
			ter+=d;
			jesz-=d;
		}
		while(jesz)
		{
			jesz--;
			wyn=max(wyn, tab[v]^ter);
			v=oj[v];
			ter++;
		}
		printf("%d\n", wyn);
	}
	return 0;
}