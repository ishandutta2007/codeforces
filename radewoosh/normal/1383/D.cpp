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

int n, m;

int tab[nax][nax];
int wyn[nax][nax];

int maxrow[nax];
int maxkol[nax];

int zaczrow[nax];
int zaczkol[nax];

void nope()
{
	printf("-1\n");
	exit(0);
}

int rx[]={-1, 1, 0, 0};
int ry[]={0, 0, 1, -1};

vector<pii> bier;

void check2(int x, int y)
{
	if (x<1 || x>n || y<1 || y>m)
		return;
	int ma=0;
	for (int i=0; i<4; i++)
		ma+=(wyn[x+rx[i]][y+ry[i]]>0);
	if (ma>=2)
		bier.push_back({x, y});
}

void check1(int x, int y)
{
	for (int i=0; i<4; i++)
		check2(x+rx[i], y+ry[i]);
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=m; j++)
		{
			scanf("%d", &tab[i][j]);
			maxrow[i]=max(maxrow[i], tab[i][j]);
			maxkol[j]=max(maxkol[j], tab[i][j]);
		}
	}
	pii ost={0, 0};
	for (int v=n*m; v; v--)
	{
		int r=0;
		int k=0;
		for (int i=1; i<=n; i++)
			if (maxrow[i]==v)
				r=i;
		for (int i=1; i<=m; i++)
			if (maxkol[i]==v)
				k=i;
		//~ debug() << imie(v) << imie(r) << imie(k) << imie(bier);
		//~ for (int i=1; i<=n; i++)
			//~ debug() << range(wyn[i]+1, wyn[i]+1+m);
		if (r || k)
		{
			if (r && k)
			{
				ost.first+=1;
				ost.second+=1;
			}
			if (r && !k)
			{
				ost.first+=1;
			}
			if (k && !r)
			{
				ost.second+=1;
			}
			wyn[ost.first][ost.second]=v;
			check1(ost.first, ost.second);
			continue;
		}
		while(1)
		{
			if (bier.empty())
				nope();
			pii wez=bier.back();
			bier.pop_back();
			if (wyn[wez.first][wez.second])
				continue;
			wyn[wez.first][wez.second]=v;
			check1(wez.first, wez.second);
			break;
		}
	}
	
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=m; j++)
			printf("%d ", wyn[i][j]);
		printf("\n");
	}
	return 0;
}