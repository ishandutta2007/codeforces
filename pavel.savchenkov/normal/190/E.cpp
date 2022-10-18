//HACK ME, PLEASE! ^_^
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <utility>
#include <math.h>
#include <cstdlib>
#include <memory.h>
#include <queue>
 
#define pb push_back
#define i64 long long
#define mp make_pair
#define pii pair <int,int>
#define vi vector <int>
#define vii vector <pii>
#define f first
#define s second
#define foran(i,a,b) for (int i=a;i<(int)b;i++)
#define forn(i,n) for (int i=0;i<(int)n;i++)
#define ford(i,n) for (int i=(int)n-1;i>=0;i--)
 
const double eps = 1e-9;
const int int_inf = 1 << 31 - 1;
const i64 i64_inf = 1ll << 63 - 1;
const double pi = acos(-1.0);
 
using namespace std;
int n, m;
vi g[500500];
int par[500500];
int sz[500500];
vi gt[500500];
bool was[500500];
vi ans[500500];

int get_set(int v)
{
	if  (par[v] == v) return v;
	return par[v] = get_set(par[v]);
}

void union_set(int x, int y)
{
	x = get_set(x);
	y = get_set(y);
	if  (x == y) return;
	if  (sz[x] < sz[y]) swap(x, y);
	par[y] = x; sz[y] += sz[x];
}

void dfs(int v)
{
	was[v] = 1;
	forn(i, gt[v].size())
		if  (!was[gt[v][i]]) union_set(v, gt[v][i]), dfs(gt[v][i]);
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  cin >> n >> m;
  forn(i, m)
  {
	int u, v; scanf("%d%d",&u,&v); --v; --u;
	g[u].pb(v); g[v].pb(u);
  }
  forn(i, n) par[i] = i, sz[i] = 1;
  
  int V = 0;
  forn(i, n) {
	sort(g[i].begin(), g[i].end());
	if  ((int)g[i].size() < (int)g[V].size()) V = i;
  }
  
  g[V].insert(g[V].begin(), -1);
  g[V].pb(n);
  forn(i, g[V].size() - 1) {
	foran(j, g[V][i] + 1, g[V][i + 1])
		union_set(V, j);
  }
  
  forn(i, n) {
	if  (get_set(i) == V && i != V) continue;
	g[i].insert(g[i].begin(), -1);
	g[i].pb(n);
	forn(j, g[i].size() - 1)
		foran(z, g[i][j] + 1, g[i][j + 1])
			gt[i].pb(z), gt[z].pb(i);
  }
	
  memset(was, 0, sizeof was);
  forn(i, n)
   if  (!was[i] && (get_set(i) != V || i == V)) dfs(i);
   
  forn(i, n)
	ans[get_set(i)].pb(i);
  int sz = 0;
  forn(i, n)
	if  (!ans[i].empty()) sz++;
	
  cout << sz << endl;
  forn(i, n)
	if (!ans[i].empty())
	{
		printf("%d ", ans[i].size());
		forn(j, (int)ans[i].size())
			printf("%d ", ans[i][j] + 1);
		puts("");
	}
  
  return 0;
}