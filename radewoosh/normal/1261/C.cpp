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

int n, m;

char wcz[nax];
vector <vi> tab;

vector <vi> odl;

int rx[]={-1, 0, 1, 1, 1, 0, -1, -1};
int ry[]={1, 1, 1, 0, -1, -1, -1, 0};

vector <vi> sum;

void mini(int &a, int b)
{
	a=min(a, b);
}

int wyn=nax;

int check(int v)
{
	//~ debug() << "jade " << v;
	for (int i=0; i<=n; i++)
		for (int j=0; j<=m; j++)
			sum[i][j]=0;
	//~ debug() << "no";
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=m; j++)
		{
			if (odl[i][j]>v)
			{
				//~ debug() << i << " " << j << "   " << odl[i][j] << " " << odl[i][j-1];
				sum[i-v][j-v]++;
				sum[i+v+1][j-v]--;
				sum[i-v][j+v+1]--;
				sum[i+v+1][j+v+1]++;
			}
		}
	}
	//~ debug() << "no";
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=m; j++)
		{
			sum[i][j]+=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
			if ((sum[i][j]>0)!=tab[i][j])
				return 0;
		}
	}
	return 1;
}

int main()
{
	scanf("%d%d", &n, &m);
	tab.resize(n+3);
	for (int i=0; i<n+3; i++)
		tab[i].resize(m+3);
	for (int i=1; i<=n; i++)
	{
		scanf("%s", wcz+1);
		for (int j=1; j<=m; j++)
			tab[i][j]=(wcz[j]=='X');
	}
	odl.resize(n+3);
	for (int i=0; i<n+3; i++)
		odl[i].resize(m+3);
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=m; j++)
		{
			if (tab[i][j])
				odl[i][j]=nax;
		}
	}
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=m; j++)
		{
			mini(odl[i][j], odl[i-1][j]+1);
			mini(odl[i][j], odl[i][j-1]+1);
			mini(odl[i][j], odl[i-1][j-1]+1);
		}
	}
	for (int i=1; i<=n; i++)
	{
		for (int j=m; j; j--)
		{
			mini(odl[i][j], odl[i-1][j]+1);
			mini(odl[i][j], odl[i][j+1]+1);
			mini(odl[i][j], odl[i-1][j+1]+1);
		}
	}
	for (int i=n; i; i--)
	{
		for (int j=1; j<=m; j++)
		{
			mini(odl[i][j], odl[i+1][j]+1);
			mini(odl[i][j], odl[i][j-1]+1);
			mini(odl[i][j], odl[i+1][j-1]+1);
		}
	}
	for (int i=n; i; i--)
	{
		for (int j=m; j; j--)
		{
			mini(odl[i][j], odl[i+1][j]+1);
			mini(odl[i][j], odl[i][j+1]+1);
			mini(odl[i][j], odl[i+1][j+1]+1);
		}
	}
	sum.resize(n+3);
	for (int i=0; i<n+3; i++)
		sum[i].resize(m+3);
	int bsa=0;
	int bsb=max(n, m);
	while(bsa<bsb)
	{
		int bss=(bsa+bsb+2)>>1;
		if (check(bss))
			bsa=bss;
		else
			bsb=bss-1;
	}
	//~ for (int i=1; i<=n; i++)
	//~ {
		//~ for (int j=1; j<=m; j++)
		//~ {
			//~ if (!tab[i][j])
				//~ continue;
			//~ int czy=0;
			//~ for (int l=0; l<8; l++)
				//~ if (odl[i+rx[l]][j+ry[l]]>odl[i][j])
					//~ czy=1;
			//~ if (!czy)
				//~ debug() << i << " " << j << "  " << odl[i][j];
			//~ if (!czy)
				//~ wyn=min(wyn, odl[i][j]-1);
		//~ }
	//~ }
	printf("%d\n", bsa);
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=m; j++)
		{
			printf("%c", ".X"[odl[i][j]>bsa]);
		}
		printf("\n");
	}
	//~ printf("%d\n", wyn);
	return 0;
}