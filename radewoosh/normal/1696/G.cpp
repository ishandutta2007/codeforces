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
const int nax=1007*1007;
const int n1=1<<18;
using ld=double;

int n, q;

ll x, y;

ll tab[nax];

ll dp[nax];

ld drz[nax][3][3];

void ustaw(int v, ll w)
{
	v+=n1-1;
	drz[v][1][1]=w/(ld)(x+y);
	drz[v][2][2]=w/(ld)y;
	v>>=1;
	while(v)
	{
		for (int a=0; a<3; a++)
			for (int b=0; b<3; b++)
				drz[v][a][b]=0;
		for (int a=0; a<3; a++)
		{
			for (int b=0; b<3; b++)
			{
				for (int c=0; b+c<3; c++)
				{
					for (int d=0; d<3; d++)
					{
						drz[v][a][d]=max(drz[v][a][d], drz[2*v][a][b]+drz[2*v+1][c][d]);
					}
				}
			}
		}
		v>>=1;
	}
}

ld sta[3];
ld now[3];

void czyt(int v, int a, int b, int graa, int grab)
{
	if (a>=graa && b<=grab)
	{
		sta[0]=now[0];
		sta[1]=now[1];
		sta[2]=now[2];
		now[0]=now[1]=now[2]=0;
		for (int c=0; c<3; c++)
			for (int d=0; c+d<3; d++)
				for (int e=0; e<3; e++)
					now[e]=max(now[e], sta[c]+drz[v][d][e]);
		return;
	}
	if (a>grab || b<graa)
	{
		return;
	}
	czyt((v<<1), a, (a+b)>>1, graa, grab);
	czyt((v<<1)^1, (a+b+2)>>1, b, graa, grab);
}

int main()
{
	scanf("%d%d", &n, &q);
	scanf("%lld%lld", &x, &y);
	if (x>y)
		swap(x, y);
	for (int i=1; i<=n; i++)
	{
		scanf("%lld", &tab[i]);
		ustaw(i, tab[i]);
	}
	while(q--)
	{
		int typ;
		scanf("%d", &typ);
		if (typ==1)
		{
			int a;
			ll b;
			scanf("%d%lld", &a, &b);
			tab[a]=b;
			ustaw(a, b);
			continue;
		}
		int l, r;
		scanf("%d%d", &l, &r);
		//~ dp[l-1]=0;
		//~ dp[l]=tab[l];
		//~ for (int i=l+1; i<=r; i++)
			//~ dp[i]=max(dp[i-1], dp[i-2]+tab[i]);
		//~ printf("%.12lf\n", dp[r]/(double)y);
		
		now[0]=now[1]=now[2]=0;
		czyt(1, 1, n1, l, r);
		printf("%.12lf\n", max(now[0], max(now[1], now[2])));
	}
	return 0;
}