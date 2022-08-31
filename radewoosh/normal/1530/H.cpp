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
const int nax=100*1007;
const int inf=1e9;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n;

int per[nax];

int wyn;

vi dpl[nax];
vi dpp[nax];

int fen[nax];

void pisz_mini(int v, int w)
{
	if (v<1 || w<1 || v>n || w>n)
		return;
	for (int i=v; i; i-=(i&(-i)))
		fen[i]=min(fen[i], w);
}

int czyt_mini(int v)
{
	int ret=inf;
	for (int i=v; i<=n; i+=(i&(-i)))
		ret=min(ret, fen[i]);
	return ret;
}

void pisz_maxi(int v, int w)
{
	if (v<1 || w<1 || v>n || w>n)
		return;
	for (int i=v; i<=n; i+=(i&(-i)))
		fen[i]=max(fen[i], w);
}

int czyt_maxi(int v)
{
	int ret=-inf;
	for (int i=v; i; i-=(i&(-i)))
		ret=max(ret, fen[i]);
	return ret;
}

void solve1()
{
	for (int i=1; i<=n; i++)
	{
		dpl[i].clear();
		dpp[i].clear();
		if (i==n)
		{
			dpl[i]=dpp[i]={per[i]};
		}
	}
	for (int j=0; 1; j++)
	{
		int cosmam=0;
		{//dpl
			for (int i=1; i<=n; i++)
				fen[i]=inf;
			for (int i=n; i; i--)
			{
				if (i+1<=n && j<(int)dpl[i+1].size())
					pisz_mini(per[i+1], dpl[i+1][j]);
				if (i+1+j<=n && j<(int)dpp[i+1+j].size())
					pisz_mini(dpp[i+1+j][j], per[i+1+j]);
					
				int x=czyt_mini(per[i]);
				if (x!=inf)
				{
					cosmam=1;
					if ((int)dpl[i].size()!=j+1)
						dpl[i].resize(j+1);
					dpl[i].push_back(x);
				}
			}
		}
		{//dpp
			for (int i=1; i<=n; i++)
				fen[i]=-inf;
			for (int i=n; i; i--)
			{
				if (i+1<=n && j<(int)dpp[i+1].size())
					pisz_maxi(per[i+1], dpp[i+1][j]);
				if (i+1+j<=n && j<(int)dpl[i+1+j].size())
					pisz_maxi(dpl[i+1+j][j], per[i+1+j]);
					
				int x=czyt_maxi(per[i]);
				if (x!=-inf)
				{
					cosmam=1;
					if ((int)dpp[i].size()!=j+1)
						dpp[i].resize(j+1);
					dpp[i].push_back(x);
				}
			}
		}
		
		
		if (!cosmam)
			break;
	}
	for (int i=1; i<=n; i++)
	{
		wyn=max(wyn, (int)max(dpl[i].size(), dpp[i].size()));
		//~ debug() << i << " " << dpl[i] << " " << dpp[i];
	}
}

void solve2()
{
	for (int i=1; i<=n; i++)
	{
		dpl[i].clear();
		dpp[i].clear();
		dpl[i]={per[i]};
		dpp[i]={per[i]};
	}
	for (int j=0; 1; j++)
	{
		int cosmam=0;
		{//dpl
			for (int i=1; i<=n; i++)
				fen[i]=inf;
			for (int i=n; i; i--)
			{
				if (i+1<=n && j<(int)dpl[i+1].size())
					pisz_mini(per[i+1], dpl[i+1][j]);
				if (i+2+j<=n && j<(int)dpp[i+2+j].size())
					pisz_mini(dpp[i+2+j][j], per[i+2+j]);
					
				int x=czyt_mini(per[i]);
				if (x!=inf)
				{
					cosmam=1;
					//~ if ((int)dpl[i].size()!=j+1)
						//~ dpl[i].resize(j+1);
					dpl[i].push_back(x);
				}
			}
		}
		{//dpp
			for (int i=1; i<=n; i++)
				fen[i]=-inf;
			for (int i=n; i; i--)
			{
				if (i+1<=n && j<(int)dpp[i+1].size())
					pisz_maxi(per[i+1], dpp[i+1][j]);
				if (i+2+j<=n && j<(int)dpl[i+2+j].size())
					pisz_maxi(dpl[i+2+j][j], per[i+2+j]);
					
				int x=czyt_maxi(per[i]);
				if (x!=-inf)
				{
					cosmam=1;
					//~ if ((int)dpp[i].size()!=j+1)
						//~ dpp[i].resize(j+1);
					dpp[i].push_back(x);
				}
			}
		}
		
		
		if (!cosmam)
			break;
	}
	for (int i=1; i<=n; i++)
	{
		wyn=max(wyn, (int)max(dpl[i].size(), dpp[i].size()));
		//~ debug() << i << " " << dpl[i] << " " << dpp[i];
	}
}

void test()
{
	scanf("%d", &n);
	wyn=0;
	for (int i=1; i<=n; i++)
		scanf("%d", &per[i]);
	solve1();
	solve2();
	//~ reverse(per+1, per+1+n);
	//~ solve();
	printf("%d\n", wyn);
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}