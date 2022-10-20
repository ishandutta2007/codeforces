#include <bits/stdc++.h>

using namespace std;

const int N = 300010;

int n, m;
set<pair<int, int> > s;
set<int> notDead;
vector <int> now;

void go(int u) {
  vector <int> a;
  now.push_back(u);
  for (auto x : notDead) {
    if (s.count(make_pair(x, u)) == 0) {
      a.push_back(x);
    }
  }
  for (int i : a) {
    notDead.erase(i);
  }
  for (int i : a) {
    go(i);
  }
}

int main() {
  int k;
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    s.insert(make_pair(u, v));
    s.insert(make_pair(v, u));
  }
  for (int i = 2; i <= n; i++) {
    notDead.insert(i);
  }
  int cnt = 0;
  for (int i = 2; i <= n; i++) {
    if (notDead.count(i)) {
      now.clear();
      cnt++;
      notDead.erase(i);
      go(i);
      int f = 0;
      for (int j : now) {
        if (s.count(make_pair(1, j)) == 0) {
          f = 1;
          break;
        }
      }
      if (!f) {
        puts("impossible");
        return 0;
      }
    }
  }
  int tot = 0;
  for (int i = 2; i <= n; i++) {
    tot += s.count(make_pair(1, i)) == 0;
  }
  if (tot < k) {
    puts("impossible");
    return 0;
  }
  if (cnt > k) {
    puts("impossible");
    return 0;
  }
  puts("possible");
  return 0;
}