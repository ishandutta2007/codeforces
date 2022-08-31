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
const int nax=1507;
const ll mod=1000000000039LL;
ll mnoha;

int n, m;

int sta[nax][nax];
int kon[nax][nax];

ll hasta[nax];
ll hakon[nax];

void nope()
{
	printf("-1\n");
	exit(0);
}

map<ll,vi> mapa;
int per[nax];

void ans(vi wek)
{
	printf("%d\n", (int)wek.size());
	for (int i : wek)
		printf("%d ", i);
	printf("\n");
	exit(0);
}

int wolne[nax];
int blok[nax];
int wrzu[nax];

pii mam[nax];

bool mniej(pii a, pii b)
{
	return a.first<b.first;
}

int main()
{
	srand(time(0));
	mnoha=(1000*100+rand()%(10000));
	
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
			scanf("%d", &sta[i][j]);
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
			scanf("%d", &kon[i][j]);
	
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=m; j++)
			hasta[i]=(hasta[i]*mnoha+sta[i][j])%mod;
		for (int j=1; j<=m; j++)
			hakon[i]=(hakon[i]*mnoha+kon[i][j])%mod;
	}
	for (int i=n; i; i--)
		mapa[hasta[i]].push_back(i);
	for (int i=1; i<=n; i++)
	{
		if (mapa[hakon[i]].empty())
			nope();
		per[i]=mapa[hakon[i]].back();
		mapa[hakon[i]].pop_back();
	}
	//~ debug() << imie(range(per+1, per+1+n));
	for (int i=1; i<n; i++)
	{
		for (int j=1; j<=m; j++)
		{
			if (kon[i+1][j]<kon[i][j])
				blok[j]++;
		}
	}
	vi kol;
	for (int i=1; i<=m; i++)
	{
		if (!blok[i])
		{
			kol.push_back(i);
			wrzu[i]=1;
		}
	}
	vi wyn;
	while(!kol.empty())
	{
		int v=kol.back();
		kol.pop_back();
		wyn.push_back(v);
		for (int i=1; i<n; i++)
		{
			if (kon[i][v]<kon[i+1][v] && !wolne[i])
			{
				wolne[i]=1;
				for (int j=1; j<=m; j++)
				{
					if (kon[i+1][j]<kon[i][j])
					{
						blok[j]--;
						if (!blok[j] && !wrzu[j])
						{
							wrzu[j]=1;
							kol.push_back(j);
						}
					}
				}
			}
		}
	}
	reverse(wyn.begin(), wyn.end());
	//~ debug() << imie(wyn);
	for (int i=1; i<=n; i++)
	{
		mam[i].second=i;
	}
	for (int i : wyn)
	{
		//~ debug() << i << " " << range(mam+1, mam+1+n);
		for (int j=1; j<=n; j++)
			mam[j].first=sta[mam[j].second][i];
		stable_sort(mam+1, mam+1+n, mniej);
	}
	//~ debug() << range(mam+1, mam+1+n);
	for (int i=1; i<=n; i++)
		if (mam[i].second!=per[i])
			nope();
	ans(wyn);
	return 0;
}