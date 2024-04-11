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
//~ const int d=(1<<18);
const int d=300;

int n, q;

int k;

int tab[nax];

int fen[nax];

void pisz(int v, int w)
{
	for (int i=v; i<=n; i+=(i&(-i)))
		fen[i]+=w;
}

int czyt(int v)
{
	int ret=0;
	for (int i=v; i; i-=(i&(-i)))
		ret+=fen[i];
	return ret;
}

int szukfen(int v)
{
	int mni=0;
	int x=0;
	for (int i=(1<<17); i; i>>=1)
	{
		if ((x^i)+mni+fen[(x^i)]<v)
		{
			x^=i;
			mni+=fen[x];
		}
	}
	return x;
}

int f(int v)
{
	return (v+d-1)/d;
}

int lew(int v)
{
	return (v-1)*d+1;
}

int pra(int v)
{
	return min(n, v*d);
}

int wla[nax];
vi wek[nax];

int topocz[nax];

void przelicz(int v)
{
	//~ debug() << "prze a " << v;
	int a=lew(v);
	int b=pra(v);
	wek[v].clear();
	for (int i=a; i<=b; i++)
	{
		//~ wla[i]=tab[i]-czyt(tab[i]-1);
		wla[i]=szukfen(tab[i])+1;
		//~ debug() << i << "   " << wla[i];
		pisz(wla[i], 1);
		wek[v].push_back(wla[i]);
	}
	for (int i=a; i<=b; i++)
		pisz(wla[i], -1);
	sort(wek[v].begin(), wek[v].end());
	//~ debug() << a << " " << b << " " << wek[v];
	//~ debug() << "prze b";
}

int znajdz(int v)
{
	//~ debug() << "a " << v;
	int ret=tab[v];
	int x=v+1;
	while(x<=n && !topocz[x])
	{
		//~ debug() << x << " " << tab[x];
		if (ret>=tab[x])
			ret++;
		x++;
	}
	//~ debug() << "po " << ret;
	if (x>n)
		return ret;
	x=f(x);
	for (int i=x; i<=k; i++)
	{
		//~ debug() << "cip " << i;
		ret+=upper_bound(wek[i].begin(), wek[i].end(), ret)-wek[i].begin();
	}
	//~ debug() << "b";
	return ret;
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		scanf("%d", &tab[i]);
		tab[i]=i-tab[i];
	}
	//~ debug() << range(tab+1, tab+1+n);
	k=f(n);
	//~ debug() << imie(k);
	for (int i=1; i<=k; i++)
		topocz[lew(i)]=1;
	//~ debug() << range(topocz+1, topocz+1+n);
	for (int i=1; i<=k; i++)
		przelicz(i);
	scanf("%d", &q);
	while(q--)
	{
		int typ;
		scanf("%d", &typ);
		if (typ==1)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			tab[a]=a-b;
			przelicz(f(a));
		}
		else
		{
			int a;
			scanf("%d", &a);
			//~ int x=tab[a];
			//~ for (int i=a+1; i<=n; i++)
				//~ if (tab[i]<=x)
					//~ x++;
			//~ printf("%d\n", x);
			//~ int x=tab[a];
			//~ printf("%d\n", x+licz(1, 1, n1, a+1, tab[a]));
			printf("%d\n", znajdz(a));
		}
	}
	return 0;
}