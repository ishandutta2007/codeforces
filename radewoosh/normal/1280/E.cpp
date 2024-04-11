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
const ll mod=1000*1000*1000+7;
const ll inf=3e18;

int cel;

int n;
char wcz[nax];
char pom[nax];

int m;
ll wyn[nax];

int g;

ll dp[nax];

int k;
pii prz[nax];
vi drz[nax];
char typ[nax];
int licz;
int kt[nax];

ll mno(ll a, ll b)
{
	ll r=a*b;
	if (r/a!=b || r/b!=a)
		return inf;
	return min(r, inf);
}

int dfs1()
{
	k++;
	int v=k;
	drz[v].clear();
	prz[v].first=g;
	if (wcz[g]=='*')
	{
		licz++;
		kt[v]=licz;
		typ[v]='X';
		prz[v].second=g;
		dp[v]=1;
		return v;
	}
	g++;
	drz[v].push_back(dfs1());
	while(1)
	{
		g++;
		if (wcz[g]==')')
			break;
		typ[v]=wcz[g];
		g++;
		drz[v].push_back(dfs1());
	}
	prz[v].second=g;
	if (typ[v]=='S')
	{
		dp[v]=nax;
		for (int i : drz[v])
			dp[v]=min(dp[v], dp[i]);
	}
	else
	{
		dp[v]=0;
		for (int i : drz[v])
			dp[v]+=dp[i];
	}
	return v;
}

void dfs2(int v, ll mno)
{
	if (typ[v]=='X')
	{
		wyn[kt[v]]=cel*mno;
		return;
	}
	if (typ[v]=='S')
	{
		for (int i : drz[v])
		{
			if (dp[i]==dp[v])
			{
				dfs2(i, mno);
				return;
			}
		}
		assert(0);
	}
	else
	{
		for (int i : drz[v])
			dfs2(i, mno);
	}
}

void test()
{
	scanf("%d", &cel);
	int poz=0;
	n=0;
	while(1)
	{
		scanf("%s", pom+1);
		for (int i=1; pom[i]; i++)
		{
			n++;
			wcz[n]=pom[i];
			if (pom[i]=='(')
				poz++;
			if (pom[i]==')')
				poz--;
		}
		if (!poz)
			break;
	}
	m=0;
	for (int i=1; i<=n; i++)
		m+=(wcz[i]=='*');
	for (int i=1; i<=m; i++)
		wyn[i]=0;
	debug() << range(wcz+1, wcz+1+n);
	g=1;
	k=0;
	licz=0;
	dfs1();
	debug() << imie(range(dp+1, dp+1+k));
	dfs2(1, dp[1]);
	
	
	
	
	
	printf("REVOLTING");
	for (int i=1; i<=m; i++)
		printf(" %lld", wyn[i]);
	printf("\n");
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}