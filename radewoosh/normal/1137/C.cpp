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
const int nax=100*1007;
const int kax=57;

int n, m, d;

vi graf[nax];
vi farg[nax];

char wcz[kax];
bitset <kax> tab[nax];

int bylo[nax];
int l;
int post[nax];
int spo[nax];
vi zbi[nax];
int k;

int cyk[nax];

int dp[nax][kax];

int gle[nax];

void dfs1(int v)
{
	if (bylo[v])
		return;
	bylo[v]=1;
	for (int i : graf[v])
	{
		if (!bylo[i])
			gle[i]=(gle[v]+1)%d;
		dfs1(i);
	}
	l++;
	post[l]=v;
}

void dfs2(int v)
{
	if (spo[v])
		return;
	spo[v]=l;
	zbi[l].push_back(v);
	for (int i : farg[v])
		dfs2(i);
}

void maxi(int &a, int b)
{
	a=max(a, b);
}

int main()
{
	scanf("%d%d%d", &n, &m, &d);
	for (int i=1; i<=m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graf[a].push_back(b);
		farg[b].push_back(a);
	}
	for (int i=1; i<=n; i++)
	{
		scanf("%s", wcz);
		for (int j=0; j<d; j++)
			tab[i][j]=wcz[j]-'0';
	}
	for (int i=1; i<=n; i++)
	{
		//~ if (!bylo[i])
			//~ gle[i]=1;
		dfs1(i);
	}
	l=0;
	for (int i=n; i; i--)
	{
		int v=post[i];
		if (!spo[v])
		{
			l++;
			dfs2(v);
		}
	}
	k=l;
	for (int i=1; i<=k; i++)
	{
		cyk[i]=d;
		for (int j : zbi[i])
		{
			for (int l : graf[j])
			{
				if (spo[l]==spo[j])
				{
					cyk[i]=__gcd(cyk[i], abs(gle[j]-gle[l]+1));
				}
			}
		}
		debug() << i << " " << cyk[i];
	}
	debug() << range(gle+1, gle+1+n);
	for (int i=k; i; i--)
	{
		for (int j=0; j<cyk[i]; j++)
		{
			for (int l=j; l<d; l+=cyk[i])
			{
				for (int v : zbi[i])
				{
					for (int u : graf[v])
					{
						if (spo[v]==spo[u])
							continue;
						maxi(dp[i][(j-gle[v]+d)%cyk[i]], dp[spo[u]][(l+1-gle[u]+d)%d]);
					}
				}
			}
		}
		for (int v : zbi[i])
		{
			for (int j=0; j<cyk[i]; j++)
			{
				int czy=0;
				for (int l=j; l<d; l+=cyk[i])
					if (tab[v][(l+gle[v])%d])
						czy=1;
				if (czy)
					dp[i][j]++;
			}
		}
		for (int j=cyk[i]; j<d; j++)
			dp[i][j]=dp[i][j-cyk[i]];
		debug() << i << " " << range(dp[i], dp[i]+d);
	}
	printf("%d\n", dp[spo[1]][0]);
	//~ debug() << range(spo+1, spo+1+n);
	return 0;
}