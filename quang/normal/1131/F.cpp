#include <bits/stdc++.h>

using namespace std;

const int N = 150010;

int n;
set<pair<int, int> > s[N];
int root[N];

int getRoot(int u) {
  return root[u] ? root[u] = getRoot(root[u]) : u;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    s[i].insert({0, i});
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    u = getRoot(u);
    v = getRoot(v);
    if (s[u].size() < s[v].size()) swap(u, v);
    int delta = s[u].size();
    for (auto x : s[v]) {
      s[u].insert({x.first + delta, x.second});
    }
    root[v] = u;
  }
  int now = getRoot(1);
  for (auto x : s[now]) {
    cout << x.second << ' ';
  }
  cout << endl;
  return 0;
}