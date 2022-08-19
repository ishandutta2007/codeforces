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
const int nax=307;
const ll mod=998244353;
const ll o2=(mod+1)/2;

int n;

vi graf[nax];

ll dpzly[nax][nax];
ll dpdobry[nax][nax];
ll dpdone[nax];

ll conaj[nax];

int cel;

void dod(ll &a, ll b)
{
	a=(a+b)%mod;
}

int lacz(int a, int b)
{
	if (!a)
		return b;
	if (!b)
		return a;
	return min(a, b);
}

vi da, db, za, zb;

void polacz_dzieci(int a, int b)
{
	memset(dpzly[0], 0, sizeof(dpzly[0]));
	memset(dpdobry[0], 0, sizeof(dpdobry[0]));
	dpdone[0]=0;
	da.clear();
	db.clear();
	za.clear();
	zb.clear();
	//~ debug() << "lacze " << a << " " << b;
	for (int i=0; i<=n; i++)
	{
		if (dpdobry[a][i])
			da.push_back(i);
		if (dpdobry[b][i])
			db.push_back(i);
		if (dpzly[a][i])
			za.push_back(i);
		if (dpzly[b][i])
			zb.push_back(i);
	}
	for (int i : da)
	{
		for (int j : db)
		{
			dod(dpdobry[0][max(i, j)], dpdobry[a][i]*dpdobry[b][j]);
		}
	}
	for (int i : za)
	{
		for (int j : zb)
		{
			dod(dpzly[0][min(i, j)], dpzly[a][i]*dpzly[b][j]);
		}
	}
	ll sa=0;
	ll sb=0;
	for (int i=0; i<=n; i++)
	{
		dod(sa, dpzly[a][i]+dpdobry[a][i]);
		dod(sb, dpzly[b][i]+dpdobry[b][i]);
	}
	dod(dpdone[0], dpdone[a]*(dpdone[b]+sb)+dpdone[b]*sa);
	for (int h=0; h<2; h++)
	{
		for (int i : da)
		{
			for (int j : zb)
			{
				if (i+j+2<=cel)
					dod(dpzly[0][j], dpdobry[a][i]*dpzly[b][j]);
				else                                           
					dod(dpdobry[0][i], dpdobry[a][i]*dpzly[b][j]);
			}
		}
		swap(a, b);
		da.swap(db);
		za.swap(zb);
	}
}

void przepisz(int z, int gdz)
{
	for (int i=0; i<=n; i++)
	{
		dpzly[gdz][i]=dpzly[z][i];
		dpdobry[gdz][i]=dpdobry[z][i];
	}
	dpdone[gdz]=dpdone[z];
}

void ciagnij(int v)
{
	memset(dpzly[v], 0, sizeof(dpzly[v]));
	memset(dpdobry[v], 0, sizeof(dpdobry[v]));
	dpdone[v]=0;
	
	
	{//dobry
		dod(dpdone[v], dpdone[0]);
		for (int i=0; i<=n; i++)
		{
			if (i+1>=cel)
				dod(dpdone[v], dpdobry[0][i]);
			else
				dod(dpdobry[v][i+1], dpdobry[0][i]);
		}
		for (int i=0; i<=n; i++)
		{
			if (i>=cel)
			{
				if (cel)
					dod(dpdobry[v][0], dpzly[0][i]);
				else
					dod(dpdone[v], dpzly[0][i]);
			}
			else
			{
				dod(dpzly[v][min(i+1, n)], dpzly[0][i]);
			}
		}
	}
	{//zly
		dod(dpdone[v], dpdone[0]);
		for (int i=0; i<=n; i++)
		{
			dod(dpzly[v][0], dpzly[0][i]+dpdobry[0][i]);
		}
	}
}

void dfs1(int v, int oj)
{
	for (int i : graf[v])
	{
		if (i==oj)
			continue;
		dfs1(i, v);
	}
	przepisz(n+2, 0);
	dpzly[0][n]=1;
	for (int i : graf[v])
	{
		if (i==oj)
			continue;
		przepisz(0, n+1);
		polacz_dzieci(n+1, i);
	}
	ciagnij(v);
	//~ debug() << 0 << " " << dpdone[0] << " " << range(dpzly[0], dpzly[0]+1+n) << " " << range(dpdobry[0], dpdobry[0]+1+n);
	//~ debug() << v << " " << dpdone[v] << " " << range(dpzly[v], dpzly[v]+1+n) << " " << range(dpdobry[v], dpdobry[v]+1+n);
	//~ debug();
}

int dfs2(int v, int oj)
{
	int ret=0;
	for (int i : graf[v])
		if (i!=oj)
			ret=max(ret, dfs2(i, v)+1);
	return ret;
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	int naj=0;
	for (int i=1; i<=n; i++)
		naj=max(naj, dfs2(i, 0));
	for (int g=0; g<=naj; g++)
	{
		cel=g;
		//~ debug() << imie(cel);
		dfs1(1, 0);
		conaj[g]=dpdone[1];
		for (int i=0; i<=n; i++)
			dod(conaj[g], dpdobry[1][i]);
		//~ debug() << imie(g) << imie(conaj[g]);
		//~ return 0;
	}
	//~ int naj=0;
	//~ for (int i=1; i<=n; i++)
		//~ naj=max(naj, dfs2(i, 0));
	//~ debug() << range(conaj, conaj+n);
	//~ debug() << imie(naj);
	//~ dod(conaj[naj], mod-1);
	ll wyn=0;
	dod(wyn, mod-naj);
	for (int i=1; i<n; i++)
		dod(wyn, conaj[i]);
	dod(wyn, n-1);
	for (int i=1; i<=n; i++)
		wyn=(wyn*o2)%mod;
	printf("%lld\n", wyn);
	return 0;
}