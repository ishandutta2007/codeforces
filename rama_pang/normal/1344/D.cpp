#include <bits/stdc++.h>
using namespace std;
using lint = __int128;
const int MAXN = 100005;
const lint INF = 1e30;

lint N, K;
lint A[MAXN];
lint ans[MAXN];

lint ReadInt() {
  long long x;
  cin >> x;
  return (lint) x;
}

void Write(lint x) {
  long long x_ = x;
  cout << x_ << " ";
}

pair<lint, lint> Try(lint mincost, bool print = false) {
  lint res = 0;
  lint cost = 0;
  vector<lint> ans(N);
  for (int i = 0; i < N; i++) {
    lint L = 0, R = A[i];
    auto pow3 = [](const lint &x) { return x * x * x; };
    while (L < R) {
      lint mid = (L + R + 1) / 2;
      if (A[i] - (pow3(mid) - pow3(mid - 1)) >= mincost + print) {
        L = mid;
      } else {
        R = mid - 1;
      }
    }
    ans[i] = L;
    res += L;
    cost += (A[i] - L * L) * L;
  }

  if (print) {
    for (int i = 0; i < N; i++) {
      lint L = ans[i], R = A[i];
      auto pow3 = [](const lint &x) { return x * x * x; };
      while (L < R) {
        lint mid = (L + R + 1) / 2;
        if (A[i] - (pow3(mid) - pow3(mid - 1)) >= mincost) {
          L = mid;
        } else {
          R = mid - 1;
        }
      }

      res -= ans[i];
      cost -= (A[i] - ans[i] * ans[i]) * ans[i];
      res += L;
      ans[i] = L;
      if (res >= K) {
        ans[i] -= res - K;
        res = K;
      }

      cost += (A[i] - ans[i] * ans[i]) * ans[i];
      if (res == K) break;
    }

    for (int i = 0; i < N; i++) {
      Write(ans[i]);
    }
    cout << "\n";
  }

  return {res, cost};
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  N = ReadInt();
  K = ReadInt();
  for (int i = 0; i < N; i++) {
    A[i] = ReadInt();
  }

  lint lo = 0, hi = INF + INF;
  while (lo < hi) {
    lint mid = (lo + hi + 1) / 2;
    if (Try(mid - INF).first >= K) {
      lo = mid;
    } else {
      hi = mid - 1;
    }
  }

  Try(lo - INF, 1);
  return 0;
}