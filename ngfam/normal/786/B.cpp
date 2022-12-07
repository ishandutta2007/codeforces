#include <bits/stdc++.h>
#define mid ((l + r) >> 1)
#define ii pair < long long, int >

using namespace std;

const int N = 800040;
vector < pair < int, int > > adj[N];

int n, q, st, sz;
int in, out;
int pos[N][3];
int done[N];
long long path[N];
pair < int, int > a[N];

bool minimize(long long &u, long long v){
  if(u > v){
    u = v;
    return true;
  }
  return false;
}

void build(int i, int l, int r, int p, int dir){
  if(p != 0){
    if(dir == 1){
      adj[p].push_back(make_pair(i, 0));
    }
    else{
      adj[i].push_back(make_pair(p, 0));
    }
  }
  if(l == r){
    pos[l][dir] = i;
    return;
  }
  a[i].first = ++sz;
  a[i].second = ++sz;
  build(a[i].first, l, mid, i, dir);
  build(a[i].second, mid + 1, r, i, dir);
}

void add(int u, int l, int r, int d, int c, int x, int w){
  if(l >= d && r <= c){
    adj[x].push_back(make_pair(u, w));
    return;
  }
  if(l > c || d > r){
    return;
  }
  add(a[u].first, l, mid, d, c, x, w);
  add(a[u].second, mid + 1, r, d, c, x, w);
}

void ins(int u, int l, int r, int d, int c, int x, int w){
  if(l >= d && r <= c){
    adj[u].push_back(make_pair(x, w));
    return;
  }
  if(l > c || d > r){
    return;
  }
  ins(a[u].first, l, mid, d, c, x, w);
  ins(a[u].second, mid + 1, r, d, c, x, w);
}

int main(){
  #ifndef ONLINE_JUDGE
    freopen("1.inp", "r", stdin);
    //freopen(".out", "w", stdout);
  #endif // ONLINE_JUDGE
  scanf("%d%d%d", &n, &q, &st);
  in = ++sz;
  build(in, 1, n, 0, 1);
  out = ++sz;
  build(out, 1, n, 0, 2);
  for(int i = 1; i <= n; ++i){
    adj[pos[i][1]].push_back(make_pair(pos[i][2], 0));
    adj[pos[i][2]].push_back(make_pair(pos[i][1], 0));
  }
  while(q--){
    int type;
    scanf("%d", &type);
    if(type == 1){
      int u, v, w;
      scanf("%d%d%d", &u, &v, &w);
      adj[pos[u][1]].push_back(make_pair(pos[v][1], w));
    }
    else{
      int u, l, r, w;
      scanf("%d%d%d%d", &u, &l, &r, &w);
      if(type == 2){
        add(in, 1, n, l, r, pos[u][1], w);
      }
      else{
        ins(out, 1, n, l, r, pos[u][1], w);
      }
    }
  }
  fill(path, path + N, 1e18);
  path[pos[st][1]] = 0;
  priority_queue < ii, vector < ii >, greater < ii > > heap;
  heap.push(make_pair(0, pos[st][1]));
  while(!heap.empty()){
    int u = heap.top().second;
    heap.pop();
    if(done[u] == 1){
      continue;
    }
    done[u] = 1;
    for(auto p : adj[u]){
      int v = p.first, w = p.second;
      if(minimize(path[v], path[u] + w)){
        heap.push(make_pair(path[v], v));
      }
    }
  }
  for(int i = 1; i <= n; ++i){
    int v = pos[i][1];
    if(path[v] == path[0]){
      printf("-1 ");
    }
    else{
      printf("%lld ", path[v]);
    }
  }
  return 0;
}