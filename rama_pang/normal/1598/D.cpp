#include <bits/stdc++.h>
using namespace std;

using lint = long long;
const lint MOD = 1e9 + 7;
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

void Main() {
  int n;
  cin >> n;
  // n = 10;
  lint brute = 0;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    a[i]--, b[i]--;
    // a[i] = rnd() % 10;
    // b[i] = rnd() % 10;
  }
  if (0) {
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        for (int k = j + 1; k < n; k++) {
          if (a[i] != a[j] && a[j] != a[k] && a[i] != a[k]) {
            brute++;
          } else if (b[i] != b[j] && b[j] != b[k] && b[i] != b[k]) {
            brute++;
          }
        }
      }
    }
    cout << brute << '\n';
  }
  lint ans = 0;
  vector<int> ga(n), gb(n);
  for (int i = 0; i < n; i++) {
    ga[a[i]]++;
    gb[b[i]]++;
  }
  ans += 1ll * n * (n - 1) * (n - 2) / 6;
  ans += 1ll * n * (n - 1) * (n - 2) / 6;
  for (int i = 0; i < n; i++) {
    ans -= 1ll * ga[i] * (ga[i] - 1) * (ga[i] - 2) / 6;
    ans -= 1ll * gb[i] * (gb[i] - 1) * (gb[i] - 2) / 6;
    ans -= 1ll * ga[i] * (ga[i] - 1) / 2 * (n - ga[i]);
    ans -= 1ll * gb[i] * (gb[i] - 1) / 2 * (n - gb[i]);
  }
  map<int, vector<int>> ls;
  for (int i = 0; i < n; i++) {
    ls[a[i]].emplace_back(b[i]);
  }
  lint total = 0;
  lint sumall = 0;
  lint sumsame = 0;
  vector<lint> cnt(n);
  lint lazy = 0;
  vector<lint> samexdiffy(n);
  vector<lint> ways(n);
  vector<lint> fq(n);
  for (auto [x, vec] : ls) {
    vector<array<lint, 2>> event;
    for (auto y : vec) {
      ans -= (sumall - sumsame - (cnt[y] * (total - cnt[y]) - samexdiffy[y]));
    }
    // for (auto y : vec) {
    //   ways[y] += total - cnt[y];
    //   ways[y] -= cnt[y];
    //   lazy += 1;
    // }
    for (auto y : vec) {
      sumall += total;
      sumsame += cnt[y];
    }
    for (auto y : vec) {
      cnt[y] += 1;
      total += 1;
    }
    lint sfq = 0;
    for (auto y : vec) {
      fq[y]++;
      sfq++;
    }
    for (auto y : vec) if (fq[y] != 0) {
      samexdiffy[y] += sfq - fq[y];
      fq[y] = 0;
    }
  }
  cout << ans << '\n';
  return;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}