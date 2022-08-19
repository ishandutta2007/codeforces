//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
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
const int d=300;
const ll inf=1007*1007*1007;

int q;

set <int> nadal[2];

int alive[nax];
vector <pll> war[nax][2];
ll tab[nax][2];
ll mini[nax][2];
ll suma[nax][2];

vll pom;

void wygladz(int v, int t)
{
	if (t==2)
	{
		wygladz(v, 0);
		wygladz(v, 1);
		return;
	}
	int a=v*d;
	int b=(v+1)*d-1;
	war[v][t].clear();
	pom.clear();
	for (int i=a; i<=b; i++)
	{
		tab[i][t]=min(tab[i][t], mini[v][t]);
		if (alive[i]==2)
			pom.push_back(tab[i][t]);
	}
	sort(pom.begin(), pom.end());
	suma[v][t]=0;
	for (ll i : pom)
	{
		suma[v][t]+=i;
		if (war[v][t].empty() || war[v][t].back().first!=i)
			war[v][t].push_back({i, 0});
		war[v][t].back().second++;
	}
}

void obudz(int v)
{
	//~ debug() << "budze " << v;
	wygladz(v/d, 2);
}

void fast(int v, ll w, int t)
{
	mini[v][t]=min(mini[v][t], w);
	int ile=0;
	while(!war[v][t].empty() && war[v][t].back().first>=w)
	{
		suma[v][t]-=war[v][t].back().first*war[v][t].back().second;
		ile+=war[v][t].back().second;
		war[v][t].pop_back();
	}
	suma[v][t]+=ile*w;
	if (ile)
		war[v][t].push_back({w, ile});
}

void dodaj()
{
	int a, b;
	ll y;
	int t;
	scanf("%d%d%lld", &a, &b, &y);
	t=(y>0);
	y=abs(y);
	b--;
	while(1)
	{
		int x=*nadal[t].lower_bound(a);
		if (x>b)
			break;
		nadal[t].erase(x);
		alive[x]++;
		if (alive[x]==2)
			obudz(x);
	}
	if ((a/d)+1>=(b/d))
	{
		for (int i=a; i<=b; i++)
			tab[i][t]=min(tab[i][t], y);
		wygladz(a/d, t);
		wygladz(b/d, t);
		return;
	}
	for (int i=a; (i/d)==(a/d); i++)
		tab[i][t]=min(tab[i][t], y);
	wygladz(a/d, t);
	for (int i=b; i>=0 && (i/d)==(b/d); i--)
		tab[i][t]=min(tab[i][t], y);
	wygladz(b/d, t);
	for (int i=(a/d)+1; i<(b/d); i++)
		fast(i, y, t);
}

ll f1(int v)
{
	return (alive[v]/2)*(tab[v][0]+tab[v][1]);
}

void pytanie()
{
	int a, b;
	scanf("%d%d", &a, &b);
	b--;
	wygladz(a/d, 2);
	wygladz(b/d, 2);
	ll ret=0;
	if ((a/d)+1>=(b/d))
	{
		for (int i=a; i<=b; i++)
		{
			debug() << i << " " << f1(i);
			ret+=f1(i);
		}
	}
	else
	{
		for (int i=a; (i/d)==(a/d); i++)
			ret+=f1(i);
		for (int i=b; i>=0 && (i/d)==(b/d); i--)
			ret+=f1(i);
		for (int i=(a/d)+1; i<(b/d); i++)
			ret+=suma[i][0]+suma[i][1];
	}
	
	
	printf("%lld\n", ret);
}

int main()
{
	scanf("%d", &q);
	for (int i=0; i<nax; i++)
	{
		for (int j=0; j<2; j++)
		{
			nadal[j].insert(i);
			tab[i][j]=inf;
			nadal[j].insert(i);
			mini[i][j]=inf;
		}
	}
	while(q--)
	{
		int typ;
		scanf("%d", &typ);
		if (typ==1)
		{
			dodaj();
		}
		else
		{
			pytanie();
		}
	}
	return 0;
}