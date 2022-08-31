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

const int nax=307;
int d;
using ll=long long;
const ll inf=1e18;

int x, k, n, q;

struct mac
{
	ll tab[nax][nax];
	mac()
	{
		for (int i=0; i<nax; i++)
			for (int j=0; j<nax; j++)
				tab[i][j]=inf;
	}
	mac(ll v)
	{
		for (int i=0; i<nax; i++)
			for (int j=0; j<nax; j++)
				tab[i][j]=inf;
		for (int i=0; i<nax; i++)
			tab[i][i]=v;
	}
	void wypisz()
	{
		for (int i=0; i<d; i++)
			debug() << range(tab[i], tab[i]+d);
	}
};

mac operator * (mac a, mac b)
{
	mac ret=mac();
	for (int i=0; i<d; i++)
		for (int j=0; j<d; j++)
			for (int l=0; l<d; l++)
				ret.tab[i][l]=min(ret.tab[i][l], a.tab[i][j]+b.tab[j][l]);
	return ret;
}

mac pot(mac a, int wyk)
{
	mac ret=mac(0);
	while(wyk)
	{
		if (wyk&1)
			ret=ret*a;
		a=a*a;
		wyk>>=1;
	}
	return ret;
}

mac start, prze;

ll skok[nax];

int num[nax];
int cotu[nax];

int czysuw[nax];

map <int,ll> faj;

int czyfaj(int a)
{
	return faj.count(a);
}

void przesun(int v, int u)
{
	debug() << "z " << v << " do " << u;
	if (v+1<u)
	{
		start=start*pot(prze, u-v);
		return;
	}
	mac tu=prze;
	for (int i=0; i<d; i++)
	{
		if (czysuw[i])
			continue;
		for (int j=1; j<=k; j++)
		{
			int now=(cotu[i]|(1<<j))/2;
			if (__builtin_popcount(now)!=x)
				continue;
			if (czyfaj(v+j))
				tu.tab[i][num[now]]+=faj[v+j];
		}
	}
	start=start*tu;
}

int main()
{
	scanf("%d%d%d%d", &x, &k, &n, &q);
	start=mac(0);
	prze=mac();
	for (int i=1; i<=k; i++)
		scanf("%lld", &skok[i]);
	for (int i=0; i<(1<<k); i++)
	{
		if (__builtin_popcount(i)==x)
		{
			num[i]=d;
			cotu[d]=i;
			d++;
		}
	}
	for (int i=0; i<d; i++)
	{
		if (!(cotu[i]&1))
		{
			prze.tab[i][num[cotu[i]/2]]=0;
			czysuw[i]=1;
			continue;
		}
		for (int j=1; j<=k; j++)
		{
			int now=(cotu[i]|(1<<j))/2;
			if (__builtin_popcount(now)!=x)
				continue;
			prze.tab[i][num[now]]=skok[j];
		}
	}
	//~ start.wypisz();
	//~ prze.wypisz();
	set <int> inter;
	inter.insert(0);
	inter.insert(n-x);
	while(q--)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		faj[a]=b;
		for (int i=-k; i<=0; i++)
		{
			int w=a+i;
			w=max(w, 0);
			w=min(w, n-x);
			inter.insert(w);
		}
	}
	inter.erase(0);
	int ost=0;
	for (int i : inter)
	{
		przesun(ost, i);
		ost=i;
	}
	printf("%lld\n", start.tab[0][0]);
	return 0;
}