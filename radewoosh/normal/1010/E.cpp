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

void ff()
{
	fflush(stdout);
}

using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
const int nax=500*1007;
const int n1=(1<<17);

int lim[3];
int n, m, q;

int mini[3];
int maxi[3];

vi puny[nax];
vi zap[nax];

int wyn[nax];

vector <int> pyty[8];

int drz[nax];

void czys()
{
	for (int i=0; i<nax; i++)
		drz[i]=nax;
}

void pisz(int v, int a, int b, int graa, int grab, int w)
{
	if (a>=graa && b<=grab)
	{
		drz[v]=min(drz[v], w);
		return;
	}
	if (a>grab || b<graa)
	{
		return;
	}
	pisz((v<<1), a, (a+b)>>1, graa, grab, w);
	pisz((v<<1)^1, (a+b+2)>>1, b, graa, grab, w);
}

int czyt(int v)
{
	v+=n1-1;
	int ret=nax;
	while(v)
	{
		ret=min(ret, drz[v]);
		v>>=1;
	}
	return ret;
}

bool mniej(int a, int b)
{
	return zap[a]<zap[b];
}

void solve(int v)
{
	for (int i=0; i<3; i++)
		if (!(v&(1<<i)))
			for (int j=1; j<=m; j++)
				puny[j][i]*=-1;
	for (int i : pyty[v])
	{
		for (int j=0; j<3; j++)
			zap[i][j]=abs(zap[i][j]);
	}
	czys();
	sort(puny+1, puny+1+m);
	sort(pyty[v].begin(), pyty[v].end(), mniej);
	int w=1;
	for (int i : pyty[v])
	{
		while(w<=m && puny[w][0]<=zap[i][0])
		{
			if (puny[w][0]>=0 && puny[w][1]>=0 && puny[w][2]>=0)
				pisz(1, 1, n1, puny[w][1]+1, n1, puny[w][2]);
			w++;
		}
		wyn[i]=(czyt(zap[i][1]+1)>zap[i][2]);
	}
	
	
	for (int i=0; i<3; i++)
		if (!(v&(1<<i)))
			for (int j=1; j<=m; j++)
				puny[j][i]*=-1;
}


vi popr(vi v)
{
	for (int i=0; i<3; i++)
	{
		if (v[i]>=mini[i] && v[i]<=maxi[i])
		{
			v[i]=0;
			continue;
		}
		if (v[i]<mini[i])
			v[i]=v[i]-mini[i];
		else
			v[i]=v[i]-maxi[i];
	}
	return v;
}

vi czyt()
{
	vi ret(3);
	for (int i=0; i<3; i++)
		scanf("%d", &ret[i]);
	return ret;
}

int main()
{
	scanf("%d%d%d", &lim[0], &lim[1], &lim[2]);
	scanf("%d%d%d", &n, &m, &q);
	
	for (int i=0; i<3; i++)
		mini[i]=lim[i]+1;
	for (int i=1; i<=n; i++)
	{
		vi wez=czyt();
		for (int j=0; j<3; j++)
		{
			mini[j]=min(mini[j], wez[j]);
			maxi[j]=max(maxi[j], wez[j]);
		}
	}
	for (int i=1; i<=m; i++)
	{
		puny[i]=czyt();
		puny[i]=popr(puny[i]);
	}
	for (int i=1; i<=m; i++)
	{
		if (puny[i]==vi{0, 0, 0})
		{
			printf("INCORRECT\n");
			return 0;
		}
	}
	printf("CORRECT\n");
	for (int i=1; i<=q; i++)
	{
		zap[i]=czyt();
		zap[i]=popr(zap[i]);
		if (zap[i]==vi{0, 0, 0})
		{
			wyn[i]=-1;
			continue;
		}
		int a=(zap[i][0]>=0);
		int b=(zap[i][1]>=0);
		int c=(zap[i][2]>=0);
		pyty[a+b*2+c*4].push_back(i);
	}
	
	for (int h=0; h<8; h++)
		solve(h);
	
	
	for (int i=1; i<=q; i++)
	{
		if (wyn[i]==-1)
			printf("OPEN\n");
		if (wyn[i]==0)
			printf("CLOSED\n");
		if (wyn[i]==1)
			printf("UNKNOWN\n");
	}
	return 0;
}