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
const int nax=300*1007;
const ll inf=1007LL*1007LL*1007LL*1007LL*1007LL*1007LL;
const int n1=(1<<17);

int n, c, q;

int tab[nax];
int tabkop[nax];

ll dp[nax][9];
ll sumdp[nax][5];

int zapa[nax];
ll zapb[nax];

int wyn[nax];

ll dod(ll a, ll b)
{
	return min(a+b, inf);
}

vi wek[nax][5];

struct prze
{
	int a, b;
	prze()
	{
	}
	prze(int aa, int bb)
	{
		a=aa;
		b=bb;
	}
	prze(pii v)
	{
		a=v.first;
		b=v.second;
	}
	void zrob()
	{
		reverse(tab+a, tab+b+1);
	}
	void zrobkop()
	{
		reverse(tabkop+a, tabkop+b+1);
	}
};

bool operator <(prze a, prze b)
{
	if (a.a==b.a && a.b==b.b)
		return 0;
	a.zrob();
	b.zrobkop();
	int res=0;
	for (int i=min(a.a, b.a); 1; i++)
	{
		assert(i<=n);
		if (tab[i]!=tabkop[i])
		{
			if (tab[i]<tabkop[i])
				res=1;
			break;
		}
	}
	a.zrob();
	b.zrobkop();
	return res;
}

int k;
prze wsz[nax];
pii wszpar[nax];

ll drz[nax];

int gdz[nax][5];

void czysc()
{
	memset(drz, 0, sizeof(drz));
}

void pisz(int v, ll w)
{
	v+=n1-1;
	while(v)
	{
		drz[v]=dod(drz[v], w);
		v>>=1;
	}
}

ll skip;

int szuk(int v, int a, int b, ll chce)
{
	if (a==b)
		return a;
	if (drz[v*2]>=chce)
		return szuk((v<<1), a, (a+b)>>1, chce);
	skip+=drz[v*2];
	return szuk((v<<1)^1, (a+b+2)>>1, b, chce-drz[v*2]);
}

void test()
{
	scanf("%d%d%d", &n, &c, &q);
	//~ debug() << imie(n) << imie(c) << imie(q);
	for (int i=1; i<=n; i++)
	{
		scanf("%d", &tab[i]);
		tabkop[i]=tab[i];
	}
	memset(dp, 0, sizeof(dp));
	for (int i=0; i<=n+1; i++)
		for (int j=0; j<=c; j++)
			wek[i][j].clear();
	dp[n+1][0]=1;
	for (int i=n; i; i--)
	{
		for (int j=0; j<=c; j++)
		{
			for (int l=0; i+l<=n && l<=j; l++)
				dp[i][j]=dod(dp[i][j], dp[i+l+1][j-l]);
		}
		//~ debug() << i << " " << range(dp[i], dp[i]+1+c);
	}
	ll sum=0;
	for (int i=0; i<=c; i++)
		sum=dod(sum, dp[1][i]);
	for (int i=1; i<=n+1; i++)
	{
		sumdp[i][0]=dp[i][0];
		for (int j=1; j<=c; j++)
			sumdp[i][j]=dod(dp[i][j], sumdp[i][j-1]);
	}
	for (int i=1; i<=q; i++)
	{
		scanf("%d%lld", &zapa[i], &zapb[i]);
		if (zapb[i]>sum)
		{
			wyn[i]=-1;
			continue;
		}
		wyn[i]=0;
		wek[1][c].push_back(i);
	}
	k=0;
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=c && i+j<=n; j++)
		{
			k++;
			wsz[k]=prze(i, i+j);
		}
	}
	k++;
	wsz[k]=prze(n+1, n+1);
	sort(wsz+1, wsz+1+k);
	for (int i=1; i<=k; i++)
		wszpar[i]={wsz[i].a, wsz[i].b};
	for (int i=1; i<=k; i++)
	{
		if (wszpar[i].first==n+1)
			gdz[n+1][0]=i;
		else
			gdz[wszpar[i].first][wszpar[i].second-wszpar[i].first]=i;
	}
	//~ debug() << imie(k);
	//~ for (int i=1; i<=k; i++)
		//~ debug() << wszpar[i];
	for (int h=c; h>=0; h--)
	{
		czysc();
		for (int i=n+1; i; i--)
		{
			if (i==n+1)
			{
				int kt=gdz[n+1][0];
				ll potem=1;
				pisz(kt, potem);
			}
			else
			{
				for (int j=1; j<=h && i+j<=n; j++)
				{
					int kt=gdz[i][j];
					ll potem=sumdp[i+j+1][h-j];
					pisz(kt, potem);
				}
			}
			for (int j : wek[i][h])
			{
				skip=0;
				int wez=szuk(1, 1, n1, zapb[j]);
				pii par=wszpar[wez];
				if (zapa[j]<=par.second)
				{
					wsz[wez].zrob();
					wyn[j]=tab[zapa[j]];
					wsz[wez].zrob();
					continue;
				}
				zapb[j]-=skip;
				wek[par.second+1][h-(par.second-par.first)].push_back(j);
			}
		}
	}
	
	
	for (int i=1; i<=q; i++)
		printf("%d\n", wyn[i]);
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}