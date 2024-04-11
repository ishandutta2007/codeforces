#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 1;

int n, m, sz, tag;
int arr[N];
int crr[N];
int dead[N];
int team[N];
int found = -1;
vector < int > adj[N];
vector < int > cell[N];

void dfs(int u, int change, int pre = 0){
  if(u <= n){
    for(int v : adj[u]){
      if(v == pre){
        continue;
      }
      if(crr[u] != 1){
        if(crr[v] != -1){
          if(crr[v] != 1){
            found = 0;
            return;
          }
        }
        else{
          crr[u] = 1;
          dfs(v, 1, u);
        }
      }
      else{
        if(crr[v] != -1){
          if(crr[v] != 0){
            found = 0;
            return;
          }
        }
      else{
          dfs(v, 0, u);
        }
      }
      if(found != -1){
        return;
      }
    }
  }
  else{
    crr[u] = change;
    for(int v : adj[u]){
      if(v == pre){
        continue;
      }
      if(change == 1){
        if(crr[v] != -1){
          if(crr[v] == 1){
            found = 0;
            return;
          }
          else{
            crr[v] = 1;
          }
        }
        else{
          crr[v] = 1 - arr[v];
          dfs(v, 0, u);
        }
      }
      else{
        if(crr[v] != -1){
          if(crr[v] != 1){
            found = 0;
            return;
          }
          else{
            crr[v] = 1;
          }
        }
        else{
          crr[v] = arr[v];
          dfs(v, 1, u);
        }
      }
      if(found != -1){

        return;
      }
    }
  }
}

void vst(int u){
  cell[tag].push_back(u);
  team[u] = tag;
  for(int v : adj[u]){
    if(team[v] != 0){
      continue;
    }
    vst(v);
  }
}

int main(){
  #ifndef ONLINE_JUDGE
    freopen("1.inp", "r", stdin);
    //freopen("1.out", "w", stdout);
  #endif
  scanf("%d%d", &n, &m);
  sz = n;
  for(int i = 1; i <= n; ++i){
    scanf("%d", arr + i);
  }
  for(int i = 1; i <= m; ++i){
    int x;
    ++sz;
    scanf("%d", &x);
    for(int j = 1; j <= x; ++j){
      int u;
      scanf("%d", &u);
      adj[sz].push_back(u);
      adj[u].push_back(sz);
    }
  }
  for(int i = 1; i <= sz; ++i){
    if(team[i] == 0){
      ++tag;
      vst(i);
    }
  }
  for(int i = n + 1; i <= sz; ++i){
    if(dead[i] == 1){
      continue;
    }
    for(int v : cell[team[i]]){
      crr[v] = -1;
    }
    found = -1;
    dfs(i, 1);
    if(found == -1){
      bool ok = true;
      for(int v : cell[team[i]]){
        if(v <= n){
          if(crr[v] != 1){
            ok = false;
            break;
          }
        }
      }
      if(ok == true){
        for(int v : cell[team[i]]){
          dead[v] = 1;
        }
        continue;
      }
    }
    for(int v : cell[team[i]]){
      crr[v] = -1;
    }
    found = -1;
    dfs(i, 0);
    if(found == -1){
      bool ok = false;
      for(int v : cell[team[i]]){
        if(v <= n){
          if(crr[v] != 1){
            ok = true;
            break;
          }
        }
      }
      if(ok == false){
        for(int v : cell[team[i]]){
          dead[v] = 1;
        }
        continue;
      }
    }
    cout << "NO";
    exit(0);
  }
  cout << "YES";
  return 0;
}