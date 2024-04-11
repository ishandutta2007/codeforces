//while (clock()<=69*CLOCKS_PER_SEC)
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
const int nax=1100*1007;
const int n1=(1<<19);

int n, q;

int drz[nax];

void ustaw(int v, int w)
{
	v+=n1-1;
	drz[v]=w;
	v/=2;
	while(v)
	{
		drz[v]=__gcd(drz[v<<1], drz[(v<<1)^1]);
		v>>=1;
	}
}

int nl, nr;

void szuklew(int v, int a, int b, int graa, int grab, int w)
{
	if (a>grab || b<graa)
		return;
	if (a>=graa && b<=grab)
	{
		if (!(drz[v]%w))
			return;
		if (a==b)
		{
			nl=min(nl, a);
		}
		else
		{
			if (drz[(v<<1)]%w)
				szuklew((v<<1), a, (a+b)>>1, graa, grab, w);
			else
				szuklew((v<<1)^1, (a+b+2)>>1, b, graa, grab, w);
		}
	}
	else
	{
		szuklew((v<<1), a, (a+b)>>1, graa, grab, w);
		szuklew((v<<1)^1, (a+b+2)>>1, b, graa, grab, w);
	}
}

void szukpra(int v, int a, int b, int graa, int grab, int w)
{
	if (a>grab || b<graa)
		return;
	if (a>=graa && b<=grab)
	{
		if (!(drz[v]%w))
			return;
		//~ if (a==1 && b==4)
			//~ debug() << v << "  " << drz[v] <<  "  " << drz[v*2] <<  "  " << drz[v*2+1] << " " << w;
		//~ if (a==3 && b==4)
			//~ debug() << v << "  " << drz[v] <<  "  " << drz[v*2] <<  "  " << drz[v*2+1] << " " << w;
		if (a==b)
		{
			nr=max(nr, a);
		}
		else
		{
			if (drz[(v<<1)^1]%w)
				szukpra((v<<1)^1, (a+b+2)>>1, b, graa, grab, w);
			else
				szukpra((v<<1), a, (a+b)>>1, graa, grab, w);
		}
	}
	else
	{
		szukpra((v<<1), a, (a+b)>>1, graa, grab, w);
		szukpra((v<<1)^1, (a+b+2)>>1, b, graa, grab, w);
	}
}

void query()
{
	int l, r, x;
	scanf("%d%d%d", &l, &r, &x);
	nl=nax;
	nr=-1;
	szuklew(1, 1, n1, l, r, x);
	szukpra(1, 1, n1, l, r, x);
	debug() << nl << " " << nr;
	if (nl>=nr)
		printf("YES\n");
	else
		printf("NO\n");
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		int x;
		scanf("%d", &x);
		ustaw(i, x);
	}
	scanf("%d", &q);
	while(q--)
	{
		int typ;
		scanf("%d", &typ);
		if (typ==2)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			ustaw(a, b);
		}
		else
		{
			query();
		}
	}
	return 0;
}