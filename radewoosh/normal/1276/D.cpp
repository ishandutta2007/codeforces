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
const int nax=1000*1007;
const ll mod=998244353;

int n;

vector <pii> graf[nax];

ll dp[nax][2][2];
int prz[2][2][2][2];

void dod(ll &a, ll b)
{
	a=(a+b)%mod;
}

void mno(ll &a, ll b)
{
	a=(a*b)%mod;
}

ll st[2];
ll now[2];

void dfs1(int v, int oj)
{
	vi mni;
	vi wie;
	for (pii i : graf[v])
	{
		if (i.second==oj)
			continue;
		dfs1(i.first, i.second);
		if (i.second<oj)
			mni.push_back(i.first);
		else
			wie.push_back(i.first);
	}
	for (int a=0; a<2; a++)
	{
		for (int b=0; b<2; b++)
		{
			for (int c=0; c<2; c++)
			{
				for (int d=0; d<2; d++)
				{
					if (!prz[a][b][c][d])
						continue;
					now[0]=1;
					now[1]=0;
					for (int i : mni)
					{
						st[0]=now[0];
						st[1]=now[1];
						now[0]=now[1]=0;
						for (int x=0; x<2; x++)
							for (int y=0; y<2; y++)
								dod(now[y], st[x]*dp[i][x][y]);
					}
					st[0]=now[0];
					st[1]=now[1];
					now[0]=now[1]=0;
					//~ dod(now[c], st[a]);
					dod(now[d], st[b]);
					for (int i : wie)
					{
						st[0]=now[0];
						st[1]=now[1];
						now[0]=now[1]=0;
						for (int x=0; x<2; x++)
							for (int y=0; y<2; y++)
								dod(now[y], st[x]*dp[i][x][y]);
					}
					dod(dp[v][a][c], now[0]+now[1]);
				}
			}
		}
	}
	//~ for (int i=0; i<2; i++)
		//~ for (int j=0; j<2; j++)
			//~ debug() << v << "  " << i << " " << j << "  " << dp[v][i][j];
	//~ debug();
}

int main()
{
	prz[0][0][0][1]=1;
	prz[0][0][1][0]=1;
	prz[1][0][1][0]=1;
	prz[0][1][0][1]=1;
	prz[1][1][1][1]=1;
	scanf("%d", &n);
	for (int i=1; i<n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graf[a].push_back({b, i});
		graf[b].push_back({a, i});
	}
	dfs1(1, 0);
	printf("%lld\n", dp[1][1][1]);
	return 0;
}