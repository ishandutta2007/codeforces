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
const int nax=1200*1007;
const int n1=(1<<19);

int n, q;

ll tab[nax];

pll zap[nax];

ll fen[2][2][nax];

int k;
map<ll,int> mapa;

void pisz(int a, int b, int v, ll w)
{
	for (int i=v; i<=k; i+=(i&(-i)))
		fen[a][b][i]+=w;
}

ll drznor[nax];
ll drzsum[nax];
ll drzmag[nax];

void drzpisz(int v, ll w)
{
	v+=n1-1;
	drzsum[v]=drzmag[v]=w;
	drznor[v]=(w>0);
	v>>=1;
	while(v)
	{
		drznor[v]=drznor[(v<<1)]+drznor[(v<<1)^1];
		drzsum[v]=drzsum[(v<<1)]+drzsum[(v<<1)^1];
		drzmag[v]=drzmag[(v<<1)]+drzmag[(v<<1)^1]+drzsum[(v<<1)]*drznor[(v<<1)^1];
		v>>=1;
	}
}

ll drzpom;

int k_ta_pozycja(int v)
{
	v--;
	int w=0;
	for (int i=(1<<19); i>0; i>>=1)
	{
		if ((w^i)<=k && fen[0][0][w^i]<=v)
		{
			w^=i;
			v-=fen[0][0][w];
		}
	}
	return w+1;
}

ll get_mag(int v, int a, int b, int graa, int grab)
{
	if (v==1)
		drzpom=0;
	if (a>=graa && b<=grab)
	{
		ll ret=drzmag[v]+drzsum[v]*drzpom;
		drzpom+=drznor[v];
		return ret;
	}
	if (a>grab || b<graa)
		return 0;
	ll ret=0;
	ret+=get_mag((v<<1)^1, (a+b+2)>>1, b, graa, grab);
	ret+=get_mag((v<<1), a, (a+b)>>1, graa, grab);
	return ret;
}

ll get_sum(int a, int b)
{
	ll ret=0;
	if (b>0)
		for (int i=b; i; i-=(i&(-i)))
			ret+=fen[0][1][i];
	if (a>1)
		for (int i=a-1; i; i-=(i&(-i)))
			ret-=fen[0][1][i];
	return ret;
}

ll sumyprefiksowe_od_do(int a, int b)
{
	a=max(a, 1);
	if (a>b)
		return 0;
	int x=k_ta_pozycja(a);
	int y=k_ta_pozycja(b);
	ll wez=get_mag(1, 1, n1, x, y);
	return wez+get_sum(1, x-1)*(b-a+1);
}

ll suma_prefiksowa(int v)
{
	return get_sum(1, k_ta_pozycja(v));
}

int roz;

ll suma_roznic_pomiedzy(int a, int b)
{
	if (a>b)
		return 0;
	//~ debug() << "kurwa " << a << " " << b << " " << get_sum(1, k) << imie(sumyprefiksowe_od_do(roz-b, roz-a)) << imie(sumyprefiksowe_od_do(a, b));
	return get_sum(1, k)*(b-a+1)-sumyprefiksowe_od_do(roz-b, roz-a)-sumyprefiksowe_od_do(a, b);
}

void pojaw(ll w)
{
	int g=mapa[w];
	assert(g);
	pisz(0, 0, g, 1);
	pisz(0, 1, g, w);
	pisz(1, 0, k+1-g, 1);
	pisz(1, 1, k+1-g, w);
	drzpisz(g, w);
}

void usun(ll w)
{
	int g=mapa[w];
	assert(g);
	pisz(0, 0, g, -1);
	pisz(0, 1, g, -w);
	pisz(1, 0, k+1-g, -1);
	pisz(1, 1, k+1-g, -w);
	drzpisz(g, 0);
}

ll sumpiex(int g, int x)//0 to min, 1 to max
{
	int oryx=x;
	ll ret=0;
	int w=0;
	for (int i=(1<<19); i>0; i>>=1)
	{
		if ((w^i)<=k && fen[g][0][w^i]<=x)
		{
			w^=i;
			x-=fen[g][0][w];
			ret+=fen[g][1][w];
		}
	}
	return ret;
}

ll zmergowane(int a, int b)
{
	return suma_prefiksowa(roz)-suma_prefiksowa(roz-b)-suma_prefiksowa(a);
}

void policz()
{
	if (roz<=1)
	{
		printf("0\n");
		return;
	}
	ll ret=0;
	//~ ret=suma_roznic_pomiedzy(1, roz);
	int sr=(roz/2);
	{
		int bsa=sr;
		int bsb=roz;
		while(bsa<bsb)
		{
			int bss=(bsa+bsb+2)>>1;
			if (sumpiex(0, bss)<=sumpiex(1, bss-1))
				bsa=bss;
			else
				bsb=bss-1;
		}
		ret+=zmergowane(sr, bsa)+suma_roznic_pomiedzy(bsa+1, roz);
		//~ debug() << imie(sr) << imie(bsa) << imie(zmergowane(sr, bsa)) << imie(suma_roznic_pomiedzy(bsa+1, roz));
	}
	{
		int bsa=1;
		int bsb=sr;
		while(bsa<bsb)
		{
			int bss=(bsa+bsb)>>1;
			if (sumpiex(0, bss+1)<=sumpiex(1, bss))
				bsb=bss;
			else
				bsa=bss+1;
		}
		ret+=zmergowane(bsa, sr)+suma_roznic_pomiedzy(1, bsa-1);
		//~ debug() << imie(sr) << imie(bsa) << imie(zmergowane(bsa, sr)) << imie(suma_roznic_pomiedzy(1, bsa-1));
	}
	ret-=zmergowane(sr, sr);
	
	
	printf("%lld\n", ret);
}

int main()
{
	scanf("%d%d", &n, &q);
	for (int i=1; i<=n; i++)
	{
		scanf("%lld", &tab[i]);
		mapa[tab[i]];
	}
	for (int i=1; i<=q; i++)
	{
		ll a, b;
		scanf("%lld%lld", &a, &b);
		if (a==1)
			mapa[b];
		zap[i]={a, b};
	}
	for (auto &i : mapa)
	{
		k++;
		i.second=k;
	}
	//~ debug() << mapa;
	for (int i=1; i<=n; i++)
	{
		pojaw(tab[i]);
	}
	//~ for (int i=1; i<=n; i++)
		//~ for (int j=i; j<=n; j++)
			//~ debug() << i << " " << j << " " << sumyprefiksowe_od_do(i, j);
	//~ for (int i=1; i<=n; i++)
	//~ {
		//~ debug() << i << " " << sumpiex(0, i) << " " << sumpiex(1, i);
		//~ ll a=sumpiex(0, i);
		//~ ll b=sumpiex(1, i);
		//~ debug() << i << " " << a << " " << b;
	//~ }
	roz=n;
	policz();
	for (int i=1; i<=q; i++)
	{
		if (zap[i].first==1)
		{
			pojaw(zap[i].second);
			roz++;
		}
		else
		{
			usun(zap[i].second);
			roz--;
		}
		policz();
	}
	return 0;
}