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
const int nax=100*1007;

int n;
int tab[nax];

ll ile[nax];

ll m;

void rek(int a, int b)
{
	if (a>b)
		return;
	int s=(a+b)>>1;
	vector <pll> l, p;
	int x=0;
	for (int i=s; i>=a; i--)
	{
		x=__gcd(x, tab[i]);
		if (l.empty() || x!=l.back().first)
			l.push_back({x, 0});
		l.back().second++;
	}
	x=0;
	for (int i=s; i<=b; i++)
	{
		x=__gcd(x, tab[i]);
		if (p.empty() || x!=p.back().first)
			p.push_back({x, 0});
		p.back().second++;
	}
	for (pll i : l)
		for (pll j : p)
			ile[__gcd(i.first, j.first)]+=i.second*j.second;
	rek(a, s-1);
	rek(s+1, b);
}

ll brut(ll v)
{
	vll wek;
	for (int i=1; i<nax; i++)
		for (int j=0; j<ile[i]; j++)
			wek.push_back(i);
	ll ret=0;
	for (int i=0; i<(int)wek.size(); i++)
	{
		ll s=0;
		for (int j=i; j<(int)wek.size(); j++)
		{
			s+=wek[j];
			if (s>v)
				break;
			ret++;
		}
	}
	return ret;
}

ll brut2(ll v)
{
	vll wek;
	for (int i=1; i<nax; i++)
		for (int j=0; j<ile[i]; j++)
			wek.push_back(i);
	ll ret=0;
	for (int i=0; i<(int)wek.size(); i++)
	{
		ll s=0;
		for (int j=i; j<(int)wek.size(); j++)
		{
			s+=wek[j];
			if (s>v)
				break;
			if (wek[j]!=wek[i])
				ret++;
		}
	}
	return ret;
}

ll daj(pll v)
{
	return v.first*v.second;
}

ll sum[nax];

ll magiabr(ll lim, ll a, ll m1, ll b, ll m2)
{
	ll ret=0;
	for (ll i=1; i<=m1; i++)
		for (ll j=1; j<=m2; j++)
			if (i*a+j*b<=lim)
				ret++;
	//~ debug() << imie(ret);
	return ret;
}

namespace copypaste
{
  void eukl(ll &x, ll &y, ll a, ll b) {
  if (!a) { x = 0; y = 1; return; }
  eukl(y, x, b % a, a);
  x -= y * (b / a);
}

ll euklides(ll y, ll x, ll d)
{
	if (!y)
		return d+1;
	if (y>=x)
	{
		ll dz=y/x;
		ll ile=d*(d+1)/2;
		return euklides(y%x, x, d)+dz*ile;
	}
	else
	{
		ll ile=(d*y+x-1)/x;
		ll sum=(d+1)*(ile+1)+1+d/x+((ile*x)/y-d);
		return sum-euklides(x, y, ile);
	}
}

ll main2(ll a, ll b, ll c)
{
	//~ ll a, b, c;
	//~ scanf("%lld%lld%lld", &a, &b, &c);
	if (a>c || b>c)
	{
		//~ printf("%lld\n", 1+c/a+c/b);
		return 1+c/a+c/b;
		//~ return 0;
	}
	ll g=__gcd(a, b);
	c/=g;
	a/=g;
	b/=g;
	ll x, y;
	eukl(x, y, a, b);
	x*=(c%a);
	y*=(c%a);
	x+=(c/a);
	assert(x*a+b*y==c);
	
	if (x<0)
	{
		ll ile=(-x-1)/b;
		x+=ile*b;
		y-=ile*a;
	}
	if (x>=0)
	{
		ll ile=x/b+1;
		x-=ile*b;
		y+=ile*a;
	}
	
	assert(x*a+b*y==c);
	assert(x<0);
	assert(x+b>=0);
	
	ll p=c/b;
	
	ll wyn=x*(p+1);
	wyn-=euklides(b, a, y-p-1);
	wyn+=euklides(b, a, y);
	
	return wyn;
	//~ printf("%lld\n", wyn);
	//~ return 0;
}
}//copy

