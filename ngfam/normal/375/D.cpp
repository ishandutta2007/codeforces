#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10, Base = 320;

struct query{
  int fr;
  int to;
  int k;
  int id;
}ask[N];

int n, m, curr;
int arr[N];
int crr[N];
int to[N];
int fr[N];
int topo[N];
int cnt[N];
int f[N];
int answer[N];
vector < int > adj[N];
vector < query > block[Base];

void ins(int u){
  ++cnt[u];
  ++f[cnt[u]];
}

void del(int u){
  --f[cnt[u]];
  --cnt[u];
}

void dfs(int u, int p){
  fr[u] = ++curr;
  topo[curr] = u;
  for(int v : adj[u]){
    if(v == p){
      continue;
    }
    dfs(v, u);
  }
  to[u] = curr;
}

bool cmp(query u, query v){
  return u.fr < v.fr;
}

bool cmp2(query u, query v){
  return u.to < v.to;
}

int main(){
  #ifdef pts
    freopen("1.inp", "r", stdin);
    //freopen(".out", "w", stdout);
  #endif // pts
  scanf("%d%d", &n, &m);
  for(int i = 1; i <= n; ++i){
    scanf("%d", crr + i);
  }
  for(int i = 1; i < n; ++i){
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1, 0);
  for(int i = 1; i <= n; ++i){
    arr[i] = crr[topo[i]];
  }
  for(int i = 1; i <= m; ++i){
    int u, k;
    scanf("%d%d", &u, &k);
    ask[i] = {fr[u], to[u], k, i};
  }
  sort(ask + 1, ask + m + 1, cmp);
  for(int i = 1; i <= m; ++i){
    int val = (ask[i].fr - 1) / Base + 1;
    block[val].push_back(ask[i]);
  }
  for(int i = 1; i < Base; ++i){
    sort(block[i].begin(), block[i].end(), cmp2);
  }
  for(int tt = 1; tt < Base; ++tt){
    if(block[tt].size() == 0){
      continue;
    }
    memset(cnt, 0, sizeof cnt);
    memset(f, 0, sizeof f);
    for(int i = block[tt][0].fr; i <= block[tt][0].to; ++i){
      ins(arr[i]);
    }
    answer[block[tt][0].id] = f[block[tt][0].k];
    for(int i = 1; i < block[tt].size(); ++i){
      int fpre = block[tt][i - 1].fr, tpre = block[tt][i - 1].to;
      int fcur = block[tt][i].fr, tcur = block[tt][i].to;
      if(fpre <= fcur){
        for(int idx = fpre; idx < fcur; ++idx){
          del(arr[idx]);
        }
      }
      else{
        for(int idx = fcur; idx < fpre; ++idx){
          ins(arr[idx]);
        }
      }
      if(tpre <= tcur){
        for(int idx = tpre + 1; idx <= tcur; ++idx){
          ins(arr[idx]);
        }
      }
      else{
        for(int idx = tcur + 1; idx <= tpre; ++idx){
          del(arr[idx]);
        }
      }
      answer[block[tt][i].id] = f[block[tt][i].k];
    }
  }
  for(int i = 1; i <= m; ++i){
    printf("%d\n", answer[i]);
  }
  return 0;
}