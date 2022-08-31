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

const int nax=107;
using ll=long long;
const ll mod=1000*1000*1000+7;

int n;

vector <int> graf[nax];

ll dp[nax][nax][nax];
int roz[nax];

ll sta[nax][nax];

inline void dod(ll &a, ll b)
{
	a=(a+b)%mod;
}

ll odw[nax];

ll dziel(ll a, ll b)
{
	ll wyk=mod-2;
	while(wyk)
	{
		if (wyk&1)
			a=(a*b)%mod;
		b=(b*b)%mod;
		wyk>>=1;
	}
	return a;
}

void podczep(int v, int u)
{
	for (int i=0; i<nax; i++)
	{
		for (int j=0; j<nax; j++)
		{
			sta[i][j]=dp[v][i][j];
			dp[v][i][j]=0;
		}
	}
	for (int i=1; i<=roz[v]; i++)
	{
		for (int j=1; j<=roz[v]; j++)
		{
			for (int l=1; l<=roz[u]; l++)
			{
				for (int k=1; k<=roz[u]; k++)
				{
					dod(dp[v][i+l][j], sta[i][j]*dp[u][l][k]);
					dod(dp[v][i+l-1][j+k], ((sta[i][j]*dp[u][l][k])%mod)*(((odw[j]*odw[k])%mod)*(j+k)%mod));
				}
			}
		}
	}
	roz[v]+=roz[u];
}

void dfs(int v, int oj)
{
	dp[v][1][1]=1;
	roz[v]=1;
	for (int i : graf[v])
	{
		if (i==oj)
			continue;
		dfs(i, v);
		podczep(v, i);
	}
	debug() << range(dp[v][1], dp[v][1]+n+1);
}

ll wyn[nax];
ll kom[nax][nax];

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		odw[i]=dziel(1, i);
	for (int i=1; i<n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		//~ a=i;
		//~ b=i+1;
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	dfs(1, 0);
	for (int i=1; i<=n; i++)
	{
		debug() << range(dp[1][i], dp[1][i]+n+1);
		for (int j=1; j<=n; j++)
			dod(wyn[i], dp[1][i][j]);
		//~ debug() << i << " " << wyn[i];
		for (int j=1; j<=i-2; j++)
			wyn[i]=(wyn[i]*n)%mod;
		if (i==1)
			wyn[i]=(wyn[i]*odw[n])%mod;
		debug() << i << " " << wyn[i];
	}
	for (int i=0; i<=n; i++)
	{
		kom[i][0]=1;
		for (int j=1; j<=i; j++)
			kom[i][j]=(kom[i-1][j]+kom[i-1][j-1])%mod;
	}
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<i; j++)
			dod(wyn[i], -wyn[j]*kom[n-j][n-i]);
		wyn[i]%=mod;
		wyn[i]+=mod;
		wyn[i]%=mod;
	}
	for (int i=n; i; i--)
		printf("%lld ", wyn[i]);
	//~ for (int i=n-1; i>=0; i--)
	//~ {
		//~ for (int j=i+1; j<n; j++)
		//~ {
			//~ int tu=
			//~ dod(wyn[i], -wyn[j]*);
		//~ }
	//~ }
	printf("\n");
	return 0;
}