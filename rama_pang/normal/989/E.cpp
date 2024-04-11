#include <bits/stdc++.h>
using namespace std;

template<typename... Args>
void read(Args&... args) {
  ((cin >> args), ...);
}

template<typename... Args>
void write(Args&&... args) {
  ((cout << args), ...);
}

template<typename... Args>
void debug(Args&&... args) {
  ((cerr << args), ...);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  read(N);
  vector<int> X(N), Y(N);
  for (int i = 0; i < N; i++) {
    read(X[i], Y[i]);
  }

  const int LOG = 15;
  vector<map<pair<int, int>, vector<int>>> lines(N);
  vector<vector<vector<double>>> mat(LOG, vector<vector<double>>(N, vector<double>(N)));

  for (int i = 0; i < N; i++) {
    auto &mp = lines[i];
    for (int j = 0; j < N; j++) if (i != j) {
      int dx = X[j] - X[i];
      int dy = Y[j] - Y[i];
      if (dx == 0) {
        dy = 1;
      } else if (dy == 0) {
        dx = 1;
      } else {
        int g = gcd(abs(dx), abs(dy));
        dx /= g;
        dy /= g;
        if (dy < 0) {
          dx *= -1;
          dy *= -1;
        }
      }
      mp[{dx, dy}].emplace_back(j);
    }
    int cnt = mp.size();
    for (auto &[slope, vec] : mp) {
      vec.emplace_back(i);
      int sz = vec.size();
      for (auto j : vec) {
        mat[0][j][i] += (1.0 / sz) / cnt;
      }
    }
  }

  for (int p = 1; p < LOG; p++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        mat[p][i][j] = 0;
        for (int k = 0; k < N; k++) {
          mat[p][i][j] += mat[p - 1][i][k] * mat[p - 1][k][j];
        }
      }
    }
  }

  const auto Solve = [&](int et, int m) {
    vector<double> dp(N, 0), ndp(N, 0);
    dp[et] = 1;
    for (int p = 0; p < LOG; p++) {
      if ((m >> p) & 1) {
        fill(begin(ndp), end(ndp), 0);
        for (int i = 0; i < N; i++) {
          for (int j = 0; j < N; j++) {
            ndp[j] += dp[i] * mat[p][i][j];
          }
        }
        swap(dp, ndp);
      }
    }
    return dp;
  };

  int Q;
  read(Q);
  while (Q--) {
    int et, m;
    read(et, m);
    et--;

    // Choose a starting point in S
    double ans = 0;
    vector<double> save(N);
    
    auto save0 = Solve(et, m - 0);
    auto save1 = Solve(et, m - 1);
    
    for (int i = 0; i < N; i++) {
      ans = max(ans, save0[i]);
      for (auto &[slope, vec] : lines[i]) {
        double sum = 0;
        int sz = vec.size();
        for (auto j : vec) {
          sum += 1.0 * save1[j] / sz;
        }
        ans = max(ans, sum);
      }
    }
    write(fixed, setprecision(12), ans, '\n');
  }
  return 0;
}