#include <bits/stdc++.h>
using namespace std;

using lint = long long;
// #define int lint

lint ReadInt() {
  char c = getchar();
  while (!('0' <= c && c <= '9')) c = getchar();
  lint x = 0;
  while ('0' <= c && c <= '9') {
    x = x * 10 + (c - '0');
    c = getchar();
  }
  return x;
}

const lint MAX = 1e5 + 100;
lint cntBlock[MAX];

void Main() {
  lint N;
  cin >> N;
  vector<lint> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  lint ans = 0;
  const lint MOD = 998244353;
  vector<pair<lint, lint>> lasts;
  vector<pair<lint, lint>> newLasts;
  vector<int> que;
  for (int r = N - 1; r >= 0; r--) {
    for (auto [x, y] : lasts) {
      lint c = (A[r] + x - 1) / x;
      ans += 1ll * (c - 1) * y % MOD * (r + 1) % MOD;
      ans %= MOD;
      newLasts.emplace_back(A[r] / c, y);
    }
    que.clear();
    newLasts.emplace_back(A[r], 1);
    for (auto [x, y] : newLasts) {
      if (cntBlock[x] == 0) {
        que.emplace_back(x);
      }
      cntBlock[x] += y;
    }
    lasts.clear();
    newLasts.clear();
    for (auto x : que) {
      lasts.emplace_back(x, cntBlock[x]);
      cntBlock[x] = 0;
    }
  }
  cout << ans << '\n';
  // return;

  // ans = 0;
  // for (int l = 0; l < N; l++) {
  //   for (int r = l; r < N; r++) {
  //     lint last = A[r];
  //     for (int i = r - 1; i >= l; i--) {
  //       lint c = (A[i] + last - 1) / last;
  //       ans += c - 1;
  //       last = A[i] / c;
  //     }
  //     // 
  //     // last = A[i] / c has sqrt N values
  //     // so 
  //   }
  // }
  // cout << ans << '\n';
}

int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}