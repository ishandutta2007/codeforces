#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, p[N], c[N];
bool vis[N];

bool all_same_color(const vector<int> &v) {
  for (int i = 1; i < v.size(); ++i) {
    if (c[v[i]] != c[v[0]]) return false;
  }

  return true;
}

int minimum_power(const vector<int> &v) {
  int n = v.size();
  vector<int> divisors;
  for (int i = 1; i*i <= n; ++i) {
    if (n % i != 0) continue;
    divisors.push_back(i);
    if (i*i != n) divisors.push_back(n/i);
  }

  sort(divisors.begin(), divisors.end());
  for (int d: divisors) {
    vector<int> cycles[d];
    for (int i = 0; i < v.size(); ++i) {
      cycles[i % d].push_back(v[i]);
    }

    for (int i = 0; i < d; ++i) if (all_same_color(cycles[i])) return d;
  }

  return -1;
}

int solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &p[i]), --p[i];
  for (int i = 0; i < n; ++i) scanf("%d", &c[i]);

  for (int i = 0; i < n; ++i) {
    vis[i] = false;
  }

  int ans = n;
  for (int i = 0; i < n; ++i) {
    if (vis[i]) continue;
    vis[i] = true;

    vector<int> v = {i};
    int j = p[i];
    while (j != i) {
      v.push_back(j);
      vis[j] = true;
      j = p[j];
    }

    ans = min(ans, minimum_power(v));
  }

  printf("%d\n", ans);
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}