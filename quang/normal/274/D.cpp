#include <bits/stdc++.h>

using namespace std;

const int N = 300010;

int n, m, cnt;
vector <int> a[N];
vector <int> ord;
int pos[N];
int used[N];

void dfs(int u) {
  used[u] = 1;
  for (int v : a[u]) {
    if (!used[v]) {
      dfs(v);
    }
  }
  ord.push_back(u);
}

int main() {
//  freopen("input.txt", "r", stdin);
  scanf("%d %d", &n, &m);
  cnt = m;
  vector <pair<int, int> > b;
  vector <pair<int, int> > c;
  for (int i = 0; i < n; i++) {
    b.clear();
    c.clear();
    for (int j = 0; j < m; j++) {
      int u;
      scanf("%d", &u);
      if (u != -1) {
        b.push_back(make_pair(u * 2, j));
      }
    }
    sort(b.begin(), b.end());
    if (b.empty()) {
      continue;
    }
    c.push_back(b[0]);
    for (int j = 1; j < b.size(); j++) {
      if (b[j].first != b[j - 1].first) {
        c.push_back(make_pair(b[j].first - 1, cnt++));
      }
      c.push_back(b[j]);
    }
    int now = 0;
    for (int j = 0; j < c.size(); j++) {
      while (now < c.size() && c[now].first <= c[j].first) {
        now++;
      }
      if (now == c.size()) {
        break;
      }
      int val = c[now].first;
      for (int k = now; k < c.size(); k++) {
        if (c[k].first != val) {
          break;
        }
        a[c[j].second].push_back(c[k].second);
      }
    }
  }
  for (int i = 0; i < cnt; i++) {
    if (!used[i]) {
      dfs(i);
    }
  }
  reverse(ord.begin(), ord.end());
  for (int i = 0; i < cnt; i++) {
    pos[ord[i]] = i;
  }
  for (int u = 0; u < cnt; u++) {
    for (int v : a[u]) {
      if (pos[u] > pos[v]) {
        cout << -1 << endl;
        return 0;
      }
    }
  }
  for (int i : ord) {
    if (i < m) {
      printf("%d ", i + 1);
    }
  }
//  freopen("input.txt", "w", stdout);
//  cout << 1 << " " << 100000 << endl;
//  for (int i = 1; i <= 50000; i++) {
//    cout << 1 << " ";
//  }
//  for (int i = 1; i <= 50000; i++) {
//    cout << 2 << " ";
//  }
  return 0;
}