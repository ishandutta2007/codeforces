#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
const int N = 1e5 + 123;

int n, m;
vector<int> g[N];
int a[N];
int pr[N];
bool taken[N];
vector<int> ans;

void NO() {
  cout << "-1\n";
  exit(0);
}

void dfs(int v) {
  if (a[v] != v && a[pr[v]] != a[v]) NO();
  
  for (int u : g[v]) {
    dfs(u);
  }
  
  if (taken[v]) ans.push_back(v);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  
  #ifdef LOCAL
  freopen("input.txt", "r", stdin);
  #endif
  
  cin >> n >> m;
  fill(pr, pr + n, -1);
  for (int i = 0; i < m; i++) {
    int p, q;
    cin >> p >> q;
    p--; q--;
    g[p].push_back(q);
    pr[q] = p;
  }
  
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
    
    if (!taken[a[i]]) {
      taken[a[i]] = 1;
    }
  }
  
  for (int i = 0; i < n; i++) {
    if (pr[i] != -1) continue;
    
    dfs(i);
  }
  
  cout << ans.size() << "\n";
  for (int i : ans) cout << i + 1 << "\n";
  
  return 0;
}