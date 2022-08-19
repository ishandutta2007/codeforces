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
const int n1=(1<<18);

int n, q;

ll pod[nax];
int zmien[nax];
ll naco[nax];

ll mini[nax];

ll dlu[nax];

ll dajmini(int v)
{
	if (zmien[v])
		return naco[v];
	return mini[v];
}

ll daj(int v)
{
	if (zmien[v])
		return dlu[v]*naco[v];
	return pod[v];
}

void pisz(int v, int a, int b, int graa, int grab, ll w)
{
	if (a>=graa && b<=grab)
	{
		zmien[v]=1;
		naco[v]=w;
		return;
	}
	if (a>grab || b<graa)
	{
		return;
	}
	if (zmien[v])
	{
		zmien[v]=0;
		zmien[v*2]=zmien[v*2+1]=1;
		naco[v*2]=naco[v*2+1]=naco[v];
	}
	pisz((v<<1), a, (a+b)>>1, graa, grab, w);
	pisz((v<<1)^1, (a+b+2)>>1, b, graa, grab, w);
	pod[v]=daj(v*2)+daj(v*2+1);
	mini[v]=min(dajmini(v*2), dajmini(v*2+1));
}

ll czyt(int v, int a, int b, int lim)
{
	if (a>lim)
		return 0;
	if (zmien[v])
		return naco[v]*(min(lim, b)-a+1);
	if (b<=lim)
		return daj(v);
	return czyt((v<<1), a, (a+b)>>1, lim)+czyt((v<<1)^1, (a+b+2)>>1, b, lim);
}

int wartosc(int v)
{
	ll ret=0;
	v+=n1-1;
	while(v)
	{
		if (zmien[v])
			ret=naco[v];
		v>>=1;
	}
	return ret;
}

int pierwsze_mniejsze_rowne(int v, int a, int b, ll lim)
{
	if (a==b)
		return a;
	if (zmien[v])
		return a;
	if (dajmini(v*2)<=lim)
		return pierwsze_mniejsze_rowne((v<<1), a, (a+b)>>1, lim);
	return pierwsze_mniejsze_rowne((v<<1)^1, (a+b+2)>>1, b, lim);
}

int glo;
ll bedzie;

void suma_mniejsza_rowna(int v, int a, int b, ll lim)
{
	//~ debug() << imie(a) << imie(b);
	if (zmien[v])
	{
		//~ debug() << "case 1 " << v << " " << naco[v] << " " << dlu[v] << " " << lim;
		ll x=min(lim/naco[v], dlu[v]);
		glo+=x;
		bedzie+=x*naco[v];
		return;
	}
	if (a==b)
	{
		//~ debug() << "case 2 ";
		glo++;
		return;
	}
	ll x=daj(v*2);
	//~ debug() << "w lewo " << x;
	if (x<=lim)
	{
		glo+=dlu[v]/2;
		bedzie+=x;
		suma_mniejsza_rowna((v<<1)^1, (a+b+2)>>1, b, lim-x);
	}
	else
	{
		suma_mniejsza_rowna((v<<1), a, (a+b)>>1, lim);
	}
}

void query()
{
	int start;
	ll kasa;
	scanf("%d%lld", &start, &kasa);
	//~ debug() << "jade " << imie(start) << imie(kasa);
	int wyn=0;
	while(start<=n)
	{
		start=max(pierwsze_mniejsze_rowne(1, 1, n1, kasa), start);
		if (start>n)
			break;
		glo=bedzie=0;
		//~ debug() << imie(start) << imie(kasa);
		ll przed=czyt(1, 1, n1, start-1);
		//~ debug() << imie(przed);
		suma_mniejsza_rowna(1, 1, n1, kasa+przed);
		glo=min(glo, n);
		//~ debug() << imie(glo) << imie(bedzie);
		wyn+=glo-start+1;
		start=glo;
		kasa-=(bedzie-przed);
		if (glo==n)
			break;
	}
	printf("%d\n", wyn);
}

int main()
{
	scanf("%d%d", &n, &q);
	for (int i=1; i<=n1; i++)
		dlu[n1-1+i]=1;
	for (int i=n1-1; i; i--)
		dlu[i]=dlu[i*2]+dlu[i*2+1];
	for (int i=1; i<=n; i++)
	{
		ll x;
		scanf("%lld", &x);
		pisz(1, 1, n1, i, i, x);
	}
	while(q--)
	{
		int typ;
		scanf("%d", &typ);
		if (typ==1)
		{
			ll lim;
			ll cena;
			scanf("%lld%lld", &lim, &cena);
			int bsa=1;
			int bsb=lim+1;
			while(bsa<bsb)
			{
				int bss=(bsa+bsb)>>1;
				if (wartosc(bss)<=cena)
					bsb=bss;
				else
					bsa=bss+1;
			}
			pisz(1, 1, n1, bsa, lim, cena);
		}
		else
		{
			query();
		}
	}
	return 0;
}