#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;
vector <int> a[N];
pair<int, int> b[N];
int pos;

void dfs(int u, int p) {
  if (u != pos && a[u].size() == 1) {
    b[u] = make_pair(1, 1);
    return;
  }
  b[u] = make_pair(1, 1);
  for (int v : a[u]) {
    if (v == p) {
      continue;
    }
    dfs(v, u);
    b[u].first &= b[v].second;
  }
  int x = a[u].size();
  if (u != pos) {
    x--;
  }
  if (b[u].first == 0) {
    b[u].second = 0;
  }
  if (x == 2) {
    b[u].second = 0;
  }
  if (x > 2) {
    b[u] = make_pair(0, 0);
  }
}

void dfs2(int u, int p, int ex, int f) {
  if (b[u].first == 1) {
    return;
  }
  int cnt = 0;
  int sl = 0;
  vector <int> st;
  for (int v : a[u]) {
    if (v == p) {
      continue;
    }
    if (b[v].first == 0) {
      cnt++;
      if (cnt > ex) {
        cout << "No";
        exit(0);
      }
      st.push_back(v);
    }
    if (b[v].first == 1) {
      if (b[v].second == 0) {
        sl = 3;
      } else {
        sl++;
      }
    }
  }
  int next = 1;
  if (f == 1 && sl <= 2 && cnt == 1) {
    next = 2;
  }
  for (int v : st) {
    dfs2(v, u, next, 0);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  #ifdef Doflamingo
  freopen("input.txt", "r", stdin);
  #endif // Doflamingo
  cin >> n;
  if (n <= 4) {
    cout << "Yes";
    return 0;
  }
  for (int i = 1; i < n; i++) {
    int u , v;
    cin >> u >> v;
    a[u].push_back(v);
    a[v].push_back(u);
  }
  pos = 0;
  for (int i = 1; i <= n; i++) {
    if ((int)a[pos].size() < (int)a[i].size()) {
      pos = i;
    }
  }
  dfs(pos, 0);
  dfs2(pos, 0, 2, 1);
  cout << "Yes";
  return 0;
}