#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const lint INF = 1e16;
const lint LIM = 1e8;

lint N, A, B;
lint P[2005];
lint Q[2005];
lint PQ[2005];

lint dp[2005];
lint type[2005];

tuple<lint, lint, lint> trial(lint lambda1, lint lambda2) {
  dp[0] = 0;
  for (lint i = 1; i <= N; i++) {
    dp[i] = dp[i - 1];
    type[i] = 0;

    if (dp[i] < dp[i - 1] + P[i] - lambda1) {
      dp[i] = dp[i - 1] + P[i] - lambda1;
      type[i] = 1;
    }
    if (dp[i] < dp[i - 1] + Q[i] - lambda2) {
      dp[i] = dp[i - 1] + Q[i] - lambda2;
      type[i] = 2;
    }
    if (dp[i] < dp[i - 1] + PQ[i] - lambda1 - lambda2) {
      dp[i] = dp[i - 1] + PQ[i] - lambda1 - lambda2;
      type[i] = 3;
    }
    if (P[i] - lambda1 == Q[i] - lambda2 && (type[i] == 1 || type[i] == 2)) {
      type[i] = 4;
    }
  }

  lint cntA = 0, cntB = 0, cntAB = 0;
  for (lint i = N; i >= 1; i--) {
    if (type[i] == 1 || type[i] == 3) {
      cntA++;
    }
    if (type[i] == 2 || type[i] == 3) {
      cntB++;
    }
    if (type[i] == 4) {
      cntAB++;
    }
  }
  return make_tuple(cntA, cntB, cntAB);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  cin >> N >> A >> B;
  for (lint i = 1; i <= N; i++) {
    double x;
    cin >> x;
    P[i] = x * LIM;
  }
  for (lint i = 1; i <= N; i++) {
    double x;
    cin >> x;
    Q[i] = x * LIM;
  }
  for (lint i = 1; i <= N; i++) {
    double x, y;
    x = P[i], y = Q[i];
    x /= LIM, y /= LIM;
    PQ[i] = LIM * (x + y - x * y);
  }
  pair<lint, lint> opt = {-1, -1};
  for (lint l1 = 0, r1 = INF, m1 = (l1 + r1) / 2; l1 < r1; m1 = (l1 + r1) / 2) {
    lint opt2 = -1;
    for (lint l2 = 0, r2 = INF, m2 = (l2 + r2) / 2; l2 < r2; m2 = (l2 + r2) / 2) {
      lint cntA, cntB, cntAB;
      tie(cntA, cntB, cntAB) = trial(m1, m2);
      if (cntB <= B) {
        opt2 = m2;
        r2 = m2 - 1;
      } else {
        l2 = m2 + 1;
      }
    }
    lint cntA, cntB, cntAB;
    tie(cntA, cntB, cntAB) = trial(m1, opt2);
    if (cntA <= A && cntB <= B && cntA + cntB + cntAB <= A + B) {
      opt = {m1, opt2};
      r1 = m1 - 1;
    } else {
      l1 = m1 + 1;
    }
  }

  trial(opt.first, opt.second);
  cout << fixed << setprecision(10);
  cout << (1.00 * (dp[N] + A * opt.first + B * opt.second) / (1.00 * LIM)) << "\n";
  return 0;
}