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
const int int_inf = 2000000000;
const i64 i64_inf = 1000000000000000000LL;
const double pi = acos(-1.0);
 
using namespace std;
bool was[100500];
vector < pair <int, bool> > g[100500];
vector <int> gt[100500]; 
int up[100500];
int tin[100500];
int tout[100500];
int color[100500];
int pr[100500][100];
int d[100500];
int de[100500];
int timer = 0;
int col = 0;
int L = 0;
int k;
int n, m;

void dfs(int v, int p = -1)
{
    was[v] = 1;
    tin[v] = up[v] = timer++;
    
    forn(i, g[v].size())
    {
        int to = g[v][i].f;
        if (to == p || to == v) continue;
        if (was[to]) { up[v] = min(up[v], tin[to]); continue; }
        dfs(to, v);
        up[v] = min(up[to], up[v]);
        if (up[to] > tin[v]) 
        {
            g[v][i].s = 1;
            int l = 0; int r = (int)g[to].size();
            while (l != r - 1)
            {
                int m = (l + r) >> 1;
                if (g[to][m].f <= v) l = m; else r = m; 
            }
            g[to][l].s = 1;
        }
    }
}

void dfs2(int v)
{
    color[v] = col;
    forn(i, g[v].size())
      if (color[g[v][i].f] == -1 && !g[v][i].s) dfs2(g[v][i].f);
}

void dfs3(int v,int p = 0)
{
    tin[v] = ++timer;
    pr[v][0] = p;
    de[v] = de[p] + 1;
    for (int i=1; i<=L; i++)
        pr[v][i] = pr[pr[v][i-1]][i-1];

    forn(i, gt[v].size())
        if (gt[v][i] != p) dfs3(gt[v][i], v);
    
    tout[v] = ++timer;
}

bool ispr(int a, int b) {
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca (int a, int b) {
    if (ispr (a, b))  return a;
    if (ispr (b, a))  return b;
    for (int i=L; i>=0; i--)
        if ( !ispr(pr[a][i], b) )
            a = pr[a][i];
    return pr[a][0];
}

void build_lca()
{
    timer = 0;
    L = 1;
    while ( ( 1 << L ) <= col)  L++;
    de[0] = 0;
    dfs3(0);
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  cin >> n >> m;
  forn(i, m)
  {
    int u, v; scanf("%d%d",&u,&v);
    --u; -- v; g[u].pb(mp(v,0)); g[v].pb(mp(u,0));
  }
  memset(was,0,sizeof(was));
  forn(i,n) sort(g[i].begin(),g[i].end());
  dfs(0);
  memset(color,-1,sizeof(color));
  forn(i, n)
    if (color[i] == -1) dfs2(i), col++; 

  forn(i, n)
    forn(j, g[i].size())
        if (g[i][j].s) { gt[color[i]].pb(color[g[i][j].f]); gt[color[g[i][j].f]].pb(color[i]); }
        
  forn(i, col)
    { sort(gt[i].begin(), gt[i].end()); gt[i].resize( unique(gt[i].begin(), gt[i].end()) - gt[i].begin()); }
  /*
  forn(i, col)
  {
    cout << i << "->" << endl;
    forn(j, gt[i].size())
        cout << gt[i][j] << " ";
    cout << endl;
  }
  */
  cin >> k;
  build_lca();
//  queue <int> q;
  
  
  forn(i, k)
  {
      int a, b; scanf("%d%d",&a,&b);
      a = color[a - 1]; b = color[b - 1];
      int lc = lca(a, b);
      int res;
//    cout << a + 1 << " " << b + 1<< " " << lc + 1 << endl;
      if (lc == a)
        res = de[b] - de[a];
      else
        if (lc == b)
            res = de[a] - de[b];
        else res = de[a] - de[lc] - de[lc] + de[b];
      printf("%d\n",res);
      continue;
     /* 
      forn(j, col)
        d[j] = int_inf;
      d[a] = 0;
      
      q.push(a);
      while (!q.empty())
      {
        int v = q.front();
        q.pop();
        forn(j, gt[v].size())
            if (d[gt[v][j]] > d[v] + 1) { d[gt[v][j]] = d[v] + 1; q.push(gt[v][j]); }
      }
      printf("%d\n\n",d[b]);
      */
  }
  
  return 0;
}