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
const int n1=(1<<18);

int n, q;

int drz[nax];

int typ[nax];
vi zap[nax];

int jaki[nax];
int kied[nax];

int pref[2][nax];

int pod[nax];

void pisz(int v, int a, int b, int graa, int grab, int w)
{
	if (a>=graa && b<=grab)
	{
		drz[v]=min(drz[v], w);
		return;
	}
	if (a>grab || b<graa)
	{
		return;
	}
	pisz((v<<1), a, (a+b)>>1, graa, grab, w);
	pisz((v<<1)^1, (a+b+2)>>1, b, graa, grab, w);
}

void pchaj(int v, int a, int b)
{
	if (a==b)
	{
		kied[a]=drz[v];
		return;
	}
	for (int i=2*v; i<=2*v+1; i++)
		drz[i]=min(drz[i], drz[v]);
	pchaj((v<<1), a, (a+b)>>1);
	pchaj((v<<1)^1, (a+b+2)>>1, b);
}

void lift(int v, int a, int b)
{
	if (a==b)
	{
		pod[v]=kied[a];
		return;
	}
	lift((v<<1), a, (a+b)>>1);
	lift((v<<1)^1, (a+b+2)>>1, b);
	pod[v]=max(pod[2*v], pod[2*v+1]);
}

int czyt(int v, int a, int b, int graa, int grab)
{
	if (a>=graa && b<=grab)
	{
		return pod[v];
	}
	if (a>grab || b<graa)
	{
		return 0;
	}
	return max(
		czyt((v<<1), a, (a+b)>>1, graa, grab),
		czyt((v<<1)^1, (a+b+2)>>1, b, graa, grab)
	);
}

int main()
{
	scanf("%d%d", &n, &q);
	for (int i=1; i<=n; i++)
		kied[i]=q+1;
	for (int i=1; i<2*n1; i++)
		drz[i]=q+1;
	for (int i=1; i<=q; i++)
	{
		scanf("%d", &typ[i]);
		typ[i]^=1;
		if (!typ[i])
		{
			int g;
			scanf("%d", &g);
			zap[i]={g};
		}
		else
		{
			int a, b, x;
			scanf("%d%d%d", &a, &b, &x);
			zap[i]={a, b, x};
			if (!x)
				pisz(1, 1, n1, a, b, i);
		}
	}
	pchaj(1, 1, n1);
	for (int i=1; i<=n; i++)
	{
		if (kied[i]==q+1)
		{
			jaki[i]=1;
			pref[0][i]=1;
			pref[1][i]=i;
			pisz(1, 1, n1, i, i, 0);
		}
	}
	pchaj(1, 1, n1);
	lift(1, 1, n1);
	for (int h=0; h<2; h++)
		for (int i=1; i<=n; i++)
			pref[h][i]+=pref[h][i-1];
	for (int i=1; i<=n; i++)
		if (!kied[i])
			kied[i]=q+1;
	for (int i=1; i<=q; i++)
	{
		if (typ[i]==1 && zap[i][2])
		{
			int a=zap[i][0];
			int b=zap[i][1];
			if (pref[0][a-1]+1==pref[0][b])
			{
				int x=pref[1][b]-pref[1][a-1];
				kied[x]=min(kied[x], max(czyt(1, 1, n1, a, b), i));
			}
		}
	}
	for (int i=1; i<=q; i++)
	{
		if (!typ[i])
		{
			int x=zap[i][0];
			if (kied[x]>i)
			{
				printf("N/A\n");
			}
			else
			{
				if (jaki[x])
					printf("YES\n");
				else
					printf("NO\n");
			}
		}
	}
	return 0;
}