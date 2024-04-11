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
using pii=pair <int,int>;
const int nax=8007;
const int vax=80;
const ll mod=998244353;

void ans(ll v)
{
	printf("%lld\n", v);
	exit(0);
}

int np[2];
int n, k;
vector <pii> graf[nax];

ll dpnor[nax][vax];
ll dpblok[nax][vax];

ll ilej[2][vax];

void dod(ll &a, ll b)
{
	a=(a+b+mod)%mod;
}

ll kom[vax][vax];

ll sum[nax][vax];

void fix(ll &a)
{
	a%=mod;
	a+=mod;
	a%=mod;
}

int main()
{
	scanf("%d%d%d", &np[0], &np[1], &k);
	if (k&1)
		ans(0);
	for (int h=0; h<2; h++)
	{
		n=np[h];
		for (int i=1; i<=n; i++)
			graf[i].clear();
		for (int i=1; i<n; i++)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			graf[a].push_back({b, i*2});
			graf[b].push_back({a, i*2+1});
		}
		memset(dpnor, 0, sizeof(dpnor));
		memset(dpblok, 0, sizeof(dpblok));
		memset(sum, 0, sizeof(sum));
		//~ memset(dpgor, 0, sizeof(dpgor));
		for (int i=1; i<=n; i++)
			dpnor[i][0]=1;
		for (int i=2; i<2*n; i++)
			dpblok[i][0]=1;
		//~ for (int i=1; i<=n; i++)
			//~ sum[i][0]=graf[i].size();
		for (int i=1; i<=k/2; i++)
		{
			debug() << imie(i);
			for (int j=1; j<=n; j++)
			{
				for (pii l : graf[j])
				{
					ll ter=0;
					for (int p=0; p<i; p++)
						dod(ter, dpblok[l.second^1][p]*dpnor[j][i-p-1]);
					dod(dpnor[j][i], ter);
					//~ dod(dpblok[l.second][i], -ter);
				}
				//~ for (pii l : graf[j])
					//~ dod(dpblok[l.second][i], dpnor[j][i]);
				
				//~ debug() << j << " " << dpnor[j][i];
				//~ for (pii l : graf[j])
					//~ debug() << l << " " << dpblok[l.second][i];
			}
			for (int j=1; j<=n; j++)
			{
				for (pii l : graf[j])
					dod(sum[j][i-1], dpblok[l.second^1][i-1]);
			}
			for (int j=1; j<=n; j++)
			{
				for (pii l : graf[j])
				{
					ll ter=0;
					for (int p=0; p<i; p++)
						dod(ter, (sum[j][p]-dpblok[l.second^1][p])*dpblok[l.second][i-p-1]);
					fix(ter);
					dod(dpblok[l.second][i], ter);
				}
				
				//~ debug() << j << " " << dpnor[j][i];
				//~ for (pii l : graf[j])
					//~ debug() << l << " " << dpblok[l.second][i];
			}
		}
		for (int i=0; i<=k/2; i++)
			for (int j=1; j<=n; j++)
				dod(ilej[h][i*2], dpnor[j][i]);
	}
	//~ for (int h=0; h<2; h++)
		//~ debug() << range(ilej[h], ilej[h]+1+k);
	for (int i=0; i<=k; i++)
	{
		kom[i][0]=1;
		for (int j=1; j<=i; j++)
			kom[i][j]=(kom[i-1][j]+kom[i-1][j-1])%mod;
	}
	//~ debug() << range(kom[k], kom[k]+1+k);
	ll wyn=0;
	for (int i=0; i<=k; i++)
		dod(wyn, ((ilej[0][i]*ilej[1][k-i])%mod)*kom[k][i]);
	ans(wyn);
	return 0;
}