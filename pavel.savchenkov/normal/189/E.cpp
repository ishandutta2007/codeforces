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
const int int_inf = 2147483640;
const i64 i64_inf = 9223372036854775800ll;
const double pi = acos(-1.0);

using namespace std;

bool mark[100500];
vi g[100500];
int n, m, k;
int s, t;
int d[100500];
bool was[100500];

void dfs(int v, int ma) {
    was[v] = 1;
    
    forn(i, g[v].size()) {
        int to = g[v][i];
        if  (was[to]) continue;
        if  (d[v] < (ma >> 1)) {
            if  (d[to] <= (ma >> 1)) dfs(to, ma);
        } 
        else if (d[v] == (ma >> 1))
                if ( d[to] < (ma >> 1) || (d[to] == (ma >> 1) && (ma & 1)) ) dfs(to, ma); 
    }
    
}

bool can(int ma) {
    memset(was, 0, sizeof was);
    dfs(s, ma);
    return was[t];
}

int solve() {
  
  int l = 0; int r = n + 1;
  while (l != r - 1) {
    int m = (l + r) >> 1;
    if  (can(m)) r = m; else l = m;
  }
  
  if  (!can(r)) return -1; else return r;
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  memset(mark, 0 ,sizeof mark);
  cin >> n >> m >> k;
  forn(i, k) { int u; scanf("%d",&u); --u; mark[u] = 1; }
  forn(i, m) {
    int u, v; scanf("%d%d",&u,&v); v--; u--;
    g[u].pb(v);
    g[v].pb(u);
  }
  
  cin >> s >> t; s--; t--; mark[t] = 1;
  queue <int> q;
  forn(i, n) if  (mark[i]) q.push(i), d[i] = 0; else d[i] = int_inf;
  
  while (!q.empty()) {
    int v = q.front(); q.pop();
    forn(i, g[v].size()) {
        int to = g[v][i];
        if  (d[to] > d[v] + 1) d[to] = d[v] + 1, q.push(to);
    }
  }
  
  cout << solve();
  return 0;
}