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

using ll=long long;
const int nax=200*1007;

int n;

vector <int> graf[nax];

char wcz[nax];

ll hasz[nax];
ll tab[nax];

int bylcen[nax];
 
vector <int> spo;
int roz[nax];
int maxroz[nax];

ll wyn[nax];

vector <int> check;

int mapa[(1<<22)+7];

void dfs1(int v, int oj)
{
	roz[v]=1;
	maxroz[v]=0;
	spo.push_back(v);
	for (int i : graf[v])
	{
			if (i==oj || bylcen[i])
					continue;
			dfs1(i, v);
			roz[v]+=roz[i];
			maxroz[v]=max(maxroz[v], roz[i]);
	}
}

int pyt(int v)
{
	return mapa[v];
}

void dfs_zbierz(int v, int oj, int h, int r)
{
	h^=tab[v];
	mapa[h]+=r;
	for (int i : graf[v])
		if (i!=oj && !bylcen[i])
			dfs_zbierz(i, v, h, r);
}

ll dfs_licz(int v, int oj, int h)
{
	h^=tab[v];
	ll ret=0;
	for (ll i : check)
		ret+=pyt(h^i);
	for (int i : graf[v])
		if (i!=oj && !bylcen[i])
			ret+=dfs_licz(i, v, h);
	wyn[v]+=ret;
	return ret;
}

void szukaj(int v)
{
	if (bylcen[v])
			return;
	spo.clear();
	dfs1(v, 0);
	int c=-1;
	int ss=spo.size();
	for (int i : spo)
			if (maxroz[i]*2<=ss && (ss-roz[i])*2<=ss)
					c=i;
	assert(c!=-1);
	
	debug() << c;
	
	vector <int> wek;
	
	for (int i : graf[c])
		if (!bylcen[i])
			wek.push_back(i);
	
	//~ mapa.clear();
	for (int i : wek)
		dfs_zbierz(i, c, tab[c], 1);
	mapa[tab[c]]++;
	ll kum=1;
	for (ll i : check)
		kum+=pyt(i);
	for (int i : wek)
	{
		dfs_zbierz(i, c, tab[c], -1);
		kum+=dfs_licz(i, c, 0LL);
		dfs_zbierz(i, c, tab[c], 1);
	}
	wyn[c]+=kum/2;
	mapa[tab[c]]--;
	for (int i : wek)
		dfs_zbierz(i, c, tab[c], -1);
	
	//~ debug() << range(wyn+1, wyn+1+n);

	bylcen[c]=1;
	for (int i : graf[c])
			szukaj(i);
}

int main()
{
	srand(time(0));
	scanf("%d", &n);
	
	for (int i=1; i<n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	scanf("%s", wcz+1);
	for (int i='a'; i<='t'; i++)
	{
		hasz[i-'a']=(1<<(i-'a'));
		check.push_back(hasz[i-'a']);
	}
	for (int i=1; i<=n; i++)
		tab[i]=hasz[wcz[i]-'a'];
	check.push_back(0);
	//~ debug() << range(tab+1, tab+1+n);
	szukaj(1);
	
	for (int i=1; i<=n; i++)
		printf("%lld ", wyn[i]);
	printf("\n");
	
	return 0;
}