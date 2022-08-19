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
const ll inf=1e18;

int n;

vector <pair<int,ll>> graf[nax];
int ojc[nax];
ll wagoj[nax];

int gle[nax];
int sto[nax];

int dos[nax];

vector <pll> wsz[nax];
vll ter[nax];
vll sum[nax];

bool mniej(int a, int b)
{
	return sto[a]>sto[b];
}

bool mniej2(pair<int,ll> a, pair<int,ll> b)
{
	return sto[a.first]>sto[b.first];
}

bool mniej3(int a, int b)
{
	return gle[a]>gle[b];
}

void dfs1(int v, int oj)
{
	gle[v]++;
	ojc[v]=oj;
	for (auto &i : graf[v])
	{
		if (i.first==oj)
		{
			swap(i, graf[v].back());
			graf[v].pop_back();
			break;
		}
	}
	sort(graf[v].begin(), graf[v].end(), mniej2);
	for (auto i : graf[v])
	{
		wagoj[i.first]=i.second;
		gle[i.first]=gle[v];
		dfs1(i.first, v);
	}
}

ll wyn;

vi ost{-7};

void przelicz(int v)
{
	for (int i=1; i<=n; i++)
	{
		if (sto[i]<=v)
			continue;
		ter[i].clear();
		sum[i].clear();
		sum[i].push_back(0);
		ll s=0;
		for (pll j : wsz[i])
		{
			if (sto[j.second]>v)
				continue;
			ter[i].push_back(j.first);
			s+=j.first;
			sum[i].push_back(s);
		}
		ter[i].push_back(inf);
		sum[i].push_back(inf);
	}
}

ll dpbez[nax];
ll dpgor[nax];

void ogarnij(int v, int lim)
{
	int som=0;
	while(som<(int)graf[v].size() && sto[graf[v][som].first]>lim)
		som++;
	int gor=(sto[ojc[v]]>lim);
	int resz=sto[v]-som-gor;
	int insta=max(0, resz-lim);
	int inpam=insta;
	//~ debug() << "og " << v << " " << lim << " " << som << " " << gor << " " << insta;
	{
		vll opc;
		ll pam=sum[v][insta];
		for (int i=0; i<som; i++)
		{
			pam+=dpbez[graf[v][i].first];
			opc.push_back(dpgor[graf[v][i].first]-dpbez[graf[v][i].first]);
		}
		if (gor)
			opc.push_back(wagoj[v]);
		opc.push_back(inf);
		sort(opc.begin(), opc.end());
		int w=0;
		int musz=sto[v]-insta-lim;
		//~ debug() << opc << " " << ter[v] << " " << musz << " " << insta;
		while(musz--)
		{
			if (opc[w]<ter[v][insta])
			{
				pam+=opc[w];
				w++;
			}
			else
			{
				pam+=ter[v][insta];
				insta++;
			}
		}
		dpbez[v]=pam;
		if (sto[ojc[v]]<=lim)
		{
			wyn+=dpbez[v];
			return;
		}
	}
	insta=inpam;
	//~ debug() << "sr";
	{
		vll opc;
		ll pam=sum[v][insta];
		for (int i=0; i<som; i++)
		{
			pam+=dpbez[graf[v][i].first];
			opc.push_back(dpgor[graf[v][i].first]-dpbez[graf[v][i].first]);
		}
		assert(gor);
		pam+=wagoj[v];
		opc.push_back(inf);
		sort(opc.begin(), opc.end());
		int w=0;
		int musz=sto[v]-insta-lim-1;
		//~ debug() << musz << " " << opc << " " << ter[v];
		//~ debug() << opc << " " << ter[v] << " " << musz << " " << insta;
		while(musz--)
		{
			if (opc[w]<ter[v][insta])
			{
				pam+=opc[w];
				w++;
			}
			else
			{
				pam+=ter[v][insta];
				insta++;
			}
		}
		dpgor[v]=pam;
	}
	assert(dpbez[v]<=dpgor[v]);
	//~ dpbez[v]=min(dpbez[v], dpgor[v]);
}

void solve(int v)
{
	if (!v)
	{
		ll s=0;
		for (int i=1; i<=n; i++)
			s+=wagoj[i];
		printf("%lld ", s);
		return;
	}
	vi wek;
	for (int i=1; i<=n && sto[dos[i]]>v; i++)
		wek.push_back(dos[i]);
	sort(wek.begin(), wek.end(), mniej3);
	if (wek!=ost)
	{
		przelicz(v);
		ost=wek;
	}
	//~ debug() << wek;
	wyn=0;
	for (int i : wek)
	{
		ogarnij(i, v);
	}
	
	printf("%lld ", wyn);
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
		sto[a]++;
		sto[b]++;
	}
	sto[1]++;
	for (int i=1; i<=n; i++)
		dos[i]=i;
	sort(dos+1, dos+1+n, mniej);
	dfs1(1, 0);
	for (int i=1; i<=n; i++)
	{
		for (auto j : graf[i])
			wsz[i].push_back({j.second, j.first});
		wsz[i].push_back({wagoj[i], ojc[i]});
		sort(wsz[i].begin(), wsz[i].end());
	}
	for (int h=0; h<n; h++)
		solve(h);
	printf("\n");
	return 0;
}