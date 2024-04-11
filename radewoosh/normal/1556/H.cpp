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
const int nax=2507;
const int inf=1e9;

int n, k;

int lim[nax];
int mac[nax][nax];
int num[nax][nax];

vector<pii> spec, og;
vll samo;
int wziete[nax];

int wyn=inf;

int oj[nax];

int fin(int v)
{
	if (v!=oj[v])
		oj[v]=fin(oj[v]);
	return oj[v];
}

void uni(int a, int b)
{
	oj[fin(a)]=fin(b);
}

void clear()
{
	for (int i=1; i<=n; i++)
		oj[i]=i;
}

int mastop[nax];

vi graf[nax];

void czysgraf()
{
	for (int i=1; i<=n; i++)
		graf[i].clear();
}

vi glo;

vi stos;

void dfs1(int v, int oj, int cel)
{
	stos.push_back(v);
	if (v==cel)
	{
		for (int i=0; i+1<(int)stos.size(); i++)
			if (num[stos[i]][stos[i+1]]>=0)
				glo.push_back(num[stos[i]][stos[i+1]]);
		stos.pop_back();
		return;
	}
	for (int i : graf[v])
	{
		if (i==oj)
			continue;
		dfs1(i, v, cel);
		if (!glo.empty())
			break;
	}
	stos.pop_back();
}

void znajdz_sciezke(int a, int b)
{
	glo.clear();
	stos.clear();
	dfs1(a, 0, b);
}

int startowy[nax];
int koncowy[nax];

vi super[nax];

ll odl[nax];
int z[nax];

int aktu[nax];

void solve(int maska)
{
	clear();
	czysgraf();
	for (int i=1; i<=k; i++)
		mastop[i]=0;
	for (int i=0; i<(int)spec.size(); i++)
	{
		if (maska&(1<<i))
		{
			int a=spec[i].first;
			int b=spec[i].second;
			if (fin(a)==fin(b))
				return;
			uni(a, b);
			mastop[a]++;
			mastop[b]++;
			graf[a].push_back(b);
			graf[b].push_back(a);
		}
	}
	for (int i=1; i<=k; i++)
		if (mastop[i]>lim[i])
			return;
	int jeszcze=n-1-(int)__builtin_popcount(maska);
	int r=og.size();
	for (int i=0; i<r; i++)
		wziete[i]=0;
	if (!maska)
		debug() << imie(jeszcze);
	while(jeszcze--)
	{
		for (int i=0; i<r; i++)
			super[i].clear();
		for (int i=1; i<=n; i++)
			mastop[i]=0;
		clear();
		czysgraf();
		for (int i=0; i<(int)spec.size(); i++)
		{
			if (maska&(1<<i))
			{
				int a=spec[i].first;
				int b=spec[i].second;
				uni(a, b);
				graf[a].push_back(b);
				graf[b].push_back(a);
				mastop[a]++;
				mastop[b]++;
			}
		}
		for (int i=0; i<r; i++)
		{
			if (wziete[i])
			{
				int a=og[i].first;
				int b=og[i].second;
				uni(a, b);
				graf[a].push_back(b);
				graf[b].push_back(a);
				mastop[a]++;
				mastop[b]++;
			}
		}
		for (int i=0; i<r; i++)
		{
			startowy[i]=koncowy[i]=0;
			if (!wziete[i])
			{
				int a=og[i].first;
				int b=og[i].second;
				if (mastop[a]<lim[a])
				{
					startowy[i]=1;
				}
				else
				{
					startowy[i]=0;
					for (int j : graf[a])
						if (num[a][j]>=0)
							super[num[a][j]].push_back(i);
				}
				if (fin(a)!=fin(b))
				{
					koncowy[i]=1;
				}
				else
				{
					koncowy[i]=0;
					znajdz_sciezke(a, b);
					for (int j : glo)
						super[i].push_back(j);
				}
			}
		}
		queue<int> kol;
		for (int i=0; i<r; i++)
		{
			if (!startowy[i])
			{
				odl[i]=inf;
				aktu[i]=1;
			}
			else
			{
				aktu[i]=0;
				odl[i]=samo[i];
				kol.push(i);
			}
		}
		while(!kol.empty())
		{
			int v=kol.front();
			kol.pop();
			if (aktu[v])
				continue;
			aktu[v]=1;
			for (int i : super[v])
			{
				ll nowy=odl[v];
				if (wziete[i])
					nowy-=samo[i];
				else
					nowy+=samo[i];
				if (nowy<odl[i])
				{
					odl[i]=nowy;
					aktu[i]=0;
					kol.push(i);
					z[i]=v;
				}
			}
		}
		int g=-1;
		for (int i=0; i<r; i++)
		{
			if (!koncowy[i] || odl[i]>inf/2 || wziete[i])
				continue;
			if (g==-1 || odl[i]<odl[g])
				g=i;
		}
		if (g==-1)
			return;
		//~ if (!maska)
			//~ debug() << imie(g);
		while(1)
		{
			wziete[g]^=1;
			if (startowy[g] && odl[g]==samo[g])
				break;
			g=z[g];
		}
	}
	int s=0;
	for (int i=0; i<(int)spec.size(); i++)
	{
		if (maska&(1<<i))
		{
			int a=spec[i].first;
			int b=spec[i].second;
			s+=mac[a][b];
		}
	}
	for (int i=0; i<r; i++)
	{
		if (wziete[i])
		{
			int a=og[i].first;
			int b=og[i].second;
			s+=mac[a][b];
		}
	}
	//~ debug() << maska << " " << s;
	//~ if (s==3)
	//~ {
		//~ debug() << "kurwa " << maska;
		//~ for (int i=0; i<r; i++)
			//~ if (wziete[i])
				//~ debug() << og[i];
	//~ }
	wyn=min(wyn, s);
}

int main()
{
	scanf("%d%d", &n, &k);
	for (int i=1; i<=k; i++)
		scanf("%d", &lim[i]);
	for (int i=k+1; i<=n; i++)
		lim[i]=n+7;
	for (int i=1; i<=n; i++)
	{
		for (int j=i+1; j<=n; j++)
		{
			scanf("%d", &mac[i][j]);
			mac[j][i]=mac[i][j];
			if (j<=k)
			{
				spec.push_back({i, j});
				num[i][j]=num[j][i]=-1;
			}
			else
			{
				num[i][j]=num[j][i]=og.size();
				og.push_back({i, j});
				samo.push_back(mac[i][j]);
			}
		}
	}
	int r=spec.size();
	//~ wyn=0;
	for (int i=0; i<(1<<r); i++)
		solve(i);
	printf("%d\n", wyn);
	return 0;
}