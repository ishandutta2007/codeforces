//PRZEMYSL ASSERTY

//SPRAWDZ CORNER CASE'Y, MINIMALNE I MAKSYMALNE WEJCIE I WYJCIE

//MODULO = 1

//while (clock()<=69*CLOCKS_PER_SEC)

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

const int nax=1007;

int n, m;

char wcz[nax][nax];

pair <int,int> s, k;

int dp_ver[nax][nax];
int dp_hor[nax][nax];

void tak()
{
	printf("YES\n");
	exit(0);
}

void nie()
{
	printf("NO\n");
	exit(0);
}

void consider(int v, int u)
{
	if (wcz[v][u]=='*')
		return;
	dp_hor[v][u]=min(dp_hor[v][u], dp_ver[v][u]+1);
	dp_ver[v][u]=min(dp_ver[v][u], dp_hor[v][u]+1);
	dp_hor[v-1][u]=min(dp_hor[v-1][u], dp_hor[v][u]);
	dp_hor[v+1][u]=min(dp_hor[v+1][u], dp_hor[v][u]);
	dp_ver[v][u-1]=min(dp_ver[v][u-1], dp_ver[v][u]);
	dp_ver[v][u+1]=min(dp_ver[v][u+1], dp_ver[v][u]);
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; i++)
		scanf("%s", wcz[i]+1);
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=m; j++)
		{
			if (wcz[i][j]=='S')
				s={i, j};
			if (wcz[i][j]=='T')
				k={i, j};
			dp_ver[i][j]=6;
			dp_hor[i][j]=6;
		}
	}
	dp_ver[s.first][s.second]=0;
	dp_hor[s.first][s.second]=0;
	for (int h=0; h<=4; h++)
	{
		for (int i=1; i<=n; i++)
			for (int j=1; j<=m; j++)
				consider(i, j);
				
		for (int i=n; i; i--)
			for (int j=m; j; j--)
				consider(i, j);
	}
	if (min(dp_hor[k.first][k.second], dp_ver[k.first][k.second])<=2)
		tak();
	nie();
	return 0;
}