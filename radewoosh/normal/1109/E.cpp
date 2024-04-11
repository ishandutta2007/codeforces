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
const int nax=400*1007;
const int n1=(1<<17);
//~ const int n1=8;

ll mod;
ll phi;

vi roz, nor;

int n;

int domn[nax][10];
ll mno[nax];
ll sum[nax];

vll poty[17];

ll pot(ll a, ll b)
{
	ll ret=1;
	while(b)
	{
		if (b&1)
			ret=(ret*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return ret;
}

ll dziel(ll a, ll b)
{
	return (a*pot(b, phi-1))%mod;
}

ll fast(int v, int kt)
{
	if (poty[v].empty())
		poty[v].push_back(1);
	while((int)poty[v].size()<=kt)
	{
		ll y=poty[v].back()*roz[v]%mod;
		poty[v].push_back(y);
	}
	return poty[v][kt];
}

ll daj(int v)
{
	ll ret=sum[v];
	ret=(ret*mno[v])%mod;
	for (int i=0; i<(int)roz.size(); i++)
		ret=(ret*fast(i, domn[v][i]))%mod;
	return ret;
}

void upd(int v, int pchaj=1, int ciag=1)
{
	if (pchaj)
	{
		for (int i=0; i<2; i++)
		{
			int c=2*v+i;
			mno[c]=(mno[c]*mno[v])%mod;
			for (int j=0; j<(int)roz.size(); j++)
				domn[c][j]+=domn[v][j];
		}
		mno[v]=1;
		for (int &i : domn[v])
			i=0;
	}
	if (ciag)
	{
		sum[v]=(daj(v*2)+daj(v*2+1))%mod;
	}
}

vi pen;

void rzuc(int v, int a, int b, int graa, int grab, ll w)
{
	if (a>=graa && b<=grab)
	{
		mno[v]=(mno[v]*w)%mod;
		for (int i=0; i<(int)roz.size(); i++)
			domn[v][i]+=pen[i];
		return;
	}
	if (a>grab || b<graa)
		return;
	rzuc((v<<1), a, (a+b)>>1, graa, grab, w);
	rzuc((v<<1)^1, (a+b+2)>>1, b, graa, grab, w);
	upd(v, 0, 1);
}

void dziel(int v, int a, int b, int c, ll w)
{
	if (a>c || b<c)
		return;
	if (a==b)
	{
		for (int i=0; i<(int)roz.size(); i++)
		{
			while(!(w%roz[i]))
			{
				w/=roz[i];
				domn[v][i]--;
			}
		}
		mno[v]=dziel(mno[v], w);
		return;
	}
	upd(v, 1, 0);
	dziel((v<<1), a, (a+b)>>1, c, w);
	dziel((v<<1)^1, (a+b+2)>>1, b, c, w);
	upd(v, 0, 1);
}

void pomn(int a, int b, ll w)
{
	pen.resize(roz.size());
	fill(pen.begin(), pen.end(), 0);
	for (int i=0; i<(int)roz.size(); i++)
	{
		while(!(w%roz[i]))
		{
			w/=roz[i];
			pen[i]++;
		}
	}
	rzuc(1, 1, n1, a, b, w);
}


ll czyt(int v, int a, int b, int graa, int grab)
{
	if (a>=graa && b<=grab)
	{
		return daj(v);
	}
	if (a>grab || b<graa)
		return 0;
	upd(v);
	ll ret=(czyt((v<<1), a, (a+b)>>1, graa, grab)+
	czyt((v<<1)^1, (a+b+2)>>1, b, graa, grab))%mod;
	return ret;
}

int main()
{
	scanf("%d%lld", &n, &mod);
	ll pom=mod;
	for (ll i=2; i*i<=pom; i++)
	{
		if (!(pom%i))
		{
			if (roz.empty() || roz.back()!=i)
				roz.push_back(i);
			nor.push_back(i);
			pom/=i;
			i--;
		}
	}
	if (roz.empty() || roz.back()!=pom)
		roz.push_back(pom);
	nor.push_back(pom);
	phi=1;
	ll ost=-1;
	for (ll i : nor)
	{
		phi*=(i-(i!=ost));
		ost=i;
	}
	//~ debug() << imie(phi);
	debug() << roz;
	for (int i=1; i<2*n1; i++)
		mno[i]=1;
	for (int i=1; i<=n1; i++)
		sum[i+n1-1]=1;
	for (int i=n1-1; i; i--)
	{
		sum[i]=(sum[2*i]+sum[2*i+1])%mod;
		//~ if (i==2)
			//~ debug() << i << " " << sum[i] << " " << sum[2*i] << " " << sum[2*i+1] << " " << daj(i) << " " << mno[i] << " " << domn[i];
	}
	//~ return 0;
	//~ debug() << imie(daj(1));
	//~ debug() << imie(daj(2));
	//~ debug() << imie(daj(4));
	//~ debug() << imie(daj(5));
	//~ debug() << imie(daj(8));
	for (int i=1; i<=n; i++)
	{
		ll x;
		scanf("%lld", &x);
		pomn(i, i, x);
	}
	int q;
	scanf("%d", &q);
	while(q--)
	{
		int typ;
		scanf("%d", &typ);
		if (typ==1)
		{
			int l, r, x;
			scanf("%d%d%d", &l, &r, &x);
			pomn(l, r, x);
		}
		if (typ==2)
		{
			int l, x;
			scanf("%d%d", &l, &x);
			dziel(1, 1, n1, l, x);
		}
		if (typ==3)
		{
			int l, r;
			scanf("%d%d", &l, &r);
			printf("%lld\n", czyt(1, 1, n1, l, r));
		}
	}
	return 0;
}