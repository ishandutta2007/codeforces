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
const int nax=507;
const int inf=1e9;

int n, m;

char wcz[nax];

int dlu[nax];
int kru[nax];

int spoko[nax];

int au[nax][2];

int kmp[nax];

int d;
int dpn[nax][nax];
int dps[nax][nax];

void mini(int &a, int b)
{
	a=min(a, b);
}

int main()
{
	scanf("%d%d", &n, &m);
	scanf("%s", wcz+1);
	for (int i=1; i<=n; i++)
		dlu[i]=wcz[i]-'0';
	scanf("%s", wcz+1);
	for (int i=1; i<=m; i++)
		kru[i]=wcz[i]-'0';
	//~ debug() << range(ktu+1, ktu+1+m);
	for (int i=2; i<=m; i++)
	{
		int it=kmp[i-1];
		while(it && kru[i]!=kru[it+1])
			it=kmp[it];
		if (kru[i]==kru[it+1])
			kmp[i]=it+1;
	}
	for (int i=0; i<=m; i++)
	{
		for (int p=0; p<2; p++)
		{
			int x=i;
			while(x && (x==m || kru[x+1]!=p))
				x=kmp[x];
			if (kru[x+1]==p)
				au[i][p]=x+1;
		}
		debug() << i << " " << au[i][0] << " " << au[i][1];
	}
	d=n-m+1;
	for (int i=0; i<=m; i++)
		for (int j=0; j<=d; j++)
			dpn[i][j]=inf;
	dpn[0][0]=0;
	for (int h=0; h<n; h++)
	{
		for (int i=0; i<=m; i++)
		{
			for (int j=0; j<=d; j++)
			{
				dps[i][j]=dpn[i][j];
				dpn[i][j]=inf;
			}
		}
		for (int i=0; i<=m; i++)
		{
			for (int j=0; j<=d; j++)
			{
				for (int w=0; w<2; w++)
				{
					mini(dpn[au[i][w]][j+(au[i][w]==m)], dps[i][j]+(dlu[h+1]!=w));
				}
			}
		}
	}
	for (int i=0; i<=d; i++)
	{
		int x=inf;
		for (int j=0; j<=m; j++)
			mini(x, dpn[j][i]);
		if (x==inf)
			x=-1;
		printf("%d ", x);
	}
	printf("\n");
	return 0;
}