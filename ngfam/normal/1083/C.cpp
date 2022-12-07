#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 200100;
 
int n; 
int a[N];
int inv[N];
int pos[N];
int height[N];
int lg[N << 1];
vector < int > g[N];
pair < int, int > it[N << 2];
pair < int, int > rmq[N << 1][20];
 
int szTour;
int tour[N << 1];
 
void dfs(int v, int p = 0){
  height[v] = height[p] + 1;
  
  tour[++szTour] = v;
  pos[v] = szTour;
  
  for(int u : g[v]) {
    dfs(u, v);
    tour[++szTour] = v;
  }
}
 
int lca(int x, int y){
  x = pos[x]; y = pos[y];
  if(x > y) swap(x, y);
  int lgr = lg[y - x + 1];
  return min(rmq[x][lgr], rmq[y - (1 << lgr) + 1][lgr]).second;
}
 
int dist(int x, int y) {
  return height[x] + height[y] - 2 * height[lca(x, y)];
}
 
pair < int, int > combine(pair < int, int > u, pair < int, int > v){
  if(min(u.first, v.first) == -2) return max(u, v);
  if(min(u.first, v.first) == -1) return make_pair(-1, -1);
  /// Inside
  
  if(dist(u.first, u.second) > dist(v.first, v.second)) swap(u, v);
  if(dist(v.first, u.first) + dist(u.first, u.second) + dist(u.second, v.second) == dist(v.first, v.second)) return v;
  swap(u.first, u.second);
  if(dist(v.first, u.first) + dist(u.first, u.second) + dist(u.second, v.second) == dist(v.first, v.second)) return v;
  
  /// Overlap
  
  if(dist(u.first, v.first) + dist(v.first, u.second) + dist(u.second, v.second) == dist(u.first, v.second)) return make_pair(u.first, v.second);
  swap(v.first, v.second);
  if(dist(u.first, v.first) + dist(v.first, u.second) + dist(u.second, v.second) == dist(u.first, v.second)) return make_pair(u.first, v.second);
  swap(u.first, u.second);
  if(dist(u.first, v.first) + dist(v.first, u.second) + dist(u.second, v.second) == dist(u.first, v.second)) return make_pair(u.first, v.second);
  swap(v.first, v.second);
  if(dist(u.first, v.first) + dist(v.first, u.second) + dist(u.second, v.second) == dist(u.first, v.second)) return make_pair(u.first, v.second);
  
  /// Non-overlap
  
 
  if(dist(u.first, u.second) + dist(u.second, v.first) + dist(v.first, v.second) == dist(u.first, v.second)) 
    return make_pair(u.first, v.second);
  swap(v.first, v.second);
  if(dist(u.first, u.second) + dist(u.second, v.first) + dist(v.first, v.second) == dist(u.first, v.second)) 
    return make_pair(u.first, v.second);
  swap(u.first, u.second);
  if(dist(u.first, u.second) + dist(u.second, v.first) + dist(v.first, v.second) == dist(u.first, v.second)) 
    return make_pair(u.first, v.second);
  swap(v.first, v.second);
  if(dist(u.first, u.second) + dist(u.second, v.first) + dist(v.first, v.second) == dist(u.first, v.second)) 
    return make_pair(u.first, v.second);
  return make_pair(-1, -1);
}
 
#define mid ((l + r) >> 1)
 
void build(int x, int l, int r){
  if(l == r) {
    it[x] = make_pair(inv[r], inv[r]);
    return;
  }
  build(x + x, l, mid);
  build(x + x + 1, mid + 1, r);
  it[x] = combine(it[x + x], it[x + x + 1]);
}
 
void modify(int x, int l, int r, int p, int v){
  if(l > p || r < p) return;
  if(l == r) it[x] = make_pair(v, v);
  else {
    modify(x + x, l, mid, p, v);
    modify(x + x + 1, mid + 1, r, p, v);
    it[x] = combine(it[x + x], it[x + x + 1]);
  }
}
 
int ans;
pair < int, int > cur;
 
void find(int x, int l, int r) {
  if(combine(cur, it[x]).first != -1) {
    ans = r + 1;
    cur = combine(cur, it[x]);
    return;
  }
  if(l == r) return;
  
  if(combine(cur, it[x + x]).first != -1) {
    cur = combine(cur, it[x + x]);
    ans = mid + 1;
    return find(x + x + 1, mid + 1, r);
  }
  return find(x + x, l, mid);
}
 
int main(){
  
  for(int i = 2; i < N + N; ++i) {
    lg[i] = lg[i / 2] + 1;
  }
  
  scanf("%d", &n);
  
  for(int i = 1; i <= n; ++i) scanf("%d", a + i), inv[a[i]] = i;
  for(int i = 2; i <= n; ++i) {
    int p;
    scanf("%d", &p);
    g[p].push_back(i);
  }
  
  dfs(1);
  
  for(int i = szTour; i >= 1; --i){
    rmq[i][0] = make_pair(height[tour[i]], tour[i]);
    for(int j = 1; j < 20; ++j) {
      if(i + (1 << j) - 1 <= szTour) rmq[i][j] = min(rmq[i][j - 1], rmq[i + (1 << (j - 1))][j - 1]);
    }
  }
  
  build(1, 0, n - 1);
  
  int q; scanf("%d", &q);
  
  
  while(q--){
    int t;
    scanf("%d", &t);
    
    if(t == 1) {
      int x, y;
      scanf("%d%d", &x, &y);
      modify(1, 0, n - 1, a[x], y);
      modify(1, 0, n - 1, a[y], x);
      swap(a[x], a[y]);
    }
    else{
      ans = 1;
      cur = make_pair(-2, -2);
      find(1, 0, n - 1);
      printf("%d\n", ans);
    }
  }
  
  return 0;
}