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
const int nax=100*1007;
const int d=200;

int n, q;

int indy[nax];
int narz[nax];

int upo[nax];
int maupo[nax];

int poza[nax];
int supoza[nax];

inline int f(const int &v)
{
	return (v+d-1)/d;
}

inline int pra(const int &v)
{
	return v*d;
}

inline int lew(const int &v)
{
	return (v-1)*d+1;
}

inline int lca(const int &v)
{
	return max(1, v-indy[v]-narz[f(v)]);
}

void touch(const int &v)
{
	//~ debug() << "dot " << v;
	const int p=v*d;
	const int l=p-d+1;
	maupo[v]=0;
	for (int i=l; i<=p; i++)
	{
		//~ debug() << imie(i);
		//~ debug() << imie(indy[i]);
		//~ debug() << imie(narz[v]);
		const int x=max(i-indy[i]-narz[v], 1);
		//~ debug() << imie(x);
		if (i==1 || x<l)
		{
			poza[i]=i;
			upo[v]=0;
		}
		else
		{
			poza[i]=poza[x];
			maupo[v]=1;
			upo[v]=1;
		}
	}
	//~ debug() << "kon";
}

int main()
{
	scanf("%d%d", &n, &q);
	//~ n=q=1e5;
	for (int i=2; i<=n; i++)
	{
		int x;
		scanf("%d", &x);
		//~ x=i-2;
		indy[i]=i-x;
	}
	for (int i=n+1; f(i)==f(n); i++)
		indy[i]=1;
	for (int i=1; i<=f(n); i++)
		touch(i);
	ll iter1=0;
	ll iter2=0;
	ll iter3=0;
	while(q--)
	{
		if (!(q%10000))
		{
			for (int i=1; i<=n; i++)
				indy[i]=min(indy[i], nax);
			for (int i=1; i<=f(n); i++)
				narz[i]=min(narz[i], nax);
		}
		int typ;
		scanf("%d", &typ);
		//~ typ=2;
		if (typ==1)
		{
			int l, r, x;
			scanf("%d%d%d", &l, &r, &x);
			if (f(l)==f(r))
			{
				for (int i=l; i<=r; i++)
					indy[i]+=x;
				touch(f(l));
			}
			else
			{
				int a=f(l);
				int b=f(r);
				for (int i=l; f(i)==a; i++)
					indy[i]+=x;
				for (int i=r; f(i)==b; i--)
					indy[i]+=x;
				touch(a);
				touch(b);
				for (int i=a+1; i<b; i++)
				{
					narz[i]+=x;
					if (maupo[i])
						touch(i);
				}
			}
		}
		else
		{
			int l, r;
			scanf("%d%d", &l, &r);
			//~ l=rand()%n+1;
			//~ r=rand()%n+1;
			if (l>r)
				swap(l, r);
			//~ debug() << imie(l) << imie(r);
			while(poza[l]!=poza[r])
			{
				if (l>r)
					swap(l, r);
				iter2++;
				r=lca(poza[r]);
			}
			//~ debug() << imie(l) << imie(r);
			while(l!=r)
			{
				iter3++;
				if (l<r)
					swap(l, r);
				l=lca(l);
			}
			printf("%d\n", l);
		}
	}
	debug() << imie(iter1) << imie(iter2) << imie(iter3);
	return 0;
}