#include<bits/stdc++.h>

/***
  basically gcd of all cycles
***/

using namespace std;

int gcd(int x, int y) {
  if(x == 0) return y;
  if(y == 0) return x;
  return __gcd(x, y);
}

const int MAXN = 100010;

int n, m, cycle_length;
vector<int> g[MAXN], rg[MAXN];

int cur;
int height[MAXN], choosen[MAXN];

int color[MAXN];

void dfs_color(int v, int c) {
  choosen[v] = cur;
  for(int s : g[v]) if(!choosen[s]) {
    color[s] = (color[v] + 1) % c;
    dfs_color(s, c);
  }
  for(int s : rg[v]) if(!choosen[s]) {
    color[s] = (color[v] - 1 + c) % c;
    dfs_color(s, c);
  }
}

int check(int c) {
  fill(color, color + MAXN, 0);
  fill(choosen, choosen + MAXN, 0);
  ++cur;
  for(int i = 0; i < n; ++i) {
    if(!choosen[i]) dfs_color(i, c);
  }
  for(int u = 0; u < n; ++u) {
    for(int v : g[u]) {
      if(color[v] != (color[u] + 1) % c){
        if(c == n + 1) return abs((color[v] - (color[u] + 1)));
        return (color[v] - (color[u] + 1) + c) % c;
      }
    }
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  cin >> n >> m;
  for(int i = 0; i < m; ++i) {
    int u, v; cin >> u >> v;
    g[--u].push_back(--v);
    rg[v].push_back(u);
  }

  int ans = 0;
  while(true) {
    int x = check((ans == 0 ? n + 1 : ans));
    x = gcd(ans, x);
    if(x == ans) break;
    ans = x;
  }

  cout << (ans ? ans : n);

  return 0;
}