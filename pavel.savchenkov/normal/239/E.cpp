#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <math.h>
#include <cstdlib>
#include <memory.h>
#include <queue>
#include <assert.h>

#define pb push_back
#define LL long long
#define uLL unsigned long long
#define mp make_pair
#define pii pair <int,int>
#define vi vector <int>
#define vii vector <pii>
#define f first
#define s second
#define foran(i,a,b) for (int i=a;i<(int)b;i++)
#define forn(i,n) for (int i=0;i<(int)n;i++)
#define ford(i,n) for (int i=(int)n-1;i>=0;i--)
#define sqr(x) ((x) * (x))
#define y1 fucking_y1

const double EPS = 1e-9;
const int INT_INF = 2 * (int)1e9;
const LL LL_INF = 8 * (LL)1e18;
const double PI = acos(-1.0);

using namespace std;
 
vii g[3010];
int n;
int res = INT_INF;
int sz[3010];

int a[3010];
int sza;
int cnt0;

void dfs_sz(int v, int par = -1) {
 sz[v] = 0;
 forn(i, g[v].size()) {
    int to = g[v][i].f;
    if  (to == par) continue;
    dfs_sz(to, v);
    sz[v] += sz[to] + g[v][i].s;
 }
}

void dfs(int v, int par = -1, int add = 0, int cur_min = 0) {
  res = min(res, add + sz[v] + min(cur_min, cnt0));
//  printf("%d %d %d %d\n", v, par, add, cur_min);
  forn(i, g[v].size()) {
    int to = g[v][i].f;
    if  (to == par) continue;
    sza++;
    if  (g[v][i].s == 1) {
        if  (sza > 1) 
            a[sza - 1] = a[sza - 2] + 1;
        else
            a[sza - 1] = 1;
        dfs(to, v, add + sz[v] - sz[to] - 1, min(cur_min, a[sza - 1]));
        sza--;
    } else {
        if  (sza > 1) 
            a[sza - 1] = a[sza - 2];
        else
            a[sza - 1] = 0;
        cnt0++;
        dfs(to, v, add + sz[v] - sz[to], min(cur_min + 1, a[sza - 1]));
        cnt0--;
        sza--;
    }   
  } 
}

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  cin >> n;
  forn(i, n - 1) {
    int a, b;
    scanf("%d%d", &a, &b);
    a--; b--;
    g[a].pb(mp(b, 0));
    g[b].pb(mp(a, 1));
  }
    
  for (int root = 0; root < n; root++) {
    dfs_sz(root);
    sza = cnt0 = 0;
    res = min(res, sz[root]);
    dfs(root);
  }              
  printf("%d\n", res);
  return 0;
}