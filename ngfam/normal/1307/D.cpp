#include<bits/stdc++.h>

using namespace std;

const int maxn = 200005;

vector<int> g[maxn];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int n, m, k;
  cin >> n >> m >> k;

  vector<int> spec(k), inspec(n);
  for(int &x : spec) {
    cin >> x;
    inspec[--x] = 1;
  }

  for(int i = 0; i < m; ++i) {
    int u, v; cin >> u >> v;
    g[--u].push_back(--v);
    g[v].push_back(u);
  }

  vector<int> f(n, 1e9), w(n, 1e9);

  auto bfs = [&](int s, vector<int> &p) {
    p[s] = 0;
    queue <int> que; que.push(s);
    while(!que.empty()) {
      int x = que.front(); que.pop();
      for(int s : g[x]) {
        if(p[s] > p[x] + 1) {
          p[s] = p[x] + 1;
          que.push(s);
        }
      }
    }
  };

  bfs(0, f);
  bfs(n - 1, w);

  for(int x : spec) {
    for(int y : g[x]) {
      if(inspec[y]) {
        cout << w[0] << endl;
        return 0;
      }
    }
  }

  sort(spec.begin(), spec.end(), [&](int x, int y){
    return f[x] < f[y];
  });

  multiset<int> cur;
  for(int x : spec) cur.insert(w[x]);

  int ans = 0;
  for(int x : spec) {
    cur.erase(cur.find(w[x]));
    if(!cur.empty()) {
      ans = max(ans, f[x] + *cur.rbegin() + 1);
    }
  }

  cout << min(ans, f[n - 1]) << endl;

  return 0;
}