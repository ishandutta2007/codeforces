#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

int n, m, q, curr, sz, tag;
int num[N];
int low[N];
int dead[N];
int team[N];
int jump[N][20];
int depth[N];
int up[N];
int direct[N];
int lab[N];
int tree[N];
int vsted[N];
vector < int > adj[N];
set < int > gra[N];
stack < int > current;

void dfs(int u, int p = 0){
  current.push(u);
  num[u] = low[u] = ++curr;
  int parent = 1;
  for(int v : adj[u]){
    if(dead[v] == 1){
      continue;
    }
    if(v == p && parent == 1){
      parent = 0;
      continue;
    }
    if(num[v] == 0){
      dfs(v, u);
      low[u] = min(low[u], low[v]);
    }
    else{
      low[u] = min(low[u], num[v]);
    }
  }
  if(low[u] >= num[u]){
    ++sz;
    while(true){
      int v = current.top();
      dead[v] = 1;
      team[v] = sz;
      current.pop();
      if(v == u){
        break;
      }
    }
  }
}

void vst(int u, int p){
  tree[u] = tag;
  vsted[u] = 1;
  jump[u][0] = p;
  for(int i = 1; i < 20; ++i){
    if(jump[u][i - 1] == 0){
      break;
    }
    jump[u][i] = jump[jump[u][i - 1]][i - 1];
  }
  for(int v : gra[u]){
    if(v == p){
      continue;
    }
    depth[v] = depth[u] + 1;
    vst(v, u);
  }
}

int lca(int u, int v){
  if(depth[u] < depth[v]){
    swap(u, v);
  }
  for(int i = 19; i >= 0; --i){
    if(jump[u][i] == 0){
      continue;
    }
    if(depth[jump[u][i]] >= depth[v]){
      u = jump[u][i];
    }
  }
  if(u == v){
    return u;
  }
  for(int i = 19; i >= 0; --i){
    if(jump[u][i] != jump[v][i]){
      u = jump[u][i];
      v = jump[v][i];
    }
  }
  return jump[u][0];
}

int fin(int u){
  if(lab[u] == u){
    return u;
  }
  return lab[u] = fin(lab[u]);
}

void join(int u, int v){
  lab[u] = v;
}

void work(int u, int p, int dir){
  while(u != p){
    if(direct[u] != -1){
      if(direct[u] != dir){
        puts("No");
        exit(0);
      }
      else{
        if(fin(u) == fin(p)){
          return;
        }
        u = fin(u);
      }
    }
    else{
      direct[u] = dir;
      join(u, jump[u][0]);
      u = jump[u][0];
    }
  }
}

int main(){
  #ifdef pts
    freopen("1.inp", "r", stdin);
  //  freopen("1.out", "w", stdout);
  #endif
  memset(direct, -1, sizeof direct);
  scanf("%d%d%d", &n, &m, &q);
  for(int i = 1; i <= m; ++i){
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for(int i = 1; i <= n; ++i){
    lab[i] = i;
    if(num[i] == 0){
      dfs(i);
    }
  }
  for(int u = 1; u <= n; ++u){
    for(int v : adj[u]){
      if(team[u] == team[v]){
        continue;
      }
      gra[team[u]].insert(team[v]);
    }
  }
  for(int i = 1; i <= sz; ++i){
    if(!vsted[i]){
      ++tag;
      vst(i, 0);
    }
  }
  for(int i = 1; i <= q; ++i){
    int u, v, p;
    scanf("%d%d", &u, &v);
    u = team[u];
    v = team[v];
    if(u == v){
      continue;
    }
    if(tree[u] != tree[v]){
      cout << "No";
      return 0;
    }
    p = lca(u, v);
    work(u, p, 0);
    work(v, p, 1);
  }
  cout << "Yes";
  return 0;
}