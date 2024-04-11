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

const int nax=5007;
const long long inf=1000*1000*1000+7;

int n;
long long b;

long long c[nax];
long long d[nax];
int oj[nax];
vector <int> graf[nax];

int roz[nax];
long long dpkup[nax][nax];
long long dpbez[nax][nax];

void dfs(int v)
{
	for (int i=0; i<=n; i++)
		dpkup[v][i]=dpbez[v][i]=inf;
	
	roz[v]=0;
	
	dpkup[v][0]=0;
	dpbez[v][0]=0;
	
	for (int i : graf[v])
	{
		dfs(i);
		
		for (int j=roz[v]; j>=0; j--)
		{
			for (int l=roz[i]; l>=0; l--)
			{
				dpkup[v][j+l]=min(dpkup[v][j+l], dpkup[v][j]+min(dpkup[i][l], dpbez[i][l]));
				dpbez[v][j+l]=min(dpbez[v][j+l], dpbez[v][j]+dpbez[i][l]);
			}
		}
		roz[v]+=roz[i];
	}
	for (int i=roz[v]; i>=0; i--)
		dpkup[v][i+1]=dpkup[v][i]+c[v]-d[v];
	for (int i=roz[v]; i>=0; i--)
		dpbez[v][i+1]=min(dpbez[v][i+1], dpbez[v][i]+c[v]);
	roz[v]++;
}

int main()
{
	scanf("%d%lld", &n, &b);
	
	for (int i=1; i<=n; i++)
	{
		scanf("%lld%lld", &c[i], &d[i]);
		if (i>1)
		{
			scanf("%d", &oj[i]);
			graf[oj[i]].push_back(i);
		}
	}
	
	dfs(1);
	
	for (int i=1; 1; i++)
	{
		if (i>n || ( dpbez[1][i]>b && dpkup[1][i]>b ))
		{
			printf("%d\n", i-1);
			return 0;
		}
	}
	
	return 0;
}