#include <stdio.h>
#include <vector>

using namespace std;

const int N = 100010;
const int mod = 1000000007;

typedef pair<int, int> pii;

vector<pii> adj[N];
int n, m;

int pass[N], state[N];
int err = false;
int cnt = 0;

void dfs(int u, int c) {
  if(pass[u]) {
    if(c != state[u]) { 
      err = true;
    }
    return;
  }
  pass[u] = 1;
  state[u] = c;
  for(pii e : adj[u]) {
    if(e.second) {
      dfs(e.first, c);
    }else {
      dfs(e.first, not c);
    }
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for(int i = 0;i < m;i++) {
    int u, v, c;
    scanf("%d%d%d", &u, &v, &c);
    adj[u].push_back({v, c});
    adj[v].push_back({u, c});
  }
  for(int i = 1;i <= n;i++) {
    if((not pass[i])) {
      cnt++;
      dfs(i, 0);
    }
  }
  if(err) {
    printf("0\n");
  }else {
    int ans = 1;
    for(int i = 0;i < cnt-1;i++) {
      ans = (ans + ans) % mod;
    }
    printf("%d\n", ans);
  }
  return 0;
}