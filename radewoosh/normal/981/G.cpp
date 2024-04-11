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
const int nax=1200*1007;
const int n1=(1<<18);
const ll mod=998244353;

int n, q;

set < pair <int,int> > setel[nax];

ll mno[nax];
ll dod[nax];
ll pod[nax];
ll roz[nax];

ll daj(int v)
{
	return (pod[v]*mno[v]+dod[v]*roz[v])%mod;
}

void pusz(int v)
{
	pod[v]=0;
	for (int h=0; h<2; h++)
	{
		int c=2*v+h;
		dod[c]=(dod[c]*mno[v])%mod;
		mno[c]=(mno[c]*mno[v])%mod;
		dod[c]=(dod[c]+dod[v])%mod;
		pod[v]+=daj(c);
	}
	pod[v]%=mod;
	dod[v]=0;
	mno[v]=1;
}

void pisz(int v, int a, int b, int graa, int grab, int typ)
{
	if (v==1)
		debug() << "Robie " << typ << " " << graa << " " << grab;
	if (a>=graa && b<=grab)
	{
		//~ debug() << "pisze na " << a << " " << b;
		if (typ==1)
		{
			dod[v]=(dod[v]+1)%mod;
		}
		else
		{
			dod[v]=(dod[v]*2)%mod;
			mno[v]=(mno[v]*2)%mod;
		}
		return;
	}
	if (a>grab || b<graa)
	{
		return;
	}
	pusz(v);
	pisz((v<<1), a, (a+b)>>1, graa, grab, typ);
	pisz((v<<1)^1, (a+b+2)>>1, b, graa, grab, typ);
	pusz(v);
}

ll czytaj(int v, int a, int b, int graa, int grab)
{
	if (a>=graa && b<=grab)
	{
		debug() << a << " " << b << "   " << pod[v] << " " << mno[v] << " " << dod[v];
		return daj(v);
	}
	if (a>grab || b<graa)
	{
		return 0;
	}
	pusz(v);
	ll ret=0;
	ret+=czytaj((v<<1), a, (a+b)>>1, graa, grab);
	ret+=czytaj((v<<1)^1, (a+b+2)>>1, b, graa, grab);
	//~ pusz(v);
	return ret;
}

void zmien()
{
	int a, b, x;
	scanf("%d%d%d", &a, &b, &x);
	
	int pampocz=a;
	auto it=setel[x].lower_bound({a, -1});
	
	if (it!=setel[x].begin())
	{
		it--;
		if ((*it).second>=a)
		{
			if ((*it).second>=b)
			{
				pisz(1, 1, n1, a, b, 2);
				return;
			}
			pisz(1, 1, n1, a, (*it).second, 2);
			a=(*it).second+1;
			pampocz=(*it).first;
			setel[x].erase(it);
		}
	}
	while(1)
	{
		it=setel[x].lower_bound({a, -1});
		if (it==setel[x].end() || (*it).first>b)
			break;
		if ((*it).second>b)
		{
			pisz(1, 1, n1, a, (*it).first-1, 1);
			pisz(1, 1, n1, (*it).first, b, 2);
			b=(*it).second;
			a=b+1;
			setel[x].erase(it);
			break;
		}
		pisz(1, 1, n1, a, (*it).first-1, 1);
		pisz(1, 1, n1, (*it).first, (*it).second, 2);
		a=(*it).second+1;
		setel[x].erase(it);
	}
	
	pisz(1, 1, n1, a, b, 1);
	setel[x].insert({pampocz, b});
	debug() << "po " << x << " " << setel[x];
}

void pytaj()
{
	int a, b;
	scanf("%d%d", &a, &b);
	printf("%lld\n", czytaj(1, 1, n1, a, b)%mod);
}

int main()
{
	for (int i=2*n1-1; i; i--)
	{
		mno[i]=1;
		//~ roz[i]=max(1LL, roz[2*i]+roz[2*i+1]);
		if (i<n1)
			roz[i]=roz[2*i]+roz[2*i+1];
		else
			roz[i]=1;
	}
	scanf("%d%d", &n, &q);
	while(q--)
	{
		int typ;
		scanf("%d", &typ);
		if (typ==1)
			zmien();
		else
			pytaj();
	}
	return 0;
}