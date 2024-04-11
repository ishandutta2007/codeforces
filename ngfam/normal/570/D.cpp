#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 10;

struct query{
  int x;
  int height;
  int idx;
};

int n, m, curr, sz;
int fr[N];
int to[N];
int depth[N];
char arr[N];
long long answer[N];
long long f[N];
vector < int > adj[N / 4];
query ask[N];

void dfs(int u){
  if(u == 1){
    depth[u] = 1;
  }
  fr[u] = ++curr;
  for(int v : adj[u]){
    depth[v] = depth[u] + 1;
    dfs(v);
  }
  to[u] = curr;
}

bool comp(query u, query v){
  if(u.x == v.x){
    return u.idx == 0;
  }
  return u.x < v.x;
}

int main(){
  #ifdef pts
    freopen("1.inp", "r", stdin);
  //  freopen("1.out", "w", stdout);
  #endif
  scanf("%d%d", &n, &m);
  for(int i = 2; i <= n; ++i){
    int parent;
    scanf("%d", &parent);
    adj[parent].push_back(i);
  }
  scanf("%s", arr + 1);
  dfs(1);
  for(int i = 1; i <= m; ++i){
    int u, h;
    scanf("%d%d", &u, &h);
    ask[++sz] = {fr[u] - 1, h, i};
    ask[++sz] = {to[u], h, i};
  }
  for(int i = 1; i <= n; ++i){
    ask[++sz] = {fr[i], i, 0};
  }
  sort(ask + 1, ask + sz + 1, comp);
  for(int i = 1; i <= sz; ++i){
    if(ask[i].idx == 0){
      int u = ask[i].height;
      f[depth[u]] ^= (1LL << (arr[u] - 'a'));
    }
    else{
      int idx = ask[i].idx;
      answer[idx] ^= f[ask[i].height];
    }
  }
  for(int i = 1; i <= m; ++i){
    if(__builtin_popcount(answer[i]) <= 1){
      puts("Yes");
    }
    else{
      puts("No");
    }
  }
  return 0;
}