ll trzesienie(ll a, ll b, ll c) {
	if (c<0) return 0;
	if (a>b) swap(a, b);
	ll p=c/b;
	ll k=b/a;
	ll d=(c-p*b)/a;
	return trzesienie(b-k*a, a, c-a*(k*p+d+1))+(p+1)*(d+1)+k*p*(p+1)/2;
}

ll eukl(ll lim, ll a, ll b)
{
	if (lim<0)
		return 0;
	return trzesienie(a, b, lim);
	//~ if (!a)
		//~ return lim/b+1;
	//~ if (!b)
		//~ return lim/a+1;
	//~ ll ret=0;
	//~ for (ll i=0; i*a<=lim; i++)
	//~ {
		//~ for (ll j=0; j*b<=lim; j++)
			//~ if (i*a+j*b<=lim)
				//~ ret++;
	//~ }
	//~ return ret;
}

ll magia(ll lim, ll a, ll x, ll b, ll y)
{
	lim-=a+b;
	if (lim<0)
		return 0;
	if (lim>=(x-1)*a+(y-1)*b)
		return x*y;
	//~ return eukl(lim, a, x, b, y);
	return eukl(lim, a, b)-eukl(lim-x*a, a, b)-eukl(lim-y*b, a, b)+eukl(lim-x*a-y*b, a, b);
}

ll licz(ll v)
{
	//~ return brut(v);
	ll ret=0;
	for (int i=1; i<nax; i++)
	{
		if (!ile[i])
			continue;
		ll w=min(ile[i], v/i);
		ret+=w*(2*ile[i]-w+1)/2;
	}
	//~ return ret+brut2(v);
	vector<pll> wek;
	for (int i=1; i<nax; i++)
		if (ile[i])
			wek.push_back({i, ile[i]});
	int r=wek.size();
	int w=0;
	ll trz=0;
	sum[0]=0;
	for (int i=0; i<r; i++)
		sum[i+1]=sum[i]+wek[i].second;
	//~ debug() << "jade " << v << " " << wek;
	for (int i=0; i<r; i++)
	{
		w=max(w, i);
		if (w==i)
			trz=0;
		while(w+1<r && trz+daj(wek[w+1])<=v)
		{
			w++;
			trz+=daj(wek[w]);
		}
		if (w+1!=r)
			ret+=magia(v-trz, wek[i].first, wek[i].second, wek[w+1].first, wek[w+1].second);
		//~ debug() << "kurwa " << i << " " << w << "    " << trz;
		ll ter=trz;
		for (int j=w; j>i; j--)
		{
			ter-=daj(wek[j]);
			if (ter+daj(wek[j])+daj(wek[i])<=v)
			{
				ret+=wek[i].second*(sum[j+1]-sum[i+1]);
				//~ debug() << "hurt " << wek[i].second*(sum[j+1]-sum[i+1]);
				break;
			}
			ret+=magia(v-ter, wek[i].first, wek[i].second, wek[j].first, wek[j].second);
		}
		
		if (i+1!=r)
			trz-=daj(wek[i+1]);
	}
	//~ assert(ret==brut(v));
	return ret;
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		scanf("%d", &tab[i]);
	rek(1, n);
	//~ for (int i=1; i<nax; i++)
		//~ if (ile[i])
			//~ debug() << i << " " << ile[i];
	ll pom=n*(n+1LL)/2;
	m=(pom*(pom+1))/2;
	m=(m+1)/2;
	debug() << imie(m);
	ll bsa=1;
	ll bsb=0;
	for (int i=1; i<nax; i++)
		bsb+=i*ile[i];
	//~ debug() << imie(bsb);
	while(bsa<bsb)
	{
		ll bss=(bsa+bsb)>>1;
		if (licz(bss)>=m)
			bsb=bss;
		else
			bsa=bss+1;
	}
	printf("%lld\n", bsa);
	return 0;
}