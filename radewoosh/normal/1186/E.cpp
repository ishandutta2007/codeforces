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
const int nax=1007;
const ll inf=nax*nax*nax;

int n, m, q;

int tab[nax][nax];

char wcz[nax];

int s(int a, int b)
{
	return tab[a][b];
}

int so(int a, int b)
{
	return a*b-tab[a][b];
}

int sm(int a, int b, int bit)
{
	if (!bit)
		return s(a, b);
	return so(a, b);
}
//~ sim, class m> using my_unordered_map = cc_hash_table<c, m, hash<c>>;
//~ my_unordered_map <ll,ll> mapa[2];
unordered_map <ll,ll> mapa[2];

int gladz(int v)
{
	int x=31-__builtin_clz(v);
	return 1<<x;
}

int sony(int v)
{
	int r=v/2;
	if (v&1)
	{
		v--;
		r+=((__builtin_popcount(v)&1)==0);
	}
	return r;
}

ll liczrek(ll a, ll b, int bit=0)
{
	if (a<=0 || b<=0)
		return 0;
	if (a<=n && b<=m)
		return sm(a, b, bit);
	//~ if (!(a%n))
	//~ {
		//~ assert(b<m);
		//~ a/=n;
		
		//~ ll ra=sony(a);
		//~ ll za=a-ra;
		//~ return ra*s(n, b)+za*so(n, b);
	//~ }
	//~ if (!(b%m))
	//~ {
		//~ assert(a<n);
		//~ b/=m;
		
		//~ ll rb=sony(b);
		//~ ll zb=b-rb;
		//~ return rb*s(a, m)+zb*so(a, m);
	//~ }
	//~ ll h=a*inf+b;
	//~ if (mapa[bit][h])
		//~ return mapa[bit][h]-1;
	ll w=gladz(max((a-1)/n, (b-1)/m));
	ll wn=w*n;
	ll wm=w*m;
	ll ret=0;
	ret+=liczrek(min(a, wn), min(b, wm), bit);
	ret+=liczrek(a-wn, min(b, wm), bit^1);
	ret+=liczrek(min(a, wn), b-wm, bit^1);
	ret+=liczrek(a-wn, b-wm, bit);
	//~ mapa[bit][h]=ret+1;
	return ret;
}

int czy(int v)
{
	return __builtin_popcount(v)&1;
}

ll licz(ll a, ll b)
{
	ll ret=0;
	ll pa=a;
	ll pb=b;
	
	{
		a/=n;
		b/=m;
		
		ll ra=sony(a);
		ll za=a-ra;
		ll rb=sony(b);
		ll zb=b-rb;
		
		ll r=ra*rb+za*zb;
		ll z=ra*zb+za*rb;
		ret+=r*s(n, m)+z*so(n, m);
		//~ assert(ret==liczrek(a*n, b*m));
		a=pa;
		b=pb;
	}
	
	{
		a/=n;
		b%=m;
		
		ll ra=sony(a);
		ll za=a-ra;
		if (czy(pb/m))
			swap(ra, za);
		ret+=ra*s(n, b)+za*so(n, b);
		
		a=pa;
		b=pb;
	}
	
	{
		a%=n;
		b/=m;
		
		ll rb=sony(b);
		ll zb=b-rb;
		if (czy(pa/n))
			swap(rb, zb);
		ret+=rb*s(a, m)+zb*so(a, m);
		
		a=pa;
		b=pb;
	}
	
	{
		a%=n;
		b%=m;
		
		ll r=1;
		ll z=0;
		if (czy(pa/n)!=czy(pb/m))
			swap(r, z);
		ret+=r*s(a, b)+z*so(a, b);
		
		a=pa;
		b=pb;
	}
	//~ if (ret!=liczrek(a, b))
		//~ debug() << imie(a) << imie(b);
	//~ assert(ret==liczrek(a, b));
	return ret;
}

int main()
{
	scanf("%d%d%d", &n, &m, &q);
	for (int i=1; i<=n; i++)
	{
		scanf("%s", wcz+1);
		for (int j=1; j<=m; j++)
			tab[i][j]=tab[i-1][j]+tab[i][j-1]-tab[i-1][j-1]+(wcz[j]-'0');
	}
	while(q--)
	{
		ll a, b, x, y;
		scanf("%lld%lld%lld%lld", &a, &b, &x, &y);
		//~ a=1e8-(rand()%10000000);
		//~ b=1e8-(rand()%10000000);
		//~ x=1e9-(rand()%10000000);
		//~ y=1e9-(rand()%10000000);
		a--;
		b--;
		//~ mapa[0].clear();
		//~ mapa[1].clear();
		printf("%lld\n", licz(x, y)-licz(a, y)-licz(x, b)+licz(a, b));
		//~ debug() << imie(mapa[0].size()+mapa[1].size());
	}
	return 0;
}