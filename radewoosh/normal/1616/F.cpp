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
const int nax=267;

int n, m;

int som[nax][nax];
int mac[nax][nax];

int wek[nax];

int zle;

void zam(int a, int b)
{
	for (int i=0; i<=m; i++)
		swap(mac[a][i], mac[b][i]);
}

void dod(int a, int b, int x)
{
	for (int i=0; i<=m; i++)
		mac[a][i]=(mac[a][i]+mac[b][i]*x)%3;
}

void mno(int a, int x)
{
	for (int i=0; i<=m; i++)
		mac[a][i]=(mac[a][i]*x)%3;
}

void pusznij()
{
	for (int i=0; i<=m; i++)
		mac[0][i]=wek[i];
	for (int i=1; i<=m; i++)
	{
		if (!mac[i][i] || !mac[0][i])
			continue;
		int x=mac[0][i];
		dod(0, i, 3-x);
	}
	int g=1;
	while(g<=m && !mac[0][g])
		g++;
	if (g==m+1)
	{
		if (mac[0][0])
			zle=1;
		return;
	}
	zam(0, g);
	if (mac[g][g]==2)
		mno(g, 2);
	for (int i=1; i<=m; i++)
	{
		if (i==g)
			continue;
		if (mac[i][g])
			dod(i, g, 3-mac[i][g]);
	}
}

void test()
{
	scanf("%d%d", &n, &m);
	for (int i=0; i<=max(n, m); i++)
		for (int j=0; j<=max(n, m); j++)
			mac[i][j]=som[i][j]=0;
	zle=0;
	for (int i=1; i<=m; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		som[a][b]=som[b][a]=i;
		if (c!=-1)
		{
			for (int j=0; j<=m; j++)
				wek[j]=0;
			wek[i]=1;
			wek[0]=c%3;
			pusznij();
		}
		//~ debug() << "po " << i;
		//~ for (int i=1; i<=m; i++)
		//~ {
			//~ debug() << range(mac[i]+1, mac[i]+1+m) << " " << mac[i][0];
		//~ }
		//~ debug();
	}
	for (int i=1; i<=n; i++)
	{
		for (int j=i+1; j<=n; j++)
		{
			for (int l=j+1; l<=n; l++)
			{
				if (som[i][j] && som[j][l] && som[i][l])
				{
					for (int p=0; p<=m; p++)
						wek[p]=0;
					//~ debug() << "jade";
					wek[som[i][j]]=wek[som[i][l]]=wek[som[j][l]]=1;
					pusznij();
				}
			}
		}
	}
	if (zle)
	{
		printf("-1\n");
		return;
	}
	for (int i=1; i<=m; i++)
	{
		if (mac[i][i])
			continue;
		for (int p=0; p<=m; p++)
			wek[p]=0;
		wek[i]=0;
		pusznij();
	}
	for (int i=1; i<=m; i++)
	{
		int x=mac[i][0];
		if (!x)
			x=3;
		printf("%d ", x);
	}
	printf("\n");
	//~ debug();
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}