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
const int nax=1000*1007;
const ll inf=1e18;
const int kax=30;

int n;

vector<pair<int,ll>> graf[nax];
int k;
int stre[nax];

char wcz[nax];

ll pass[kax];
ll fine[kax];
ll przerwa;

ll gle[nax];
int ost[nax];
int ojc[nax];

ll zaw[200*1007][kax];

int ojf[nax];
vi spo[nax];

ll nibymin[200*1007][kax];
int maska[nax];

int q;
int typzap[nax];
vi zapzar[nax];
ll wyn[nax];

vi tuodp[nax];
vector<pii> zmienia[kax][3];

int fin(int v)
{
	if (v!=ojf[v])
		ojf[v]=fin(ojf[v]);
	return ojf[v];
}

void uni(int a, int b)
{
	ojf[fin(a)]=fin(b);
}

void dfs1(int v, int oj)
{
	ost[v]=v;
	ojc[v]=oj;
	if (oj && stre[oj]==stre[v])
		ost[v]=ost[oj];
	for (auto i : graf[v])
	{
		if (i.first==oj)
			continue;
		gle[i.first]=gle[v]+i.second;
		dfs1(i.first, v);
	}
}

ll ter[kax];

ll zanim(ll v)
{
	if (!v)
		return 0;
	return (v-1)/przerwa;
}

ll bedzie_kontroli(ll dys, ll mom)
{
	return zanim(mom+dys)-zanim(mom);
}

ll baza;
ll doplac[kax];

set<int> zwracany[nax];

void dfs2(int v)
{
	zwracany[v].insert(maska[v]);
	for (auto i : graf[v])
	{
		if (ojc[v]==i.first)
			continue;
		dfs2(i.first);
		if (stre[i.first]==stre[v])
			for (int j : zwracany[i.first])
				zwracany[v].insert(j);
		zwracany[i.first].clear();
	}
	for (int i : tuodp[v])
	{
		//~ debug() << v << " " << i << " " << mapa[stre[v]];
		for (int j=0; j<k; j++)
		{
			int g=lower_bound(zmienia[j][1].begin(), zmienia[j][1].end(), pii{i, 0})-zmienia[j][1].begin();
			g--;
			pass[j]=zmienia[j][1][g].second;
		}
		for (int j=0; j<k; j++)
		{
			int g=lower_bound(zmienia[j][2].begin(), zmienia[j][2].end(), pii{i, 0})-zmienia[j][2].begin();
			g--;
			fine[j]=zmienia[j][2][g].second;
		}
		baza=0;
		for (int j=0; j<k; j++)
		{
			ll pod=nibymin[fin(v)][j];
            pod=min(pod, (ll)2e9);
			baza+=min(pass[j], fine[j]*pod);
			doplac[j]=min(pass[j], fine[j]*(pod+1))-min(pass[j], fine[j]*pod);
		}
		ll best=inf;
		for (int i : zwracany[v])
		{
			ll tu=0;
			for (int j=0; j<k; j++)
				if (i&(1<<j))
					tu+=doplac[j];
			best=min(best, tu);
		}
		wyn[i]=baza+best;
		//~ debug() << v << " " << i << " " << baza << " " << range(doplac, doplac+k);
	}
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<n; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		graf[a].push_back({b, c});
		graf[b].push_back({a, c});
	}
	scanf("%d", &k);
	scanf("%s", wcz+1);
	for (int i=1; i<=n; i++)
		stre[i]=wcz[i]-'A';
	for (int i=0; i<k; i++)
		scanf("%lld", &pass[i]);
	for (int i=0; i<k; i++)
		scanf("%lld", &fine[i]);
	scanf("%lld", &przerwa);
	dfs1(1, 0);
	//~ debug() << range(stre+1, stre+1+n);
	//~ debug() << range(ost+1, ost+1+n);
	for (int i=1; i<=n; i++)
	{
		for (int j=0; j<k; j++)
			ter[j]=0;
		int v=i;
		ll mom=0;
		while(v)
		{
			int u=ojc[ost[v]];
			ll odl=gle[v]-gle[u];
			//~ debug() << v << " " << u << "   " << bedzie_kontroli(gle[v], mom) << "  " << bedzie_kontroli(gle[u], mom+odl);
			ter[stre[v]]+=bedzie_kontroli(gle[v], mom)-bedzie_kontroli(gle[u], mom+odl);
			v=u;
			mom+=odl;
		}
		//~ debug() << i << " " << range(ter, ter+k);
		for (int j=0; j<k; j++)
			if (j!=stre[i])
				zaw[i][j]=ter[j];
		//~ debug() << i << " " << range(zaw[i], zaw[i]+k);
	}
	for (int i=1; i<=n; i++)
		ojf[i]=i;
	for (int i=1; i<=n; i++)
		for (auto j : graf[i])
			if (stre[i]==stre[j.first])
				uni(i, j.first);
	for (int i=1; i<=n; i++)
		spo[fin(i)].push_back(i);
	for (int i=1; i<=n; i++)
	{
		if (ojf[i]!=i)
			continue;
		for (int j=0; j<k; j++)
			nibymin[i][j]=inf;
		for (int j : spo[i])
			for (int l=0; l<k; l++)
				nibymin[i][l]=min(nibymin[i][l], zaw[j][l]);
		for (int j : spo[i])
		{
			for (int l=0; l<k; l++)
			{
				assert(zaw[j][l]==nibymin[i][l] || zaw[j][l]==nibymin[i][l]+1);
				if (zaw[j][l]==nibymin[i][l]+1)
					maska[j]|=(1<<l);
			}
		}
	}
	//~ for (int i=1; i<=n; i++)
		//~ debug() << imie(maska[i]);
	for (int i=0; i<k; i++)
	{
		zmienia[i][1].push_back({0, pass[i]});
		zmienia[i][2].push_back({0, fine[i]});
	}
	scanf("%d", &q);
	for (int i=1; i<=q; i++)
	{
		scanf("%d", &typzap[i]);
		if (typzap[i]<=2)
		{
			char z;
			int x;
			scanf(" %c%d", &z, &x);
			zapzar[i]={z-'A', x};
			zmienia[z-'A'][typzap[i]].push_back({i, x});
			
		}
		else
		{
			int v;
			scanf("%d", &v);
			tuodp[v].push_back(i);
		}
	}
	dfs2(1);
	for (int i=1; i<=q; i++)
		if (typzap[i]==3)
			printf("%lld\n", wyn[i]);
	return 0;
}