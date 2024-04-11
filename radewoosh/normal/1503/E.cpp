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
const int nax=2107;
const ll mod=998244353;

int n, m;

ll dp[nax][nax];

ll sci[nax][nax];

void dod(ll &a, ll b)
{
	a=(a+b)%mod;
}

ll wyn;

//~ int pom[nax][nax];

//~ int li=0;

//~ void brut(int mas)
//~ {
	//~ for (int i=0; i<3; i++)
	//~ {
		//~ for (int j=0; j<4; j++)
		//~ {
			//~ pom[i][j]=(mas&1);
			//~ mas>>=1;
		//~ }
	//~ }
	//~ for (int i=0; i<3; i++)
		//~ pom[i][4]=0;
	//~ for (int j=0; j<4; j++)
		//~ pom[3][j]=1;
	//~ for (int i=0; i<3; i++)
	//~ {
		//~ int ile=0;
		//~ for (int j=0; j<4; j++)
			//~ ile+=(pom[i][j]==1 && pom[i][j+1]==0);
		//~ if (ile!=1)
			//~ return;
	//~ }
	//~ for (int i=0; i<4; i++)
	//~ {
		//~ int ile=0;
		//~ for (int j=0; j<3; j++)
			//~ ile+=(pom[j][i]==0 && pom[j+1][i]==1);
		//~ if (ile!=1)
			//~ return;
	//~ }
	
	//~ li++;
	//~ debug() << imie(li);
	//~ for (int i=0; i<3; i++)
		//~ debug() << range(pom[i], pom[i]+4);
	//~ debug();
//~ }

ll lg(int a, int b)
{
	return sci[a][b-1];
}

ll ld(int a, int b)
{
	return sci[n-a-1][b];
}

ll pg(int a, int b)
{
	return sci[a-1][m-b];
}

ll pd(int a, int b)
{
	return sci[n-a][m-b-1];
}

int main()
{
	//~ for (int i=0; i<(1<<12); i++)
		//~ brut(i);
	//~ debug() << "po";
	scanf("%d%d", &n, &m);
	if (n==1 || m==1)
	{
		printf("0\n");
		return 0;
	}
	sci[0][0]=1;
	for (int i=0; i<nax; i++)
	{
		for (int j=0; j<nax; j++)
		{
			if (i)
				dod(sci[i][j], sci[i-1][j]);
			if (j)
				dod(sci[i][j], sci[i][j-1]);
		}
	}
	//~ for (int i=2; i<=n; i++)
	//~ {
		//~ for (int j=2; j<=m; j++)
		//~ {
			
		//~ }
	//~ }
	for (int i=1; i<n; i++)
	{
		for (int j=1; j<m; j++)
		{
			//~ debug() << lg(i, j) << " " << ld(i, j) << " " << pg(i, j) << " " << pd(i, j);
			dod(wyn, lg(i, j)*ld(i, j)%mod*pg(i, j)%mod*pd(i, j));
		}
	}
	for (int i=1; i<n; i++)
	{
		ll s=0;
		for (int j=1; j<m; j++)
		{
			dod(wyn, s*ld(i, j)%mod*pd(i, j));
			dod(s, lg(i, j)*pg(i, j));
		}
	}
	for (int j=1; j<m; j++)
	{
		ll s=0;
		for (int i=1; i<n; i++)
		{
			dod(wyn, s*ld(i, j)%mod*lg(i, j));
			dod(s, pd(i, j)*pg(i, j));
		}
	}
	dod(wyn, wyn);
	printf("%lld\n", wyn);
	return 0;
}