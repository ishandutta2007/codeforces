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

typedef long long LL;
typedef pair<int,int> PII;
using VI=vector<int>;
#define MP make_pair
#define FOR(v,p,k) for(int v=p;v<=k;++v)
#define FORD(v,p,k) for(int v=p;v>=k;--v)
#define REP(i,n) for(int i=0;i<(n);++i)
#define VAR(v,i) __typeof(i) v=(i)
#define FOREACH(i,c) for(VAR(i,(c).begin());i!=(c).end();++i)
#define PB push_back
#define ST first
#define ND second
#define SIZE(x) (int)x.size()
#define ALL(c) c.begin(),c.end()

#define shandom_ruffle random_shuffle

const int N=1000*1000;
VI implies[2*N]; //wymuszenia, 2*x to zmienna 2*x+1 to jej zaprzeczenie
int sat_val[2*N],sat_vis[2*N],sat_sort[2*N],sat_ile;

inline void sat_or(int a,int b){
  implies[a^1].PB(b);
  implies[b^1].PB(a);
}

void sat_dfs_mark(int x){
  sat_vis[x]=1; sat_val[x]=sat_val[x^1]==-1;
  FOREACH(it,implies[x]) if (!sat_vis[*it]) sat_dfs_mark(*it);
}

void sat_dfs(int x){
  sat_vis[x]=1;
  FOREACH(it,implies[x^1]) if (!sat_vis[*it^1]) sat_dfs(*it^1);
  sat_sort[sat_ile++]=x;
}

/*przekazujemy liczbe zmiennych*/
int sat2(int n){
  sat_ile=0;
  REP(i,2*n) sat_vis[i]=0,sat_val[i]=-1;
  REP(i,2*n) if (!sat_vis[i]) sat_dfs(i);
  REP(i,2*n) sat_vis[i]=0;
  FORD(i,2*n-1,0) if (!sat_vis[sat_sort[i]]) sat_dfs_mark(sat_sort[i]);
  REP(i,2*n) if (sat_val[i]) FOREACH(it,implies[i]) if (!sat_val[*it]) return 0;
  return 1;
}


const int nax=1000*1007;

int n, m;

vector <int> wek[nax];

void nope()
{
	printf("No\n");
	exit(0);
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; i++)
	{
		int il;
		scanf("%d", &il);
		while(il--)
		{
			int x;
			scanf("%d", &x);
			wek[i].push_back(x-1);
		}
	}
	for (int i=1; i<n; i++)
	{
		int mini=min(wek[i].size(), wek[i+1].size());
		int gdz=-1;
		for (int j=0; j<mini; j++)
		{
			if (wek[i][j]!=wek[i+1][j])
			{
				gdz=j;
				break;
			}
		}
		if (gdz==-1)
		{
			if ((int)wek[i].size()>(int)wek[i+1].size())
				nope();
			continue;
		}
		if (wek[i][gdz]>wek[i+1][gdz])
		{
			sat_or(2*wek[i][gdz], 2*wek[i][gdz]);
			sat_or(2*wek[i+1][gdz]+1, 2*wek[i+1][gdz]+1);
		}
		else
		{
			sat_or(2*wek[i][gdz], 2*wek[i+1][gdz]+1);
		}
	}
	if (!sat2(m))
		nope();
	printf("Yes\n");
	vector <int> wek;
	for (int i=0; i<m; i++)
		if (sat_val[2*i])
			wek.push_back(i+1);
	printf("%d\n", (int)wek.size());
	for (int i : wek)
		printf("%d ", i);
	printf("\n");
	return 0;
}