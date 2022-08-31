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
const int nax=1000*1007;
using ld=long double;
using pdd=pair<ld,ld>;
const ld pi=2*acosl(0);

ld krec(ld v, ld w)
{
	while(v>=w)
		v-=w;
	return v;
}

inline ld Reduce(ld a) { return krec(a + 2.0 * pi, 2.0 * pi); }

inline ld dist(pdd v)
{
	return sqrt(v.first*v.first+v.second*v.second);
}

int n, k;

pdd tab[nax];

ld read()
{
	double x;
	scanf("%lf", &x);
	return x;
}

int pocz[nax];
int kon[nax];

int m;
int ile[nax];

int check(ld r)
{
	vector < pair<ld,int> > dos;
	for (int i=1; i<=n; i++)
	{
		ld arg = atan2(tab[i].second, tab[i].first);
		ld theta = acos(r / dist(tab[i]));
		ld a = Reduce(arg - theta);
		ld b = Reduce(arg + theta);
		dos.push_back({a, -i});
		dos.push_back({b, i});
	}
	sort(dos.begin(), dos.end());
	for (int i=0; i<2*n; i++)
	{
		if (dos[i].second<0)
			pocz[-dos[i].second]=i+1;
		else
			kon[dos[i].second]=i+1;
	}
	vector <pii> zjeb, nor;
	for (int i=1; i<=n; i++)
	{
		if (pocz[i]<kon[i])
			nor.push_back({pocz[i], kon[i]});
		else
			zjeb.push_back({pocz[i], kon[i]});
	}
	
	int pra=2*n+1;
	sort(nor.begin(), nor.end());
	vector <pii> prz;
	for (int i=(int)nor.size()-1; i>=0; i--)
	{
		if (nor[i].second>=pra)
			continue;
		pra=min(pra, nor[i].second);
		prz.push_back(nor[i]);
	}
	nor=prz;
	sort(nor.begin(), nor.end());
	sort(zjeb.begin(), zjeb.end());
	int lew=2*n+1;
	for (pii i : nor)
		lew=min(lew, i.second);
	pra=0;
	for (pii i : nor)
		pra=max(pra, i.first);
	for (int i=(int)zjeb.size()-1; i>=0; i--)
	{
		if (zjeb[i].second>=lew || zjeb[i].first<=pra)
		{
			lew=min(lew, zjeb[i].second);
			continue;
		}
		lew=min(lew, zjeb[i].second);
		nor.push_back(zjeb[i]);
	}
	
	
	sort(nor.begin(), nor.end());
	debug() << nor;
	for (pii &i : nor)
		if (i.second<i.first)
			i.second+=2*n;
	m=nor.size();
	int w=0;
	for (int i=0; i<m; i++)
	{
		w=max(w, i);
		while(w<m && nor[w].first<=nor[i].second)
			w++;
		ile[i]=w-i;
	}
	w=0;
	for (int i=0; i<m; i++)
	{
		if (nor[i].second<=2*n)
			continue;
		int z=nor[i].second-2*n;
		while(nor[w].first<=z)
			w++;
		ile[i]+=w;
	}
	ll s=0;
	queue <int> kol;
	int v=0;
	int ret=3*n;
	for (int h=0; h<5*m; h++)
	{
		int x=ile[v];
		s+=x;
		v=(v+x)%m;
		kol.push(x);
		while(s-kol.front()>=m)
		{
			s-=kol.front();
			kol.pop();
		}
		if (s>=m)
			ret=min(ret, (int)kol.size());
	}
	return (ret<=k);
}

int main()
{
	scanf("%d%d", &n, &k);
	for (int i=1; i<=n; i++)
	{
		tab[i].first=read();
		tab[i].second=read();
	}
	ld bsa=0;
	ld bsb=1e18;
	for (int i=1; i<=n; i++)
		bsb=min(bsb, dist(tab[i]));
	//~ check(0.99);
	//~ check(1.3);
	//~ check(1.4142135617-(1e-9));
	//~ check(1.4142135617+(1e-9));
	//~ return 0;
	for (int h=0; h<90 && bsb-bsa>(1e-9); h++)
	{
		ld bss=(bsa+bsb)/2;
		if (check(bss))
			bsa=bss;
		else
			bsb=bss;
	}
	printf("%.9lf\n", (double)((bsa+bsb)/2));
	return 0;
}