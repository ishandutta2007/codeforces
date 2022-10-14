#include <bits/stdc++.h>
using namespace std;
using lint = long long;

const lint INF = 1e16;

lint a[1 << 23];
int mindepth[1 << 23];
int h, g, N, POP, diff;

int assess(int n) {
  int l = 2 * n;
  int r = 2 * n + 1;

  if (a[l] == 0 && a[r] == 0) {
    return 0;
  }

  if (a[l] > a[r]) {
    return 1 + min(assess(l), mindepth[r]);
  } else {
    return 1 + min(assess(r), mindepth[l]);
  }
}

void f(int n) {
  int l = 2 * n;
  int r = 2 * n + 1;

  if (a[l] == 0 && a[r] == 0) {
    a[n] = 0;
    mindepth[n] = 0;
    return;
  }

  if (a[l] > a[r]) {
    a[n] = a[l];
    f(l);
  } else {
    a[n] = a[r];
    f(r);
  }

  mindepth[n] = 1 + min(mindepth[n * 2], mindepth[n * 2 + 1]);

}

vector<int> ans;
lint sum;

void dfs(int n, int k) {
  if (a[n] == 0) return;
  while (assess(n) >= k) {
    sum -= a[n];
    ans.emplace_back(n);
    f(n);
  }
  dfs(n * 2 + 1, k - 1);
  dfs(n * 2, k - 1);
}

void solve() {
  cin >> h >> g;
  int N = (1 << h) - 1;
  POP = (1 << h) - (1 << g);
  sum = 0;
  for (int i = 1; i <= N; i++) {
    cin >> a[i];
    sum += a[i];
  }
  for (int i = N; i >= 1; i--) {
    mindepth[i] = mindepth[i * 2] + 1;
  }

  dfs(1, g);
  cout << sum << "\n";
  for (auto &i : ans) {
    cout << i << " ";
  }
  cout << "\n";

  ans.clear();


  for (int i = 0; i <= 2 * N + 10; i++) {
    a[i] = 0;
    mindepth[i] = 0;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    solve();
  }

}