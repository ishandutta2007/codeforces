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
const ll mod=998244353;

int invfast[nax];

void init_inv()
{
	invfast[1]=1;
	for (int i=2; i<nax; i++)
		invfast[i]=invfast[mod%i]*(mod-mod/i)%mod;
}

ll inv(ll v)
{
	if (v<nax)
		return invfast[v];
	return inv(mod%v)*(mod-mod/v)%mod;
}

struct ntt
{
	vll omega[30];
	ll gen=1;
	ntt()
	{
		while(1)
		{
			gen++;
			ll x=gen;
			for (int i=1; i<__builtin_ctzll(mod-1); i++)
				x=(x*x)%mod;
			if (x==mod-1)
				break;
		}
	}
	int lift(int v)
	{
		int ret=1;
		while(ret<v)
			ret<<=1;
		return ret;
	}
	void omegas(int v)
	{
		if (!omega[v].empty())
			return;
		int n=(1<<v);
		int should=((mod-1)&(-(mod-1)));
		ll mul=gen;
		while(n<should)
		{
			mul=(mul*mul)%mod;
			should>>=1;
		}
		omega[v].resize(n+1);
		omega[v][0]=1;
		for (int i=1; i<=n; i++)
			omega[v][i]=(omega[v][i-1]*mul)%mod;
	}
	void dft(vll &a, int dir)
	{
		int n=a.size();
		static vll b;
		b.resize(n);
		const int ch=(!dir ? 1 : -1);
		for (int i=1, w=1; i<n; i<<=1, w++)
		{
			omegas(w);
			ll *om=omega[w].data();
			b.swap(a);
			const int &d=n>>w;
			ll *pa=a.data();
			ll *pb=b.data();
			int now=(!dir ? 0 : (i<<1));
			for (int j=0; j<n; j+=d, now+=ch)
			{
				const ll &mul=om[now];
				int left=(j<<1);
				if (left>=n)
					left-=n;
				int right=(left+d);
				for (int l=0; l<d; l++)
					pa[j+l]=(pb[left+l]+pb[right+l]*mul)%mod;
			}
		}
	}
	vll multi(vll a, vll b)
	{
		if (a.empty() || b.empty())
			return {};
		int n=lift(a.size()+b.size());
		a.resize(n);
		b.resize(n);
		dft(a, 0);
		dft(b, 0);
		for (int i=0; i<n; i++)
			a[i]=(a[i]*b[i])%mod;
		dft(a, 1);
		ll div=inv(n);
		for (ll &i : a)
			i=(i*div)%mod;
		return a;
	}
};

vll norm(vll a)
{
	for (ll &i : a)
		if ((i%=mod)<0)
			i+=mod;
	while(!a.empty() && !a.back())
		a.pop_back();
	return a;
}

vll operator + (const vll &a, const vll &b)
{
	vll ret(max(a.size(), b.size()));
	for (int i=0; i<(int)a.size(); i++)
		ret[i]=a[i];
	for (int i=0; i<(int)b.size(); i++)
		ret[i]+=b[i];
	return norm(ret);
}

vll operator - (const vll &a, const vll &b)
{
	vll ret(max(a.size(), b.size()));
	for (int i=0; i<(int)a.size(); i++)
		ret[i]=a[i];
	for (int i=0; i<(int)b.size(); i++)
		ret[i]-=b[i];
	return norm(ret);
}

vll operator *(const vll &a, const vll &b)
{
	static ntt my_ntt;
	return norm(my_ntt.multi(norm(a), norm(b)));
}

int n, m;

ll tab[nax];

int wyb[nax];
ll pref[nax];
ll suf[nax];

ll res[nax];

ll daj_pref(int v)
{
	return pref[max(0, min(v, n))];
}

ll daj_suf(int v)
{
	return suf[max(1, min(v, n+1))];
}

void rek(int a, int b)
{
	if (a+1>=b)
		return;
	int s=(a+b)/2;
	rek(a, s);
	rek(s+1, b);
	vll raz, dwa;
	for (int i=a; i<=s; i++)
		raz.push_back(daj_pref(i));
	for (int i=s+1; i<=b; i++)
		dwa.push_back(daj_suf(i));
	vll wez=raz*dwa;
	//~ debug() << a << " " << b << " " << s << "  " << raz << " " << dwa << " " << wez;
	for (int i=0; i<(int)wez.size(); i++)
	{
		int g=a+s+1+i;
		if ((g&1) || g<0)
			continue;
		g>>=1;
		if (g>=a && g<=b)
		{
			res[g]=(res[g]+wez[i])%mod;
			//~ debug() << g << " dostaje " << wez[i];
		}
	}
}

int main()
{
	init_inv();
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; i++)
	{
		scanf("%lld", &tab[i]);
	}
	for (int i=1; i<=m; i++)
	{
		int x;
		scanf("%d", &x);
		wyb[x]=1;
	}
	pref[0]=suf[n+1]=1;
	for (int i=1; i<=n; i++)
		pref[i]=pref[i-1]*(1+wyb[i])%mod;
	for (int i=n; i; i--)
		suf[i]=suf[i+1]*(1+wyb[i])%mod;
	rek(-n+1, 2*n);
	for (int i=1; i<=n; i++)
		res[i]=(res[i]+mod-min(i-(-n+1), 2*n-i))%mod;
	//~ debug() << range(res+1, res+1+n);
	ll dz=1;
	for (int i=1; i<=m; i++)
		dz=(dz*2)%mod;
	dz--;
	dz=inv(dz);
	ll wyn=0;
	for (int i=1; i<=n; i++)
		wyn=(wyn+res[i]*tab[i])%mod;
	printf("%lld\n", wyn*dz%mod);
	return 0;
}