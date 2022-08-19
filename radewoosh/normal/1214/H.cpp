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
const int nax=200*1007;

void nope()
{
	printf("No\n");
	exit(0);
}

void tak(vi wek)
{
	printf("Yes\n");
	for (int i : wek)
		printf("%d ", i);
	printf("\n");
	exit(0);
}

int n, k;

vi graf[nax];

int aodl[nax];
int bodl[nax];
int odl[nax];

int kol[nax];

void setodl(int v, int oj, int o)
{
	odl[v]=o;
	for (int i : graf[v])
		if (i!=oj)
			setodl(i, v, o+1);
}

ll los[nax];
ll wsz;

deque <ll> dp[nax];
ll dlawsz[nax];

void dfs(int v, int oj)
{
	vi dz;
	for (int i : graf[v])
	{
		if (i==oj)
			continue;
		dfs(i, v);
		dz.push_back(i);
	}
	dp[v].push_back(los[kol[v]]);
	for (int i : dz)
	{
		int a=i;
		int b=v;
		if ((int)dp[a].size()>(int)dp[b].size())
			swap(a, b);
		int ra=dp[a].size();
		int rb=dp[b].size();
		debug() << v << " " << i << "   " << dp[v] << " " << dp[i] << " " << dlawsz[v] << " " << dlawsz[i];
		for (int j=0; j<ra; j++)
		{
			int tam=(k-(j+1))-1;
			if (tam>=rb)
				continue;
			debug() << j << " " << tam;
			if (dp[a][j]==-1 || dp[b][tam]==-1 || (dp[a][j]^dlawsz[a]^dp[b][tam]^dlawsz[b])!=wsz)
			{
				debug() << "kur " << v << " " << i << "  " << a << " " << b;
				debug() << dp[v][0] << " " << dp[v].front();
				nope();
			}
		}
		dp[i].push_front(dlawsz[i]);
		dlawsz[i]^=los[kol[v]];
		if ((int)dp[i].size()>(int)dp[v].size())
		{
			dp[v].swap(dp[i]);
			swap(dlawsz[v], dlawsz[i]);
		}
		debug() << "mer " << v << " " << i << "  " << dp[v] << " " << dp[i] << " " << dlawsz[v] << " " << dlawsz[i];
		int ri=dp[i].size();
		for (int j=0; j<ri; j++)
		{
			//~ debug() << (dlawsz[i]^dp[i][j]) << "  " << (dlawsz[v]^dp[v][j]);
			if (dp[v][j]==-1 || dp[i][j]==-1 || (dlawsz[i]^dp[i][j])!=(dlawsz[v]^dp[v][j]))
				dp[v][j]=-1;
		}
		if ((int)dp[v].size()==k)
			dp[v].pop_back();
	}
	if ((int)dp[v].size()==k)
		dp[v].pop_back();
	debug() << "ret " << v << " " << dp[v];
}

int main()
{
	scanf("%d%d", &n, &k);
	srand(time(0));
	for (int i=1; i<=k; i++)
	{
		for (int j=0; j<62; j++)
			los[i]=(los[i]*2+(rand()&1));
		//~ los[i]=(1LL<<(i-1));
		wsz^=los[i];
	}
	for (int i=1; i<n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	setodl(1, 0, 0);
	int a=1;
	for (int i=1; i<=n; i++)
		if (odl[a]<odl[i])
			a=i;
	setodl(a, 0, 0);
	int b=1;
	for (int i=1; i<=n; i++)
		if (odl[b]<odl[i])
			b=i;
	for (int i=1; i<=n; i++)
		aodl[i]=odl[i];
	setodl(b, 0, 0);
	for (int i=1; i<=n; i++)
		bodl[i]=odl[i];
	for (int i=1; i<=n; i++)
	{
		if (aodl[i]>=bodl[i])
		{
			kol[i]=aodl[i]%k;
		}
		else
		{
			kol[i]=(aodl[b]-bodl[i])%k;
		}
		kol[i]++;
	}
	
	//~ debug() << imie(a) << imie(b);
	//~ debug() << range(aodl+1, aodl+1+n);
	//~ debug() << range(bodl+1, bodl+1+n);
	
	debug() << range(kol+1, kol+1+n);
	
	dfs(1, 0);
	
	vi wez;
	for (int i=1; i<=n; i++)
		wez.push_back(kol[i]);
	tak(wez);
	
	return 0;
}