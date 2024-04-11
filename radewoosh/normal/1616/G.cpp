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
const int nax=150*1007;
const int vax=(6080);
//~ const int vax=3;
using bn=bitset<vax>;

int n, m;

vi graf[nax];

ll wyn;

int najd[nax];

int ist(int a, int b)
{
	for (int i : graf[a])
		if (i==b)
			return 1;
	return 0;
}

vector<vi> cons;

vi ter;

bn dp[nax][2];
int juz[nax][2];

void solve(int suf)
{
	for (int i=0; i<=n; i++)
	{
		juz[i][0]=juz[i][1]=0;
	}
	for (int i=0; i<(int)ter.size(); i++)
	{
		juz[ter[i]][0]=1;
		dp[ter[i]][0].reset();
		dp[ter[i]][0][i]=1;
	}
	for (int i=0; i<=n; i++)
	{
		for (int j=0; j<2; j++)
		{
			if (!juz[i][j])
				continue;
			for (int l : graf[i])
			{
				if (l==i+1)
					continue;
				if (l>najd[i+1]+1)
					continue;
				if (juz[l-1][j^1])
				{
					dp[l-1][j^1]|=dp[i][j];
				}
				else
				{
					juz[l-1][j^1]=1;
					dp[l-1][j^1]=dp[i][j];
				}
			}
		}
	}
	//~ debug() << imie(ter);
	for (int i=suf-1; i<=n; i++)
	{
		if (!juz[i][0])
			continue;
		//~ for (int j=0; j<(int)ter.size(); j++)
			//~ if (dp[i][0][j])
				//~ debug() << "z " << ter[j] << " do " << i;
		wyn+=dp[i][0].count();
		for (int j=(int)ter.size()-1; j>=0; j--)
		{
			if (ter[j]==i && dp[i][0][j])
				wyn--;
			else
				break;
		}
	}
}

void test()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; i++)
	{
		graf[i].clear();
	}
	for (int i=1; i<=n; i++)
	{
		graf[0].push_back(i);
		graf[i].push_back(n+1);
	}
	for (int i=1; i<=m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graf[a].push_back(b);
	}
	wyn=0;
	{
		int ok=1;
		for (int i=1; i<n; i++)
			ok&=ist(i, i+1);
		if (ok)
		{
			for (int i=0; i<n; i++)
				wyn+=i;
			printf("%lld\n", wyn);
			return;
		}
	}
	int p=1;
	while(ist(p, p+1))
		p++;
	int s=n;
	while(ist(s-1, s))
		s--;
	najd[n+1]=n+1;
	for (int i=n; i>=0; i--)
	{
		najd[i]=i;
		if (ist(i, i+1))
			najd[i]=najd[i+1];
	}
	cons.clear();
	for (int i=0; i<=p; i++)
	{
		if (!(i%vax))
			cons.push_back(vi{});
		cons.back().push_back(i);
	}
	for (int i=0; i<(int)cons.size(); i++)
	{
		ter=cons[i];
		solve(s);
	}
	
	printf("%lld\n", wyn);
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}